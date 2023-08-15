/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/nio/nio_controller.h"

#include "modules/common_msgs/basic_msgs/vehicle_signal.pb.h"

#include "cyber/common/log.h"
#include "cyber/time/time.h"
#include "modules/canbus/vehicle/nio/nio_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::common::ErrorCode;
using ::apollo::control::ControlCommand;
using ::apollo::drivers::canbus::ProtocolData;
// using ::apollo::canbus;

namespace {

const int32_t kMaxFailAttempt = 10;
const int32_t kMaxFailCanAttempt = 3;
const uint64_t kMaxMaxLatencyDefault = 200 * 1e3;
const int32_t kMaxControlLatencyAttempt = 2;
int32_t kMaxFailSteerAttempt = 1;
int32_t kMaxFailEpsAttempt = 1;
double_t kMaxEpsOverload = 3.0;
bool enable_override_detection_flag = false;
int32_t kMaxBrakeAttempt = 100;
const int32_t CHECK_RESPONSE_STEER_PAI_UNIT_FLAG = 0x1 << 1;
const int32_t CHECK_RESPONSE_STEER_DAI_UNIT_FLAG = 0x1 << 2;
const int32_t CHECK_RESPONSE_STEER_TOI_UNIT_FLAG = 0x1 << 3;
const int32_t CHECK_RESPONSE_SPEED_UNIT_FLAG = 0x1 << 4;
const int32_t CHECK_RESPONSE_STEER_NO_FLAG = 0x1 << 5;
const int32_t CHECK_RESPONSE_SPEED_NOT_FLAG = 0x1 << 6;
const int32_t CHECK_RESONSE_GEAR_DRIVE = 0x01 << 7;
const int32_t CHECK_RESONSE_GEAR_REVERSE = 0x01 << 8;
const int32_t CHECK_RESONSE_GEAR_PARKING = 0x01 << 9;
}  // namespace

ErrorCode NioController::Init(
    const VehicleParameter& params,
    CanSender<::apollo::canbus::ChassisDetail>* const can_sender,
    MessageManager<::apollo::canbus::ChassisDetail>* const message_manager) {
  if (is_initialized_) {
    AINFO << "NioController has already been initiated.";
    return ErrorCode::CANBUS_ERROR;
  }

  vehicle_params_.CopyFrom(
      common::VehicleConfigHelper::Instance()->GetConfig().vehicle_param());
  params_.CopyFrom(params);
  if (!params_.has_driving_mode()) {
    AERROR << "Vehicle conf pb not set driving_mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  if (can_sender == nullptr) {
    return ErrorCode::CANBUS_ERROR;
  }
  can_sender_ = can_sender;

  if (message_manager == nullptr) {
    AERROR << "protocol manager is null.";
    return ErrorCode::CANBUS_ERROR;
  }
  message_manager_ = message_manager;

  // sender part
  Accreq7f_ = dynamic_cast<Accreq7f*>(
      message_manager_->GetMutableProtocolDataById(Accreq7f::ID));
  if (Accreq7f_ == nullptr) {
    AERROR << "Accreq7f does not exist in the NioMessageManager!";
    return ErrorCode::CANBUS_ERROR;
  }

  Aebreq79_ = dynamic_cast<Aebreq79*>(
      message_manager_->GetMutableProtocolDataById(Aebreq79::ID));
  if (Aebreq79_ == nullptr) {
    AERROR << "Aebreq79 does not exist in the NioMessageManager!";
    return ErrorCode::CANBUS_ERROR;
  }

  AvpReq15e_ = dynamic_cast<Avpreq15e*>(
      message_manager_->GetMutableProtocolDataById(Avpreq15e::ID));
  if (AvpReq15e_ == nullptr) {
    AERROR << "Avpreq15e does not exist in the NioMessageManager!";
    return ErrorCode::CANBUS_ERROR;
  }

  EpsReqC6_ = dynamic_cast<Epsreqc6*>(
      message_manager_->GetMutableProtocolDataById(Epsreqc6::ID));
  if (EpsReqC6_ == nullptr) {
    AERROR << "Epsreqc6 does not exist in the NioMessageManager!";
    return ErrorCode::CANBUS_ERROR;
  }

  LightReq336_ = dynamic_cast<Lightreq336*>(
      message_manager_->GetMutableProtocolDataById(Lightreq336::ID));
  if (LightReq336_ == nullptr) {
    AERROR << "Lightreq336 does not exist in the NioMessageManager!";
    return ErrorCode::CANBUS_ERROR;
  }

  can_sender_->AddMessage(Accreq7f::ID, Accreq7f_, false);
  can_sender_->AddMessage(Aebreq79::ID, Aebreq79_, false);
  can_sender_->AddMessage(Avpreq15e::ID, AvpReq15e_, false);
  can_sender_->AddMessage(Epsreqc6::ID, EpsReqC6_, false);
  can_sender_->AddMessage(Lightreq336::ID, LightReq336_, false);

  if (!params_.has_eps_mode()) {
    AERROR << "Vehicle conf pb not set eps_mode.";
    return ErrorCode::CANBUS_ERROR;
  }
  switch (params_.eps_mode()) {
    case VehicleParameter_EpsMode::VehicleParameter_EpsMode_EPS_PAI:
    case VehicleParameter_EpsMode::VehicleParameter_EpsMode_EPS_DAI:
    case VehicleParameter_EpsMode::VehicleParameter_EpsMode_EPS_TOI:
    case VehicleParameter_EpsMode::VehicleParameter_EpsMode_EPS_NO:
      SetSteerType(params_.eps_mode());
      break;
    default:
      SetSteerType(VehicleParameter_EpsMode::VehicleParameter_EpsMode_EPS_PAI);
      break;
  }
  SetSteerChckeResponseFlag(GetSteerType());
  check_response_steer_unit_flag = CHECK_RESPONSE_STEER_NO_FLAG;
  if (params_.has_max_latency()) {
    set_max_letency_on_control_message(params_.max_latency());
  } else {
    set_max_letency_on_control_message(kMaxMaxLatencyDefault);
  }
  if (params_.has_max_fail_steer_attempt()) {
    kMaxFailSteerAttempt = params_.max_fail_steer_attempt();
  }
  if (params_.has_max_fail_eps_attempt()) {
    kMaxFailEpsAttempt = params_.max_fail_eps_attempt();
  }
  if (params_.has_max_eps_overload()) {
    kMaxEpsOverload = params_.max_eps_overload();
  }
  if (params_.has_enable_override_detection()) {
    enable_override_detection_flag = params_.enable_override_detection();
  }
  if (params_.has_max_fail_brk_attempt()) {
    kMaxBrakeAttempt = params_.max_fail_brk_attempt();
  }

  // need sleep to ensure all messages received
  AINFO << "NioController is initialized.";

  is_initialized_ = true;
  speed_current_ = 0.0;
  return ErrorCode::OK;
}

NioController::~NioController() {}

bool NioController::Start() {
  if (!is_initialized_) {
    AERROR << "NioController has NOT been initiated.";
    return false;
  }
  const auto& update_func = [this] { SecurityDogThreadFunc(); };
  thread_.reset(new std::thread(update_func));

  return true;
}

void NioController::Stop() {
  if (!is_initialized_) {
    AERROR << "NioController stops or starts improperly!";
    return;
  }

  if (thread_ != nullptr && thread_->joinable()) {
    thread_->join();
    thread_.reset();
    AINFO << "NioController stopped.";
  }
}

Chassis NioController::chassis() {
  chassis_.Clear();

  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);

  // 21, 22, previously 1, 2
  if (driving_mode() == Chassis::EMERGENCY_MODE) {
    set_chassis_error_code(Chassis::NO_ERROR);
  }

  chassis_.set_driving_mode(driving_mode());
  chassis_.set_error_code(chassis_error_code());

  // 3
  // UpdateVehicleState(chassis_detail);
  if (!chassis_detail.has_nio()) {
    AERROR << "NO nio chassis information!";
    set_chassis_error_code(
        ::apollo::canbus::Chassis::ErrorCode::Chassis_ErrorCode_CHASSIS_ERROR);
    chassis_.set_error_code(chassis_error_code());
    // chassis_msg.CopyFrom(chassis_, true);
    return chassis_;
  }
  chassis_.set_engine_started(true);
  Nio nio = chassis_detail.nio();

  // 4 motor speed
  // AINFO << "chassis() motor speed" << std::endl;
  // front motor or read motor speed
  float motor_speed_rpm_front = 0.0f;
  if (nio.has_motorsts_02_86() &&
      (nio.motorsts_02_86().frntmotspdvalid() ==
       ::apollo::canbus::Motorsts_02_86_FrntmotspdvalidType::
           Motorsts_02_86_FrntmotspdvalidType_FRNTMOTSPDVALID_VALID)) {
    motor_speed_rpm_front = nio.motorsts_02_86().frntmotspd() * 1.0;
  }
  float motor_speed_rpm_rear = 0.0f;
  if (nio.has_motorsts_01_8e() &&
      (nio.motorsts_01_8e().rearmottqvalid() ==
       ::apollo::canbus::Motorsts_01_8e_RearmottqvalidType::
           Motorsts_01_8e_RearmottqvalidType_REARMOTTQVALID_VALID)) {
    motor_speed_rpm_rear = nio.motorsts_01_8e().rearmotspd() * 1.0;
  }
  // get max speed
  chassis_.set_engine_rpm(MAX(motor_speed_rpm_front, motor_speed_rpm_rear));

  // 5 6, speeds
  if (nio.has_brkdrvstatus_24c() &&
      (nio.brkdrvstatus_24c().vehspdsts() ==
       ::apollo::canbus::Brkdrvstatus_24c_VehspdstsType::
           Brkdrvstatus_24c_VehspdstsType_VEHSPDSTS_VALID)) {
    // km/h convert mps
    float speed_mps = nio.bodystatus_24d().vehspd() * 1000.0 / 3600.0;
    if (nio.brkdrvstatus_24c().vehspddir() ==
        ::apollo::canbus::Brkdrvstatus_24c_VehspddirType::
            Brkdrvstatus_24c_VehspddirType_VEHSPDDIR_BACKWARD) {
      speed_mps *= -1;
    }
    chassis_.set_speed_mps(speed_mps);
    speed_current_ = speed_mps;
  } else {
    chassis_.set_speed_mps(0.0);
    speed_current_ = 0.0;
  }
  // rr
  const ::apollo::canbus::WheelSpeed::WheelSpeedType chassis_whl_dir_convert[] =
      {
          ::apollo::canbus::WheelSpeed::WheelSpeedType::
              WheelSpeed_WheelSpeedType_STANDSTILL,
          ::apollo::canbus::WheelSpeed::WheelSpeedType::
              WheelSpeed_WheelSpeedType_FORWARD,
          ::apollo::canbus::WheelSpeed::WheelSpeedType::
              WheelSpeed_WheelSpeedType_BACKWARD,
          ::apollo::canbus::WheelSpeed::WheelSpeedType::
              WheelSpeed_WheelSpeedType_INVALID,
      };

  // Fr
  if (nio.has_whlspdfront_51() &&
      (nio.whlspdfront_51().whlspdfrsts() ==
       ::apollo::canbus::Whlspdfront_51_WhlspdfrstsType::
           Whlspdfront_51_WhlspdfrstsType_WHLSPDFRSTS_VALID)) {
    chassis_.mutable_wheel_speed()->set_is_wheel_spd_fr_valid(true);
    chassis_.mutable_wheel_speed()->set_wheel_direction_fr(
        chassis_whl_dir_convert[static_cast<uint16_t>(
            nio.whlspdfront_51().whlspdfrdir())]);
    chassis_.mutable_wheel_speed()->set_wheel_spd_fr(
        nio.whlspdfront_51().whlspdfr());
  }
  // Fl
  if (nio.has_whlspdfront_51() &&
      (nio.whlspdfront_51().whlspdflsts() ==
       ::apollo::canbus::Whlspdfront_51_WhlspdflstsType::
           Whlspdfront_51_WhlspdflstsType_WHLSPDFLSTS_VALID)) {
    chassis_.mutable_wheel_speed()->set_is_wheel_spd_fl_valid(true);
    chassis_.mutable_wheel_speed()->set_wheel_direction_fl(
        chassis_whl_dir_convert[static_cast<uint16_t>(
            nio.whlspdfront_51().whlspdfldir())]);
    chassis_.mutable_wheel_speed()->set_wheel_spd_fl(
        nio.whlspdfront_51().whlspdfl());
  }

  // Rr
  if (nio.has_whlspdrear_52() &&
      (nio.whlspdrear_52().whlspdrrsts() ==
       ::apollo::canbus::Whlspdrear_52_WhlspdrrstsType::
           Whlspdrear_52_WhlspdrrstsType_WHLSPDRRSTS_VALID)) {
    chassis_.mutable_wheel_speed()->set_is_wheel_spd_rr_valid(true);
    chassis_.mutable_wheel_speed()->set_wheel_direction_rr(
        chassis_whl_dir_convert[static_cast<uint16_t>(
            nio.whlspdrear_52().whlspdrrdir())]);
    chassis_.mutable_wheel_speed()->set_wheel_spd_rr(
        nio.whlspdrear_52().whlspdrr());
  }

  // rl
  if (nio.has_whlspdrear_52() &&
      (nio.whlspdrear_52().whlspdrlsts() ==
       ::apollo::canbus::Whlspdrear_52_WhlspdrlstsType::
           Whlspdrear_52_WhlspdrlstsType_WHLSPDRLSTS_VALID)) {
    chassis_.mutable_wheel_speed()->set_is_wheel_spd_rl_valid(true);
    chassis_.mutable_wheel_speed()->set_wheel_direction_rl(
        chassis_whl_dir_convert[static_cast<uint16_t>(
            nio.whlspdrear_52().whlspdrldir())]);
    chassis_.mutable_wheel_speed()->set_wheel_spd_rl(
        nio.whlspdrear_52().whlspdrl());
  }

  //   // 7
  chassis_.set_fuel_range_m(0);
  //   // 8
  const float kMaxAcc = 5.75;  // from ES6 DBC File
  const float kMinAcc = -7.0;  // from ES6 DBC File

  if (nio.has_brkdrvstatus_24c()) {
    chassis_.set_throttle_percentage(0);
    chassis_.set_brake_percentage(0);
    float acc = nio.brkdrvstatus_24c().longaccvalue() * 9.8f;  // g=9.8 m/s^2

    if (acc > 0) {
      chassis_.set_throttle_percentage(acc / kMaxAcc * 100.0);
    } else {
      chassis_.set_brake_percentage(acc / kMinAcc * 100.0);
    }
    chassis_.set_lon_accel(acc);
  }

  // 23, previously 10 gear position
  if (nio.has_vcusts_01_218() &&
      nio.vcusts_01_218().actual_gearvalid() ==
          ::apollo::canbus::Vcusts_01_218_Actual_gearvalidType::
              Vcusts_01_218_Actual_gearvalidType_ACTUAL_GEARVALID_VALID) {
    switch (nio.vcusts_01_218().actual_gear()) {
      case ::apollo::canbus::Vcusts_01_218_Actual_gearType::
          Vcusts_01_218_Actual_gearType_ACTUAL_GEAR_N:
        chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_NEUTRAL);
        break;

      case ::apollo::canbus::Vcusts_01_218_Actual_gearType::
          Vcusts_01_218_Actual_gearType_ACTUAL_GEAR_D:
        chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_DRIVE);
        break;

      case ::apollo::canbus::Vcusts_01_218_Actual_gearType::
          Vcusts_01_218_Actual_gearType_ACTUAL_GEAR_R:
        chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_REVERSE);
        break;

      case ::apollo::canbus::Vcusts_01_218_Actual_gearType::
          Vcusts_01_218_Actual_gearType_ACTUAL_GEAR_P:
        chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_PARKING);
        break;

      default:
        chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_INVALID);
        break;
    }
  } else {
    chassis_.set_gear_location(::apollo::canbus::Chassis::GEAR_INVALID);
  }

  // 11 steering wheel angle and sign
  if (nio.has_epsstatus01_d5()) {
    auto streering_percentage_dir = 1;
    switch (nio.epsstatus01_d5().steer_angledir()) {
      case ::apollo::canbus::Epsstatus01_d5_Steer_angledirType::
          Epsstatus01_d5_Steer_angledirType_STEER_ANGLEDIR_LEFT_PLUS:
        streering_percentage_dir = 1;
        break;

      case ::apollo::canbus::Epsstatus01_d5_Steer_angledirType::
          Epsstatus01_d5_Steer_angledirType_STEER_ANGLEDIR_RIGHT_MINUS:
      default:
        streering_percentage_dir = -1;
        break;
    }
    chassis_.set_steering_percentage(
        streering_percentage_dir * nio.epsstatus01_d5().steer_angle() * 100.0 /
        vehicle_params_.max_steer_angle() * M_PI / 180);
  }

  // 12 init torque
  if (nio.has_epsstatus01_d5()) {
    chassis_.set_steering_torque_nm(nio.epsstatus01_d5().torsbartq());
  }

  // 13 parking brake
  if (nio.has_brkdrvstatus_24c()) {
    chassis_.set_parking_brake(
        nio.brkdrvstatus_24c().epbswsts() ==
                ::apollo::canbus::Brkdrvstatus_24c_EpbswstsType::
                    Brkdrvstatus_24c_EpbswstsType_EPBSWSTS_PRESSED
            ? true
            : false);
  }

  // 14, 15 low beam
  if (nio.vehiclelights_2c7().lobeamlightsts() ==
      ::apollo::canbus::Vehiclelights_2c7_LobeamlightstsType::
          Vehiclelights_2c7_LobeamlightstsType_LOBEAMLIGHTSTS_ON) {
    chassis_.mutable_signal()->set_head_lamps(
        ::apollo::common::VehicleSignal_HeadLampsCmd::
            VehicleSignal_HeadLampsCmd_HEAD_LAMPS_LOW);
  } else if (nio.vehiclelights_2c7().hibeamlightsts() ==
             ::apollo::canbus::Vehiclelights_2c7_HibeamlightstsType::
                 Vehiclelights_2c7_HibeamlightstsType_HIBEAMLIGHTSTS_ON) {
    chassis_.mutable_signal()->set_head_lamps(
        ::apollo::common::VehicleSignal_HeadLampsCmd::
            VehicleSignal_HeadLampsCmd_HEAD_LAMPS_HIGH);
  } else {
    chassis_.mutable_signal()->set_head_lamps(
        ::apollo::common::VehicleSignal_HeadLampsCmd::
            VehicleSignal_HeadLampsCmd_HEAD_LAMPS_OFF);
  }
  chassis_.mutable_signal()->set_front_wiper(
      static_cast<::apollo::common::VehicleSignal_FrontWiper>(
          nio.vehiclelights_2c7().frntwipersts()));

  // emergency light
  switch (nio.vehiclelights_2c7().emergcylightsts()) {
    case ::apollo::canbus::Vehiclelights_2c7_EmergcylightstsType::
        Vehiclelights_2c7_EmergcylightstsType_EMERGCYLIGHTSTS_1_25HZ:
    case ::apollo::canbus::Vehiclelights_2c7_EmergcylightstsType::
        Vehiclelights_2c7_EmergcylightstsType_EMERGCYLIGHTSTS_1HZ:
      chassis_.mutable_signal()->set_emergency_light(true);
      break;
    default:
      chassis_.mutable_signal()->set_emergency_light(false);
      break;
  }

  // 16, 17
  auto turn_right_signal = GetRightTurnlightsts(
      nio.vehiclelights_2c7().rightturnlightsts());
  auto turn_left_signal =
      GetLeftTurnlightsts(nio.vehiclelights_2c7().leftturnlightsts());
  chassis_.mutable_signal()->set_turn_signal(
      (turn_right_signal >
       ::apollo::common::VehicleSignal_TurnSignal::VehicleSignal_TurnSignal_TURN_NONE)
          ? turn_right_signal
          : turn_left_signal);
  chassis_.set_left_turn_signal(
      turn_left_signal > ::apollo::common::VehicleSignal_TurnSignal::VehicleSignal_TurnSignal_TURN_NONE);
  chassis_.set_right_turn_signal(
      turn_right_signal >
      ::apollo::common::VehicleSignal_TurnSignal::VehicleSignal_TurnSignal_TURN_NONE);
  // 18 vin
  chassis_.mutable_vehicle_id()->set_vin("");

  if (chassis_error_mask_) {
    chassis_.set_chassis_error_mask(chassis_error_mask_);
  }
  // brake
  if (nio.has_brkdrvstatus_24c()) {
    if (nio.brkdrvstatus_24c().brkpedlsts() ==
        ::apollo::canbus::Brkdrvstatus_24c_BrkpedlstsType::
            Brkdrvstatus_24c_BrkpedlstsType_BRKPEDLSTS_NOT_PRESSED) {
      chassis_.mutable_brake()->set_is_brake_valid(true);
      chassis_.mutable_brake()->set_is_brake_pedal_pressed(false);
    } else if (nio.brkdrvstatus_24c().brkpedlsts() ==
               ::apollo::canbus::Brkdrvstatus_24c_BrkpedlstsType::
                   Brkdrvstatus_24c_BrkpedlstsType_BRKPEDLSTS_PRESSED) {
      chassis_.mutable_brake()->set_is_brake_valid(true);
      chassis_.mutable_brake()->set_is_brake_pedal_pressed(true);
    } else {
      chassis_.mutable_brake()->set_is_brake_valid(false);
      chassis_.mutable_brake()->set_is_brake_pedal_pressed(false);
    }
  }
  // eps status
  if (nio.has_epsstatus01_d5()) {
chassis_.mutable_eps()->set_is_eps_valid(true);
chassis_.mutable_eps()->set_eps_bar(nio.epsstatus01_d5().torsbartq());

  } else {
    chassis_.mutable_eps()->set_eps_bar(0.0);
  }
  // driver state
  if (nio.has_driverstatus_24e()) {
    chassis_.mutable_driver_status()->set_is_acc_pedal_override(
        nio.driverstatus_24e().vcuaccrpedlovrd() ==
                ::apollo::canbus::Driverstatus_24e_VcuaccrpedlovrdType::
                    Driverstatus_24e_VcuaccrpedlovrdType_VCUACCRPEDLOVRD_REQUEST
            ? true
            : false);
  }

  chassis_.set_expect_action(action_);
  chassis_.set_auto_drive_state(ad_state_);
  chassis_.set_driving_mode(driving_mode());
  chassis_.set_error_code(chassis_error_code());
  chassis_.set_stand_still(
      stand_still_status_ !=
      ::apollo::canbus::Bcusts_5e_StandstillstsType::Bcusts_5e_StandstillstsType_STANDSTILLSTS_NON_HOLD);
  // chassis_msg.CopyFrom(chassis_, true);
  return chassis_;
}

void NioController::Emergency() {
  set_driving_mode(Chassis::EMERGENCY_MODE);
  ResetProtocol();
  action_ = Chassis::ExpectAction::Chassis_ExpectAction_STOPPING;
  ad_state_ = Chassis::AutoDriveState::Chassis_AutoDriveState_AD_INIT;
}

ErrorCode NioController::EnableAutoMode() {
  ChassisDetail chassis_detail;
  if (message_manager_->GetSensorData(&chassis_detail) != ErrorCode::OK) {
    AERROR_EVERY(100) << "EnableAutoMode: get chassis detail failed." << std::endl;
    return ErrorCode::CANBUS_ERROR;
  }
  
  // check
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "already in COMPLETE_AUTO_DRIVE mode";
    return ErrorCode::OK;
  }

  AINFO << "NioEnableSteerMode:";
  // steer
  if (NioEnableSteerMode() != ErrorCode::OK) {
    AERROR << "Failed to switch to DrivingMode::EnableAutoMode mode.";
    return ErrorCode::CANBUS_ERROR;
  }
  AINFO << "NioEnableGear:";
  // set gear
  if (NioEnableGear(control_req_gear_position_) != ErrorCode::OK) {
    AERROR << "Failed to switch to DrivingMode::EnableAutoMode mode.";
    NioEnableGear(Chassis::GEAR_INVALID);
    return ErrorCode::CANBUS_ERROR;
  }

  AINFO << "NioEnableSpeedMode:~~~";
  // speed mode
  if (NioEnableSpeedMode() != ErrorCode::OK) {
    AERROR << "Failed to switch to DrivingMode::EnableAutoMode mode.";
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "switch to DrivingMode::EnableAutoMode mode Ok." << static_cast<int>(driving_mode());
  stop_condition_counter_ = 0;

  return ErrorCode::OK;
}

ErrorCode NioController::DisableAutoMode() {
  ResetProtocol();
  can_sender_->Update();
  set_driving_mode(Chassis::COMPLETE_MANUAL);
  AINFO << "Switch to DrivingMode::COMPLETE_MANUAL ok.";
  return ErrorCode::OK;
}

ErrorCode NioController::EnableSteeringOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_STEER_ONLY) {
    set_driving_mode(Chassis::AUTO_STEER_ONLY);
    AINFO << "Already in DrivingMode::Chassis_DrivingMode_AUTO_STEER_ONLY mode.";
    return ErrorCode::OK;
  }
  if (NioEnableSteerMode() == ErrorCode::OK) {
    set_driving_mode(Chassis::AUTO_STEER_ONLY);
    AINFO << "entern in DrivingMode::Chassis_DrivingMode_AUTO_STEER_ONLY mode.";
    return ErrorCode::OK;
  }
  return ErrorCode::CANBUS_ERROR;
}

ErrorCode NioController::EnableSpeedOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_SPEED_ONLY) {
    AINFO << "Already in DrivingMode::AUTO_SPEED_ONLY mode";
    return ErrorCode::OK;
  }
  return ErrorCode::CANBUS_ERROR;
}

// NEUTRAL, REVERSE, DRIVE
void NioController::Gear(Chassis::GearPosition gear_position) {
  if (gear_position == Chassis::GEAR_INVALID) {
    return;
  }
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "This drive mode no need to set gear.";
    return;
  }
  switch (gear_position) {
    case Chassis::GEAR_REVERSE:
    case Chassis::GEAR_DRIVE: {
      if (GetGearPositionStatus() != gear_position) {
        // R->P->D or D->P->R, changing and keep driving mode
        // 1. exit acc mode
        // 2. change gear
        // Enter auto mode
        AINFO << "Gear :: ";
        driving_mode_change_status_.exchange(DRIVING_MODE_CHANGING_ACTION);
        NioDisableSpeedMode();
        NioEnableGear(Chassis::GEAR_PARKING);
        // init to COMPLETE_MANUAL
        set_driving_mode(Chassis::COMPLETE_MANUAL);
        EnableAutoMode();
        driving_mode_change_status_.exchange(DRIVING_MODE_CHANGE_NOT_ACTION);
      }
      break;
    }
    case Chassis::GEAR_PARKING: {
      driving_mode_change_status_.exchange(DRIVING_MODE_CHANGING_ACTION);
      NioDisableSpeedMode();
      NioEnableGear(Chassis::GEAR_PARKING);
      DisableAutoMode();
      driving_mode_change_status_.exchange(DRIVING_MODE_CHANGE_NOT_ACTION);
      break;
    }
    default: {
      // AvpReq15e_->set_avp_targearreq(::apollo::canbus::Avp_req_15e::AVP_TARGEARREQ_NO_GEAR_REQUEST);
      break;
    }
  }
}

// brake with pedal
// pedal:0.00~99.99 unit:
void NioController::Brake(double pedal) {
  // double real_value = vehicle_params_.max_acceleration() * acceleration /
  // 100;
  // TODO(All) :  Update brake value based on mode
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set brake pedal.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_pedal(pedal);
  */
}

// drive with pedal
// pedal:0.00~99.99 unit:
void NioController::Throttle(double pedal) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set throttle pedal.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  throttle_62_->set_pedal(pedal);
  */
}

// confirm the car is driven by acceleration command or drive/brake pedal
// drive with acceleration/deceleration
// acc:-7.0 ~ 5.0, unit:m/s^2
void NioController::Acceleration(double acc) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set acceleration.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
   */
}

// nio default, +470 ~ -470, left:+, right:-
// need to be compatible with control module, so reverse
// steering with angle
// angle:-99.99~0.00~99.99, unit:, left:+, right:-
void NioController::Steer(double angle) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }
  // const double real_angle =
  //     vehicle_params_.max_steer_angle() / M_PI * 180 * angle / 100.0;
  // reverse sign
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  steering_64_->set_steering_angle(real_angle)->set_steering_angle_speed(200);
  */
}

// steering with new angle speed
// angle:-99.99~0.00~99.99, unit:, left:+, right:-
// angle_spd:0.00~99.99, unit:deg/s
void NioController::Steer(double angle, double angle_spd) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  const double real_angle =
      vehicle_params_.max_steer_angle() / M_PI * 180 * angle / 100.0;
  const double real_angle_spd =
  ProtocolData<::apollo::canbus::ChassisDetail>::BoundedValue(
      vehicle_params_.min_steer_angle_rate(),
  vehicle_params_.max_steer_angle_rate(), vehicle_params_.max_steer_angle_rate()
  * angle_spd / 100.0); steering_64_->set_steering_angle(real_angle)
      ->set_steering_angle_speed(real_angle_spd);
  */
}

void NioController::SetEpbBreak(const ControlCommand& command) {
  if (command.parking_brake()) {
    // None
  } else {
    // None
  }
}

void NioController::SetBeam(const ControlCommand& command) {
  // if (command.signal().high_beam()) {
  //   // None
  // } else if (command.signal().low_beam()) {
  //   // None
  // } else {
  //   // None
  // }
}

void NioController::SetHorn(const ControlCommand& command) {
  if (command.signal().horn()) {
    // None
  } else {
    // None
  }
}

void NioController::SetTurningSignal(const ControlCommand& command) {
  // Set Turn Signal
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  auto signal = command.signal().turn_signal();
  if (signal == common::VehicleSignal::TURN_LEFT) {
    turnsignal_68_->set_turn_left();
  } else if (signal == common::VehicleSignal::TURN_RIGHT) {
    turnsignal_68_->set_turn_right();
  } else {
    turnsignal_68_->set_turn_none();
  }
  */
}

void NioController::ResetProtocol() { message_manager_->ResetSendMessages(); }

bool NioController::CheckChassisError() {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
   */
  return false;
}

void NioController::SecurityDogThreadFunc() {
  int32_t vertical_ctrl_fail = 0;
  int32_t horizontal_ctrl_fail = 0;

  if (can_sender_ == nullptr) {
    AERROR << "Failed to run SecurityDogThreadFunc() because can_sender_ is "
              "nullptr.";
    return;
  }
  while (!can_sender_->IsRunning()) {
    std::this_thread::yield();
  }

  std::chrono::duration<double, std::micro> default_period{50000};
  int64_t start = 0;
  int64_t end = 0;
  while (can_sender_->IsRunning()) {
    start = ::apollo::cyber::Time::Now().ToMicrosecond();
    const Chassis::DrivingMode mode = driving_mode();
    bool emergency_mode = false;

    // 1. horizontal control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_STEER_ONLY) &&
        CheckResponse(GetSteerChckeResponseFlag(), false) == false) {
      ++horizontal_ctrl_fail;
      if (horizontal_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      horizontal_ctrl_fail = 0;
    }

    // 2. vertical control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_SPEED_ONLY) &&
        !CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, false)) {
      ++vertical_ctrl_fail;
      if (vertical_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      vertical_ctrl_fail = 0;
    }
    if (CheckChassisError()) {
      set_chassis_error_code(Chassis::CHASSIS_ERROR);
      emergency_mode = true;
    }

    if (emergency_mode && mode != Chassis::EMERGENCY_MODE) {
      set_driving_mode(Chassis::EMERGENCY_MODE);
      message_manager_->ResetSendMessages();
    }
    end = ::apollo::cyber::Time::Now().ToMicrosecond();
    std::chrono::duration<double, std::micro> elapsed{end - start};
    if (elapsed < default_period) {
      std::this_thread::sleep_for(default_period - elapsed);
    } else {
      AERROR << "Too much time consumption in NioController looping process:"
             << elapsed.count();
    }
  }
}

bool NioController::CheckResponse(const int32_t flags, bool need_wait) {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
   */
  return false;
}

void NioController::set_chassis_error_mask(const int32_t mask) {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  chassis_error_mask_ = mask;
}

int32_t NioController::chassis_error_mask() {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  return chassis_error_mask_;
}

Chassis::ErrorCode NioController::chassis_error_code() {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  return chassis_error_code_;
}

void NioController::set_chassis_error_code(
    const Chassis::ErrorCode& error_code) {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  chassis_error_code_ = error_code;
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
