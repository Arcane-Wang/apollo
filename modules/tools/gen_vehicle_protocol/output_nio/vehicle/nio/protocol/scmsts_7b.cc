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

#include "modules/canbus/vehicle/nio/protocol/scmsts_7b.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Scmsts7b::Scmsts7b() {}
const int32_t Scmsts7b::ID = 0x7b;

void Scmsts7b::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasScmsts7b() ) {
           chassis->Builder().getNio().initScmsts7b();
        }
    }
  chassis->Builder().getNio().getscmsts_7b().setSCMFailSts(SCMFailSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setHiLowBeamPushSwtSts(HiLowBeamPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setFrntWiprSwtSts(FrntWiprSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setTurnIndcrSwtSts(TurnIndcrSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setFogLiPushSwtSts(FogLiPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setFrntWiprInterSpd(FrntWiprInterSpd(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setMenuOrVolDwnPushSwtSts(MenuOrVolDwnPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setAccSpdIncOrResuSwtSts(AccSpdIncOrResuSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setAccTimeGapIncSwtSts(AccTimeGapIncSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setSelnPushSwtSts(SelnPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setModeTogDecSwtSts(ModeTogDecSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setModeTogIncSwtSts(ModeTogIncSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setMenuPushSwtSts(MenuPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setSWCFailSts(SWCFailSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setAccSpdDecSwtSts(AccSpdDecSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setSCM_CRC(SCM_CRC(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setMenuLePushSwtSts(MenuLePushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setMenuOrVolUpPushSwtSts(MenuOrVolUpPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setSCM_MsgCntr(SCM_MsgCntr(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setAccTimeGapDecSwtSts(AccTimeGapDecSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setMenuRiPushSwtSts(MenuRiPushSwtSts(bytes, length));
  chassis->Builder().getNio().getscmsts_7b().setAccSetSwtSts(AccSetSwtSts(bytes, length));
}

// config detail: {'bit': 41, 'enum': {0: 'SCMFAILSTS_NORMAL', 1: 'SCMFAILSTS_FAIL', 2: 'SCMFAILSTS_RESERVED', 3: 'SCMFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SCMFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::SCMFailStsType Scmsts7b::SCMFailSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::scmsts_7b::SCMFailStsType ret =  static_cast<::atlas_messages::scmsts_7b::SCMFailStsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HILOWBEAMPUSHSWTSTS_NO_COMMAND_DEFAULT_POSITION', 1: 'HILOWBEAMPUSHSWTSTS_FLASH_COMMAND', 2: 'HILOWBEAMPUSHSWTSTS_LOW_BEAM_OR_HIGH_BEAM_COMMAND', 3: 'HILOWBEAMPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'HiLowBeamPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::HiLowBeamPushSwtStsType Scmsts7b::HiLowBeamPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::scmsts_7b::HiLowBeamPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::HiLowBeamPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'FRNTWIPRSWTSTS_FRONT_WIPER_OFF', 1: 'FRNTWIPRSWTSTS_FRONT_WIPER_LOW_SPEED', 2: 'FRNTWIPRSWTSTS_FRONT_WIPER_HIGH_SPEED', 3: 'FRNTWIPRSWTSTS_FRONT_WIPER_INTERMEDIATE_SPEED', 4: 'FRNTWIPRSWTSTS_FRONT_WIPER_WIPE_ONE_TIME', 5: 'FRNTWIPRSWTSTS_RESERVED5', 6: 'FRNTWIPRSWTSTS_RESERVED6', 7: 'FRNTWIPRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::FrntWiprSwtStsType Scmsts7b::FrntWiprSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  ::atlas_messages::scmsts_7b::FrntWiprSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::FrntWiprSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'TURNINDCRSWTSTS_NO_TURN_INDICATOR', 1: 'TURNINDCRSWTSTS_TURN_INDICATOR_LEFT', 2: 'TURNINDCRSWTSTS_TURN_INDICATOR_RIGHT', 3: 'TURNINDCRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnIndcrSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::TurnIndcrSwtStsType Scmsts7b::TurnIndcrSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::scmsts_7b::TurnIndcrSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::TurnIndcrSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 37, 'enum': {0: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_NOT_PRESSED', 1: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_PRESSED', 2: 'FOGLIPUSHSWTSTS_RESERVED', 3: 'FOGLIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'FogLiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::FogLiPushSwtStsType Scmsts7b::FogLiPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::scmsts_7b::FogLiPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::FogLiPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'FRNTWIPRINTERSPD_RESERVED', 1: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_1', 2: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_2', 3: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_3', 4: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_4', 5: 'FRNTWIPRINTERSPD_RESERVED5', 6: 'FRNTWIPRINTERSPD_RESERVED6', 7: 'FRNTWIPRINTERSPD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprInterSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::FrntWiprInterSpdType Scmsts7b::FrntWiprInterSpd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  ::atlas_messages::scmsts_7b::FrntWiprInterSpdType ret =  static_cast<::atlas_messages::scmsts_7b::FrntWiprInterSpdType>(x);
  return ret;
}

// config detail: {'bit': 55, 'enum': {0: 'MENUORVOLDWNPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLDWNPUSHSWTSTS_PRESSED', 2: 'MENUORVOLDWNPUSHSWTSTS_RESERVED', 3: 'MENUORVOLDWNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolDwnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::MenuOrVolDwnPushSwtStsType Scmsts7b::MenuOrVolDwnPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::scmsts_7b::MenuOrVolDwnPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::MenuOrVolDwnPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 59, 'enum': {0: 'ACCSPDINCORRESUSWTSTS_NOT_PRESSED', 1: 'ACCSPDINCORRESUSWTSTS_PRESSED', 2: 'ACCSPDINCORRESUSWTSTS_RESERVED', 3: 'ACCSPDINCORRESUSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdIncOrResuSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::AccSpdIncOrResuSwtStsType Scmsts7b::AccSpdIncOrResuSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 2);

  ::atlas_messages::scmsts_7b::AccSpdIncOrResuSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::AccSpdIncOrResuSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'ACCTIMEGAPINCSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPINCSWTSTS_PRESSED', 2: 'ACCTIMEGAPINCSWTSTS_RESERVED', 3: 'ACCTIMEGAPINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::AccTimeGapIncSwtStsType Scmsts7b::AccTimeGapIncSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::scmsts_7b::AccTimeGapIncSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::AccTimeGapIncSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 63, 'enum': {0: 'SELNPUSHSWTSTS_NOT_PRESSED', 1: 'SELNPUSHSWTSTS_PRESSED', 2: 'SELNPUSHSWTSTS_RESERVED', 3: 'SELNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SelnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::SelnPushSwtStsType Scmsts7b::SelnPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::scmsts_7b::SelnPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::SelnPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'MODETOGDECSWTSTS_NOT_PRESSED', 1: 'MODETOGDECSWTSTS_PRESSED', 2: 'MODETOGDECSWTSTS_RESERVED', 3: 'MODETOGDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::ModeTogDecSwtStsType Scmsts7b::ModeTogDecSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::scmsts_7b::ModeTogDecSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::ModeTogDecSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 44, 'enum': {0: 'MODETOGINCSWTSTS_NOT_PRESSED', 1: 'MODETOGINCSWTSTS_PRESSED', 2: 'MODETOGINCSWTSTS_RESERVED', 3: 'MODETOGINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::ModeTogIncSwtStsType Scmsts7b::ModeTogIncSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 2);

  ::atlas_messages::scmsts_7b::ModeTogIncSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::ModeTogIncSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'MENUPUSHSWTSTS_NOT_PRESSED', 1: 'MENUPUSHSWTSTS_PRESSED', 2: 'MENUPUSHSWTSTS_RESERVED', 3: 'MENUPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::MenuPushSwtStsType Scmsts7b::MenuPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::scmsts_7b::MenuPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::MenuPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'SWCFAILSTS_NORMAL', 1: 'SWCFAILSTS_FAIL', 2: 'SWCFAILSTS_RESERVED', 3: 'SWCFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SWCFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::SWCFailStsType Scmsts7b::SWCFailSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::scmsts_7b::SWCFailStsType ret =  static_cast<::atlas_messages::scmsts_7b::SWCFailStsType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'ACCSPDDECSWTSTS_NOT_PRESSED', 1: 'ACCSPDDECSWTSTS_PRESSED', 2: 'ACCSPDDECSWTSTS_RESERVED', 3: 'ACCSPDDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::AccSpdDecSwtStsType Scmsts7b::AccSpdDecSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::scmsts_7b::AccSpdDecSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::AccSpdDecSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'SCM_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Scmsts7b::SCM_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 61, 'enum': {0: 'MENULEPUSHSWTSTS_NOT_PRESSED', 1: 'MENULEPUSHSWTSTS_PRESSED', 2: 'MENULEPUSHSWTSTS_RESERVED', 3: 'MENULEPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuLePushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::MenuLePushSwtStsType Scmsts7b::MenuLePushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::scmsts_7b::MenuLePushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::MenuLePushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 51, 'enum': {0: 'MENUORVOLUPPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLUPPUSHSWTSTS_PRESSED', 2: 'MENUORVOLUPPUSHSWTSTS_RESERVED', 3: 'MENUORVOLUPPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolUpPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::MenuOrVolUpPushSwtStsType Scmsts7b::MenuOrVolUpPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 2);

  ::atlas_messages::scmsts_7b::MenuOrVolUpPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::MenuOrVolUpPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'SCM_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Scmsts7b::SCM_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 53, 'enum': {0: 'ACCTIMEGAPDECSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPDECSWTSTS_PRESSED', 2: 'ACCTIMEGAPDECSWTSTS_RESERVED', 3: 'ACCTIMEGAPDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::AccTimeGapDecSwtStsType Scmsts7b::AccTimeGapDecSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::scmsts_7b::AccTimeGapDecSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::AccTimeGapDecSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 49, 'enum': {0: 'MENURIPUSHSWTSTS_NOT_PRESSED', 1: 'MENURIPUSHSWTSTS_PRESSED', 2: 'MENURIPUSHSWTSTS_RESERVED', 3: 'MENURIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuRiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::MenuRiPushSwtStsType Scmsts7b::MenuRiPushSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::scmsts_7b::MenuRiPushSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::MenuRiPushSwtStsType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'ACCSETSWTSTS_NOT_PRESSED', 1: 'ACCSETSWTSTS_PRESSED', 2: 'ACCSETSWTSTS_RESERVED', 3: 'ACCSETSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSetSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::scmsts_7b::AccSetSwtStsType Scmsts7b::AccSetSwtSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  ::atlas_messages::scmsts_7b::AccSetSwtStsType ret =  static_cast<::atlas_messages::scmsts_7b::AccSetSwtStsType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
