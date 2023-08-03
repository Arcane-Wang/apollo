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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace nio {

class Vcusts01218 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcusts01218();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 39, 'enum': {0: 'VCUNBSSTsNBSInitial', 1: 'VCUNBSSTsNBSStandby', 2: 'VCUNBSSTsNBSActive', 3: 'VCUNBSSTsNBSOverride', 4: 'VCUNBSSTsNBSInhibit', 5: 'VCUNBSSTsObstacleDetected', 6: 'VCUNBSSTsGearshiftAllowed', 7: 'VCUNBSSTsRes'}, 'is_signed_var': False, 'len': 3, 'name': 'VCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::VcunbsstsType vcunbssts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'VcuVlcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t vcuvlcsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 2, 'name': 'VcuLlcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t vcullcsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'enum': {0: 'TagGearvalidvalid', 1: 'TagGearvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'TagGearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::TaggearvalidType taggearvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 3, 'name': 'TagGear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t taggear(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'enum': {0: 'ActualGearvalidvalid', 1: 'ActualGearvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'ActualGearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::ActualgearvalidType actualgearvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'ActualGearnone', 1: 'ActualGearD', 2: 'ActualGearR', 3: 'ActualGearN', 4: 'ActualGearP'}, 'is_signed_var': False, 'len': 3, 'name': 'ActualGear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::ActualgearType actualgear(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Vcu17Msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t vcu17msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Vcu17Crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t vcu17crc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'VcuEpfailInit', 1: 'VcuEpfailNormal', 2: 'VcuEpfailFault'}, 'is_signed_var': False, 'len': 2, 'name': 'VcuEpfail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::VcuepfailType vcuepfail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'VCUmodindAuto', 1: 'VCUmodindEconomy', 2: 'VCUmodindComfort', 3: 'VCUmodindSport', 4: 'VCUmodindReserved4', 5: 'VCUmodindReserved5', 6: 'VCUmodindReserved6', 7: 'VCUmodindInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'VCUmodind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vcusts01218::VcumodindType vcumodind(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


