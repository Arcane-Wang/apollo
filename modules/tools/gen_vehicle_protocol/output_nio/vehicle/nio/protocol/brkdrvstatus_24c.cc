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
const int32_t Brkdrvstatus24c::ID = 0x24c;

void Brkdrvstatus24c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasBrkdrvstatus24c() ) {
           chassis->Builder().getNio().initBrkdrvstatus24c();
        }
    }
  chassis->Builder().getNio().getbrkdrvstatus_24c().setBrk_Msgcntr(Brk_Msgcntr(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setBrkpressureSts(BrkpressureSts(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setBrkpressure(Brkpressure(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setLongAccValue(LongAccValue(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setVehspdsts(Vehspdsts(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setVehspddir(Vehspddir(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setVehspd(Vehspd(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setEPBswsts(EPBswsts(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setDrv_state(Drv_state(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setBrkPedlSts(BrkPedlSts(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setBrkLists(BrkLists(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setEPBfaillamp(EPBfaillamp(bytes, length));
  chassis->Builder().getNio().getbrkdrvstatus_24c().setEPBwarnlamp(EPBwarnlamp(bytes, length));
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 4, 'name': 'Brk_Msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|16]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Brkdrvstatus24c::Brk_Msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'BRKPRESSURESTS_NOT_INIT', 1: 'BRKPRESSURESTS_NORMAL', 2: 'BRKPRESSURESTS_FAULT'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkpressureSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::BrkpressureStsType Brkdrvstatus24c::BrkpressureSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::brkdrvstatus_24c::BrkpressureStsType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::BrkpressureStsType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'Brkpressure', 'offset': -30.0, 'order': 'motorola', 'physical_range': '[-30|276.6]', 'physical_unit': 'bar', 'precision': 0.3, 'type': 'double'}
 Brkdrvstatus24c::Brkpressure(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

   ret = x * 0.300000 + -30.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'LongAccValue', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[2|2]', 'physical_unit': 'g', 'precision': 0.001, 'type': 'double'}
 Brkdrvstatus24c::LongAccValue(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

   ret = x * 0.001000 + -2.000000;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'VEHSPDSTS_VALID', 1: 'VEHSPDSTS_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Vehspdsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::VehspdstsType Brkdrvstatus24c::Vehspdsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::brkdrvstatus_24c::VehspdstsType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::VehspdstsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'VEHSPDDIR_STANDSTILL', 1: 'VEHSPDDIR_FORWARD', 2: 'VEHSPDDIR_BACKWARD', 3: 'VEHSPDDIR_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'Vehspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::VehspddirType Brkdrvstatus24c::Vehspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::brkdrvstatus_24c::VehspddirType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::VehspddirType>(x);
  return ret;
}

// config detail: {'bit': 22, 'is_signed_var': False, 'len': 13, 'name': 'Vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 1.0, 'type': 'int'}
 Brkdrvstatus24c::Vehspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 7);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

   ret = x;
  return ret;
}

// config detail: {'bit': 1, 'enum': {0: 'EPBSWSTS_NOT_PRESSED', 1: 'EPBSWSTS_PRESSED', 2: 'EPBSWSTS_RESERVED', 3: 'EPBSWSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBswsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::EPBswstsType Brkdrvstatus24c::EPBswsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::brkdrvstatus_24c::EPBswstsType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::EPBswstsType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'DRV_STATE_PARKED', 1: 'DRV_STATE_READY_FOR_DRVING', 2: 'DRV_STATE_DRIVING', 3: 'DRV_STATE_INVALID', 15: 'DRV_STATE_INVALID_OTHER_VALUES_RESERVED'}, 'is_signed_var': False, 'len': 4, 'name': 'Drv_state', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::Drv_stateType Brkdrvstatus24c::Drv_state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 4);

  ::atlas_messages::brkdrvstatus_24c::Drv_stateType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::Drv_stateType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'BRKPEDLSTS_NOT_PRESSED', 1: 'BRKPEDLSTS_PRESSED', 2: 'BRKPEDLSTS_RESERVED', 3: 'BRKPEDLSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkPedlSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::BrkPedlStsType Brkdrvstatus24c::BrkPedlSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 2);

  ::atlas_messages::brkdrvstatus_24c::BrkPedlStsType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::BrkPedlStsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'BRKLISTS_NO_REQUEST', 1: 'BRKLISTS_REQUEST', 2: 'BRKLISTS_RESERVED', 3: 'BRKLISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::BrkListsType Brkdrvstatus24c::BrkLists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::brkdrvstatus_24c::BrkListsType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::BrkListsType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'EPBFAILLAMP_OFF', 1: 'EPBFAILLAMP_ON', 2: 'EPBFAILLAMP_BLINKING', 3: 'EPBFAILLAMP_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBfaillamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::EPBfaillampType Brkdrvstatus24c::EPBfaillamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::brkdrvstatus_24c::EPBfaillampType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::EPBfaillampType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'EPBWARNLAMP_ONLY_READY_DURING_FUNCTION', 1: 'EPBWARNLAMP_DOOR_OPEN_DURING_AUTO', 2: 'EPBWARNLAMP_SEAT_BELT_UNBUCKLED', 3: 'EPBWARNLAMP_DOOR_OPEN_AND_BELT_UNBUCKLED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBwarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::brkdrvstatus_24c::EPBwarnlampType Brkdrvstatus24c::EPBwarnlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::brkdrvstatus_24c::EPBwarnlampType ret =  static_cast<::atlas_messages::brkdrvstatus_24c::EPBwarnlampType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
