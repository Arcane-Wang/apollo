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

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace nio {

class Accreq7f : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Accreq7f();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'ACC_DRVOFF_NO_REQUEST', 1: 'ACC_DRVOFF_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_DrvOff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq_7f::Acc_drvoffType acc_drvoff(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'ACC_DE_STOP_NO_REQUEST', 1: 'ACC_DE_STOP_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_De_stop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq_7f::Acc_de_stopType acc_de_stop(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MaxJerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
  double acc_maxjerk(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MinJerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
  double acc_minjerk(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'ACC_MODE_OFF_MODE', 1: 'ACC_MODE_PASSIVE_MODE', 2: 'ACC_MODE_STANDBY_MODE', 3: 'ACC_MODE_ACTIVE_CONTROL_MODE', 4: 'ACC_MODE_BRAKE_ONLY_MODE', 5: 'ACC_MODE_OVERRIDE_MODE', 6: 'ACC_MODE_STANDSTILL_MODE', 7: 'ACC_MODE_FAILURE_MODE'}, 'is_signed_var': False, 'len': 3, 'name': 'Acc_Mode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq_7f::Acc_modeType acc_mode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforLow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
  double acc_comforlow(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforUp', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
  double acc_comforup(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'ACC_HVYDECEL_NOT_REQUEST', 1: 'ACC_HVYDECEL_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_HvyDecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq_7f::Acc_hvydecelType acc_hvydecel(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 30, 'enum': {0: 'ACC_HEAVYMODE_INACTIVE', 1: 'ACC_HEAVYMODE_RESERVED1', 2: 'ACC_HEAVYMODE_RESERVED2', 3: 'ACC_HEAVYMODE_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'Acc_HeavyMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq_7f::Acc_heavymodeType acc_heavymode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'Acc_TarA', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
  double acc_tara(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Acc_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int acc_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Acc_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int acc_crc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


