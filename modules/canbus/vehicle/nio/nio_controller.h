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

#pragma once

#include <memory>
#include <thread>

#include "modules/canbus/proto/canbus_conf.pb.h"
#include "modules/canbus/proto/vehicle_parameter.pb.h"
#include "modules/common_msgs/basic_msgs/error_code.pb.h"
#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/control_msgs/control_cmd.pb.h"

#include "modules/canbus/vehicle/nio/protocol/accreq_7f.h"
#include "modules/canbus/vehicle/nio/protocol/aebreq_79.h"
#include "modules/canbus/vehicle/nio/protocol/avp_req_15e.h"
#include "modules/canbus/vehicle/nio/protocol/bcusts_5e.h"
#include "modules/canbus/vehicle/nio/protocol/eps_req_c6.h"
#include "modules/canbus/vehicle/nio/protocol/light_req_336.h"
#include "modules/canbus/vehicle/nio/protocol/scmsts_7b.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "modules/canbus/vehicle/nio/protocol/vehiclelights_2c7.h"

namespace apollo {
namespace canbus {
namespace nio {

const int TRUN_SIGNAL_DELAY_TIME_10MS = 100;
enum DrivingModeChangingAction {
  DRIVING_MODE_CHANGE_NOT_ACTION = 0,
  DRIVING_MODE_CHANGING_ACTION = 1,
};

class NioController final
    : public VehicleController<::apollo::canbus::ChassisDetail> {
 public:
  explicit NioController(){};

  virtual ~NioController();

  ::apollo::common::ErrorCode Init(
      const VehicleParameter& params,
      CanSender<::apollo::canbus::ChassisDetail>* const can_sender,
      MessageManager<::apollo::canbus::ChassisDetail>* const message_manager)
      override;

  bool Start() override;

  /**
   * @brief stop the vehicle controller.
   */
  void Stop() override;

  /**
   * @brief calculate and return the chassis.
   * @returns a copy of chassis. Use copy here to avoid multi-thread issues.
   */
  ::apollo::canbus::Chassis chassis() override;

  /**
   * @brief update the vehicle controller.
   * @param command the control command
   * @return error_code
   */
  virtual ::apollo::common::ErrorCode Update(
      const ::apollo::control::ControlCommand& command);

 private:
  // main logical function for operation the car enter or exit the auto driving
  void Emergency() override;
  ::apollo::common::ErrorCode EnableAutoMode() override;
  ::apollo::common::ErrorCode DisableAutoMode() override;
  ::apollo::common::ErrorCode EnableSteeringOnlyMode() override;
  ::apollo::common::ErrorCode EnableSpeedOnlyMode() override;

  // NEUTRAL, REVERSE, DRIVE
  void Gear(::apollo::canbus::Chassis::GearPosition state) override;

  // brake with new acceleration
  // acceleration:0.00~99.99, unit:
  // acceleration_spd: 60 ~ 100, suggest: 90
  void Brake(double acceleration) override;

  // drive with old acceleration
  // gas:0.00~99.99 unit:
  void Throttle(double throttle) override;

  // drive with acceleration/deceleration
  // acc:-7.0~5.0 unit:m/s^2
  void Acceleration(double acc) override;

  // steering with old angle speed
  // angle:-99.99~0.00~99.99, unit:, left:+, right:-
  void Steer(double angle) override;

  // steering with new angle speed
  // angle:-99.99~0.00~99.99, unit:, left:+, right:-
  // angle_spd:0.00~99.99, unit:deg/s
  void Steer(double angle, double angle_spd) override;

  // set Electrical Park Brake
  void SetEpbBreak(const ::apollo::control::ControlCommand& command) override;
  void SetBeam(const ::apollo::control::ControlCommand& command) override;
  void SetHorn(const ::apollo::control::ControlCommand& command) override;
  void SetTurningSignal(
      const ::apollo::control::ControlCommand& command) override;

  void SetEmergencyLight(const ::apollo::control::ControlCommand& command) override;
  void SetExpectAction(const ::apollo::control::ControlCommand& command) override;
  void UpdateVehicleState() override;
  void UpdateVehicleState(::apollo::canbus::ChassisDetail& chassis_detail) override;

  void ADStateManager(const ::apollo::control::ControlCommand& command);
  void DetExpectAction(const ::apollo::control::ControlCommand& command);

  ::apollo::common::ErrorCode NioEnableSteerMode();
  ::apollo::common::ErrorCode NioEnableSpeedMode();
  ::apollo::common::ErrorCode NioDisableSpeedMode();
  ::apollo::common::ErrorCode NioEnableGear(::apollo::canbus::Chassis::GearPosition gear_position);

  void SetSteerType(::apollo::canbus::VehicleParameter_EpsMode rep_type) { steer_type = rep_type; }
  ::apollo::canbus::VehicleParameter_EpsMode GetSteerType() { return steer_type; }
  ::apollo::canbus::Eps_req_c6::EpsreqtypType EpsModeConvertToEpsReqTyp(::apollo::canbus::VehicleParameter_EpsMode rep_type);
  void SetGearPositionStatus(::apollo::canbus::Chassis::GearPosition gear_position) {
    gear_position_status_.exchange(gear_position);
  }
  ::apollo::canbus::Chassis::GearPosition GetGearPositionStatus(void) { return gear_position_status_; }

  void SetSteerChckeResponseFlag(::apollo::canbus::VehicleParameter_EpsMode rep_type);
  int32_t GetSteerChckeResponseFlag() { return check_response_steer_unit_flag; };


  void ResetProtocol();
  bool CheckChassisError();

 private:
  void SecurityDogThreadFunc();
  virtual bool CheckResponse(const int32_t flags, bool need_wait);
  void set_chassis_error_mask(const int32_t mask);
  int32_t chassis_error_mask();
  ::apollo::canbus::Chassis::ErrorCode chassis_error_code();
  void set_chassis_error_code(const ::apollo::canbus::Chassis::ErrorCode& error_code);

  void clear_chassis_error_code(const ::apollo::canbus::Chassis::ErrorCode& error_code);
  common::VehicleSignal::TurnSignal GetLeftTurnlightsts(
      ::apollo::canbus::Vehiclelights_2c7::LeftturnlightstsType state) {
    static int close_delay_time = 0;
    if (state == ::apollo::canbus::Vehiclelights_2c7::LeftturnlightstsType::Vehiclelights_2c7_LeftturnlightstsType_LEFTTURNLIGHTSTS_ON) {
      close_delay_time = TRUN_SIGNAL_DELAY_TIME_10MS;
    } else {
      if (close_delay_time) close_delay_time--;
    }
    if (close_delay_time == 0) {
      return common::VehicleSignal::VehicleSignal::TurnSignal::VehicleSignal_TurnSignal_TURN_NONE;
    } else {
      return common::VehicleSignal::VehicleSignal::TurnSignal::VehicleSignal_TurnSignal_TURN_LEFT;
    }
  }
  common::VehicleSignal::VehicleSignal::TurnSignal GetRightTurnlightsts(
      ::apollo::canbus::Vehiclelights_2c7::RightturnlightstsType state) {
    static int close_delay_time = 0;
    if (state == ::apollo::canbus::Vehiclelights_2c7::RightturnlightstsType::Vehiclelights_2c7_RightturnlightstsType_RIGHTTURNLIGHTSTS_ON) {
      close_delay_time = TRUN_SIGNAL_DELAY_TIME_10MS;
    } else {
      if (close_delay_time) close_delay_time--;
    }
    if (close_delay_time == 0) {
      return common::VehicleSignal::VehicleSignal::TurnSignal::VehicleSignal_TurnSignal_TURN_NONE;
    } else {
      return common::VehicleSignal::VehicleSignal::TurnSignal::VehicleSignal_TurnSignal_TURN_LEFT;
    }
  }

 private:
  // control protocol
  Accreq7f* Accreq7f_ = nullptr;
  Aebreq79* Aebreq79_ = nullptr;
  Avpreq15e* AvpReq15e_ = nullptr;
  Bcusts5e* Bcusts5e_ = nullptr;
  Epsreqc6* EpsReqC6_ = nullptr;
  Lightreq336* LightReq336_ = nullptr;
  Scmsts7b* Scmsts7b_ = nullptr;

  ::apollo::canbus::Chassis chassis_;
  std::unique_ptr<std::thread> thread_;
  bool is_chassis_error_ = false;

  std::mutex chassis_error_code_mutex_;
  ::apollo::canbus::Chassis::ErrorCode chassis_error_code_ = ::apollo::canbus::Chassis::NO_ERROR;
  ::apollo::canbus::Chassis::ExpectAction action_ = ::apollo::canbus::Chassis::ExpectAction::Chassis_ExpectAction_STOPPING;
  ::apollo::canbus::Chassis::AutoDriveState ad_state_ = ::apollo::canbus::Chassis::AutoDriveState::Chassis_AutoDriveState_AD_INIT;
  std::string ad_error_reason_;

  apollo::cyber::Time init_time_;
  apollo::cyber::Time ad_starting_time_;
  apollo::cyber::Duration ad_response_time_;

  std::mutex chassis_mask_mutex_;
  int32_t chassis_error_mask_ = 0;


  int32_t check_response_steer_unit_flag = 0;
//   atlas::canbus::VehicleParameter_EpsMode steer_type;
  std::atomic<::apollo::canbus::VehicleParameter_EpsMode> steer_mode_status_;
  std::atomic<::apollo::canbus::Chassis::GearPosition> gear_position_status_;
  ::apollo::canbus::VehicleParameter_EpsMode steer_type;
  
  std::atomic<DrivingModeChangingAction> driving_mode_change_status_ = {DRIVING_MODE_CHANGE_NOT_ACTION};
  std::atomic<::apollo::canbus::Chassis::GearPosition> control_req_gear_position_ = {
      ::apollo::canbus::Chassis::GearPosition::Chassis_GearPosition_GEAR_INVALID};
  std::atomic<float> driving_speed_mps_ = {0};
  std::atomic<bool> brk_pedl_sts = {false};
  std::atomic<double> eps_tors_bar = {0.0};
  double speed_current_ = 0.0;
  int stop_condition_counter_ = 0;  // used for if enter to stopping 
  std::atomic<::apollo::canbus::Bcusts_5e_StandstillstsType> stand_still_status_ = {::apollo::canbus::Bcusts_5e_StandstillstsType::Bcusts_5e_StandstillstsType_STANDSTILLSTS_NON_HOLD};
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
