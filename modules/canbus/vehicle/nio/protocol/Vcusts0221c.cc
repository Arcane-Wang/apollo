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

#include "modules/canbus/vehicle/nio/protocol/Vcusts0221c.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Vcusts0221c::Vcusts0221c() {}
const int32_t Vcusts0221c::ID = 0x21C;

void Vcusts0221c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_accpedelftravelvalid(accpedelftravelvalid(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_accpedelftravel(accpedelftravel(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_accpedacttravelvalid(accpedacttravelvalid(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_accpedacttravel(accpedacttravel(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_vcu4msgcntr(vcu4msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Vcusts0221c()->set_vcu4crc(vcu4crc(bytes, length));
}

// config detail: {'bit': 47, 'enum': {0: 'Accpedelftravelvalidvalid', 1: 'Accpedelftravelvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'accpedelftravelvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts0221c::AccpedelftravelvalidType Vcusts0221c::accpedelftravelvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  Vcusts0221c::AccpedelftravelvalidType ret =  static_cast<Vcusts0221c::AccpedelftravelvalidType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'accpedelftravel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|99.96]', 'physical_unit': '', 'precision': 0.392, 'type': 'Float64'}
Float64 Vcusts0221c::accpedelftravel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Float64 ret = x * 0.392000;
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'Accpedacttravelvalidvalid', 1: 'Accpedacttravelvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'accpedacttravelvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Vcusts0221c::AccpedacttravelvalidType Vcusts0221c::accpedacttravelvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  Vcusts0221c::AccpedacttravelvalidType ret =  static_cast<Vcusts0221c::AccpedacttravelvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'accpedacttravel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|99.96]', 'physical_unit': '', 'precision': 0.392, 'type': 'Float64'}
Float64 Vcusts0221c::accpedacttravel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Float64 ret = x * 0.392000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'vcu4msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts0221c::vcu4msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  Int32 ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'vcu4crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
Int32 Vcusts0221c::vcu4crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Int32 ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
