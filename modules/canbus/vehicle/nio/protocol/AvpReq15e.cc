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

#include "modules/canbus/vehicle/nio/protocol/AvpReq15e.h"

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
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpapaparkmod(avpapaparkmod(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpnbssts(avpnbssts(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpadcvcunbssts(avpadcvcunbssts(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpapasts(avpapasts(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpbrkmodsts(avpbrkmodsts(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpspdlmt(avpspdlmt(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpgearreqactv(avpgearreqactv(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpmsgcntr(avpmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpcrc(avpcrc(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpdstreq(avpdstreq(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avptargearreq(avptargearreq(bytes, length));
  chassis->mutable_nio()->mutable_AvpReq15e()->set_avpcrtlmode(avpcrtlmode(bytes, length));
}

// config detail: {'bit': 39, 'enum': {0: 'AvpApaparkmodoff', 1: 'AvpApaparkmodSapa', 2: 'AvpApaparkmodVpps', 3: 'AvpApaparkmodNBS', 4: 'AvpApaparkmodDescriptionForTheValue0x4', 5: 'AvpApaparkmodDescriptionForTheValue0x5', 6: 'AvpApaparkmodDescriptionForTheValue0x6', 7: 'AvpApaparkmodDescriptionForTheValue0x7'}, 'is_signed_var': False, 'len': 3, 'name': 'avpapaparkmod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpapaparkmodType Avpreq15e::avpapaparkmod(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Avpreq15e::AvpapaparkmodType ret =  static_cast<Avpreq15e::AvpapaparkmodType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'AvpNbsstsNBSOff', 1: 'AvpNbsstsNBSInitial', 2: 'AvpNbsstsNBSStandby', 3: 'AvpNbsstsNBSMoving', 4: 'AvpNbsstsNBSAbort', 5: 'AvpNbsstsNBSFail', 6: 'AvpNbsstsDescriptionForTheValue0x6', 7: 'AvpNbsstsDescriptionForTheValue0x7'}, 'is_signed_var': False, 'len': 3, 'name': 'avpnbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpnbsstsType Avpreq15e::avpnbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  Avpreq15e::AvpnbsstsType ret =  static_cast<Avpreq15e::AvpnbsstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'AvpAdcvcunbsstsNBSOFF', 1: 'AvpAdcvcunbsstsNBSIntial', 2: 'AvpAdcvcunbsstsNBSStandby', 3: 'AvpAdcvcunbsstsNBSMoving', 4: 'AvpAdcvcunbsstsNBSAbort', 5: 'AvpAdcvcunbsstsNBSFail', 6: 'AvpAdcvcunbsstsDescriptionForTheValue0x6', 7: 'AvpAdcvcunbsstsDescriptionForTheValue0x7', 8: 'AvpAdcvcunbsstsDescriptionForTheValue0x8', 9: 'AvpAdcvcunbsstsDescriptionForTheValue0x9', 10: 'AvpAdcvcunbsstsDescriptionForTheValue0xA', 11: 'AvpAdcvcunbsstsDescriptionForTheValue0xB', 12: 'AvpAdcvcunbsstsDescriptionForTheValue0xC', 13: 'AvpAdcvcunbsstsDescriptionForTheValue0xD', 14: 'AvpAdcvcunbsstsDescriptionForTheValue0xE', 15: 'AvpAdcvcunbsstsDescriptionForTheValue0xF'}, 'is_signed_var': False, 'len': 4, 'name': 'avpadcvcunbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpadcvcunbsstsType Avpreq15e::avpadcvcunbssts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 4);

  Avpreq15e::AvpadcvcunbsstsType ret =  static_cast<Avpreq15e::AvpadcvcunbsstsType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'AvpApastsinitial', 1: 'AvpApastsStandby', 2: 'AvpApastsSearch', 3: 'AvpApastsPreGuidence', 4: 'AvpApastsGuidance', 5: 'AvpApastsReserved', 6: 'AvpApastsAbort', 7: 'AvpApastsFault', 8: 'AvpApastsPubRoad', 9: 'AvpApastsOffMode', 10: 'AvpApastsReserved10', 11: 'AvpApastsReserved11', 12: 'AvpApastsReserved12', 13: 'AvpApastsReserved13', 14: 'AvpApastsReserved14', 15: 'AvpApastsReserved15'}, 'is_signed_var': False, 'len': 4, 'name': 'avpapasts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpapastsType Avpreq15e::avpapasts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 4);

  Avpreq15e::AvpapastsType ret =  static_cast<Avpreq15e::AvpapastsType>(x);
  return ret;
}

// config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AvpBrkmodstsNoBrake', 1: 'AvpBrkmodstsComfort', 2: 'AvpBrkmodstsEmergency', 3: 'AvpBrkmodstsReserved'}, 'is_signed_var': False, 'len': 3, 'name': 'avpbrkmodsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpbrkmodstsType Avpreq15e::avpbrkmodsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(1, 3);

  Avpreq15e::AvpbrkmodstsType ret =  static_cast<Avpreq15e::AvpbrkmodstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'avpspdlmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
double Avpreq15e::avpspdlmt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 6);

  double ret = x * 0.100000 + -3.200000;
  return ret;
}

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'avpgearreqactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Avpreq15e::avpgearreqactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'avpmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Avpreq15e::avpmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'avpcrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Avpreq15e::avpcrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'avpdstreq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int32_t'}
int32_t Avpreq15e::avpdstreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 5);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int32_t ret = x + -4095.000000;
  return ret;
}

// config detail: {'bit': 63, 'enum': {0: 'AvpTargearreqNoGearRequest', 1: 'AvpTargearreqD', 2: 'AvpTargearreqR', 3: 'AvpTargearreqN', 4: 'AvpTargearreqP'}, 'is_signed_var': False, 'len': 3, 'name': 'avptargearreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvptargearreqType Avpreq15e::avptargearreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(5, 3);

  Avpreq15e::AvptargearreqType ret =  static_cast<Avpreq15e::AvptargearreqType>(x);
  return ret;
}

// config detail: {'bit': 55, 'enum': {0: 'AvpCrtlmodeNo', 1: 'AvpCrtlmodeDistCrtl', 2: 'AvpCrtlmodeSpdCrtl', 3: 'AvpCrtlmodeRes'}, 'is_signed_var': False, 'len': 4, 'name': 'avpcrtlmode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Avpreq15e::AvpcrtlmodeType Avpreq15e::avpcrtlmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 4);

  Avpreq15e::AvpcrtlmodeType ret =  static_cast<Avpreq15e::AvpcrtlmodeType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
