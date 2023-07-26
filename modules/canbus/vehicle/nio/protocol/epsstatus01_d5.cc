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

#include "modules/canbus/vehicle/nio/protocol/epsstatus01_d5.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Epsstatus01d5::Epsstatus01d5() {}
const int32_t Epsstatus01d5::ID = 0xD5;

void Epsstatus01d5::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_epswarnlamp(epswarnlamp(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_abs_agreqavl(abs_agreqavl(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_torsbartq(torsbartq(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_epssts(epssts(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_epsmod(epsmod(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_steeragspddir(steeragspddir(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_steeragspd(steeragspd(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_steer_angledir(steer_angledir(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_steer_angleandspdvalid(steer_angleandspdvalid(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_steer_angle(steer_angle(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_eps_d_msgcntr(eps_d_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01_d5()->set_eps_d_crc(eps_d_crc(bytes, length));
}

// config detail: {'bit': 26, 'enum': {0: 'EPSWARNLAMP_OFF', 1: 'EPSWARNLAMP_ON', 2: 'EPSWARNLAMP_NOT_AVAILABLE', 3: 'EPSWARNLAMP_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'epswarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::EpswarnlampType Epsstatus01d5::epswarnlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  Epsstatus01_d5::EpswarnlampType ret =  static_cast<Epsstatus01_d5::EpswarnlampType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'ABS_AGREQAVL_NOT_AVAILABLE', 1: 'ABS_AGREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'abs_agreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::Abs_agreqavlType Epsstatus01d5::abs_agreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Epsstatus01_d5::Abs_agreqavlType ret =  static_cast<Epsstatus01_d5::Abs_agreqavlType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 10, 'name': 'torsbartq', 'offset': -10.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
double Epsstatus01d5::torsbartq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 0.020000 + -10.000000;
  return ret;
}

// config detail: {'bit': 36, 'enum': {0: 'EPSSTS_INIT', 1: 'EPSSTS_NORMAL', 2: 'EPSSTS_DEGRADED_DUE_TO_TEMP_OR_VOL', 3: 'EPSSTS_TEMPORARY_ERROR', 4: 'EPSSTS_PERMAMEMT_ERROR', 5: 'EPSSTS_RESERVED5', 6: 'EPSSTS_RESERVED6', 7: 'EPSSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'epssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::EpsstsType Epsstatus01d5::epssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 3);

  Epsstatus01_d5::EpsstsType ret =  static_cast<Epsstatus01_d5::EpsstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'EPSMOD_NONE', 1: 'EPSMOD_PAI', 2: 'EPSMOD_DAI', 3: 'EPSMOD_TOI', 7: 'EPSMOD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'epsmod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::EpsmodType Epsstatus01d5::epsmod(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Epsstatus01_d5::EpsmodType ret =  static_cast<Epsstatus01_d5::EpsmodType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'STEERAGSPDDIR_LEFT_PLUS', 1: 'STEERAGSPDDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'steeragspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::SteeragspddirType Epsstatus01d5::steeragspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Epsstatus01_d5::SteeragspddirType ret =  static_cast<Epsstatus01_d5::SteeragspddirType>(x);
  return ret;
}

// config detail: {'bit': 52, 'is_signed_var': False, 'len': 9, 'name': 'steeragspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|2550]', 'physical_unit': 'Deg/sec', 'precision': 5.0, 'type': 'double'}
double Epsstatus01d5::steeragspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 5);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 5.000000;
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'STEER_ANGLEDIR_LEFT_PLUS', 1: 'STEER_ANGLEDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'steer_angledir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::Steer_angledirType Epsstatus01d5::steer_angledir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Epsstatus01_d5::Steer_angledirType ret =  static_cast<Epsstatus01_d5::Steer_angledirType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'STEER_ANGLEANDSPDVALID_VALID', 1: 'STEER_ANGLEANDSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'steer_angleandspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01_d5::Steer_angleandspdvalidType Epsstatus01d5::steer_angleandspdvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Epsstatus01_d5::Steer_angleandspdvalidType ret =  static_cast<Epsstatus01_d5::Steer_angleandspdvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 13, 'name': 'steer_angle', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|800]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsstatus01d5::steer_angle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'eps_d_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsstatus01d5::eps_d_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'eps_d_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsstatus01d5::eps_d_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
