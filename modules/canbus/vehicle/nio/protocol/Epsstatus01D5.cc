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

#include "modules/canbus/vehicle/nio/protocol/Epsstatus01D5.h"

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
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_epswarnlamp(epswarnlamp(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_absagreqavl(absagreqavl(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_torsbartq(torsbartq(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_epssts(epssts(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_epsmod(epsmod(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_steeragspddir(steeragspddir(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_steeragspd(steeragspd(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_steerangledir(steerangledir(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_steerangleandspdvalid(steerangleandspdvalid(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_steerangle(steerangle(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_epsdmsgcntr(epsdmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus01D5()->set_epsdcrc(epsdcrc(bytes, length));
}

// config detail: {'bit': 26, 'enum': {0: 'EPSwarnLampoff', 1: 'EPSwarnLampon', 2: 'EPSwarnLampNotAvailable', 3: 'EPSwarnLampreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'epswarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::EpswarnlampType Epsstatus01d5::epswarnlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  Epsstatus01d5::EpswarnlampType ret =  static_cast<Epsstatus01d5::EpswarnlampType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'AbsAgreqavlNotAvailable', 1: 'AbsAgreqavlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'absagreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::AbsagreqavlType Epsstatus01d5::absagreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Epsstatus01d5::AbsagreqavlType ret =  static_cast<Epsstatus01d5::AbsagreqavlType>(x);
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

// config detail: {'bit': 36, 'enum': {0: 'EPSstsinit', 1: 'EPSstsnormal', 2: 'EPSstsDegradedDueToTempOrVol', 3: 'EPSstsTemporaryError', 4: 'EPSstsPermamemtError', 5: 'EPSstsreserved5', 6: 'EPSstsreserved6', 7: 'EPSstsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'epssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::EpsstsType Epsstatus01d5::epssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 3);

  Epsstatus01d5::EpsstsType ret =  static_cast<Epsstatus01d5::EpsstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'EPSModNone', 1: 'EPSModPAI', 2: 'EPSModDAI', 3: 'EPSModTOI', 7: 'EPSModinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'epsmod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::EpsmodType Epsstatus01d5::epsmod(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Epsstatus01d5::EpsmodType ret =  static_cast<Epsstatus01d5::EpsmodType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'SteeragspddirLeftPlus', 1: 'SteeragspddirRightMinus'}, 'is_signed_var': False, 'len': 1, 'name': 'steeragspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::SteeragspddirType Epsstatus01d5::steeragspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Epsstatus01d5::SteeragspddirType ret =  static_cast<Epsstatus01d5::SteeragspddirType>(x);
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

// config detail: {'bit': 10, 'enum': {0: 'SteerAngledirLeftPlus', 1: 'SteerAngledirRightMinus'}, 'is_signed_var': False, 'len': 1, 'name': 'steerangledir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::SteerangledirType Epsstatus01d5::steerangledir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Epsstatus01d5::SteerangledirType ret =  static_cast<Epsstatus01d5::SteerangledirType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'SteerAngleandspdvalidvalid', 1: 'SteerAngleandspdvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'steerangleandspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus01d5::SteerangleandspdvalidType Epsstatus01d5::steerangleandspdvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Epsstatus01d5::SteerangleandspdvalidType ret =  static_cast<Epsstatus01d5::SteerangleandspdvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 13, 'name': 'steerangle', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|800]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsstatus01d5::steerangle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'epsdmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsstatus01d5::epsdmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'epsdcrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsstatus01d5::epsdcrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
