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

#include "modules/canbus/vehicle/nio/protocol/Whlspdfront51.h"

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
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_wfmsgcntr(wfmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_wfcrc(wfcrc(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdfrsts(whlspdfrsts(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdfrdir(whlspdfrdir(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdfr(whlspdfr(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdflsts(whlspdflsts(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdfldir(whlspdfldir(bytes, length));
  chassis->mutable_nio()->mutable_Whlspdfront51()->set_whlspdfl(whlspdfl(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'wfmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Whlspdfront51::wfmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'wfcrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Whlspdfront51::wfcrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'WhlspdFRstsvalid', 1: 'WhlspdFRstsinvalid', 2: 'WhlspdFRstsinitial', 3: 'WhlspdFRstsreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdfrsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdfront51::WhlspdfrstsType Whlspdfront51::whlspdfrsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Whlspdfront51::WhlspdfrstsType ret =  static_cast<Whlspdfront51::WhlspdfrstsType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'WhlspdFRdirstandstill', 1: 'WhlspdFRdirforward', 2: 'WhlspdFRdirbackward', 3: 'WhlspdFRdirinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdfrdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdfront51::WhlspdfrdirType Whlspdfront51::whlspdfrdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  Whlspdfront51::WhlspdfrdirType ret =  static_cast<Whlspdfront51::WhlspdfrdirType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'whlspdfr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'Float64'}
Float64 Whlspdfront51::whlspdfr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  Float64 ret = x * 0.056250;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'WhlspdFLstsvalid', 1: 'WhlspdFLstsinvalid', 2: 'WhlspdFLstsinitial', 3: 'WhlspdFLstsreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdflsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdfront51::WhlspdflstsType Whlspdfront51::whlspdflsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Whlspdfront51::WhlspdflstsType ret =  static_cast<Whlspdfront51::WhlspdflstsType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'WhlspdFLdirstandstill', 1: 'WhlspdFLdirforward', 2: 'WhlspdFLdirbackward', 3: 'WhlspdFLdirinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'whlspdfldir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Whlspdfront51::WhlspdfldirType Whlspdfront51::whlspdfldir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  Whlspdfront51::WhlspdfldirType ret =  static_cast<Whlspdfront51::WhlspdfldirType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'whlspdfl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'Float64'}
Float64 Whlspdfront51::whlspdfl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  Float64 ret = x * 0.056250;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
