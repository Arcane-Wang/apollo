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

#include "modules/canbus/vehicle/nio/protocol/motorsts_02_86.h"

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
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasMotorsts0286() ) {
           chassis->Builder().getNio().initMotorsts0286();
        }
    }
  chassis->Builder().getNio().getmotorsts_02_86().setMotor02_MsgCntr(Motor02_MsgCntr(bytes, length));
  chassis->Builder().getNio().getmotorsts_02_86().setMotor02_CRC(Motor02_CRC(bytes, length));
  chassis->Builder().getNio().getmotorsts_02_86().setFrntMotTqValid(FrntMotTqValid(bytes, length));
  chassis->Builder().getNio().getmotorsts_02_86().setFrntMotTq(FrntMotTq(bytes, length));
  chassis->Builder().getNio().getmotorsts_02_86().setFrntMotSpdValid(FrntMotSpdValid(bytes, length));
  chassis->Builder().getNio().getmotorsts_02_86().setFrntMotSpd(FrntMotSpd(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Motor02_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Motorsts0286::Motor02_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Motor02_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Motorsts0286::Motor02_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'FRNTMOTTQVALID_VALID', 1: 'FRNTMOTTQVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'FrntMotTqValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::motorsts_02_86::FrntMotTqValidType Motorsts0286::FrntMotTqValid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::motorsts_02_86::FrntMotTqValidType ret =  static_cast<::atlas_messages::motorsts_02_86::FrntMotTqValidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': True, 'len': 15, 'name': 'FrntMotTq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-2048|2047.875]', 'physical_unit': 'Nm', 'precision': 0.125, 'type': 'double'}
 Motorsts0286::FrntMotTq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  x <<= 17;
  x >>= 17;

   ret = x * 0.125000;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'FRNTMOTSPDVALID_VALID', 1: 'FRNTMOTSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'FrntMotSpdValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::motorsts_02_86::FrntMotSpdValidType Motorsts0286::FrntMotSpdValid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::motorsts_02_86::FrntMotSpdValidType ret =  static_cast<::atlas_messages::motorsts_02_86::FrntMotSpdValidType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': True, 'len': 16, 'name': 'FrntMotSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32768|32767]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int'}
 Motorsts0286::FrntMotSpd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

   ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
