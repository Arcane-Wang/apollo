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

class Pulsecnt65 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Pulsecnt65();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 63, 'enum': {0: 'WHLPLSCNTRRVLD_VALID', 1: 'WHLPLSCNTRRVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntRRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::pulsecnt_65::whlplscntRRvldType whlplscntRRvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntRR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
   whlplscntRR(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'WHLPLSCNTRLVLD_VALID', 1: 'WHLPLSCNTRLVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntRLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::pulsecnt_65::whlplscntRLvldType whlplscntRLvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntRL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
   whlplscntRL(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'WHLPLSCNTFRVLD_VALID', 1: 'WHLPLSCNTFRVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntFRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::pulsecnt_65::whlplscntFRvldType whlplscntFRvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
   whlplscntFR(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'WHLPLSCNTFLVLD_VALID', 1: 'WHLPLSCNTFLVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntFLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::pulsecnt_65::whlplscntFLvldType whlplscntFLvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
   whlplscntFL(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


