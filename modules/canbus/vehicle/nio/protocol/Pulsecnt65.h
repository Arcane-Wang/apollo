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

  // config detail: {'bit': 63, 'enum': {0: 'WhlplscntRRvldvalid', 1: 'WhlplscntRRvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'WhlplscntRRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Pulsecnt65::WhlplscntrrvldType whlplscntrrvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'WhlplscntRR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'Int32'}
  Int32 whlplscntrr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'WhlplscntRLvldvalid', 1: 'WhlplscntRLvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'WhlplscntRLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Pulsecnt65::WhlplscntrlvldType whlplscntrlvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'WhlplscntRL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'Int32'}
  Int32 whlplscntrl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'WhlplscntFRvldvalid', 1: 'WhlplscntFRvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'WhlplscntFRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Pulsecnt65::WhlplscntfrvldType whlplscntfrvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'WhlplscntFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'Int32'}
  Int32 whlplscntfr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'WhlplscntFLvldvalid', 1: 'WhlplscntFLvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'WhlplscntFLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Pulsecnt65::WhlplscntflvldType whlplscntflvld(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WhlplscntFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'Int32'}
  Int32 whlplscntfl(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


