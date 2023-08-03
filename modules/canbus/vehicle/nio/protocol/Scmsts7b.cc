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

#include "modules/canbus/vehicle/nio/protocol/Scmsts7b.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Scmsts7b::Scmsts7b() {}
const int32_t Scmsts7b::ID = 0x7B;

void Scmsts7b::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Scmsts7b()->set_scmfailsts(scmfailsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_hilowbeampushswtsts(hilowbeampushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_frntwiprswtsts(frntwiprswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_turnindcrswtsts(turnindcrswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_foglipushswtsts(foglipushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_frntwiprinterspd(frntwiprinterspd(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_menuorvoldwnpushswtsts(menuorvoldwnpushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_accspdincorresuswtsts(accspdincorresuswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_acctimegapincswtsts(acctimegapincswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_selnpushswtsts(selnpushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_modetogdecswtsts(modetogdecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_modetogincswtsts(modetogincswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_menupushswtsts(menupushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_swcfailsts(swcfailsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_accspddecswtsts(accspddecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_scmcrc(scmcrc(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_menulepushswtsts(menulepushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_menuorvoluppushswtsts(menuorvoluppushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_scmmsgcntr(scmmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_acctimegapdecswtsts(acctimegapdecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_menuripushswtsts(menuripushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_Scmsts7b()->set_accsetswtsts(accsetswtsts(bytes, length));
}

// config detail: {'bit': 41, 'enum': {0: 'SCMFailStsNormal', 1: 'SCMFailStsFail', 2: 'SCMFailStsReserved', 3: 'SCMFailStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'scmfailsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::ScmfailstsType Scmsts7b::scmfailsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  Scmsts7b::ScmfailstsType ret =  static_cast<Scmsts7b::ScmfailstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HiLowBeamPushSwtStsNoCommandDefaultPosition', 1: 'HiLowBeamPushSwtStsFlashCommand', 2: 'HiLowBeamPushSwtStsLowBeamOrHighBeamCommand', 3: 'HiLowBeamPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'hilowbeampushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::HilowbeampushswtstsType Scmsts7b::hilowbeampushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 2);

  Scmsts7b::HilowbeampushswtstsType ret =  static_cast<Scmsts7b::HilowbeampushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'FrntWiprSwtStsFrontWiperOff', 1: 'FrntWiprSwtStsFrontWiperLowSpeed', 2: 'FrntWiprSwtStsFrontWiperHighSpeed', 3: 'FrntWiprSwtStsFrontWiperIntermediateSpeed', 4: 'FrntWiprSwtStsFrontWiperWipeOneTime', 5: 'FrntWiprSwtStsReserved5', 6: 'FrntWiprSwtStsReserved6', 7: 'FrntWiprSwtStsInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::FrntwiprswtstsType Scmsts7b::frntwiprswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  Scmsts7b::FrntwiprswtstsType ret =  static_cast<Scmsts7b::FrntwiprswtstsType>(x);
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'TurnIndcrSwtStsNoTurnIndicator', 1: 'TurnIndcrSwtStsTurnIndicatorLeft', 2: 'TurnIndcrSwtStsTurnIndicatorRight', 3: 'TurnIndcrSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'turnindcrswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::TurnindcrswtstsType Scmsts7b::turnindcrswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Scmsts7b::TurnindcrswtstsType ret =  static_cast<Scmsts7b::TurnindcrswtstsType>(x);
  return ret;
}

// config detail: {'bit': 37, 'enum': {0: 'FogLiPushSwtStsPushSwitchNotPressed', 1: 'FogLiPushSwtStsPushSwitchPressed', 2: 'FogLiPushSwtStsReserved', 3: 'FogLiPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'foglipushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::FoglipushswtstsType Scmsts7b::foglipushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  Scmsts7b::FoglipushswtstsType ret =  static_cast<Scmsts7b::FoglipushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'FrntWiprInterSpdReserved', 1: 'FrntWiprInterSpdIntermediateSpeed1', 2: 'FrntWiprInterSpdIntermediateSpeed2', 3: 'FrntWiprInterSpdIntermediateSpeed3', 4: 'FrntWiprInterSpdIntermediateSpeed4', 5: 'FrntWiprInterSpdReserved5', 6: 'FrntWiprInterSpdReserved6', 7: 'FrntWiprInterSpdInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprinterspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::FrntwiprinterspdType Scmsts7b::frntwiprinterspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  Scmsts7b::FrntwiprinterspdType ret =  static_cast<Scmsts7b::FrntwiprinterspdType>(x);
  return ret;
}

// config detail: {'bit': 55, 'enum': {0: 'MenuOrVolDwnPushSwtStsNotPressed', 1: 'MenuOrVolDwnPushSwtStsPressed', 2: 'MenuOrVolDwnPushSwtStsReserved', 3: 'MenuOrVolDwnPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'menuorvoldwnpushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::MenuorvoldwnpushswtstsType Scmsts7b::menuorvoldwnpushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 2);

  Scmsts7b::MenuorvoldwnpushswtstsType ret =  static_cast<Scmsts7b::MenuorvoldwnpushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 59, 'enum': {0: 'AccSpdIncOrResuSwtStsNotPressed', 1: 'AccSpdIncOrResuSwtStsPressed', 2: 'AccSpdIncOrResuSwtStsReserved', 3: 'AccSpdIncOrResuSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'accspdincorresuswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::AccspdincorresuswtstsType Scmsts7b::accspdincorresuswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 2);

  Scmsts7b::AccspdincorresuswtstsType ret =  static_cast<Scmsts7b::AccspdincorresuswtstsType>(x);
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'AccTimeGapIncSwtStsNotPressed', 1: 'AccTimeGapIncSwtStsPressed', 2: 'AccTimeGapIncSwtStsReserved', 3: 'AccTimeGapIncSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'acctimegapincswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::AcctimegapincswtstsType Scmsts7b::acctimegapincswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 2);

  Scmsts7b::AcctimegapincswtstsType ret =  static_cast<Scmsts7b::AcctimegapincswtstsType>(x);
  return ret;
}

// config detail: {'bit': 63, 'enum': {0: 'SelnPushSwtStsNotPressed', 1: 'SelnPushSwtStsPressed', 2: 'SelnPushSwtStsReserved', 3: 'SelnPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'selnpushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::SelnpushswtstsType Scmsts7b::selnpushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(6, 2);

  Scmsts7b::SelnpushswtstsType ret =  static_cast<Scmsts7b::SelnpushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'ModeTogDecSwtStsNotPressed', 1: 'ModeTogDecSwtStsPressed', 2: 'ModeTogDecSwtStsReserved', 3: 'ModeTogDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'modetogdecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::ModetogdecswtstsType Scmsts7b::modetogdecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Scmsts7b::ModetogdecswtstsType ret =  static_cast<Scmsts7b::ModetogdecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 44, 'enum': {0: 'ModeTogIncSwtStsNotPressed', 1: 'ModeTogIncSwtStsPressed', 2: 'ModeTogIncSwtStsReserved', 3: 'ModeTogIncSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'modetogincswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::ModetogincswtstsType Scmsts7b::modetogincswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 2);

  Scmsts7b::ModetogincswtstsType ret =  static_cast<Scmsts7b::ModetogincswtstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'MenuPushSwtStsNotPressed', 1: 'MenuPushSwtStsPressed', 2: 'MenuPushSwtStsReserved', 3: 'MenuPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'menupushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::MenupushswtstsType Scmsts7b::menupushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Scmsts7b::MenupushswtstsType ret =  static_cast<Scmsts7b::MenupushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'SWCFailStsNormal', 1: 'SWCFailStsFail', 2: 'SWCFailStsReserved', 3: 'SWCFailStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'swcfailsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::SwcfailstsType Scmsts7b::swcfailsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Scmsts7b::SwcfailstsType ret =  static_cast<Scmsts7b::SwcfailstsType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'AccSpdDecSwtStsNotPressed', 1: 'AccSpdDecSwtStsPressed', 2: 'AccSpdDecSwtStsReserved', 3: 'AccSpdDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'accspddecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::AccspddecswtstsType Scmsts7b::accspddecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 2);

  Scmsts7b::AccspddecswtstsType ret =  static_cast<Scmsts7b::AccspddecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'scmcrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Scmsts7b::scmcrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 61, 'enum': {0: 'MenuLePushSwtStsNotPressed', 1: 'MenuLePushSwtStsPressed', 2: 'MenuLePushSwtStsReserved', 3: 'MenuLePushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'menulepushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::MenulepushswtstsType Scmsts7b::menulepushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  Scmsts7b::MenulepushswtstsType ret =  static_cast<Scmsts7b::MenulepushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 51, 'enum': {0: 'MenuOrVolUpPushSwtStsNotPressed', 1: 'MenuOrVolUpPushSwtStsPressed', 2: 'MenuOrVolUpPushSwtStsReserved', 3: 'MenuOrVolUpPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'menuorvoluppushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::MenuorvoluppushswtstsType Scmsts7b::menuorvoluppushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 2);

  Scmsts7b::MenuorvoluppushswtstsType ret =  static_cast<Scmsts7b::MenuorvoluppushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'scmmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Scmsts7b::scmmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 53, 'enum': {0: 'AccTimeGapDecSwtStsNotPressed', 1: 'AccTimeGapDecSwtStsPressed', 2: 'AccTimeGapDecSwtStsReserved', 3: 'AccTimeGapDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'acctimegapdecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::AcctimegapdecswtstsType Scmsts7b::acctimegapdecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  Scmsts7b::AcctimegapdecswtstsType ret =  static_cast<Scmsts7b::AcctimegapdecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 49, 'enum': {0: 'MenuRiPushSwtStsNotPressed', 1: 'MenuRiPushSwtStsPressed', 2: 'MenuRiPushSwtStsReserved', 3: 'MenuRiPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'menuripushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::MenuripushswtstsType Scmsts7b::menuripushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 2);

  Scmsts7b::MenuripushswtstsType ret =  static_cast<Scmsts7b::MenuripushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'AccSetSwtStsNotPressed', 1: 'AccSetSwtStsPressed', 2: 'AccSetSwtStsReserved', 3: 'AccSetSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'accsetswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts7b::AccsetswtstsType Scmsts7b::accsetswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  Scmsts7b::AccsetswtstsType ret =  static_cast<Scmsts7b::AccsetswtstsType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
