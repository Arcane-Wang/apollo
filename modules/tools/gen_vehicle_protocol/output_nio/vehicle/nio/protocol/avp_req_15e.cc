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

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Avpreq15e::Avpreq15e() {}
const int32_t Avpreq15e::ID = 0x15E;

void Avpreq15e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_apaparkmod(avp_apaparkmod(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_nbssts(avp_nbssts(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_adcvcunbssts(avp_adcvcunbssts(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_apasts(avp_apasts(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_brkmodsts(avp_brkmodsts(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_spdlmt(avp_spdlmt(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_gearreqactv(avp_gearreqactv(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_msgcntr(avp_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_crc(avp_crc(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_dstreq(avp_dstreq(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_targearreq(avp_targearreq(bytes, length));
  chassis->mutable_nio()->mutable_avp_req_15e()->set_avp_crtlmode(avp_crtlmode(bytes, length));
}

// config detail: {'bit': 39, 'enum': {0: 'AVP_APAPARKMOD_OFF', 1: 'AVP_APAPARKMOD_SAPA', 2: 'AVP_APAPARKMOD_VPPS', 3: 'AVP_APAPARKMOD_NBS', 4: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X5', 6: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'avp_apaparkmod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_apaparkmodType Avpreq15e::avp_apaparkmod(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Avp_req_15e::Avp_apaparkmodType ret =  static_cast<Avp_req_15e::Avp_apaparkmodType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'AVP_NBSSTS_NBS_OFF', 1: 'AVP_NBSSTS_NBS_INITIAL', 2: 'AVP_NBSSTS_NBS_STANDBY', 3: 'AVP_NBSSTS_NBS_MOVING', 4: 'AVP_NBSSTS_NBS_ABORT', 5: 'AVP_NBSSTS_NBS_FAIL', 6: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'avp_nbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_nbsstsType Avpreq15e::avp_nbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  Avp_req_15e::Avp_nbsstsType ret =  static_cast<Avp_req_15e::Avp_nbsstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'AVP_ADCVCUNBSSTS_NBS_OFF', 1: 'AVP_ADCVCUNBSSTS_NBS_INTIAL', 2: 'AVP_ADCVCUNBSSTS_NBS_STANDBY', 3: 'AVP_ADCVCUNBSSTS_NBS_MOVING', 4: 'AVP_ADCVCUNBSSTS_NBS_ABORT', 5: 'AVP_ADCVCUNBSSTS_NBS_FAIL', 6: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7', 8: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'is_signed_var': False, 'len': 4, 'name': 'avp_adcvcunbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_adcvcunbsstsType Avpreq15e::avp_adcvcunbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 4);

  Avp_req_15e::Avp_adcvcunbsstsType ret =  static_cast<Avp_req_15e::Avp_adcvcunbsstsType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'AVP_APASTS_INITIAL', 1: 'AVP_APASTS_STANDBY', 2: 'AVP_APASTS_SEARCH', 3: 'AVP_APASTS_PRE_GUIDENCE', 4: 'AVP_APASTS_GUIDANCE', 5: 'AVP_APASTS_RESERVED', 6: 'AVP_APASTS_ABORT', 7: 'AVP_APASTS_FAULT', 8: 'AVP_APASTS_PUB_ROAD', 9: 'AVP_APASTS_OFFMODE', 10: 'AVP_APASTS_RESERVED10', 11: 'AVP_APASTS_RESERVED11', 12: 'AVP_APASTS_RESERVED12', 13: 'AVP_APASTS_RESERVED13', 14: 'AVP_APASTS_RESERVED14', 15: 'AVP_APASTS_RESERVED15'}, 'is_signed_var': False, 'len': 4, 'name': 'avp_apasts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_apastsType Avpreq15e::avp_apasts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 4);

  Avp_req_15e::Avp_apastsType ret =  static_cast<Avp_req_15e::Avp_apastsType>(x);
  return ret;
}

// config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AVP_BRKMODSTS_NO_BRAKE', 1: 'AVP_BRKMODSTS_COMFORT', 2: 'AVP_BRKMODSTS_EMERGENCY', 3: 'AVP_BRKMODSTS_RESERVED'}, 'is_signed_var': False, 'len': 3, 'name': 'avp_brkmodsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_brkmodstsType Avpreq15e::avp_brkmodsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(1, 3);

  Avp_req_15e::Avp_brkmodstsType ret =  static_cast<Avp_req_15e::Avp_brkmodstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'avp_spdlmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
double Avpreq15e::avp_spdlmt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 6);

  double ret = x * 0.100000 + -3.200000;
  return ret;
}

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'avp_gearreqactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Avpreq15e::avp_gearreqactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'avp_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Avpreq15e::avp_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'avp_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Avpreq15e::avp_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'avp_dstreq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int'}
int Avpreq15e::avp_dstreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 5);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x + -4095.000000;
  return ret;
}

// config detail: {'bit': 63, 'enum': {0: 'AVP_TARGEARREQ_NO_GEAR_REQUEST', 1: 'AVP_TARGEARREQ_D', 2: 'AVP_TARGEARREQ_R', 3: 'AVP_TARGEARREQ_N', 4: 'AVP_TARGEARREQ_P'}, 'is_signed_var': False, 'len': 3, 'name': 'avp_targearreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_targearreqType Avpreq15e::avp_targearreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(5, 3);

  Avp_req_15e::Avp_targearreqType ret =  static_cast<Avp_req_15e::Avp_targearreqType>(x);
  return ret;
}

// config detail: {'bit': 55, 'enum': {0: 'AVP_CRTLMODE_NO', 1: 'AVP_CRTLMODE_DIST_CRTL', 2: 'AVP_CRTLMODE_SPD_CRTL', 3: 'AVP_CRTLMODE_RES'}, 'is_signed_var': False, 'len': 4, 'name': 'avp_crtlmode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avp_req_15e::Avp_crtlmodeType Avpreq15e::avp_crtlmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 4);

  Avp_req_15e::Avp_crtlmodeType ret =  static_cast<Avp_req_15e::Avp_crtlmodeType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
