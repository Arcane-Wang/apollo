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

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Aebreq79::ID = 0x79;

// public
Aebreq79::Aebreq79() { Reset(); }

uint32_t Aebreq79::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Aebreq79::UpdateData(uint8_t* data) {
  set_p_aebtardecel(data, aebtardecel_);
  set_p_abareq(data, abareq_);
  set_p_abasnvtylvl(data, abasnvtylvl_);
  set_p_awbsnvtylvl(data, awbsnvtylvl_);
  set_p_awbreq(data, awbreq_);
  set_p_scmdecelreq(data, scmdecelreq_);
  set_p_aeb_msgcntr(data, aeb_msgcntr_);
  set_p_aebdecelreq(data, aebdecelreq_);
  set_p_ebadecelreq(data, ebadecelreq_);
  set_p_abpreq(data, abpreq_);
  set_p_pedpdecreq(data, pedpdecreq_);
  set_p_aeb_crc(data, aeb_crc_);
}

void Aebreq79::Reset() {
  // TODO(All) :  you should check this manually
  aebtardecel_ = 0.0;
  abareq_ = Aebreq_79::ABAREQ_NO_REQUEST;
  abasnvtylvl_ = Aebreq_79::ABASNVTYLVL_LEVEL_0;
  awbsnvtylvl_ = Aebreq_79::AWBSNVTYLVL_LEVEL_0;
  awbreq_ = Aebreq_79::AWBREQ_NO_REQUEST;
  scmdecelreq_ = Aebreq_79::SCMDECELREQ_NO_REQUEST;
  aeb_msgcntr_ = 0;
  aebdecelreq_ = Aebreq_79::AEBDECELREQ_NO_REQUEST;
  ebadecelreq_ = Aebreq_79::EBADECELREQ_NO_REQUEST;
  abpreq_ = Aebreq_79::ABPREQ_NO_REQUEST;
  pedpdecreq_ = Aebreq_79::PEDPDECREQ_NO_REQUEST;
  aeb_crc_ = 0;
}

Aebreq79* Aebreq79::set_aebtardecel(
    double aebtardecel) {
  aebtardecel_ = aebtardecel;
  return this;
 }

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'AEBTarDecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
void Aebreq79::set_p_aebtardecel(uint8_t* data,
    double aebtardecel) {
  aebtardecel = ProtocolData::BoundedValue(-16.0, 15.99, aebtardecel);
  int x = (aebtardecel - -16.000000) / 0.000488;
  uint8_t t = 0;

  t = x & 0xF;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 4, 4);
  x >>= 4;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xF;
  Byte to_set2(data + 4);
  to_set2.set_value(t, 0, 4);
}


Aebreq79* Aebreq79::set_abareq(
    Aebreq_79::AbareqType abareq) {
  abareq_ = abareq;
  return this;
 }

// config detail: {'bit': 28, 'enum': {0: 'ABAREQ_NO_REQUEST', 1: 'ABAREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_abareq(uint8_t* data,
    Aebreq_79::AbareqType abareq) {
  int x = abareq;

  Byte to_set(data + 3);
  to_set.set_value(x, 4, 1);
}


Aebreq79* Aebreq79::set_abasnvtylvl(
    Aebreq_79::AbasnvtylvlType abasnvtylvl) {
  abasnvtylvl_ = abasnvtylvl;
  return this;
 }

// config detail: {'bit': 26, 'enum': {0: 'ABASNVTYLVL_LEVEL_0', 1: 'ABASNVTYLVL_LEVEL_1', 2: 'ABASNVTYLVL_LEVEL_2', 3: 'ABASNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'ABASnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_abasnvtylvl(uint8_t* data,
    Aebreq_79::AbasnvtylvlType abasnvtylvl) {
  int x = abasnvtylvl;

  Byte to_set(data + 3);
  to_set.set_value(x, 1, 2);
}


Aebreq79* Aebreq79::set_awbsnvtylvl(
    Aebreq_79::AwbsnvtylvlType awbsnvtylvl) {
  awbsnvtylvl_ = awbsnvtylvl;
  return this;
 }

// config detail: {'bit': 38, 'enum': {0: 'AWBSNVTYLVL_LEVEL_0', 1: 'AWBSNVTYLVL_LEVEL_1', 2: 'AWBSNVTYLVL_LEVEL_2', 3: 'AWBSNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'AWBSnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_awbsnvtylvl(uint8_t* data,
    Aebreq_79::AwbsnvtylvlType awbsnvtylvl) {
  int x = awbsnvtylvl;

  Byte to_set(data + 4);
  to_set.set_value(x, 5, 2);
}


Aebreq79* Aebreq79::set_awbreq(
    Aebreq_79::AwbreqType awbreq) {
  awbreq_ = awbreq;
  return this;
 }

// config detail: {'bit': 30, 'enum': {0: 'AWBREQ_NO_REQUEST', 1: 'AWBREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_awbreq(uint8_t* data,
    Aebreq_79::AwbreqType awbreq) {
  int x = awbreq;

  Byte to_set(data + 3);
  to_set.set_value(x, 6, 1);
}


Aebreq79* Aebreq79::set_scmdecelreq(
    Aebreq_79::ScmdecelreqType scmdecelreq) {
  scmdecelreq_ = scmdecelreq;
  return this;
 }

// config detail: {'bit': 18, 'enum': {0: 'SCMDECELREQ_NO_REQUEST', 1: 'SCMDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_scmdecelreq(uint8_t* data,
    Aebreq_79::ScmdecelreqType scmdecelreq) {
  int x = scmdecelreq;

  Byte to_set(data + 2);
  to_set.set_value(x, 2, 1);
}


Aebreq79* Aebreq79::set_aeb_msgcntr(
    int aeb_msgcntr) {
  aeb_msgcntr_ = aeb_msgcntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AEB_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Aebreq79::set_p_aeb_msgcntr(uint8_t* data,
    int aeb_msgcntr) {
  aeb_msgcntr = ProtocolData::BoundedValue(0, 15, aeb_msgcntr);
  int x = aeb_msgcntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Aebreq79* Aebreq79::set_aebdecelreq(
    Aebreq_79::AebdecelreqType aebdecelreq) {
  aebdecelreq_ = aebdecelreq;
  return this;
 }

// config detail: {'bit': 22, 'enum': {0: 'AEBDECELREQ_NO_REQUEST', 1: 'AEBDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_aebdecelreq(uint8_t* data,
    Aebreq_79::AebdecelreqType aebdecelreq) {
  int x = aebdecelreq;

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 1);
}


Aebreq79* Aebreq79::set_ebadecelreq(
    Aebreq_79::EbadecelreqType ebadecelreq) {
  ebadecelreq_ = ebadecelreq;
  return this;
 }

// config detail: {'bit': 31, 'enum': {0: 'EBADECELREQ_NO_REQUEST', 1: 'EBADECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'EBADecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_ebadecelreq(uint8_t* data,
    Aebreq_79::EbadecelreqType ebadecelreq) {
  int x = ebadecelreq;

  Byte to_set(data + 3);
  to_set.set_value(x, 7, 1);
}


Aebreq79* Aebreq79::set_abpreq(
    Aebreq_79::AbpreqType abpreq) {
  abpreq_ = abpreq;
  return this;
 }

// config detail: {'bit': 16, 'enum': {0: 'ABPREQ_NO_REQUEST', 1: 'ABPREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_abpreq(uint8_t* data,
    Aebreq_79::AbpreqType abpreq) {
  int x = abpreq;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 1);
}


Aebreq79* Aebreq79::set_pedpdecreq(
    Aebreq_79::PedpdecreqType pedpdecreq) {
  pedpdecreq_ = pedpdecreq;
  return this;
 }

// config detail: {'bit': 20, 'enum': {0: 'PEDPDECREQ_NO_REQUEST', 1: 'PEDPDECREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPDecReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_pedpdecreq(uint8_t* data,
    Aebreq_79::PedpdecreqType pedpdecreq) {
  int x = pedpdecreq;

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 1);
}


Aebreq79* Aebreq79::set_aeb_crc(
    int aeb_crc) {
  aeb_crc_ = aeb_crc;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AEB_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Aebreq79::set_p_aeb_crc(uint8_t* data,
    int aeb_crc) {
  aeb_crc = ProtocolData::BoundedValue(0, 255, aeb_crc);
  int x = aeb_crc;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
