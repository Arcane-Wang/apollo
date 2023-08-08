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

#include "modules/canbus/vehicle/nio/protocol/vehiclelights_2c7.h"

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
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_fogfrntlightsts(fogfrntlightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_leftturnlightsts(leftturnlightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_rightturnlightsts(rightturnlightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_lobeamlightsts(lobeamlightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_hibeamlightsts(hibeamlightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_emergcylightsts(emergcylightsts(bytes, length));
  chassis->mutable_nio()->mutable_vehiclelights_2c7()->set_frntwipersts(frntwipersts(bytes, length));
}

// config detail: {'bit': 2, 'enum': {0: 'FOGFRNTLIGHTSTS_OFF', 1: 'FOGFRNTLIGHTSTS_ON', 2: 'FOGFRNTLIGHTSTS_RESERVED', 3: 'FOGFRNTLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'fogfrntlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::FogfrntlightstsType Vehiclelights2c7::fogfrntlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 2);

  Vehiclelights_2c7::FogfrntlightstsType ret =  static_cast<Vehiclelights_2c7::FogfrntlightstsType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'LEFTTURNLIGHTSTS_OFF', 1: 'LEFTTURNLIGHTSTS_ON', 2: 'LEFTTURNLIGHTSTS_RESERVED', 3: 'LEFTTURNLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'leftturnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::LeftturnlightstsType Vehiclelights2c7::leftturnlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  Vehiclelights_2c7::LeftturnlightstsType ret =  static_cast<Vehiclelights_2c7::LeftturnlightstsType>(x);
  return ret;
}

// config detail: {'bit': 13, 'enum': {0: 'RIGHTTURNLIGHTSTS_OFF', 1: 'RIGHTTURNLIGHTSTS_ON', 2: 'RIGHTTURNLIGHTSTS_RESERVED', 3: 'RIGHTTURNLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'rightturnlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::RightturnlightstsType Vehiclelights2c7::rightturnlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 2);

  Vehiclelights_2c7::RightturnlightstsType ret =  static_cast<Vehiclelights_2c7::RightturnlightstsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'LOBEAMLIGHTSTS_OFF', 1: 'LOBEAMLIGHTSTS_ON', 2: 'LOBEAMLIGHTSTS_RESERVED', 3: 'LOBEAMLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'lobeamlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::LobeamlightstsType Vehiclelights2c7::lobeamlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 2);

  Vehiclelights_2c7::LobeamlightstsType ret =  static_cast<Vehiclelights_2c7::LobeamlightstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'HIBEAMLIGHTSTS_OFF', 1: 'HIBEAMLIGHTSTS_ON', 2: 'HIBEAMLIGHTSTS_RESERVED', 3: 'HIBEAMLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'hibeamlightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::HibeamlightstsType Vehiclelights2c7::hibeamlightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Vehiclelights_2c7::HibeamlightstsType ret =  static_cast<Vehiclelights_2c7::HibeamlightstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'EMERGCYLIGHTSTS_OFF', 1: 'EMERGCYLIGHTSTS_1_25HZ', 2: 'EMERGCYLIGHTSTS_1HZ', 3: 'EMERGCYLIGHTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'emergcylightsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::EmergcylightstsType Vehiclelights2c7::emergcylightsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Vehiclelights_2c7::EmergcylightstsType ret =  static_cast<Vehiclelights_2c7::EmergcylightstsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'FRNTWIPERSTS_OFF', 1: 'FRNTWIPERSTS_LOW_SPEED', 2: 'FRNTWIPERSTS_HIGH_SPEED', 3: 'FRNTWIPERSTS_RESERVED2', 4: 'FRNTWIPERSTS_RESERVED3', 5: 'FRNTWIPERSTS_RESERVED5', 6: 'FRNTWIPERSTS_RESERVED6', 7: 'FRNTWIPERSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwipersts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vehiclelights_2c7::FrntwiperstsType Vehiclelights2c7::frntwipersts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 3);

  Vehiclelights_2c7::FrntwiperstsType ret =  static_cast<Vehiclelights_2c7::FrntwiperstsType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
