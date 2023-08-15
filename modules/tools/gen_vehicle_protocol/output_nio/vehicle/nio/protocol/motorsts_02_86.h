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

class Motorsts0286 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Motorsts0286();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Motor02_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   Motor02_MsgCntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Motor02_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   Motor02_CRC(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'FRNTMOTTQVALID_VALID', 1: 'FRNTMOTTQVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'FrntMotTqValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::motorsts_02_86::FrntMotTqValidType FrntMotTqValid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': True, 'len': 15, 'name': 'FrntMotTq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-2048|2047.875]', 'physical_unit': 'Nm', 'precision': 0.125, 'type': 'double'}
   FrntMotTq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'FRNTMOTSPDVALID_VALID', 1: 'FRNTMOTSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'FrntMotSpdValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::motorsts_02_86::FrntMotSpdValidType FrntMotSpdValid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': True, 'len': 16, 'name': 'FrntMotSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32768|32767]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int'}
   FrntMotSpd(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


