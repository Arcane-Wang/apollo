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

#include "modules/canbus/vehicle/nio/protocol/Accreq7f.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Accreq7f::Accreq7f() {}
const int32_t Accreq7f::ID = 0x7F;

void Accreq7f::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Accreq7f()->set_accdrvoff(accdrvoff(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accdestop(accdestop(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accmaxjerk(accmaxjerk(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accminjerk(accminjerk(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accmode(accmode(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_acccomforlow(acccomforlow(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_acccomforup(acccomforup(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_acchvydecel(acchvydecel(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accheavymode(accheavymode(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_acctara(acctara(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_accmsgcntr(accmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Accreq7f()->set_acccrc(acccrc(bytes, length));
}

// config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'AccDrvoffNoRequest', 1: 'AccDrvoffRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'accdrvoff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq7f::AccdrvoffType Accreq7f::accdrvoff(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  Accreq7f::AccdrvoffType ret =  static_cast<Accreq7f::AccdrvoffType>(x);
  return ret;
}

// config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'AccDeStopNoRequest', 1: 'AccDeStoprequest'}, 'is_signed_var': False, 'len': 1, 'name': 'accdestop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq7f::AccdestopType Accreq7f::accdestop(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  Accreq7f::AccdestopType ret =  static_cast<Accreq7f::AccdestopType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'accmaxjerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'Float64'}
Float64 Accreq7f::accmaxjerk(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 7);

  Float64 ret = x * 0.200000;
  return ret;
}

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'accminjerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'Float64'}
Float64 Accreq7f::accminjerk(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(1, 7);

  Float64 ret = x * 0.200000 + -25.400000;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'AccModeOffMode', 1: 'AccModePassiveMode', 2: 'AccModeStandbyMode', 3: 'AccModeActiveControlMode', 4: 'AccModeBrakeOnlyMode', 5: 'AccModeOverrideMode', 6: 'AccModeStandstillMode', 7: 'AccModeFailureMode'}, 'is_signed_var': False, 'len': 3, 'name': 'accmode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq7f::AccmodeType Accreq7f::accmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 3);

  Accreq7f::AccmodeType ret =  static_cast<Accreq7f::AccmodeType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'acccomforlow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
Float64 Accreq7f::acccomforlow(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Float64 ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'acccomforup', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
Float64 Accreq7f::acccomforup(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Float64 ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'AccHvydecelNotRequest', 1: 'AccHvydecelrequest'}, 'is_signed_var': False, 'len': 1, 'name': 'acchvydecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq7f::AcchvydecelType Accreq7f::acchvydecel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  Accreq7f::AcchvydecelType ret =  static_cast<Accreq7f::AcchvydecelType>(x);
  return ret;
}

// config detail: {'bit': 30, 'enum': {0: 'AccHeavymodeinactive', 1: 'AccHeavymodereserved1', 2: 'AccHeavymodereserved2', 3: 'AccHeavymodeactive'}, 'is_signed_var': False, 'len': 2, 'name': 'accheavymode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq7f::AccheavymodeType Accreq7f::accheavymode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 2);

  Accreq7f::AccheavymodeType ret =  static_cast<Accreq7f::AccheavymodeType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'acctara', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
Float64 Accreq7f::acctara(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Float64 ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'accmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Accreq7f::accmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'acccrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Accreq7f::acccrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Int32 ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
