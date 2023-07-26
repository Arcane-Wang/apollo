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
const int32_t Scmsts7b::ID = 0x7B;

void Scmsts7b::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_scmsts_7b()->set_scmfailsts(scmfailsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_hilowbeampushswtsts(hilowbeampushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_frntwiprswtsts(frntwiprswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_turnindcrswtsts(turnindcrswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_foglipushswtsts(foglipushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_frntwiprinterspd(frntwiprinterspd(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_menuorvoldwnpushswtsts(menuorvoldwnpushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_accspdincorresuswtsts(accspdincorresuswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_acctimegapincswtsts(acctimegapincswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_selnpushswtsts(selnpushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_modetogdecswtsts(modetogdecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_modetogincswtsts(modetogincswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_menupushswtsts(menupushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_swcfailsts(swcfailsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_accspddecswtsts(accspddecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_scm_crc(scm_crc(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_menulepushswtsts(menulepushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_menuorvoluppushswtsts(menuorvoluppushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_scm_msgcntr(scm_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_acctimegapdecswtsts(acctimegapdecswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_menuripushswtsts(menuripushswtsts(bytes, length));
  chassis->mutable_nio()->mutable_scmsts_7b()->set_accsetswtsts(accsetswtsts(bytes, length));
}

// config detail: {'bit': 41, 'enum': {0: 'SCMFAILSTS_NORMAL', 1: 'SCMFAILSTS_FAIL', 2: 'SCMFAILSTS_RESERVED', 3: 'SCMFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'scmfailsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::ScmfailstsType Scmsts7b::scmfailsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  Scmsts_7b::ScmfailstsType ret =  static_cast<Scmsts_7b::ScmfailstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HILOWBEAMPUSHSWTSTS_NO_COMMAND_DEFAULT_POSITION', 1: 'HILOWBEAMPUSHSWTSTS_FLASH_COMMAND', 2: 'HILOWBEAMPUSHSWTSTS_LOW_BEAM_OR_HIGH_BEAM_COMMAND', 3: 'HILOWBEAMPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'hilowbeampushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::HilowbeampushswtstsType Scmsts7b::hilowbeampushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 2);

  Scmsts_7b::HilowbeampushswtstsType ret =  static_cast<Scmsts_7b::HilowbeampushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'FRNTWIPRSWTSTS_FRONT_WIPER_OFF', 1: 'FRNTWIPRSWTSTS_FRONT_WIPER_LOW_SPEED', 2: 'FRNTWIPRSWTSTS_FRONT_WIPER_HIGH_SPEED', 3: 'FRNTWIPRSWTSTS_FRONT_WIPER_INTERMEDIATE_SPEED', 4: 'FRNTWIPRSWTSTS_FRONT_WIPER_WIPE_ONE_TIME', 5: 'FRNTWIPRSWTSTS_RESERVED5', 6: 'FRNTWIPRSWTSTS_RESERVED6', 7: 'FRNTWIPRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::FrntwiprswtstsType Scmsts7b::frntwiprswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  Scmsts_7b::FrntwiprswtstsType ret =  static_cast<Scmsts_7b::FrntwiprswtstsType>(x);
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'TURNINDCRSWTSTS_NO_TURN_INDICATOR', 1: 'TURNINDCRSWTSTS_TURN_INDICATOR_LEFT', 2: 'TURNINDCRSWTSTS_TURN_INDICATOR_RIGHT', 3: 'TURNINDCRSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'turnindcrswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::TurnindcrswtstsType Scmsts7b::turnindcrswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Scmsts_7b::TurnindcrswtstsType ret =  static_cast<Scmsts_7b::TurnindcrswtstsType>(x);
  return ret;
}

// config detail: {'bit': 37, 'enum': {0: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_NOT_PRESSED', 1: 'FOGLIPUSHSWTSTS_PUSH_SWITCH_PRESSED', 2: 'FOGLIPUSHSWTSTS_RESERVED', 3: 'FOGLIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'foglipushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::FoglipushswtstsType Scmsts7b::foglipushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  Scmsts_7b::FoglipushswtstsType ret =  static_cast<Scmsts_7b::FoglipushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'FRNTWIPRINTERSPD_RESERVED', 1: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_1', 2: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_2', 3: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_3', 4: 'FRNTWIPRINTERSPD_INTERMEDIATE_SPEED_4', 5: 'FRNTWIPRINTERSPD_RESERVED5', 6: 'FRNTWIPRINTERSPD_RESERVED6', 7: 'FRNTWIPRINTERSPD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprinterspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::FrntwiprinterspdType Scmsts7b::frntwiprinterspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 3);

  Scmsts_7b::FrntwiprinterspdType ret =  static_cast<Scmsts_7b::FrntwiprinterspdType>(x);
  return ret;
}

// config detail: {'bit': 55, 'enum': {0: 'MENUORVOLDWNPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLDWNPUSHSWTSTS_PRESSED', 2: 'MENUORVOLDWNPUSHSWTSTS_RESERVED', 3: 'MENUORVOLDWNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'menuorvoldwnpushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::MenuorvoldwnpushswtstsType Scmsts7b::menuorvoldwnpushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 2);

  Scmsts_7b::MenuorvoldwnpushswtstsType ret =  static_cast<Scmsts_7b::MenuorvoldwnpushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 59, 'enum': {0: 'ACCSPDINCORRESUSWTSTS_NOT_PRESSED', 1: 'ACCSPDINCORRESUSWTSTS_PRESSED', 2: 'ACCSPDINCORRESUSWTSTS_RESERVED', 3: 'ACCSPDINCORRESUSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'accspdincorresuswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::AccspdincorresuswtstsType Scmsts7b::accspdincorresuswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 2);

  Scmsts_7b::AccspdincorresuswtstsType ret =  static_cast<Scmsts_7b::AccspdincorresuswtstsType>(x);
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'ACCTIMEGAPINCSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPINCSWTSTS_PRESSED', 2: 'ACCTIMEGAPINCSWTSTS_RESERVED', 3: 'ACCTIMEGAPINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'acctimegapincswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::AcctimegapincswtstsType Scmsts7b::acctimegapincswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 2);

  Scmsts_7b::AcctimegapincswtstsType ret =  static_cast<Scmsts_7b::AcctimegapincswtstsType>(x);
  return ret;
}

// config detail: {'bit': 63, 'enum': {0: 'SELNPUSHSWTSTS_NOT_PRESSED', 1: 'SELNPUSHSWTSTS_PRESSED', 2: 'SELNPUSHSWTSTS_RESERVED', 3: 'SELNPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'selnpushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::SelnpushswtstsType Scmsts7b::selnpushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(6, 2);

  Scmsts_7b::SelnpushswtstsType ret =  static_cast<Scmsts_7b::SelnpushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'MODETOGDECSWTSTS_NOT_PRESSED', 1: 'MODETOGDECSWTSTS_PRESSED', 2: 'MODETOGDECSWTSTS_RESERVED', 3: 'MODETOGDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'modetogdecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::ModetogdecswtstsType Scmsts7b::modetogdecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Scmsts_7b::ModetogdecswtstsType ret =  static_cast<Scmsts_7b::ModetogdecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 44, 'enum': {0: 'MODETOGINCSWTSTS_NOT_PRESSED', 1: 'MODETOGINCSWTSTS_PRESSED', 2: 'MODETOGINCSWTSTS_RESERVED', 3: 'MODETOGINCSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'modetogincswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::ModetogincswtstsType Scmsts7b::modetogincswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 2);

  Scmsts_7b::ModetogincswtstsType ret =  static_cast<Scmsts_7b::ModetogincswtstsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'MENUPUSHSWTSTS_NOT_PRESSED', 1: 'MENUPUSHSWTSTS_PRESSED', 2: 'MENUPUSHSWTSTS_RESERVED', 3: 'MENUPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'menupushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::MenupushswtstsType Scmsts7b::menupushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Scmsts_7b::MenupushswtstsType ret =  static_cast<Scmsts_7b::MenupushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 57, 'enum': {0: 'SWCFAILSTS_NORMAL', 1: 'SWCFAILSTS_FAIL', 2: 'SWCFAILSTS_RESERVED', 3: 'SWCFAILSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'swcfailsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::SwcfailstsType Scmsts7b::swcfailsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  Scmsts_7b::SwcfailstsType ret =  static_cast<Scmsts_7b::SwcfailstsType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'ACCSPDDECSWTSTS_NOT_PRESSED', 1: 'ACCSPDDECSWTSTS_PRESSED', 2: 'ACCSPDDECSWTSTS_RESERVED', 3: 'ACCSPDDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'accspddecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::AccspddecswtstsType Scmsts7b::accspddecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 2);

  Scmsts_7b::AccspddecswtstsType ret =  static_cast<Scmsts_7b::AccspddecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'scm_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Scmsts7b::scm_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'enum': {0: 'MENULEPUSHSWTSTS_NOT_PRESSED', 1: 'MENULEPUSHSWTSTS_PRESSED', 2: 'MENULEPUSHSWTSTS_RESERVED', 3: 'MENULEPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'menulepushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::MenulepushswtstsType Scmsts7b::menulepushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  Scmsts_7b::MenulepushswtstsType ret =  static_cast<Scmsts_7b::MenulepushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 51, 'enum': {0: 'MENUORVOLUPPUSHSWTSTS_NOT_PRESSED', 1: 'MENUORVOLUPPUSHSWTSTS_PRESSED', 2: 'MENUORVOLUPPUSHSWTSTS_RESERVED', 3: 'MENUORVOLUPPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'menuorvoluppushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::MenuorvoluppushswtstsType Scmsts7b::menuorvoluppushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 2);

  Scmsts_7b::MenuorvoluppushswtstsType ret =  static_cast<Scmsts_7b::MenuorvoluppushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'scm_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Scmsts7b::scm_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 53, 'enum': {0: 'ACCTIMEGAPDECSWTSTS_NOT_PRESSED', 1: 'ACCTIMEGAPDECSWTSTS_PRESSED', 2: 'ACCTIMEGAPDECSWTSTS_RESERVED', 3: 'ACCTIMEGAPDECSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'acctimegapdecswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::AcctimegapdecswtstsType Scmsts7b::acctimegapdecswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  Scmsts_7b::AcctimegapdecswtstsType ret =  static_cast<Scmsts_7b::AcctimegapdecswtstsType>(x);
  return ret;
}

// config detail: {'bit': 49, 'enum': {0: 'MENURIPUSHSWTSTS_NOT_PRESSED', 1: 'MENURIPUSHSWTSTS_PRESSED', 2: 'MENURIPUSHSWTSTS_RESERVED', 3: 'MENURIPUSHSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'menuripushswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::MenuripushswtstsType Scmsts7b::menuripushswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 2);

  Scmsts_7b::MenuripushswtstsType ret =  static_cast<Scmsts_7b::MenuripushswtstsType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'ACCSETSWTSTS_NOT_PRESSED', 1: 'ACCSETSWTSTS_PRESSED', 2: 'ACCSETSWTSTS_RESERVED', 3: 'ACCSETSWTSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'accsetswtsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scmsts_7b::AccsetswtstsType Scmsts7b::accsetswtsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  Scmsts_7b::AccsetswtstsType ret =  static_cast<Scmsts_7b::AccsetswtstsType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
