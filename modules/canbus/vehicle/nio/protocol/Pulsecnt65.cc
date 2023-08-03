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

#include "modules/canbus/vehicle/nio/protocol/Pulsecnt65.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Pulsecnt65::Pulsecnt65() {}
const int32_t Pulsecnt65::ID = 0x65;

void Pulsecnt65::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntrrvld(whlplscntrrvld(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntrr(whlplscntrr(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntrlvld(whlplscntrlvld(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntrl(whlplscntrl(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntfrvld(whlplscntfrvld(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntfr(whlplscntfr(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntflvld(whlplscntflvld(bytes, length));
  chassis->mutable_nio()->mutable_Pulsecnt65()->set_whlplscntfl(whlplscntfl(bytes, length));
}

// config detail: {'bit': 63, 'enum': {0: 'WhlplscntRRvldvalid', 1: 'WhlplscntRRvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntrrvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Pulsecnt65::WhlplscntrrvldType Pulsecnt65::whlplscntrrvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(7, 1);

  Pulsecnt65::WhlplscntrrvldType ret =  static_cast<Pulsecnt65::WhlplscntrrvldType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntrr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int32_t'}
int32_t Pulsecnt65::whlplscntrr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WhlplscntRLvldvalid', 1: 'WhlplscntRLvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntrlvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Pulsecnt65::WhlplscntrlvldType Pulsecnt65::whlplscntrlvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  Pulsecnt65::WhlplscntrlvldType ret =  static_cast<Pulsecnt65::WhlplscntrlvldType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int32_t'}
int32_t Pulsecnt65::whlplscntrl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'WhlplscntFRvldvalid', 1: 'WhlplscntFRvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntfrvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Pulsecnt65::WhlplscntfrvldType Pulsecnt65::whlplscntfrvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  Pulsecnt65::WhlplscntfrvldType ret =  static_cast<Pulsecnt65::WhlplscntfrvldType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntfr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int32_t'}
int32_t Pulsecnt65::whlplscntfr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'WhlplscntFLvldvalid', 1: 'WhlplscntFLvldinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntflvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Pulsecnt65::WhlplscntflvldType Pulsecnt65::whlplscntflvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  Pulsecnt65::WhlplscntflvldType ret =  static_cast<Pulsecnt65::WhlplscntflvldType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntfl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int32_t'}
int32_t Pulsecnt65::whlplscntfl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
