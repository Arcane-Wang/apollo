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

class Whlspdfront51 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Whlspdfront51();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'WF_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   WF_MsgCntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WF_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   WF_CRC(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'WHLSPDFRSTS_VALID', 1: 'WHLSPDFRSTS_INVALID', 2: 'WHLSPDFRSTS_INITIAL', 3: 'WHLSPDFRSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::whlspdfront_51::WhlspdFRstsType WhlspdFRsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'enum': {0: 'WHLSPDFRDIR_STANDSTILL', 1: 'WHLSPDFRDIR_FORWARD', 2: 'WHLSPDFRDIR_BACKWARD', 3: 'WHLSPDFRDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::whlspdfront_51::WhlspdFRdirType WhlspdFRdir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
   WhlspdFR(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'WHLSPDFLSTS_VALID', 1: 'WHLSPDFLSTS_INVALID', 2: 'WHLSPDFLSTS_INITIAL', 3: 'WHLSPDFLSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::whlspdfront_51::WhlspdFLstsType WhlspdFLsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'WHLSPDFLDIR_STANDSTILL', 1: 'WHLSPDFLDIR_FORWARD', 2: 'WHLSPDFLDIR_BACKWARD', 3: 'WHLSPDFLDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::whlspdfront_51::WhlspdFLdirType WhlspdFLdir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
   WhlspdFL(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


