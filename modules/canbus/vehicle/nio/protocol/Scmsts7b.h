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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace nio {

class Scmsts7b : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Scmsts7b();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 41, 'enum': {0: 'SCMFailStsNormal', 1: 'SCMFailStsFail', 2: 'SCMFailStsReserved', 3: 'SCMFailStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SCMFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::ScmfailstsType scmfailsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HiLowBeamPushSwtStsNoCommandDefaultPosition', 1: 'HiLowBeamPushSwtStsFlashCommand', 2: 'HiLowBeamPushSwtStsLowBeamOrHighBeamCommand', 3: 'HiLowBeamPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'HiLowBeamPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::HilowbeampushswtstsType hilowbeampushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'FrntWiprSwtStsFrontWiperOff', 1: 'FrntWiprSwtStsFrontWiperLowSpeed', 2: 'FrntWiprSwtStsFrontWiperHighSpeed', 3: 'FrntWiprSwtStsFrontWiperIntermediateSpeed', 4: 'FrntWiprSwtStsFrontWiperWipeOneTime', 5: 'FrntWiprSwtStsReserved5', 6: 'FrntWiprSwtStsReserved6', 7: 'FrntWiprSwtStsInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::FrntwiprswtstsType frntwiprswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'TurnIndcrSwtStsNoTurnIndicator', 1: 'TurnIndcrSwtStsTurnIndicatorLeft', 2: 'TurnIndcrSwtStsTurnIndicatorRight', 3: 'TurnIndcrSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnIndcrSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::TurnindcrswtstsType turnindcrswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'enum': {0: 'FogLiPushSwtStsPushSwitchNotPressed', 1: 'FogLiPushSwtStsPushSwitchPressed', 2: 'FogLiPushSwtStsReserved', 3: 'FogLiPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'FogLiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::FoglipushswtstsType foglipushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'FrntWiprInterSpdReserved', 1: 'FrntWiprInterSpdIntermediateSpeed1', 2: 'FrntWiprInterSpdIntermediateSpeed2', 3: 'FrntWiprInterSpdIntermediateSpeed3', 4: 'FrntWiprInterSpdIntermediateSpeed4', 5: 'FrntWiprInterSpdReserved5', 6: 'FrntWiprInterSpdReserved6', 7: 'FrntWiprInterSpdInvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprInterSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::FrntwiprinterspdType frntwiprinterspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'enum': {0: 'MenuOrVolDwnPushSwtStsNotPressed', 1: 'MenuOrVolDwnPushSwtStsPressed', 2: 'MenuOrVolDwnPushSwtStsReserved', 3: 'MenuOrVolDwnPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolDwnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::MenuorvoldwnpushswtstsType menuorvoldwnpushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'enum': {0: 'AccSpdIncOrResuSwtStsNotPressed', 1: 'AccSpdIncOrResuSwtStsPressed', 2: 'AccSpdIncOrResuSwtStsReserved', 3: 'AccSpdIncOrResuSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdIncOrResuSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::AccspdincorresuswtstsType accspdincorresuswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'enum': {0: 'AccTimeGapIncSwtStsNotPressed', 1: 'AccTimeGapIncSwtStsPressed', 2: 'AccTimeGapIncSwtStsReserved', 3: 'AccTimeGapIncSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::AcctimegapincswtstsType acctimegapincswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'enum': {0: 'SelnPushSwtStsNotPressed', 1: 'SelnPushSwtStsPressed', 2: 'SelnPushSwtStsReserved', 3: 'SelnPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SelnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::SelnpushswtstsType selnpushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'enum': {0: 'ModeTogDecSwtStsNotPressed', 1: 'ModeTogDecSwtStsPressed', 2: 'ModeTogDecSwtStsReserved', 3: 'ModeTogDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::ModetogdecswtstsType modetogdecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 44, 'enum': {0: 'ModeTogIncSwtStsNotPressed', 1: 'ModeTogIncSwtStsPressed', 2: 'ModeTogIncSwtStsReserved', 3: 'ModeTogIncSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::ModetogincswtstsType modetogincswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'MenuPushSwtStsNotPressed', 1: 'MenuPushSwtStsPressed', 2: 'MenuPushSwtStsReserved', 3: 'MenuPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::MenupushswtstsType menupushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'SWCFailStsNormal', 1: 'SWCFailStsFail', 2: 'SWCFailStsReserved', 3: 'SWCFailStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SWCFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::SwcfailstsType swcfailsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'enum': {0: 'AccSpdDecSwtStsNotPressed', 1: 'AccSpdDecSwtStsPressed', 2: 'AccSpdDecSwtStsReserved', 3: 'AccSpdDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::AccspddecswtstsType accspddecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'ScmCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 scmcrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'enum': {0: 'MenuLePushSwtStsNotPressed', 1: 'MenuLePushSwtStsPressed', 2: 'MenuLePushSwtStsReserved', 3: 'MenuLePushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuLePushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::MenulepushswtstsType menulepushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 51, 'enum': {0: 'MenuOrVolUpPushSwtStsNotPressed', 1: 'MenuOrVolUpPushSwtStsPressed', 2: 'MenuOrVolUpPushSwtStsReserved', 3: 'MenuOrVolUpPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolUpPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::MenuorvoluppushswtstsType menuorvoluppushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'ScmMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 scmmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'enum': {0: 'AccTimeGapDecSwtStsNotPressed', 1: 'AccTimeGapDecSwtStsPressed', 2: 'AccTimeGapDecSwtStsReserved', 3: 'AccTimeGapDecSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::AcctimegapdecswtstsType acctimegapdecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 49, 'enum': {0: 'MenuRiPushSwtStsNotPressed', 1: 'MenuRiPushSwtStsPressed', 2: 'MenuRiPushSwtStsReserved', 3: 'MenuRiPushSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuRiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::MenuripushswtstsType menuripushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'enum': {0: 'AccSetSwtStsNotPressed', 1: 'AccSetSwtStsPressed', 2: 'AccSetSwtStsReserved', 3: 'AccSetSwtStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSetSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts7b::AccsetswtstsType accsetswtsts(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


