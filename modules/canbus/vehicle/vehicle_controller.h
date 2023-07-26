/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

/**
 * @file vehicle_controller.h
 * @brief The class of VehicleController
 */

#pragma once

#include <unordered_map>

#include "modules/canbus/proto/canbus_conf.pb.h"
#include "modules/common_msgs/basic_msgs/error_code.pb.h"
#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/common_msgs/control_msgs/control_cmd.pb.h"

#include "cyber/common/log.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/message_manager.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

/**
 * @namespace apollo::canbus
 * @brief apollo::canbus
 */
namespace apollo {
namespace canbus {

using ::apollo::drivers::canbus::CanSender;
using ::apollo::drivers::canbus::MessageManager;

/**
 * @class VehicleController
 *
 * @brief This is the interface class of vehicle controller. It defines pure
 * virtual functions, and also some implemented common functions.
 */
template <typename SensorType>
class VehicleController {
 public:
  virtual ~VehicleController() = default;

  /**
   * @brief initialize the vehicle controller.
   * @param can_sender a pointer to canbus sender.
   * @param message_manager a pointer to the message_manager.
   * @return error_code
   */
  virtual common::ErrorCode Init(
      const VehicleParameter &params, CanSender<SensorType> *const can_sender,
      MessageManager<SensorType> *const message_manager) = 0;

  /**
   * @brief start the vehicle controller.
   * @return true if successfully started.
   */
  virtual bool Start() = 0;

  /**
   * @brief stop the vehicle controller.
   */
  virtual void Stop() = 0;

  /**
   * @brief calculate and return the chassis.
   * @returns a copy of chassis. Use copy here to avoid multi-thread issues.
   */
  virtual Chassis chassis() = 0;

  /**
   * @brief update the vehicle controller.
   * @param command the control command
   * @return error_code
   */
  virtual common::ErrorCode Update(const control::ControlCommand &command);

  /**
   * @brief set vehicle to appointed driving mode.
   * @param driving mode to be appointed.
   * @return error_code
   */
  virtual common::ErrorCode SetDrivingMode(
      const Chassis::DrivingMode &driving_mode);

 private:
  /*
   * @brief main logical function for operation the car enter or exit the auto
   * driving
   */
  virtual void Emergency() = 0;

  virtual common::ErrorCode EnableAutoMode() = 0;
  virtual common::ErrorCode DisableAutoMode() = 0;
  virtual common::ErrorCode EnableSteeringOnlyMode() = 0;
  virtual common::ErrorCode EnableSpeedOnlyMode() = 0;

  /*
   * @brief NEUTRAL, REVERSE, DRIVE
   */
  virtual void Gear(Chassis::GearPosition state) = 0;

  /*
   * @brief detail function for auto driving brake with new acceleration
   * acceleration:0.00~99.99, unit:%
   */
  virtual void Brake(double acceleration) = 0;

  /*
   * @brief drive with old acceleration gas:0.00~99.99 unit:%
   */
  virtual void Throttle(double throttle) = 0;

  /*
   * @brief drive with new acceleration/deceleration:-7.0~7.0, unit:m/s^2,
   * acc:-7.0~7.0, unit:m/s^2
   */
  virtual void Acceleration(double acc) = 0;

  /*
   * @brief steering with old angle speed angle:-99.99~0.00~99.99, unit:%,
   * left:+, right:-
   */
  virtual void Steer(double angle) = 0;

  /*
   * @brief steering with new angle speed angle:-99.99~0.00~99.99, unit:%,
   * left:+, right:- angle_spd:0.00~99.99, unit:deg/s
   */
  virtual void Steer(double angle, double angle_spd) = 0;

  /*
   * @brief set Electrical Park Brake
   */
  virtual void SetEpbBreak(const control::ControlCommand &command) = 0;
  virtual void SetBeam(const control::ControlCommand &command) = 0;
  virtual void SetHorn(const control::ControlCommand &command) = 0;
  virtual void SetTurningSignal(const control::ControlCommand &command) = 0;

  virtual void SetLimits() {}
  //   virtual void UpdateVehicleState(){};
  //   virtual void UpdateVehicleState(ChassisDetailInterface&
  //   chassis_detail){};

  //   virtual void SetEmergencyLight(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   SetExpectAction(const atlas_messages::ControlCommand::Reader& command){};
  //   virtual void SetFrontWiper(const atlas_messages::ControlCommand::Reader&
  //   command){}; virtual void setBrakeLight(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   setAcTemperature(const atlas_messages::ControlCommand::Reader&
  //   command){}; virtual void setAcMode(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   setAcWindSpeed(const atlas_messages::ControlCommand::Reader& command){};
  //   virtual void setAmbientLamps(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   setInnerCeilingLamps(const atlas_messages::ControlCommand::Reader&
  //   command){}; virtual void setFogLamps(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   setPositionLamps(const atlas_messages::ControlCommand::Reader&
  //   command){}; virtual void setDrivingLamps(const
  //   atlas_messages::ControlCommand::Reader& command){}; virtual void
  //   setDoor(const atlas_messages::ControlCommand::Reader& command){};

  //  public:
  //   void UpdateLastTimestampInControlMessage(void);
  //   void SaveControlMessageState(
  //       const atlas_messages::Event::Reader& event,
  //       int64_t current_message_receive_timestamp,
  //       int64_t last_message_receive_timestamp,
  //       bool ignoreg);
  //   void getDebug(IDebugChassis& debug);

  //  protected:
  //   virtual atlas_messages::Chassis::DrivingMode driving_mode();
  virtual void set_driving_mode(
      const atlas_messages::Chassis::DrivingMode &driving_mode);
  virtual void set_chassis_error_code(
      const atlas_messages::Chassis::ErrorCode &error_code) = 0;
  uint64_t last_timestamep_on_control_message(void);
  virtual bool check_is_latency_on_control_message(void);
  void set_max_letency_on_control_message(uint64_t max_latency);

  //  protected:
  //   canbus::VehicleParameter params_;
  //   common::VehicleParam vehicle_params_;
  //   CanSender<ChassisDetailInterface>* can_sender_ = nullptr;
  //   MessageManager<ChassisDetailInterface>* message_manager_ = nullptr;
  bool is_initialized_ = false;  // own by derviative concrete controller
  //   atlas_messages::Chassis::DrivingMode driving_mode_ =
  //   atlas_messages::Chassis::DrivingMode::COMPLETE_MANUAL; bool is_reset_ =
  //   false;  // reset command from control command std::mutex mode_mutex_;  //
  //   only use in this base class std::atomic<uint64_t>
  //   last_timestamep_on_control_message_; uint64_t max_latency_; std::mutex
  //   debug_mutex_; IDebugChassis debug_;
};
}  // namespace canbus
}  // namespace apollo