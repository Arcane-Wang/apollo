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

#include "modules/canbus/vehicle/nio/protocol/Brkdrvstatus24c.h"

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
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_brkmsgcntr(brkmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_brkpressurests(brkpressurests(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_brkpressure(brkpressure(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_longaccvalue(longaccvalue(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_vehspdsts(vehspdsts(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_vehspddir(vehspddir(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_vehspd(vehspd(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_epbswsts(epbswsts(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_drvstate(drvstate(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_brkpedlsts(brkpedlsts(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_brklists(brklists(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_epbfaillamp(epbfaillamp(bytes, length));
  chassis->mutable_nio()->mutable_Brkdrvstatus24c()->set_epbwarnlamp(epbwarnlamp(bytes, length));
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 4, 'name': 'brkmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|16]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Brkdrvstatus24c::brkmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 4);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'BrkpressureStsNotInit', 1: 'BrkpressureStsnormal', 2: 'BrkpressureStsfault'}, 'is_signed_var': False, 'len': 2, 'name': 'brkpressurests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::BrkpressurestsType Brkdrvstatus24c::brkpressurests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 2);

  Brkdrvstatus24c::BrkpressurestsType ret =  static_cast<Brkdrvstatus24c::BrkpressurestsType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'brkpressure', 'offset': -30.0, 'order': 'motorola', 'physical_range': '[-30|276.6]', 'physical_unit': 'bar', 'precision': 0.3, 'type': 'Float64'}
Float64 Brkdrvstatus24c::brkpressure(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  Float64 ret = x * 0.300000 + -30.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'longaccvalue', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[2|2]', 'physical_unit': 'g', 'precision': 0.001, 'type': 'Float64'}
Float64 Brkdrvstatus24c::longaccvalue(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Float64 ret = x * 0.001000 + -2.000000;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'Vehspdstsvalid', 1: 'Vehspdstsinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'vehspdsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::VehspdstsType Brkdrvstatus24c::vehspdsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Brkdrvstatus24c::VehspdstsType ret =  static_cast<Brkdrvstatus24c::VehspdstsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'Vehspddirstandstill', 1: 'Vehspddirforward', 2: 'Vehspddirbackward', 3: 'Vehspddirreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'vehspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::VehspddirType Brkdrvstatus24c::vehspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus24c::VehspddirType ret =  static_cast<Brkdrvstatus24c::VehspddirType>(x);
  return ret;
}

// config detail: {'bit': 22, 'is_signed_var': False, 'len': 13, 'name': 'vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 1.0, 'type': 'Int32'}
Int32 Brkdrvstatus24c::vehspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 7);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 1, 'enum': {0: 'EPBswstsNotPressed', 1: 'EPBswstspressed', 2: 'EPBswstsreserved', 3: 'EPBswstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'epbswsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::EpbswstsType Brkdrvstatus24c::epbswsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus24c::EpbswstsType ret =  static_cast<Brkdrvstatus24c::EpbswstsType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'DrvStateParked', 1: 'DrvStateReadyForDrving', 2: 'DrvStatedriving', 3: 'DrvStateinvalid', 15: 'DrvStateInvalidOtherValuesReserved'}, 'is_signed_var': False, 'len': 4, 'name': 'drvstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::DrvstateType Brkdrvstatus24c::drvstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 4);

  Brkdrvstatus24c::DrvstateType ret =  static_cast<Brkdrvstatus24c::DrvstateType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'BrkPedlStsNotPressed', 1: 'BrkPedlStspressed', 2: 'BrkPedlStsreserved', 3: 'BrkPedlStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'brkpedlsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::BrkpedlstsType Brkdrvstatus24c::brkpedlsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 2);

  Brkdrvstatus24c::BrkpedlstsType ret =  static_cast<Brkdrvstatus24c::BrkpedlstsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'BrkListsNoRequest', 1: 'BrkListsrequest', 2: 'BrkListsreserved', 3: 'BrkListsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'brklists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::BrklistsType Brkdrvstatus24c::brklists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Brkdrvstatus24c::BrklistsType ret =  static_cast<Brkdrvstatus24c::BrklistsType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'EPBfaillampoff', 1: 'EPBfaillampon', 2: 'EPBfaillampblinking', 3: 'EPBfaillampinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'epbfaillamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::EpbfaillampType Brkdrvstatus24c::epbfaillamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 2);

  Brkdrvstatus24c::EpbfaillampType ret =  static_cast<Brkdrvstatus24c::EpbfaillampType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'EPBwarnlampOnlyReadyDuringFunction', 1: 'EPBwarnlampDoorOpenDuringAuto', 2: 'EPBwarnlampSeatBeltUnbuckled', 3: 'EPBwarnlampDoorOpenAndBeltUnbuckled'}, 'is_signed_var': False, 'len': 2, 'name': 'epbwarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brkdrvstatus24c::EpbwarnlampType Brkdrvstatus24c::epbwarnlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Brkdrvstatus24c::EpbwarnlampType ret =  static_cast<Brkdrvstatus24c::EpbwarnlampType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
