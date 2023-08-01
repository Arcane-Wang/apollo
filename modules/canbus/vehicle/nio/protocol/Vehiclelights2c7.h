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

  // config detail: {'bit': 2, 'enum': {0: 'FogFrntlightStsoff', 1: 'FogFrntlightStson', 2: 'FogFrntlightStsreserved', 3: 'FogFrntlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'FogFrntlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::FogfrntlightstsType fogfrntlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'LeftTurnlightstsoff', 1: 'LeftTurnlightstson', 2: 'LeftTurnlightstsreserved', 3: 'LeftTurnlightstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'LeftTurnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::LeftturnlightstsType leftturnlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 13, 'enum': {0: 'RightTurnlightstsoff', 1: 'RightTurnlightstson', 2: 'RightTurnlightstsreserved', 3: 'RightTurnlightstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'RightTurnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::RightturnlightstsType rightturnlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'LobeamlightStsoff', 1: 'LobeamlightStson', 2: 'LobeamlightStsreserved', 3: 'LobeamlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'LobeamlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::LobeamlightstsType lobeamlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'HibeamlightStsoff', 1: 'HibeamlightStson', 2: 'HibeamlightStsreserved', 3: 'HibeamlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'HibeamlightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::HibeamlightstsType hibeamlightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'EmergcyLightStsoff', 1: 'EmergcyLightSts125Hz', 2: 'EmergcyLightSts1Hz', 3: 'EmergcyLightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'EmergcyLightSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::EmergcylightstsType emergcylightsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'FrntwiperStsoff', 1: 'FrntwiperStsLowSpeed', 2: 'FrntwiperStsHighSpeed', 3: 'FrntwiperStsreserved2', 4: 'FrntwiperStsreserved3', 5: 'FrntwiperStsreserved5', 6: 'FrntwiperStsreserved6', 7: 'FrntwiperStsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntwiperSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclelights2c7::FrntwiperstsType frntwipersts(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


