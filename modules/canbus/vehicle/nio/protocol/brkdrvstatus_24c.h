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

class Brkdrvstatus24c : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Brkdrvstatus24c();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 4, 'name': 'Brk_Msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|16]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int brk_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'BRKPRESSURESTS_NOT_INIT', 1: 'BRKPRESSURESTS_NORMAL', 2: 'BRKPRESSURESTS_FAULT'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkpressureSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::BrkpressurestsType brkpressurests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'Brkpressure', 'offset': -30.0, 'order': 'motorola', 'physical_range': '[-30|276.6]', 'physical_unit': 'bar', 'precision': 0.3, 'type': 'double'}
  double brkpressure(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'LongAccValue', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[2|2]', 'physical_unit': 'g', 'precision': 0.001, 'type': 'double'}
  double longaccvalue(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'VEHSPDSTS_VALID', 1: 'VEHSPDSTS_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Vehspdsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::VehspdstsType vehspdsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'enum': {0: 'VEHSPDDIR_STANDSTILL', 1: 'VEHSPDDIR_FORWARD', 2: 'VEHSPDDIR_BACKWARD', 3: 'VEHSPDDIR_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'Vehspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::VehspddirType vehspddir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 22, 'is_signed_var': False, 'len': 13, 'name': 'Vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 1.0, 'type': 'int'}
  int vehspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'enum': {0: 'EPBSWSTS_NOT_PRESSED', 1: 'EPBSWSTS_PRESSED', 2: 'EPBSWSTS_RESERVED', 3: 'EPBSWSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBswsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::EpbswstsType epbswsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'enum': {0: 'DRV_STATE_PARKED', 1: 'DRV_STATE_READY_FOR_DRVING', 2: 'DRV_STATE_DRIVING', 3: 'DRV_STATE_INVALID', 15: 'DRV_STATE_INVALID_OTHER_VALUES_RESERVED'}, 'is_signed_var': False, 'len': 4, 'name': 'Drv_state', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::Drv_stateType drv_state(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'enum': {0: 'BRKPEDLSTS_NOT_PRESSED', 1: 'BRKPEDLSTS_PRESSED', 2: 'BRKPEDLSTS_RESERVED', 3: 'BRKPEDLSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkPedlSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::BrkpedlstsType brkpedlsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'BRKLISTS_NO_REQUEST', 1: 'BRKLISTS_REQUEST', 2: 'BRKLISTS_RESERVED', 3: 'BRKLISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::BrklistsType brklists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'enum': {0: 'EPBFAILLAMP_OFF', 1: 'EPBFAILLAMP_ON', 2: 'EPBFAILLAMP_BLINKING', 3: 'EPBFAILLAMP_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBfaillamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::EpbfaillampType epbfaillamp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'EPBWARNLAMP_ONLY_READY_DURING_FUNCTION', 1: 'EPBWARNLAMP_DOOR_OPEN_DURING_AUTO', 2: 'EPBWARNLAMP_SEAT_BELT_UNBUCKLED', 3: 'EPBWARNLAMP_DOOR_OPEN_AND_BELT_UNBUCKLED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBwarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus_24c::EpbwarnlampType epbwarnlamp(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


