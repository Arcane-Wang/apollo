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

#include "modules/canbus/vehicle/nio/protocol/whlspdfront_51.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Whlspdfront51::Whlspdfront51() {}
const int32_t Whlspdfront51::ID = 0x51;

void Whlspdfront51::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasWhlspdfront51() ) {
           chassis->Builder().getNio().initWhlspdfront51();
        }
    }
  chassis->Builder().getNio().getwhlspdfront_51().setWF_MsgCntr(WF_MsgCntr(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWF_CRC(WF_CRC(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFRsts(WhlspdFRsts(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFRdir(WhlspdFRdir(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFR(WhlspdFR(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFLsts(WhlspdFLsts(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFLdir(WhlspdFLdir(bytes, length));
  chassis->Builder().getNio().getwhlspdfront_51().setWhlspdFL(WhlspdFL(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'WF_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Whlspdfront51::WF_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WF_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Whlspdfront51::WF_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WHLSPDFRSTS_VALID', 1: 'WHLSPDFRSTS_INVALID', 2: 'WHLSPDFRSTS_INITIAL', 3: 'WHLSPDFRSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdfront_51::WhlspdFRstsType Whlspdfront51::WhlspdFRsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::whlspdfront_51::WhlspdFRstsType ret =  static_cast<::atlas_messages::whlspdfront_51::WhlspdFRstsType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'WHLSPDFRDIR_STANDSTILL', 1: 'WHLSPDFRDIR_FORWARD', 2: 'WHLSPDFRDIR_BACKWARD', 3: 'WHLSPDFRDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdfront_51::WhlspdFRdirType Whlspdfront51::WhlspdFRdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::whlspdfront_51::WhlspdFRdirType ret =  static_cast<::atlas_messages::whlspdfront_51::WhlspdFRdirType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
 Whlspdfront51::WhlspdFR(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

   ret = x * 0.056250;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'WHLSPDFLSTS_VALID', 1: 'WHLSPDFLSTS_INVALID', 2: 'WHLSPDFLSTS_INITIAL', 3: 'WHLSPDFLSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdfront_51::WhlspdFLstsType Whlspdfront51::WhlspdFLsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::whlspdfront_51::WhlspdFLstsType ret =  static_cast<::atlas_messages::whlspdfront_51::WhlspdFLstsType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'WHLSPDFLDIR_STANDSTILL', 1: 'WHLSPDFLDIR_FORWARD', 2: 'WHLSPDFLDIR_BACKWARD', 3: 'WHLSPDFLDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdfront_51::WhlspdFLdirType Whlspdfront51::WhlspdFLdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::whlspdfront_51::WhlspdFLdirType ret =  static_cast<::atlas_messages::whlspdfront_51::WhlspdFLdirType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
 Whlspdfront51::WhlspdFL(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

   ret = x * 0.056250;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
