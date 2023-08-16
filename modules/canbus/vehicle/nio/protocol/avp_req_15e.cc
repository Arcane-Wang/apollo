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

#include "modules/canbus/vehicle/nio/protocol/avp_req_15e.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Avpreq15e::ID = 0x15E;

// public
Avpreq15e::Avpreq15e() { Reset(); }

uint32_t Avpreq15e::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Avpreq15e::UpdateData(uint8_t* data) {
  set_p_avp_apaparkmod(data, avp_apaparkmod_);
  set_p_avp_nbssts(data, avp_nbssts_);
  set_p_avp_adcvcunbssts(data, avp_adcvcunbssts_);
  set_p_avp_apasts(data, avp_apasts_);
  set_p_avp_brkmodsts(data, avp_brkmodsts_);
  set_p_avp_spdlmt(data, avp_spdlmt_);
  set_p_avp_gearreqactv(data, avp_gearreqactv_);
  set_p_avp_msgcntr(data, avp_msgcntr_);
  set_p_avp_crc(data, avp_crc_);
  set_p_avp_dstreq(data, avp_dstreq_);
  set_p_avp_targearreq(data, avp_targearreq_);
  set_p_avp_crtlmode(data, avp_crtlmode_);
}

void Avpreq15e::Reset() {
  // TODO(All) :  you should check this manually
  avp_apaparkmod_ = Avp_req_15e::AVP_APAPARKMOD_OFF;
  avp_nbssts_ = Avp_req_15e::AVP_NBSSTS_NBS_OFF;
  avp_adcvcunbssts_ = Avp_req_15e::AVP_ADCVCUNBSSTS_NBS_OFF;
  avp_apasts_ = Avp_req_15e::AVP_APASTS_INITIAL;
  avp_brkmodsts_ = Avp_req_15e::AVP_BRKMODSTS_NO_BRAKE;
  avp_spdlmt_ = 0.0;
  avp_gearreqactv_ = false;
  avp_msgcntr_ = 0;
  avp_crc_ = 0;
  avp_dstreq_ = 0;
  avp_targearreq_ = Avp_req_15e::AVP_TARGEARREQ_NO_GEAR_REQUEST;
  avp_crtlmode_ = Avp_req_15e::AVP_CRTLMODE_NO;
}

Avpreq15e* Avpreq15e::set_avp_apaparkmod(
    Avp_req_15e::Avp_apaparkmodType avp_apaparkmod) {
  avp_apaparkmod_ = avp_apaparkmod;
  return this;
 }

// config detail: {'bit': 39, 'enum': {0: 'AVP_APAPARKMOD_OFF', 1: 'AVP_APAPARKMOD_SAPA', 2: 'AVP_APAPARKMOD_VPPS', 3: 'AVP_APAPARKMOD_NBS', 4: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X5', 6: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_ApaParkMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_apaparkmod(uint8_t* data,
    Avp_req_15e::Avp_apaparkmodType avp_apaparkmod) {
  int x = avp_apaparkmod;

  Byte to_set(data + 4);
  to_set.set_value(x, 5, 3);
}


Avpreq15e* Avpreq15e::set_avp_nbssts(
    Avp_req_15e::Avp_nbsstsType avp_nbssts) {
  avp_nbssts_ = avp_nbssts;
  return this;
 }

// config detail: {'bit': 19, 'enum': {0: 'AVP_NBSSTS_NBS_OFF', 1: 'AVP_NBSSTS_NBS_INITIAL', 2: 'AVP_NBSSTS_NBS_STANDBY', 3: 'AVP_NBSSTS_NBS_MOVING', 4: 'AVP_NBSSTS_NBS_ABORT', 5: 'AVP_NBSSTS_NBS_FAIL', 6: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_NBSSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_nbssts(uint8_t* data,
    Avp_req_15e::Avp_nbsstsType avp_nbssts) {
  int x = avp_nbssts;

  Byte to_set(data + 2);
  to_set.set_value(x, 1, 3);
}


Avpreq15e* Avpreq15e::set_avp_adcvcunbssts(
    Avp_req_15e::Avp_adcvcunbsstsType avp_adcvcunbssts) {
  avp_adcvcunbssts_ = avp_adcvcunbssts;
  return this;
 }

// config detail: {'bit': 23, 'enum': {0: 'AVP_ADCVCUNBSSTS_NBS_OFF', 1: 'AVP_ADCVCUNBSSTS_NBS_INTIAL', 2: 'AVP_ADCVCUNBSSTS_NBS_STANDBY', 3: 'AVP_ADCVCUNBSSTS_NBS_MOVING', 4: 'AVP_ADCVCUNBSSTS_NBS_ABORT', 5: 'AVP_ADCVCUNBSSTS_NBS_FAIL', 6: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7', 8: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ADCVCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_adcvcunbssts(uint8_t* data,
    Avp_req_15e::Avp_adcvcunbsstsType avp_adcvcunbssts) {
  int x = avp_adcvcunbssts;

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 4);
}


Avpreq15e* Avpreq15e::set_avp_apasts(
    Avp_req_15e::Avp_apastsType avp_apasts) {
  avp_apasts_ = avp_apasts;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'AVP_APASTS_INITIAL', 1: 'AVP_APASTS_STANDBY', 2: 'AVP_APASTS_SEARCH', 3: 'AVP_APASTS_PRE_GUIDENCE', 4: 'AVP_APASTS_GUIDANCE', 5: 'AVP_APASTS_RESERVED', 6: 'AVP_APASTS_ABORT', 7: 'AVP_APASTS_FAULT', 8: 'AVP_APASTS_PUB_ROAD', 9: 'AVP_APASTS_OFFMODE', 10: 'AVP_APASTS_RESERVED10', 11: 'AVP_APASTS_RESERVED11', 12: 'AVP_APASTS_RESERVED12', 13: 'AVP_APASTS_RESERVED13', 14: 'AVP_APASTS_RESERVED14', 15: 'AVP_APASTS_RESERVED15'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ApaSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_apasts(uint8_t* data,
    Avp_req_15e::Avp_apastsType avp_apasts) {
  int x = avp_apasts;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 4);
}


Avpreq15e* Avpreq15e::set_avp_brkmodsts(
    Avp_req_15e::Avp_brkmodstsType avp_brkmodsts) {
  avp_brkmodsts_ = avp_brkmodsts;
  return this;
 }

// config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AVP_BRKMODSTS_NO_BRAKE', 1: 'AVP_BRKMODSTS_COMFORT', 2: 'AVP_BRKMODSTS_EMERGENCY', 3: 'AVP_BRKMODSTS_RESERVED'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_BrkModSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_brkmodsts(uint8_t* data,
    Avp_req_15e::Avp_brkmodstsType avp_brkmodsts) {
  int x = avp_brkmodsts;

  Byte to_set(data + 7);
  to_set.set_value(x, 1, 3);
}


Avpreq15e* Avpreq15e::set_avp_spdlmt(
    double avp_spdlmt) {
  avp_spdlmt_ = avp_spdlmt;
  return this;
 }

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'Avp_SpdLmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
void Avpreq15e::set_p_avp_spdlmt(uint8_t* data,
    double avp_spdlmt) {
  avp_spdlmt = ProtocolData::BoundedValue(-3.2, 3.1, avp_spdlmt);
  int x = (avp_spdlmt - -3.200000) / 0.100000;

  Byte to_set(data + 3);
  to_set.set_value(x, 2, 6);
}


Avpreq15e* Avpreq15e::set_avp_gearreqactv(
    bool avp_gearreqactv) {
  avp_gearreqactv_ = avp_gearreqactv;
  return this;
 }

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'Avp_GearReqAcTv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Avpreq15e::set_p_avp_gearreqactv(uint8_t* data,
    bool avp_gearreqactv) {
  int x = avp_gearreqactv;

  Byte to_set(data + 3);
  to_set.set_value(x, 1, 1);
}


Avpreq15e* Avpreq15e::set_avp_msgcntr(
    int avp_msgcntr) {
  avp_msgcntr_ = avp_msgcntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Avp_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp_msgcntr(uint8_t* data,
    int avp_msgcntr) {
  avp_msgcntr = ProtocolData::BoundedValue(0, 15, avp_msgcntr);
  int x = avp_msgcntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Avpreq15e* Avpreq15e::set_avp_crc(
    int avp_crc) {
  avp_crc_ = avp_crc;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Avp_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp_crc(uint8_t* data,
    int avp_crc) {
  avp_crc = ProtocolData::BoundedValue(0, 255, avp_crc);
  int x = avp_crc;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}


Avpreq15e* Avpreq15e::set_avp_dstreq(
    int avp_dstreq) {
  avp_dstreq_ = avp_dstreq;
  return this;
 }

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'Avp_DstReq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp_dstreq(uint8_t* data,
    int avp_dstreq) {
  avp_dstreq = ProtocolData::BoundedValue(-4095, 4096, avp_dstreq);
  int x = (avp_dstreq - -4095.000000);
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0x1F;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 5);
}


Avpreq15e* Avpreq15e::set_avp_targearreq(
    Avp_req_15e::Avp_targearreqType avp_targearreq) {
  avp_targearreq_ = avp_targearreq;
  return this;
 }

// config detail: {'bit': 63, 'enum': {0: 'AVP_TARGEARREQ_NO_GEAR_REQUEST', 1: 'AVP_TARGEARREQ_D', 2: 'AVP_TARGEARREQ_R', 3: 'AVP_TARGEARREQ_N', 4: 'AVP_TARGEARREQ_P'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_TarGearReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_targearreq(uint8_t* data,
    Avp_req_15e::Avp_targearreqType avp_targearreq) {
  int x = avp_targearreq;

  Byte to_set(data + 7);
  to_set.set_value(x, 5, 3);
}


Avpreq15e* Avpreq15e::set_avp_crtlmode(
    Avp_req_15e::Avp_crtlmodeType avp_crtlmode) {
  avp_crtlmode_ = avp_crtlmode;
  return this;
 }

// config detail: {'bit': 55, 'enum': {0: 'AVP_CRTLMODE_NO', 1: 'AVP_CRTLMODE_DIST_CRTL', 2: 'AVP_CRTLMODE_SPD_CRTL', 3: 'AVP_CRTLMODE_RES'}, 'is_signed_var': False, 'len': 4, 'name': 'AvP_CrtlMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp_crtlmode(uint8_t* data,
    Avp_req_15e::Avp_crtlmodeType avp_crtlmode) {
  int x = avp_crtlmode;

  Byte to_set(data + 6);
  to_set.set_value(x, 4, 4);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
