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

  // config detail: {'bit': 39, 'enum': {0: 'VCUNBSSTS_NBS_INITIAL', 1: 'VCUNBSSTS_NBS_STANDBY', 2: 'VCUNBSSTS_NBS_ACTIVE', 3: 'VCUNBSSTS_NBS_OVERRIDE', 4: 'VCUNBSSTS_NBS_INHIBIT', 5: 'VCUNBSSTS_OBSTACLE_DETECTED', 6: 'VCUNBSSTS_GEARSHIFT_ALLOWED', 7: 'VCUNBSSTS_RES'}, 'is_signed_var': False, 'len': 3, 'name': 'VCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::VCUNBSSTsType VCUNBSSTs(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'VCU_VLCSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   VCU_VLCSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 2, 'name': 'VCU_LLCSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   VCU_LLCSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'enum': {0: 'TAG_GEARVALID_VALID', 1: 'TAG_GEARVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Tag_Gearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::Tag_GearvalidType Tag_Gearvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 3, 'name': 'Tag_Gear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   Tag_Gear(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'enum': {0: 'ACTUAL_GEARVALID_VALID', 1: 'ACTUAL_GEARVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Actual_Gearvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::Actual_GearvalidType Actual_Gearvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'ACTUAL_GEAR_NONE', 1: 'ACTUAL_GEAR_D', 2: 'ACTUAL_GEAR_R', 3: 'ACTUAL_GEAR_N', 4: 'ACTUAL_GEAR_P'}, 'is_signed_var': False, 'len': 3, 'name': 'Actual_Gear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::Actual_GearType Actual_Gear(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'VCU_17_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   VCU_17_MsgCntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'VCU_17_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   VCU_17_CRC(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'VCU_EPFAIL_INIT', 1: 'VCU_EPFAIL_NORMAL', 2: 'VCU_EPFAIL_FAULT'}, 'is_signed_var': False, 'len': 2, 'name': 'VCU_EPFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::VCU_EPFailType VCU_EPFail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'VCUMODIND_AUTO', 1: 'VCUMODIND_ECONOMY', 2: 'VCUMODIND_COMFORT', 3: 'VCUMODIND_SPORT', 4: 'VCUMODIND_RESERVED4', 5: 'VCUMODIND_RESERVED5', 6: 'VCUMODIND_RESERVED6', 7: 'VCUMODIND_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'VCUmodind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::vcusts_01_218::VCUmodindType VCUmodind(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


