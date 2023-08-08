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

#include "modules/canbus/vehicle/nio/protocol/vcusts_01_218.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Vcusts01218::Vcusts01218() {}
const int32_t Vcusts01218::ID = 0x218;

void Vcusts01218::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcunbssts(vcunbssts(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcu_vlcsts(vcu_vlcsts(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcu_llcsts(vcu_llcsts(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_tag_gearvalid(tag_gearvalid(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_tag_gear(tag_gear(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_actual_gearvalid(actual_gearvalid(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_actual_gear(actual_gear(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcu_17_msgcntr(vcu_17_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcu_17_crc(vcu_17_crc(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcu_epfail(vcu_epfail(bytes, length));
  chassis->mutable_nio()->mutable_vcusts_01_218()->set_vcumodind(vcumodind(bytes, length));
}

// config detail: {'bit': 39, 'enum': {0: 'VCUNBSSTS_NBS_INITIAL', 1: 'VCUNBSSTS_NBS_STANDBY', 2: 'VCUNBSSTS_NBS_ACTIVE', 3: 'VCUNBSSTS_NBS_OVERRIDE', 4: 'VCUNBSSTS_NBS_INHIBIT', 5: 'VCUNBSSTS_OBSTACLE_DETECTED', 6: 'VCUNBSSTS_GEARSHIFT_ALLOWED', 7: 'VCUNBSSTS_RES'}, 'is_signed_var': False, 'len': 3, 'name': 'vcunbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::VcunbsstsType Vcusts01218::vcunbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Vcusts_01_218::VcunbsstsType ret =  static_cast<Vcusts_01_218::VcunbsstsType>(x);
  return ret;
}

// config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'vcu_vlcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcusts01218::vcu_vlcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 2, 'name': 'vcu_llcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcusts01218::vcu_llcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'TAG_GEARVALID_VALID', 1: 'TAG_GEARVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'tag_gearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::Tag_gearvalidType Vcusts01218::tag_gearvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Vcusts_01_218::Tag_gearvalidType ret =  static_cast<Vcusts_01_218::Tag_gearvalidType>(x);
  return ret;
}

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 3, 'name': 'tag_gear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcusts01218::tag_gear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'ACTUAL_GEARVALID_VALID', 1: 'ACTUAL_GEARVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'actual_gearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::Actual_gearvalidType Vcusts01218::actual_gearvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Vcusts_01_218::Actual_gearvalidType ret =  static_cast<Vcusts_01_218::Actual_gearvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'ACTUAL_GEAR_NONE', 1: 'ACTUAL_GEAR_D', 2: 'ACTUAL_GEAR_R', 3: 'ACTUAL_GEAR_N', 4: 'ACTUAL_GEAR_P'}, 'is_signed_var': False, 'len': 3, 'name': 'actual_gear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::Actual_gearType Vcusts01218::actual_gear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  Vcusts_01_218::Actual_gearType ret =  static_cast<Vcusts_01_218::Actual_gearType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'vcu_17_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcusts01218::vcu_17_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'vcu_17_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcusts01218::vcu_17_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'VCU_EPFAIL_INIT', 1: 'VCU_EPFAIL_NORMAL', 2: 'VCU_EPFAIL_FAULT'}, 'is_signed_var': False, 'len': 2, 'name': 'vcu_epfail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::Vcu_epfailType Vcusts01218::vcu_epfail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Vcusts_01_218::Vcu_epfailType ret =  static_cast<Vcusts_01_218::Vcu_epfailType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'VCUMODIND_AUTO', 1: 'VCUMODIND_ECONOMY', 2: 'VCUMODIND_COMFORT', 3: 'VCUMODIND_SPORT', 4: 'VCUMODIND_RESERVED4', 5: 'VCUMODIND_RESERVED5', 6: 'VCUMODIND_RESERVED6', 7: 'VCUMODIND_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'vcumodind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts_01_218::VcumodindType Vcusts01218::vcumodind(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 3);

  Vcusts_01_218::VcumodindType ret =  static_cast<Vcusts_01_218::VcumodindType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
