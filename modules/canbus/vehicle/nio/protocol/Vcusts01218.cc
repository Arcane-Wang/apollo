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

#include "modules/canbus/vehicle/nio/protocol/Vcusts01218.h"

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
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcunbssts(vcunbssts(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcuvlcsts(vcuvlcsts(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcullcsts(vcullcsts(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_taggearvalid(taggearvalid(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_taggear(taggear(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_actualgearvalid(actualgearvalid(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_actualgear(actualgear(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcu17msgcntr(vcu17msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcu17crc(vcu17crc(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcuepfail(vcuepfail(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts01218()->set_vcumodind(vcumodind(bytes, length));
}

// config detail: {'bit': 39, 'enum': {0: 'VCUNBSSTsNBSInitial', 1: 'VCUNBSSTsNBSStandby', 2: 'VCUNBSSTsNBSActive', 3: 'VCUNBSSTsNBSOverride', 4: 'VCUNBSSTsNBSInhibit', 5: 'VCUNBSSTsObstacleDetected', 6: 'VCUNBSSTsGearshiftAllowed', 7: 'VCUNBSSTsRes'}, 'is_signed_var': False, 'len': 3, 'name': 'vcunbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::VcunbsstsType Vcusts01218::vcunbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Vcusts01218::VcunbsstsType ret =  static_cast<Vcusts01218::VcunbsstsType>(x);
  return ret;
}

// config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'vcuvlcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts01218::vcuvlcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 2, 'name': 'vcullcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts01218::vcullcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'TagGearvalidvalid', 1: 'TagGearvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'taggearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::TaggearvalidType Vcusts01218::taggearvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Vcusts01218::TaggearvalidType ret =  static_cast<Vcusts01218::TaggearvalidType>(x);
  return ret;
}

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 3, 'name': 'taggear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts01218::taggear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'ActualGearvalidvalid', 1: 'ActualGearvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'actualgearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::ActualgearvalidType Vcusts01218::actualgearvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Vcusts01218::ActualgearvalidType ret =  static_cast<Vcusts01218::ActualgearvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'ActualGearnone', 1: 'ActualGearD', 2: 'ActualGearR', 3: 'ActualGearN', 4: 'ActualGearP'}, 'is_signed_var': False, 'len': 3, 'name': 'actualgear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::ActualgearType Vcusts01218::actualgear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  Vcusts01218::ActualgearType ret =  static_cast<Vcusts01218::ActualgearType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'vcu17msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts01218::vcu17msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'vcu17crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts01218::vcu17crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'VcuEpfailInit', 1: 'VcuEpfailNormal', 2: 'VcuEpfailFault'}, 'is_signed_var': False, 'len': 2, 'name': 'vcuepfail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::VcuepfailType Vcusts01218::vcuepfail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Vcusts01218::VcuepfailType ret =  static_cast<Vcusts01218::VcuepfailType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'VCUmodindAuto', 1: 'VCUmodindEconomy', 2: 'VCUmodindComfort', 3: 'VCUmodindSport', 4: 'VCUmodindReserved4', 5: 'VCUmodindReserved5', 6: 'VCUmodindReserved6', 7: 'VCUmodindInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'vcumodind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts01218::VcumodindType Vcusts01218::vcumodind(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 3);

  Vcusts01218::VcumodindType ret =  static_cast<Vcusts01218::VcumodindType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
