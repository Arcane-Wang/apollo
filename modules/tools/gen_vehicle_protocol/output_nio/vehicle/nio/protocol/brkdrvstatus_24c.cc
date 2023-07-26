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

#include "modules/canbus/vehicle/nio/protocol/brkdrvstatus_24c.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Brkdrvstatus24c::Brkdrvstatus24c() {}
const int32_t Brkdrvstatus24c::ID = 0x24C;

void Brkdrvstatus24c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_brk_msgcntr(brk_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_brkpressurests(brkpressurests(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_brkpressure(brkpressure(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_longaccvalue(longaccvalue(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_vehspdsts(vehspdsts(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_vehspddir(vehspddir(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_vehspd(vehspd(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_epbswsts(epbswsts(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_drv_state(drv_state(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_brkpedlsts(brkpedlsts(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_brklists(brklists(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_epbfaillamp(epbfaillamp(bytes, length));
  chassis->mutable_nio()->mutable_brkdrvstatus_24c()->set_epbwarnlamp(epbwarnlamp(bytes, length));
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 4, 'name': 'brk_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|16]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brkdrvstatus24c::brk_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'BRKPRESSURESTS_NOT_INIT', 1: 'BRKPRESSURESTS_NORMAL', 2: 'BRKPRESSURESTS_FAULT'}, 'is_signed_var': False, 'len': 2, 'name': 'brkpressurests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::BrkpressurestsType Brkdrvstatus24c::brkpressurests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 2);

  Brkdrvstatus_24c::BrkpressurestsType ret =  static_cast<Brkdrvstatus_24c::BrkpressurestsType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'brkpressure', 'offset': -30.0, 'order': 'motorola', 'physical_range': '[-30|276.6]', 'physical_unit': 'bar', 'precision': 0.3, 'type': 'double'}
double Brkdrvstatus24c::brkpressure(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 0.300000 + -30.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'longaccvalue', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[2|2]', 'physical_unit': 'g', 'precision': 0.001, 'type': 'double'}
double Brkdrvstatus24c::longaccvalue(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000 + -2.000000;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'VEHSPDSTS_VALID', 1: 'VEHSPDSTS_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'vehspdsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::VehspdstsType Brkdrvstatus24c::vehspdsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Brkdrvstatus_24c::VehspdstsType ret =  static_cast<Brkdrvstatus_24c::VehspdstsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'VEHSPDDIR_STANDSTILL', 1: 'VEHSPDDIR_FORWARD', 2: 'VEHSPDDIR_BACKWARD', 3: 'VEHSPDDIR_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'vehspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::VehspddirType Brkdrvstatus24c::vehspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus_24c::VehspddirType ret =  static_cast<Brkdrvstatus_24c::VehspddirType>(x);
  return ret;
}

// config detail: {'bit': 22, 'is_signed_var': False, 'len': 13, 'name': 'vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 1.0, 'type': 'int'}
int Brkdrvstatus24c::vehspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 7);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 1, 'enum': {0: 'EPBSWSTS_NOT_PRESSED', 1: 'EPBSWSTS_PRESSED', 2: 'EPBSWSTS_RESERVED', 3: 'EPBSWSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'epbswsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::EpbswstsType Brkdrvstatus24c::epbswsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus_24c::EpbswstsType ret =  static_cast<Brkdrvstatus_24c::EpbswstsType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'DRV_STATE_PARKED', 1: 'DRV_STATE_READY_FOR_DRVING', 2: 'DRV_STATE_DRIVING', 3: 'DRV_STATE_INVALID', 15: 'DRV_STATE_INVALID_OTHER_VALUES_RESERVED'}, 'is_signed_var': False, 'len': 4, 'name': 'drv_state', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::Drv_stateType Brkdrvstatus24c::drv_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 4);

  Brkdrvstatus_24c::Drv_stateType ret =  static_cast<Brkdrvstatus_24c::Drv_stateType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'BRKPEDLSTS_NOT_PRESSED', 1: 'BRKPEDLSTS_PRESSED', 2: 'BRKPEDLSTS_RESERVED', 3: 'BRKPEDLSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'brkpedlsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::BrkpedlstsType Brkdrvstatus24c::brkpedlsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 2);

  Brkdrvstatus_24c::BrkpedlstsType ret =  static_cast<Brkdrvstatus_24c::BrkpedlstsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'BRKLISTS_NO_REQUEST', 1: 'BRKLISTS_REQUEST', 2: 'BRKLISTS_RESERVED', 3: 'BRKLISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'brklists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::BrklistsType Brkdrvstatus24c::brklists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus_24c::BrklistsType ret =  static_cast<Brkdrvstatus_24c::BrklistsType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'EPBFAILLAMP_OFF', 1: 'EPBFAILLAMP_ON', 2: 'EPBFAILLAMP_BLINKING', 3: 'EPBFAILLAMP_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'epbfaillamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::EpbfaillampType Brkdrvstatus24c::epbfaillamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 2);

  Brkdrvstatus_24c::EpbfaillampType ret =  static_cast<Brkdrvstatus_24c::EpbfaillampType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'EPBWARNLAMP_ONLY_READY_DURING_FUNCTION', 1: 'EPBWARNLAMP_DOOR_OPEN_DURING_AUTO', 2: 'EPBWARNLAMP_SEAT_BELT_UNBUCKLED', 3: 'EPBWARNLAMP_DOOR_OPEN_AND_BELT_UNBUCKLED'}, 'is_signed_var': False, 'len': 2, 'name': 'epbwarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus_24c::EpbwarnlampType Brkdrvstatus24c::epbwarnlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Brkdrvstatus_24c::EpbwarnlampType ret =  static_cast<Brkdrvstatus_24c::EpbwarnlampType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
