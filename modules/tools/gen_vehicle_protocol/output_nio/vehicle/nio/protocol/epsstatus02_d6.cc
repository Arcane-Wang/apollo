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

#include "modules/canbus/vehicle/nio/protocol/epsstatus02_d6.h"

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
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_tqreqavl(eps_tqreqavl(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_pinionangreqavl(eps_pinionangreqavl(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_estrackforce(eps_estrackforce(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_handsoffdetnconfidence(eps_handsoffdetnconfidence(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_02_msgcntr(eps_02_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_pinionagvalid(eps_pinionagvalid(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_drvoverridedetn(eps_drvoverridedetn(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_02_crc(eps_02_crc(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_motortq(eps_motortq(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_motortqvalid(eps_motortqvalid(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_pinionag(eps_pinionag(bytes, length));
  chassis->mutable_nio()->mutable_epsstatus02_d6()->set_eps_estrackforcevalid(eps_estrackforcevalid(bytes, length));
}

// config detail: {'bit': 61, 'enum': {0: 'EPS_TQREQAVL_NOT_AVAILABLE', 1: 'EPS_TQREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'eps_tqreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_tqreqavlType Epsstatus02d6::eps_tqreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(5, 1);

  Epsstatus02_d6::Eps_tqreqavlType ret =  static_cast<Epsstatus02_d6::Eps_tqreqavlType>(x);
  return ret;
}

// config detail: {'bit': 60, 'enum': {0: 'EPS_PINIONANGREQAVL_NOT_AVAILABLE', 1: 'EPS_PINIONANGREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'eps_pinionangreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_pinionangreqavlType Epsstatus02d6::eps_pinionangreqavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 1);

  Epsstatus02_d6::Eps_pinionangreqavlType ret =  static_cast<Epsstatus02_d6::Eps_pinionangreqavlType>(x);
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 10, 'name': 'eps_estrackforce', 'offset': -20.48, 'order': 'motorola', 'physical_range': '[-20.48|20.44]', 'physical_unit': 'KN', 'precision': 0.04, 'type': 'double'}
double Epsstatus02d6::eps_estrackforce(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 0.040000 + -20.480000;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_ON', 1: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL1', 2: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL2', 3: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL3', 4: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL4', 5: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL5', 6: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL6', 7: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL7', 8: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL8', 9: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL9', 10: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL10', 11: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL11', 12: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL12', 13: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL13', 14: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL14', 15: 'EPS_HANDSOFFDETNCONFIDENCE_SIGNAL_NOT_AVALIBLE'}, 'is_signed_var': False, 'len': 4, 'name': 'eps_handsoffdetnconfidence', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_handsoffdetnconfidenceType Epsstatus02d6::eps_handsoffdetnconfidence(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 4);

  Epsstatus02_d6::Eps_handsoffdetnconfidenceType ret =  static_cast<Epsstatus02_d6::Eps_handsoffdetnconfidenceType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'eps_02_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsstatus02d6::eps_02_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'EPS_PINIONAGVALID_VALID', 1: 'EPS_PINIONAGVALID_INVALID', 2: 'EPS_PINIONAGVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_PINIONAGVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'eps_pinionagvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_pinionagvalidType Epsstatus02d6::eps_pinionagvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  Epsstatus02_d6::Eps_pinionagvalidType ret =  static_cast<Epsstatus02_d6::Eps_pinionagvalidType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'EPS_DRVOVERRIDEDETN_OVERRIDE_DETECTED', 1: 'EPS_DRVOVERRIDEDETN_OVERRIDE_NOT_DETECTED', 2: 'EPS_DRVOVERRIDEDETN_SIGNAL_NOT_AVAILABLE', 3: 'EPS_DRVOVERRIDEDETN_NO_ACTIVE_ADC_REQUEST'}, 'is_signed_var': False, 'len': 2, 'name': 'eps_drvoverridedetn', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_drvoverridedetnType Epsstatus02d6::eps_drvoverridedetn(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  Epsstatus02_d6::Eps_drvoverridedetnType ret =  static_cast<Epsstatus02_d6::Eps_drvoverridedetnType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'eps_02_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsstatus02d6::eps_02_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'eps_motortq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
double Epsstatus02d6::eps_motortq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 0.020000 + -10.240000;
  return ret;
}

// config detail: {'bit': 59, 'enum': {0: 'EPS_MOTORTQVALID_VALID', 1: 'EPS_MOTORTQVALID_INVALID', 2: 'EPS_MOTORTQVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_MOTORTQVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'eps_motortqvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_motortqvalidType Epsstatus02d6::eps_motortqvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 2);

  Epsstatus02_d6::Eps_motortqvalidType ret =  static_cast<Epsstatus02_d6::Eps_motortqvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 15, 'name': 'eps_pinionag', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.2]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsstatus02d6::eps_pinionag(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  double ret = x * 0.100000 + -1638.400000;
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'EPS_ESTRACKFORCEVALID_VALID', 1: 'EPS_ESTRACKFORCEVALID_INVALID', 2: 'EPS_ESTRACKFORCEVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_ESTRACKFORCEVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'eps_estrackforcevalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsstatus02_d6::Eps_estrackforcevalidType Epsstatus02d6::eps_estrackforcevalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Epsstatus02_d6::Eps_estrackforcevalidType ret =  static_cast<Epsstatus02_d6::Eps_estrackforcevalidType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
