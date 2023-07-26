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

#include "modules/canbus/vehicle/nio/protocol/accreq_7f.h"

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
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_drvoff(acc_drvoff(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_de_stop(acc_de_stop(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_maxjerk(acc_maxjerk(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_minjerk(acc_minjerk(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_mode(acc_mode(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_comforlow(acc_comforlow(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_comforup(acc_comforup(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_hvydecel(acc_hvydecel(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_heavymode(acc_heavymode(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_tara(acc_tara(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_msgcntr(acc_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_accreq_7f()->set_acc_crc(acc_crc(bytes, length));
}

// config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'ACC_DRVOFF_NO_REQUEST', 1: 'ACC_DRVOFF_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'acc_drvoff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq_7f::Acc_drvoffType Accreq7f::acc_drvoff(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  Accreq_7f::Acc_drvoffType ret =  static_cast<Accreq_7f::Acc_drvoffType>(x);
  return ret;
}

// config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'ACC_DE_STOP_NO_REQUEST', 1: 'ACC_DE_STOP_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'acc_de_stop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq_7f::Acc_de_stopType Accreq7f::acc_de_stop(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  Accreq_7f::Acc_de_stopType ret =  static_cast<Accreq_7f::Acc_de_stopType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'acc_maxjerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
double Accreq7f::acc_maxjerk(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 7);

  double ret = x * 0.200000;
  return ret;
}

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'acc_minjerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
double Accreq7f::acc_minjerk(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(1, 7);

  double ret = x * 0.200000 + -25.400000;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'ACC_MODE_OFF_MODE', 1: 'ACC_MODE_PASSIVE_MODE', 2: 'ACC_MODE_STANDBY_MODE', 3: 'ACC_MODE_ACTIVE_CONTROL_MODE', 4: 'ACC_MODE_BRAKE_ONLY_MODE', 5: 'ACC_MODE_OVERRIDE_MODE', 6: 'ACC_MODE_STANDSTILL_MODE', 7: 'ACC_MODE_FAILURE_MODE'}, 'is_signed_var': False, 'len': 3, 'name': 'acc_mode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq_7f::Acc_modeType Accreq7f::acc_mode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 3);

  Accreq_7f::Acc_modeType ret =  static_cast<Accreq_7f::Acc_modeType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'acc_comforlow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
double Accreq7f::acc_comforlow(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'acc_comforup', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
double Accreq7f::acc_comforup(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'ACC_HVYDECEL_NOT_REQUEST', 1: 'ACC_HVYDECEL_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'acc_hvydecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq_7f::Acc_hvydecelType Accreq7f::acc_hvydecel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  Accreq_7f::Acc_hvydecelType ret =  static_cast<Accreq_7f::Acc_hvydecelType>(x);
  return ret;
}

// config detail: {'bit': 30, 'enum': {0: 'ACC_HEAVYMODE_INACTIVE', 1: 'ACC_HEAVYMODE_RESERVED1', 2: 'ACC_HEAVYMODE_RESERVED2', 3: 'ACC_HEAVYMODE_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'acc_heavymode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Accreq_7f::Acc_heavymodeType Accreq7f::acc_heavymode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 2);

  Accreq_7f::Acc_heavymodeType ret =  static_cast<Accreq_7f::Acc_heavymodeType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'acc_tara', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
double Accreq7f::acc_tara(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.050000 + -7.000000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'acc_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Accreq7f::acc_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'acc_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Accreq7f::acc_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
