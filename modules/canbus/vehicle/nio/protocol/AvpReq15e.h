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

class Avpreq15e : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Avpreq15e();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 39, 'enum': {0: 'AvpApaparkmodoff', 1: 'AvpApaparkmodSapa', 2: 'AvpApaparkmodVpps', 3: 'AvpApaparkmodNBS', 4: 'AvpApaparkmodDescriptionForTheValue0x4', 5: 'AvpApaparkmodDescriptionForTheValue0x5', 6: 'AvpApaparkmodDescriptionForTheValue0x6', 7: 'AvpApaparkmodDescriptionForTheValue0x7'}, 'is_signed_var': False, 'len': 3, 'name': 'AvpApaparkmod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpapaparkmodType avpapaparkmod(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'AvpNbsstsNBSOff', 1: 'AvpNbsstsNBSInitial', 2: 'AvpNbsstsNBSStandby', 3: 'AvpNbsstsNBSMoving', 4: 'AvpNbsstsNBSAbort', 5: 'AvpNbsstsNBSFail', 6: 'AvpNbsstsDescriptionForTheValue0x6', 7: 'AvpNbsstsDescriptionForTheValue0x7'}, 'is_signed_var': False, 'len': 3, 'name': 'AvpNbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpnbsstsType avpnbssts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'AvpAdcvcunbsstsNBSOFF', 1: 'AvpAdcvcunbsstsNBSIntial', 2: 'AvpAdcvcunbsstsNBSStandby', 3: 'AvpAdcvcunbsstsNBSMoving', 4: 'AvpAdcvcunbsstsNBSAbort', 5: 'AvpAdcvcunbsstsNBSFail', 6: 'AvpAdcvcunbsstsDescriptionForTheValue0x6', 7: 'AvpAdcvcunbsstsDescriptionForTheValue0x7', 8: 'AvpAdcvcunbsstsDescriptionForTheValue0x8', 9: 'AvpAdcvcunbsstsDescriptionForTheValue0x9', 10: 'AvpAdcvcunbsstsDescriptionForTheValue0xA', 11: 'AvpAdcvcunbsstsDescriptionForTheValue0xB', 12: 'AvpAdcvcunbsstsDescriptionForTheValue0xC', 13: 'AvpAdcvcunbsstsDescriptionForTheValue0xD', 14: 'AvpAdcvcunbsstsDescriptionForTheValue0xE', 15: 'AvpAdcvcunbsstsDescriptionForTheValue0xF'}, 'is_signed_var': False, 'len': 4, 'name': 'AvpAdcvcunbssts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpadcvcunbsstsType avpadcvcunbssts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'AvpApastsinitial', 1: 'AvpApastsStandby', 2: 'AvpApastsSearch', 3: 'AvpApastsPreGuidence', 4: 'AvpApastsGuidance', 5: 'AvpApastsReserved', 6: 'AvpApastsAbort', 7: 'AvpApastsFault', 8: 'AvpApastsPubRoad', 9: 'AvpApastsOffMode', 10: 'AvpApastsReserved10', 11: 'AvpApastsReserved11', 12: 'AvpApastsReserved12', 13: 'AvpApastsReserved13', 14: 'AvpApastsReserved14', 15: 'AvpApastsReserved15'}, 'is_signed_var': False, 'len': 4, 'name': 'AvpApasts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpapastsType avpapasts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AvpBrkmodstsNoBrake', 1: 'AvpBrkmodstsComfort', 2: 'AvpBrkmodstsEmergency', 3: 'AvpBrkmodstsReserved'}, 'is_signed_var': False, 'len': 3, 'name': 'AvpBrkmodsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpbrkmodstsType avpbrkmodsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'AvpSpdlmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
  double avpspdlmt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'AvpGearreqactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool avpgearreqactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AvpMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t avpmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AvpCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t avpcrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'AvpDstreq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int32_t'}
  int32_t avpdstreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'enum': {0: 'AvpTargearreqNoGearRequest', 1: 'AvpTargearreqD', 2: 'AvpTargearreqR', 3: 'AvpTargearreqN', 4: 'AvpTargearreqP'}, 'is_signed_var': False, 'len': 3, 'name': 'AvpTargearreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvptargearreqType avptargearreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'enum': {0: 'AvpCrtlmodeNo', 1: 'AvpCrtlmodeDistCrtl', 2: 'AvpCrtlmodeSpdCrtl', 3: 'AvpCrtlmodeRes'}, 'is_signed_var': False, 'len': 4, 'name': 'AvpCrtlmode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e::AvpcrtlmodeType avpcrtlmode(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


