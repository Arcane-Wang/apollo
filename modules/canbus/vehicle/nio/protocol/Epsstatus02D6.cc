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

#include "modules/canbus/vehicle/nio/protocol/Epsstatus02D6.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Epsstatus02d6::Epsstatus02d6() {}
const int32_t Epsstatus02d6::ID = 0xD6;

void Epsstatus02d6::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epstqreqavl(epstqreqavl(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epspinionangreqavl(epspinionangreqavl(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epsestrackforce(epsestrackforce(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epshandsoffdetnconfidence(epshandsoffdetnconfidence(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_eps02msgcntr(eps02msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epspinionagvalid(epspinionagvalid(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epsdrvoverridedetn(epsdrvoverridedetn(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_eps02crc(eps02crc(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epsmotortq(epsmotortq(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epsmotortqvalid(epsmotortqvalid(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epspinionag(epspinionag(bytes, length));
  chassis->mutable_nio()->mutable_Epsstatus02D6()->set_epsestrackforcevalid(epsestrackforcevalid(bytes, length));
}

// config detail: {'bit': 61, 'enum': {0: 'EpsTqreqavlNotAvailable', 1: 'EpsTqreqavlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'epstqreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpstqreqavlType Epsstatus02d6::epstqreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(5, 1);

  Epsstatus02d6::EpstqreqavlType ret =  static_cast<Epsstatus02d6::EpstqreqavlType>(x);
  return ret;
}

// config detail: {'bit': 60, 'enum': {0: 'EpsPinionangreqavlNotAvailable', 1: 'EpsPinionangreqavlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'epspinionangreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpspinionangreqavlType Epsstatus02d6::epspinionangreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 1);

  Epsstatus02d6::EpspinionangreqavlType ret =  static_cast<Epsstatus02d6::EpspinionangreqavlType>(x);
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 10, 'name': 'epsestrackforce', 'offset': -20.48, 'order': 'motorola', 'physical_range': '[-20.48|20.44]', 'physical_unit': 'KN', 'precision': 0.04, 'type': 'double'}
double Epsstatus02d6::epsestrackforce(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 0.040000 + -20.480000;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'EpsHandsoffdetnconfidenceHandsOn', 1: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel1', 2: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel2', 3: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel3', 4: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel4', 5: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel5', 6: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel6', 7: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel7', 8: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel8', 9: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel9', 10: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel10', 11: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel11', 12: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel12', 13: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel13', 14: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel14', 15: 'EpsHandsoffdetnconfidenceSignalNotAvalible'}, 'is_signed_var': False, 'len': 4, 'name': 'epshandsoffdetnconfidence', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpshandsoffdetnconfidenceType Epsstatus02d6::epshandsoffdetnconfidence(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 4);

  Epsstatus02d6::EpshandsoffdetnconfidenceType ret =  static_cast<Epsstatus02d6::EpshandsoffdetnconfidenceType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'eps02msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsstatus02d6::eps02msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'EpsPinionagvalidValid', 1: 'EpsPinionagvalidInvalid', 2: 'EpsPinionagvalidSignalNotAvailable', 3: 'EpsPinionagvalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'epspinionagvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpspinionagvalidType Epsstatus02d6::epspinionagvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  Epsstatus02d6::EpspinionagvalidType ret =  static_cast<Epsstatus02d6::EpspinionagvalidType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'EpsDrvoverridedetnOverrideDetected', 1: 'EpsDrvoverridedetnOverrideNotDetected', 2: 'EpsDrvoverridedetnSignalNotAvailable', 3: 'EpsDrvoverridedetnNoActiveADCRequest'}, 'is_signed_var': False, 'len': 2, 'name': 'epsdrvoverridedetn', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpsdrvoverridedetnType Epsstatus02d6::epsdrvoverridedetn(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  Epsstatus02d6::EpsdrvoverridedetnType ret =  static_cast<Epsstatus02d6::EpsdrvoverridedetnType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'eps02crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsstatus02d6::eps02crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'epsmotortq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
double Epsstatus02d6::epsmotortq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 0.020000 + -10.240000;
  return ret;
}

// config detail: {'bit': 59, 'enum': {0: 'EpsMotortqvalidValid', 1: 'EpsMotortqvalidInvalid', 2: 'EpsMotortqvalidSignalNotAvailable', 3: 'EpsMotortqvalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'epsmotortqvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpsmotortqvalidType Epsstatus02d6::epsmotortqvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 2);

  Epsstatus02d6::EpsmotortqvalidType ret =  static_cast<Epsstatus02d6::EpsmotortqvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 15, 'name': 'epspinionag', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.2]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsstatus02d6::epspinionag(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  double ret = x * 0.100000 + -1638.400000;
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'EpsEstrackforcevalidValid', 1: 'EpsEstrackforcevalidInvalid', 2: 'EpsEstrackforcevalidSignalNotAvailable', 3: 'EpsEstrackforcevalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'epsestrackforcevalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02d6::EpsestrackforcevalidType Epsstatus02d6::epsestrackforcevalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Epsstatus02d6::EpsestrackforcevalidType ret =  static_cast<Epsstatus02d6::EpsestrackforcevalidType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
