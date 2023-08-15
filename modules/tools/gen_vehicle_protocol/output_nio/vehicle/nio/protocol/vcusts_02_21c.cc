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

#include "modules/canbus/vehicle/nio/protocol/vcusts_02_21c.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Vcusts0221c::Vcusts0221c() {}
const int32_t Vcusts0221c::ID = 0x21c;

void Vcusts0221c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasVcusts0221c() ) {
           chassis->Builder().getNio().initVcusts0221c();
        }
    }
  chassis->Builder().getNio().getvcusts_02_21c().setAccpedelftravelvalid(Accpedelftravelvalid(bytes, length));
  chassis->Builder().getNio().getvcusts_02_21c().setAccpedelftravel(Accpedelftravel(bytes, length));
  chassis->Builder().getNio().getvcusts_02_21c().setAccpedacttravelvalid(Accpedacttravelvalid(bytes, length));
  chassis->Builder().getNio().getvcusts_02_21c().setAccpedacttravel(Accpedacttravel(bytes, length));
  chassis->Builder().getNio().getvcusts_02_21c().setVCU_4_MsgCntr(VCU_4_MsgCntr(bytes, length));
  chassis->Builder().getNio().getvcusts_02_21c().setVCU_4_CRC(VCU_4_CRC(bytes, length));
}

// config detail: {'bit': 47, 'enum': {0: 'ACCPEDELFTRAVELVALID_VALID', 1: 'ACCPEDELFTRAVELVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Accpedelftravelvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::vcusts_02_21c::AccpedelftravelvalidType Vcusts0221c::Accpedelftravelvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::vcusts_02_21c::AccpedelftravelvalidType ret =  static_cast<::atlas_messages::vcusts_02_21c::AccpedelftravelvalidType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'Accpedelftravel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|99.96]', 'physical_unit': '', 'precision': 0.392, 'type': 'double'}
 Vcusts0221c::Accpedelftravel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

   ret = x * 0.392000;
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'ACCPEDACTTRAVELVALID_VALID', 1: 'ACCPEDACTTRAVELVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Accpedacttravelvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::vcusts_02_21c::AccpedacttravelvalidType Vcusts0221c::Accpedacttravelvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::vcusts_02_21c::AccpedacttravelvalidType ret =  static_cast<::atlas_messages::vcusts_02_21c::AccpedacttravelvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'Accpedacttravel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|99.96]', 'physical_unit': '', 'precision': 0.392, 'type': 'double'}
 Vcusts0221c::Accpedacttravel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

   ret = x * 0.392000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'VCU_4_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Vcusts0221c::VCU_4_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'VCU_4_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Vcusts0221c::VCU_4_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
