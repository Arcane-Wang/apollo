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

class Vehiclelights2c7 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vehiclelights2c7();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 2, 'enum': {0: 'FOGFRNTLIGHTSTS_OFF', 1: 'FOGFRNTLIGHTSTS_ON', 2: 'FOGFRNTLIGHTSTS_RESERVED', 3: 'FOGFRNTLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'FogFrntlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::FogfrntlightstsType fogfrntlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'LEFTTURNLIGHTSTS_OFF', 1: 'LEFTTURNLIGHTSTS_ON', 2: 'LEFTTURNLIGHTSTS_RESERVED', 3: 'LEFTTURNLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'LeftTurnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::LeftturnlightstsType leftturnlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 13, 'enum': {0: 'RIGHTTURNLIGHTSTS_OFF', 1: 'RIGHTTURNLIGHTSTS_ON', 2: 'RIGHTTURNLIGHTSTS_RESERVED', 3: 'RIGHTTURNLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'RightTurnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::RightturnlightstsType rightturnlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'LOBEAMLIGHTSTS_OFF', 1: 'LOBEAMLIGHTSTS_ON', 2: 'LOBEAMLIGHTSTS_RESERVED', 3: 'LOBEAMLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'LobeamlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::LobeamlightstsType lobeamlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'HIBEAMLIGHTSTS_OFF', 1: 'HIBEAMLIGHTSTS_ON', 2: 'HIBEAMLIGHTSTS_RESERVED', 3: 'HIBEAMLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'HibeamlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::HibeamlightstsType hibeamlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'EMERGCYLIGHTSTS_OFF', 1: 'EMERGCYLIGHTSTS_1_25HZ', 2: 'EMERGCYLIGHTSTS_1HZ', 3: 'EMERGCYLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EmergcyLightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::EmergcylightstsType emergcylightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'FRNTWIPERSTS_OFF', 1: 'FRNTWIPERSTS_LOW_SPEED', 2: 'FRNTWIPERSTS_HIGH_SPEED', 3: 'FRNTWIPERSTS_RESERVED2', 4: 'FRNTWIPERSTS_RESERVED3', 5: 'FRNTWIPERSTS_RESERVED5', 6: 'FRNTWIPERSTS_RESERVED6', 7: 'FRNTWIPERSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntwiperSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights_2c7::FrntwiperstsType frntwipersts(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


