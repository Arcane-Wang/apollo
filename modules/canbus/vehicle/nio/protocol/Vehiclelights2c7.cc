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

#include "modules/canbus/vehicle/nio/protocol/Vehiclelights2c7.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Vehiclelights2c7::Vehiclelights2c7() {}
const int32_t Vehiclelights2c7::ID = 0x2C7;

void Vehiclelights2c7::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_fogfrntlightsts(fogfrntlightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_leftturnlightsts(leftturnlightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_rightturnlightsts(rightturnlightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_lobeamlightsts(lobeamlightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_hibeamlightsts(hibeamlightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_emergcylightsts(emergcylightsts(bytes, length));
  chassis->mutable_nio()->mutable_Vehiclelights2c7()->set_frntwipersts(frntwipersts(bytes, length));
}

// config detail: {'bit': 2, 'enum': {0: 'FogFrntlightStsoff', 1: 'FogFrntlightStson', 2: 'FogFrntlightStsreserved', 3: 'FogFrntlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'fogfrntlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::FogfrntlightstsType Vehiclelights2c7::fogfrntlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 2);

  Vehiclelights2c7::FogfrntlightstsType ret =  static_cast<Vehiclelights2c7::FogfrntlightstsType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'LeftTurnlightstsoff', 1: 'LeftTurnlightstson', 2: 'LeftTurnlightstsreserved', 3: 'LeftTurnlightstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'leftturnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::LeftturnlightstsType Vehiclelights2c7::leftturnlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  Vehiclelights2c7::LeftturnlightstsType ret =  static_cast<Vehiclelights2c7::LeftturnlightstsType>(x);
  return ret;
}

// config detail: {'bit': 13, 'enum': {0: 'RightTurnlightstsoff', 1: 'RightTurnlightstson', 2: 'RightTurnlightstsreserved', 3: 'RightTurnlightstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'rightturnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::RightturnlightstsType Vehiclelights2c7::rightturnlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 2);

  Vehiclelights2c7::RightturnlightstsType ret =  static_cast<Vehiclelights2c7::RightturnlightstsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'LobeamlightStsoff', 1: 'LobeamlightStson', 2: 'LobeamlightStsreserved', 3: 'LobeamlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'lobeamlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::LobeamlightstsType Vehiclelights2c7::lobeamlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 2);

  Vehiclelights2c7::LobeamlightstsType ret =  static_cast<Vehiclelights2c7::LobeamlightstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'HibeamlightStsoff', 1: 'HibeamlightStson', 2: 'HibeamlightStsreserved', 3: 'HibeamlightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'hibeamlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::HibeamlightstsType Vehiclelights2c7::hibeamlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Vehiclelights2c7::HibeamlightstsType ret =  static_cast<Vehiclelights2c7::HibeamlightstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'EmergcyLightStsoff', 1: 'EmergcyLightSts125Hz', 2: 'EmergcyLightSts1Hz', 3: 'EmergcyLightStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'emergcylightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::EmergcylightstsType Vehiclelights2c7::emergcylightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Vehiclelights2c7::EmergcylightstsType ret =  static_cast<Vehiclelights2c7::EmergcylightstsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'FrntwiperStsoff', 1: 'FrntwiperStsLowSpeed', 2: 'FrntwiperStsHighSpeed', 3: 'FrntwiperStsreserved2', 4: 'FrntwiperStsreserved3', 5: 'FrntwiperStsreserved5', 6: 'FrntwiperStsreserved6', 7: 'FrntwiperStsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwipersts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights2c7::FrntwiperstsType Vehiclelights2c7::frntwipersts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 3);

  Vehiclelights2c7::FrntwiperstsType ret =  static_cast<Vehiclelights2c7::FrntwiperstsType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
