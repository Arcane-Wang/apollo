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

#include "modules/canbus/vehicle/nio/protocol/pulsecnt_65.h"

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
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasPulsecnt65() ) {
           chassis->Builder().getNio().initPulsecnt65();
        }
    }
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntRRvld(whlplscntRRvld(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntRR(whlplscntRR(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntRLvld(whlplscntRLvld(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntRL(whlplscntRL(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntFRvld(whlplscntFRvld(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntFR(whlplscntFR(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntFLvld(whlplscntFLvld(bytes, length));
  chassis->Builder().getNio().getpulsecnt_65().setwhlplscntFL(whlplscntFL(bytes, length));
}

// config detail: {'bit': 63, 'enum': {0: 'WHLPLSCNTRRVLD_VALID', 1: 'WHLPLSCNTRRVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntRRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::pulsecnt_65::whlplscntRRvldType Pulsecnt65::whlplscntRRvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::pulsecnt_65::whlplscntRRvldType ret =  static_cast<::atlas_messages::pulsecnt_65::whlplscntRRvldType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntRR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
 Pulsecnt65::whlplscntRR(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WHLPLSCNTRLVLD_VALID', 1: 'WHLPLSCNTRLVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntRLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::pulsecnt_65::whlplscntRLvldType Pulsecnt65::whlplscntRLvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::pulsecnt_65::whlplscntRLvldType ret =  static_cast<::atlas_messages::pulsecnt_65::whlplscntRLvldType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntRL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
 Pulsecnt65::whlplscntRL(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'WHLPLSCNTFRVLD_VALID', 1: 'WHLPLSCNTFRVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntFRvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::pulsecnt_65::whlplscntFRvldType Pulsecnt65::whlplscntFRvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::pulsecnt_65::whlplscntFRvldType ret =  static_cast<::atlas_messages::pulsecnt_65::whlplscntFRvldType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
 Pulsecnt65::whlplscntFR(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'WHLPLSCNTFLVLD_VALID', 1: 'WHLPLSCNTFLVLD_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'whlplscntFLvld', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::pulsecnt_65::whlplscntFLvldType Pulsecnt65::whlplscntFLvld(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::pulsecnt_65::whlplscntFLvldType ret =  static_cast<::atlas_messages::pulsecnt_65::whlplscntFLvldType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'whlplscntFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|254]', 'physical_unit': 'pulse', 'precision': 1.0, 'type': 'int'}
 Pulsecnt65::whlplscntFL(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
