#include "modules/canbus/vehicle/vehicle_controller.h"

namespace apollo {
namespace canbus {

using common::ErrorCode;
using control::ControlCommand;

template <typename SensorType>
Chassis::DrivingMode VehicleController<SensorType>::driving_mode() {
  std::lock_guard<std::mutex> lock(mode_mutex_);
  return driving_mode_;
}

template <typename SensorType>
void VehicleController<SensorType>::set_driving_mode(
    const Chassis::DrivingMode &driving_mode) {
  std::lock_guard<std::mutex> lock(mode_mutex_);
  driving_mode_ = driving_mode;
}

template <typename SensorType>
ErrorCode VehicleController<SensorType>::SetDrivingMode(
    const Chassis::DrivingMode &driving_mode) {
  if (driving_mode == Chassis::EMERGENCY_MODE) {
    AINFO << "Can't set vehicle to EMERGENCY_MODE driving mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  // vehicle in emergency mode only response to manual mode to reset.
  if (this->driving_mode() == Chassis::EMERGENCY_MODE &&
      driving_mode != Chassis::COMPLETE_MANUAL) {
    AINFO
        << "Vehicle in EMERGENCY_MODE, only response to COMPLETE_MANUAL mode.";
    AINFO << "Only response to RESET ACTION.";
    return ErrorCode::CANBUS_ERROR;
  }

  // if current mode is same as previous, no need to set.
  if (this->driving_mode() == driving_mode) {
    return ErrorCode::OK;
  }

  switch (driving_mode) {
    case Chassis::COMPLETE_AUTO_DRIVE: {
      if (EnableAutoMode() != ErrorCode::OK) {
        AERROR << "Failed to enable auto mode.";
        return ErrorCode::CANBUS_ERROR;
      }
      break;
    }
    case Chassis::COMPLETE_MANUAL: {
      if (DisableAutoMode() != ErrorCode::OK) {
        AERROR << "Failed to disable auto mode.";
        return ErrorCode::CANBUS_ERROR;
      }
      break;
    }
    case Chassis::AUTO_STEER_ONLY: {
      if (EnableSteeringOnlyMode() != ErrorCode::OK) {
        AERROR << "Failed to enable steer only mode.";
        return ErrorCode::CANBUS_ERROR;
      }
      break;
    }
    case Chassis::AUTO_SPEED_ONLY: {
      if (EnableSpeedOnlyMode() != ErrorCode::OK) {
        AERROR << "Failed to enable speed only mode";
        return ErrorCode::CANBUS_ERROR;
      }
      break;
    }
    default:
      break;
  }
  return ErrorCode::OK;
}

template <typename SensorType>
ErrorCode VehicleController<SensorType>::Update(
    const ControlCommand &control_command) {if (!is_initialized_) {
    AERROR << "Controller is not initialized." << std::endl;
    return ErrorCode::CANBUS_ERROR;
  }
  UpdateVehicleState();
  // Execute action to transform driving mode
  if (control_command.has_pad_msg() && control_command.pad_msg().action() != control::DrivingAction::INVALID) {
    AINFO << "Canbus received pad msg: " << static_cast<int>(control_command.pad_msg().action());
    Chassis::DrivingMode mode = Chassis::DrivingMode::COMPLETE_MANUAL;
    switch (control_command.pad_msg().action()) {
      case control::DrivingAction::START: {
        mode = Chassis::DrivingMode::COMPLETE_AUTO_DRIVE;
        break;
      }
      case control::DrivingAction::STOP:
      case control::DrivingAction::RESET: {
        // In COMPLETE_MANUAL mode clear code
        set_chassis_error_code(Chassis::ErrorCode::NO_ERROR);
        break;
      }
      default: {
        AERROR << "No response for this action." << std::endl;
        break;
      }
    }
    auto error_code = SetDrivingMode(mode);
    if (error_code != ErrorCode::OK) {
      AERROR << "Failed to set driving mode." << std::endl;
    }
    UpdateVehicleState();
  }

  if (driving_mode() == Chassis::DrivingMode::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::DrivingMode::AUTO_SPEED_ONLY) {
    Gear(control_command.getGearLocation());
    Throttle(control_command.getThrottle());
    Acceleration(control_command.getAcceleration());
    Brake(control_command.getBrake());
    SetEpbBreak(control_command);
    SetLimits();
  }
  SetExpectAction(control_command);
  if (driving_mode() == Chassis::DrivingMode::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::DrivingMode::AUTO_STEER_ONLY) {
    const double steering_rate_threshold = 1.0;
    if (control_command.steering_rate() > steering_rate_threshold) {
      Steer(control_command.steering_target(), control_command.steering_rate());
    } else {
      Steer(control_command.steering_target());
    }
  }

  if ((driving_mode() == Chassis::DrivingMode::COMPLETE_AUTO_DRIVE ||
       driving_mode() == Chassis::DrivingMode::AUTO_SPEED_ONLY ||
       driving_mode() == Chassis::DrivingMode::AUTO_STEER_ONLY) &&
      control_command.has_signal()) {
    SetHorn(control_command);
    SetTurningSignal(control_command);
    SetBeam(control_command);
    SetEmergencyLight(control_command);
    SetBrakeLightFlashing(control_command);
    SetFrontWiper(control_command);
    setBrakeLight(control_command);
    setAcTemperature(control_command);
    setAcMode(control_command);
    setAcWindSpeed(control_command);
    setAmbientLamps(control_command);
    setInnerCeilingLamps(control_command);
    setFogLamps(control_command);
    setPositionLamps(control_command);
    setDrivingLamps(control_command);
    setDoor(control_command);
  }

  return ErrorCode::OK;
}

template <typename SensorType>
void VehicleController<SensorType>::UpdateLastTimestampInControlMessage(void) {
  last_timestamep_on_control_message_.store(apollo::cyber::Time::Now().ToMicrosecond());
}

template <typename SensorType>
uint64_t VehicleController<SensorType>::last_timestamep_on_control_message(void) {
  return last_timestamep_on_control_message_.load();
}

template <typename SensorType>
void VehicleController<SensorType>::set_max_letency_on_control_message(uint64_t max_latency) {
  max_latency_ = max_latency;
}

template <typename SensorType>
bool VehicleController<SensorType>::check_is_latency_on_control_message(void) {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_SPEED_ONLY ||
      driving_mode() == Chassis::AUTO_STEER_ONLY) {
    uint64_t last_timestamep = last_timestamep_on_control_message();
    uint64_t now = apollo::cyber::Time::Now().ToMicrosecond();
    int64_t diff = max_latency_ - (now - last_timestamep);
    if (diff < 0) {
      AWARN << "\nit is latency on control message"
            << "\n             now : " << now << "\n last_timestamep : " << last_timestamep
            << "\n    max_latency_ : " << max_latency_ << "\n            diff : " << diff << " us" << std::endl;
      return true;
    }
  }
  return false;
}

template <typename SensorType>
void VehicleController<SensorType>::SaveControlMessageState(
    const control::ControlCommand &contro_command,
    int64_t current_message_receive_timestamp,
    int64_t last_message_receive_timestamp,
    bool ignore) {
  static uint32_t sequence_num = 0;
  int64_t now_timestamp = apollo::cyber::Time::Now().ToMicrosecond();
  std::lock_guard<std::mutex> lock(debug_mutex_);
  // debug_.Builder().setHeaderControlCmd(control_command.getHeader());
  // debug_.Builder().setThrottle(control_command.getThrottle());
  // debug_.Builder().setBrake(control_command.getBrake());
  // debug_.Builder().setSteeringRate(control_command.steering_rate());
  // debug_.Builder().setSteeringTarget(control_command.steering_target());
  // debug_.Builder().setParkingBrake(control_command.getParkingBrake());
  // debug_.Builder().setSpeed(control_command.getSpeed());
  // debug_.Builder().setAcceleration(control_command.getAcceleration());
  // debug_.Builder().setControlLatencyMs((current_message_receive_timestamp - last_message_receive_timestamp) / 1.0e3);
  // debug_.Builder().setControlPublishToChassisLatencySec(
  //     current_message_receive_timestamp / 1.0e6 - control_command.getHeader().getTimestampSec());
  // if (ignore) {
  //   uint32_t count = debug_.Builder().getIgnoreStatisticsOnControl();
  //   count++;
  //   debug_.Builder().setIgnoreStatisticsOnControl(count);
  // } else {
  //   debug_.Builder().setKMaxLatencySec(max_latency_);
  //   debug_.Builder().setLastTimestampOnControl(current_message_receive_timestamp / 1.0e6);
  //   debug_.Builder().setPreviousCanbusExceedTimeMs(debug_.Builder().getLastCanbusExceedTimeMs());
  //   debug_.Builder().setLastCanbusExceedTimeMs((now_timestamp - current_message_receive_timestamp) / 1.0e3);
  // }
  // debug_.Builder().setSequenceNum(sequence_num);
  sequence_num++;
}

// template <typename SensorType>
// void VehicleController<SensorType>::getDebug(IDebugChassis& debug) {
//   std::lock_guard<std::mutex> lock(debug_mutex_);
//   debug.CopyFrom(debug_, true);
// }

}  // namespace canbus
}  // namespace atlas

