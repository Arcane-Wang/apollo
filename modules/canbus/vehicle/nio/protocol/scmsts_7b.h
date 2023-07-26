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

  // config detail: {'bit': 41, 'enum': {0: 'SCMFAILSTS_NORMAL', 1: 'SCMFAILSTS_FAIL', 2: 'SCMFAILSTS_RESERVED', 3: 'SCMFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SCMFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::ScmfailstsType scmfailsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HILOWBEAMPUSHSWTSTS_NO_COMMAND_DEFAULT_POSITION', 1: 'HILOWBEAMPUSHSWTSTS_FLASH_COMMAND', 2: 'HILOWBEAMPUSHSWTSTS_LOW_BEAM_OR_HIGH_BEAM_COMMAND', 3: 'HILOWBEAMPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'HiLowBeamPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::HilowbeampushswtstsType hilowbeampushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'FRNTWIPRSWTSTS_FRONT_WIPER_OFF', 1: 'FRNTWIPRSWTSTS_FRONT_WIPER_LOW_SPEED', 2: 'FRNTWIPRSWTSTS_FRONT_WIPER_HIGH_SPEED', 3: 'FRNTWIPRSWTSTS_FRONT_WIPER_INTERMEDIATE_SPEED', 4: 'FRNTWIPRSWTSTS_FRONT_WIPER_WIPE_ONE_TIME', 5: 'FRNTWIPRSWTSTS_RESERVED5', 6: 'FRNTWIPRSWTSTS_RESERVED6', 7: 'FRNTWIPRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::FrntwiprswtstsType frntwiprswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'TURNINDCRSWTSTS_NO_TURN_INDICATOR', 1: 'TURNINDCRSWTSTS_TURN_INDICATOR_LEFT', 2: 'TURNINDCRSWTSTS_TURN_INDICATOR_RIGHT', 3: 'TURNINDCRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnIndcrSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::TurnindcrswtstsType turnindcrswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'enum': {0: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_NOT_PRESSED', 1: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_PRESSED', 2: 'FOGLIPUSHSWTSTS_RESERVED', 3: 'FOGLIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'FogLiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::FoglipushswtstsType foglipushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'FRNTWIPRINTERSPD_RESERVED', 1: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_1', 2: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_2', 3: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_3', 4: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_4', 5: 'FRNTWIPRINTERSPD_RESERVED5', 6: 'FRNTWIPRINTERSPD_RESERVED6', 7: 'FRNTWIPRINTERSPD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'FrntWiprInterSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::FrntwiprinterspdType frntwiprinterspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'enum': {0: 'MENUORVOLDWNPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLDWNPUSHSWTSTS_PRESSED', 2: 'MENUORVOLDWNPUSHSWTSTS_RESERVED', 3: 'MENUORVOLDWNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolDwnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::MenuorvoldwnpushswtstsType menuorvoldwnpushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'enum': {0: 'ACCSPDINCORRESUSWTSTS_NOT_PRESSED', 1: 'ACCSPDINCORRESUSWTSTS_PRESSED', 2: 'ACCSPDINCORRESUSWTSTS_RESERVED', 3: 'ACCSPDINCORRESUSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdIncOrResuSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::AccspdincorresuswtstsType accspdincorresuswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'enum': {0: 'ACCTIMEGAPINCSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPINCSWTSTS_PRESSED', 2: 'ACCTIMEGAPINCSWTSTS_RESERVED', 3: 'ACCTIMEGAPINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::AcctimegapincswtstsType acctimegapincswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'enum': {0: 'SELNPUSHSWTSTS_NOT_PRESSED', 1: 'SELNPUSHSWTSTS_PRESSED', 2: 'SELNPUSHSWTSTS_RESERVED', 3: 'SELNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SelnPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::SelnpushswtstsType selnpushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'enum': {0: 'MODETOGDECSWTSTS_NOT_PRESSED', 1: 'MODETOGDECSWTSTS_PRESSED', 2: 'MODETOGDECSWTSTS_RESERVED', 3: 'MODETOGDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::ModetogdecswtstsType modetogdecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 44, 'enum': {0: 'MODETOGINCSWTSTS_NOT_PRESSED', 1: 'MODETOGINCSWTSTS_PRESSED', 2: 'MODETOGINCSWTSTS_RESERVED', 3: 'MODETOGINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'ModeTogIncSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::ModetogincswtstsType modetogincswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'MENUPUSHSWTSTS_NOT_PRESSED', 1: 'MENUPUSHSWTSTS_PRESSED', 2: 'MENUPUSHSWTSTS_RESERVED', 3: 'MENUPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::MenupushswtstsType menupushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'SWCFAILSTS_NORMAL', 1: 'SWCFAILSTS_FAIL', 2: 'SWCFAILSTS_RESERVED', 3: 'SWCFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SWCFailSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::SwcfailstsType swcfailsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'enum': {0: 'ACCSPDDECSWTSTS_NOT_PRESSED', 1: 'ACCSPDDECSWTSTS_PRESSED', 2: 'ACCSPDDECSWTSTS_RESERVED', 3: 'ACCSPDDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSpdDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::AccspddecswtstsType accspddecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'SCM_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int scm_crc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'enum': {0: 'MENULEPUSHSWTSTS_NOT_PRESSED', 1: 'MENULEPUSHSWTSTS_PRESSED', 2: 'MENULEPUSHSWTSTS_RESERVED', 3: 'MENULEPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuLePushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::MenulepushswtstsType menulepushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 51, 'enum': {0: 'MENUORVOLUPPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLUPPUSHSWTSTS_PRESSED', 2: 'MENUORVOLUPPUSHSWTSTS_RESERVED', 3: 'MENUORVOLUPPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuOrVolUpPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::MenuorvoluppushswtstsType menuorvoluppushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'SCM_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int scm_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'enum': {0: 'ACCTIMEGAPDECSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPDECSWTSTS_PRESSED', 2: 'ACCTIMEGAPDECSWTSTS_RESERVED', 3: 'ACCTIMEGAPDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccTimeGapDecSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::AcctimegapdecswtstsType acctimegapdecswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 49, 'enum': {0: 'MENURIPUSHSWTSTS_NOT_PRESSED', 1: 'MENURIPUSHSWTSTS_PRESSED', 2: 'MENURIPUSHSWTSTS_RESERVED', 3: 'MENURIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'MenuRiPushSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::MenuripushswtstsType menuripushswtsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'enum': {0: 'ACCSETSWTSTS_NOT_PRESSED', 1: 'ACCSETSWTSTS_PRESSED', 2: 'ACCSETSWTSTS_RESERVED', 3: 'ACCSETSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'AccSetSwtSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scmsts_7b::AccsetswtstsType accsetswtsts(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


