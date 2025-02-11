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
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_wr_crc(wr_crc(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_wr_msgcntr(wr_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrrsts(whlspdrrsts(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrrdir(whlspdrrdir(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrr(whlspdrr(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrlsts(whlspdrlsts(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrldir(whlspdrldir(bytes, length));
  chassis->mutable_nio()->mutable_whlspdrear_52()->set_whlspdrl(whlspdrl(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'wr_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Whlspdrear52::wr_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'wr_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Whlspdrear52::wr_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WHLSPDRRSTS_VALID', 1: 'WHLSPDRRSTS_INVALID', 2: 'WHLSPDRRSTS_INITIAL', 3: 'WHLSPDRRSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdrrsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdrear_52::WhlspdrrstsType Whlspdrear52::whlspdrrsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Whlspdrear_52::WhlspdrrstsType ret =  static_cast<Whlspdrear_52::WhlspdrrstsType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'WHLSPDRRDIR_STANDSTILL', 1: 'WHLSPDRRDIR_FORWARD', 2: 'WHLSPDRRDIR_BACKWARD', 3: 'WHLSPDRRDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdrrdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdrear_52::WhlspdrrdirType Whlspdrear52::whlspdrrdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  Whlspdrear_52::WhlspdrrdirType ret =  static_cast<Whlspdrear_52::WhlspdrrdirType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'whlspdrr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
double Whlspdrear52::whlspdrr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'WHLSPDRLSTS_VALID', 1: 'WHLSPDRLSTS_INVALID', 2: 'WHLSPDRLSTS_INITIAL', 3: 'WHLSPDRLSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdrlsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdrear_52::WhlspdrlstsType Whlspdrear52::whlspdrlsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Whlspdrear_52::WhlspdrlstsType ret =  static_cast<Whlspdrear_52::WhlspdrlstsType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'WHLSPDRLDIR_STANDSTILL', 1: 'WHLSPDRLDIR_FORWARD', 2: 'WHLSPDRLDIR_BACKWARD', 3: 'WHLSPDRLDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdrldir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdrear_52::WhlspdrldirType Whlspdrear52::whlspdrldir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  Whlspdrear_52::WhlspdrldirType ret =  static_cast<Whlspdrear_52::WhlspdrldirType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'whlspdrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
double Whlspdrear52::whlspdrl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
