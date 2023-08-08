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

#include "modules/canbus/vehicle/nio/protocol/motorsts_01_8e.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Motorsts018e::Motorsts018e() {}
const int32_t Motorsts018e::ID = 0x8E;

void Motorsts018e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_motor01_msgcntr(motor01_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_motor01_crc(motor01_crc(bytes, length));
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_rearmottqvalid(rearmottqvalid(bytes, length));
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_rearmottq(rearmottq(bytes, length));
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_rearmotspdvalid(rearmotspdvalid(bytes, length));
  chassis->mutable_nio()->mutable_motorsts_01_8e()->set_rearmotspd(rearmotspd(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'motor01_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Motorsts018e::motor01_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'motor01_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Motorsts018e::motor01_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'REARMOTTQVALID_VALID', 1: 'REARMOTTQVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'rearmottqvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Motorsts_01_8e::RearmottqvalidType Motorsts018e::rearmottqvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  Motorsts_01_8e::RearmottqvalidType ret =  static_cast<Motorsts_01_8e::RearmottqvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': True, 'len': 15, 'name': 'rearmottq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-2048|2047.875]', 'physical_unit': 'Nm', 'precision': 0.125, 'type': 'double'}
double Motorsts018e::rearmottq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  x <<= 17;
  x >>= 17;

  double ret = x * 0.125000;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'REARMOTSPDVALID_VALID', 1: 'REARMOTSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'rearmotspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Motorsts_01_8e::RearmotspdvalidType Motorsts018e::rearmotspdvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Motorsts_01_8e::RearmotspdvalidType ret =  static_cast<Motorsts_01_8e::RearmotspdvalidType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': True, 'len': 16, 'name': 'rearmotspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32768|32767]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int'}
int Motorsts018e::rearmotspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  int ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
