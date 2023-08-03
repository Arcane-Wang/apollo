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

#include "modules/canbus/vehicle/nio/protocol/Motorsts0286.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Motorsts0286::Motorsts0286() {}
const int32_t Motorsts0286::ID = 0x86;

void Motorsts0286::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Motorsts0286()->set_motor02msgcntr(motor02msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Motorsts0286()->set_motor02crc(motor02crc(bytes, length));
  chassis->mutable_nio()->mutable_Motorsts0286()->set_frntmottqvalid(frntmottqvalid(bytes, length));
  chassis->mutable_nio()->mutable_Motorsts0286()->set_frntmottq(frntmottq(bytes, length));
  chassis->mutable_nio()->mutable_Motorsts0286()->set_frntmotspdvalid(frntmotspdvalid(bytes, length));
  chassis->mutable_nio()->mutable_Motorsts0286()->set_frntmotspd(frntmotspd(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'motor02msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Motorsts0286::motor02msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'motor02crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Motorsts0286::motor02crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'FrntMotTqValidvalid', 1: 'FrntMotTqValidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'frntmottqvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Motorsts0286::FrntmottqvalidType Motorsts0286::frntmottqvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  Motorsts0286::FrntmottqvalidType ret =  static_cast<Motorsts0286::FrntmottqvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': True, 'len': 15, 'name': 'frntmottq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-2048|2047.875]', 'physical_unit': 'Nm', 'precision': 0.125, 'type': 'double'}
double Motorsts0286::frntmottq(const std::uint8_t* bytes, int32_t length) const {
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

// config detail: {'bit': 11, 'enum': {0: 'FrntMotSpdValidvalid', 1: 'FrntMotSpdValidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'frntmotspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Motorsts0286::FrntmotspdvalidType Motorsts0286::frntmotspdvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Motorsts0286::FrntmotspdvalidType ret =  static_cast<Motorsts0286::FrntmotspdvalidType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': True, 'len': 16, 'name': 'frntmotspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32768|32767]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int32_t'}
int32_t Motorsts0286::frntmotspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  int32_t ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
