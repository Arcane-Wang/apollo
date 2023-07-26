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

#include "modules/canbus/vehicle/nio/protocol/aebreq_79.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Aebreq79::Aebreq79() {}
const int32_t Aebreq79::ID = 0x79;

void Aebreq79::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_aebreq_79()->set_aebtardecel(aebtardecel(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_abareq(abareq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_abasnvtylvl(abasnvtylvl(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_awbsnvtylvl(awbsnvtylvl(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_awbreq(awbreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_scmdecelreq(scmdecelreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_aeb_msgcntr(aeb_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_aebdecelreq(aebdecelreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_ebadecelreq(ebadecelreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_abpreq(abpreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_pedpdecreq(pedpdecreq(bytes, length));
  chassis->mutable_nio()->mutable_aebreq_79()->set_aeb_crc(aeb_crc(bytes, length));
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'aebtardecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
double Aebreq79::aebtardecel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 6);
  t = t2.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 0.000488 + -16.000000;
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'ABAREQ_NO_REQUEST', 1: 'ABAREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'abareq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AbareqType Aebreq79::abareq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  Aebreq_79::AbareqType ret =  static_cast<Aebreq_79::AbareqType>(x);
  return ret;
}

// config detail: {'bit': 26, 'enum': {0: 'ABASNVTYLVL_LEVEL_0', 1: 'ABASNVTYLVL_LEVEL_1', 2: 'ABASNVTYLVL_LEVEL_2', 3: 'ABASNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'abasnvtylvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AbasnvtylvlType Aebreq79::abasnvtylvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  Aebreq_79::AbasnvtylvlType ret =  static_cast<Aebreq_79::AbasnvtylvlType>(x);
  return ret;
}

// config detail: {'bit': 38, 'enum': {0: 'AWBSNVTYLVL_LEVEL_0', 1: 'AWBSNVTYLVL_LEVEL_1', 2: 'AWBSNVTYLVL_LEVEL_2', 3: 'AWBSNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'awbsnvtylvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AwbsnvtylvlType Aebreq79::awbsnvtylvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 2);

  Aebreq_79::AwbsnvtylvlType ret =  static_cast<Aebreq_79::AwbsnvtylvlType>(x);
  return ret;
}

// config detail: {'bit': 30, 'enum': {0: 'AWBREQ_NO_REQUEST', 1: 'AWBREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'awbreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AwbreqType Aebreq79::awbreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 1);

  Aebreq_79::AwbreqType ret =  static_cast<Aebreq_79::AwbreqType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'SCMDECELREQ_NO_REQUEST', 1: 'SCMDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'scmdecelreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::ScmdecelreqType Aebreq79::scmdecelreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  Aebreq_79::ScmdecelreqType ret =  static_cast<Aebreq_79::ScmdecelreqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'aeb_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Aebreq79::aeb_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 22, 'enum': {0: 'AEBDECELREQ_NO_REQUEST', 1: 'AEBDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'aebdecelreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AebdecelreqType Aebreq79::aebdecelreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 1);

  Aebreq_79::AebdecelreqType ret =  static_cast<Aebreq_79::AebdecelreqType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'EBADECELREQ_NO_REQUEST', 1: 'EBADECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ebadecelreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::EbadecelreqType Aebreq79::ebadecelreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  Aebreq_79::EbadecelreqType ret =  static_cast<Aebreq_79::EbadecelreqType>(x);
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'ABPREQ_NO_REQUEST', 1: 'ABPREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'abpreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::AbpreqType Aebreq79::abpreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Aebreq_79::AbpreqType ret =  static_cast<Aebreq_79::AbpreqType>(x);
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'PEDPDECREQ_NO_REQUEST', 1: 'PEDPDECREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'pedpdecreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Aebreq_79::PedpdecreqType Aebreq79::pedpdecreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Aebreq_79::PedpdecreqType ret =  static_cast<Aebreq_79::PedpdecreqType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'aeb_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Aebreq79::aeb_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
