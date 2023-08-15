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

#include "modules/canbus/vehicle/nio/protocol/whlspdrear_52.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Whlspdrear52::Whlspdrear52() {}
const int32_t Whlspdrear52::ID = 0x52;

void Whlspdrear52::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasWhlspdrear52() ) {
           chassis->Builder().getNio().initWhlspdrear52();
        }
    }
  chassis->Builder().getNio().getwhlspdrear_52().setWR_CRC(WR_CRC(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWR_MsgCntr(WR_MsgCntr(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRRsts(WhlspdRRsts(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRRdir(WhlspdRRdir(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRR(WhlspdRR(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRLsts(WhlspdRLsts(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRLdir(WhlspdRLdir(bytes, length));
  chassis->Builder().getNio().getwhlspdrear_52().setWhlspdRL(WhlspdRL(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WR_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Whlspdrear52::WR_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'WR_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Whlspdrear52::WR_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WHLSPDRRSTS_VALID', 1: 'WHLSPDRRSTS_INVALID', 2: 'WHLSPDRRSTS_INITIAL', 3: 'WHLSPDRRSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRRsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdrear_52::WhlspdRRstsType Whlspdrear52::WhlspdRRsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::whlspdrear_52::WhlspdRRstsType ret =  static_cast<::atlas_messages::whlspdrear_52::WhlspdRRstsType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'WHLSPDRRDIR_STANDSTILL', 1: 'WHLSPDRRDIR_FORWARD', 2: 'WHLSPDRRDIR_BACKWARD', 3: 'WHLSPDRRDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRRdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdrear_52::WhlspdRRdirType Whlspdrear52::WhlspdRRdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::whlspdrear_52::WhlspdRRdirType ret =  static_cast<::atlas_messages::whlspdrear_52::WhlspdRRdirType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdRR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
 Whlspdrear52::WhlspdRR(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

   ret = x * 0.056250;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'WHLSPDRLSTS_VALID', 1: 'WHLSPDRLSTS_INVALID', 2: 'WHLSPDRLSTS_INITIAL', 3: 'WHLSPDRLSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRLsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdrear_52::WhlspdRLstsType Whlspdrear52::WhlspdRLsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::whlspdrear_52::WhlspdRLstsType ret =  static_cast<::atlas_messages::whlspdrear_52::WhlspdRLstsType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'WHLSPDRLDIR_STANDSTILL', 1: 'WHLSPDRLDIR_FORWARD', 2: 'WHLSPDRLDIR_BACKWARD', 3: 'WHLSPDRLDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRLdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::whlspdrear_52::WhlspdRLdirType Whlspdrear52::WhlspdRLdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::whlspdrear_52::WhlspdRLdirType ret =  static_cast<::atlas_messages::whlspdrear_52::WhlspdRLdirType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdRL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
 Whlspdrear52::WhlspdRL(const std::uint8_t* bytes, int32_t length) const {
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
