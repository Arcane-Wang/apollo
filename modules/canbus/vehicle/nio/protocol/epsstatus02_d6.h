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

class Epsstatus02d6 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsstatus02d6();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 61, 'enum': {0: 'EPS_TQREQAVL_NOT_AVAILABLE', 1: 'EPS_TQREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'EPS_TqReqAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_tqreqavlType eps_tqreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 60, 'enum': {0: 'EPS_PINIONANGREQAVL_NOT_AVAILABLE', 1: 'EPS_PINIONANGREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'EPS_PinionAngReqAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_pinionangreqavlType eps_pinionangreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 10, 'name': 'EPS_EstRackForce', 'offset': -20.48, 'order': 'motorola', 'physical_range': '[-20.48|20.44]', 'physical_unit': 'KN', 'precision': 0.04, 'type': 'double'}
  double eps_estrackforce(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_ON', 1: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL1', 2: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL2', 3: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL3', 4: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL4', 5: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL5', 6: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL6', 7: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL7', 8: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL8', 9: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL9', 10: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL10', 11: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL11', 12: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL12', 13: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL13', 14: 'EPS_HANDSOFFDETNCONFIDENCE_HANDS_OFF_CONFIDENCE_LEVEL14', 15: 'EPS_HANDSOFFDETNCONFIDENCE_SIGNAL_NOT_AVALIBLE'}, 'is_signed_var': False, 'len': 4, 'name': 'EPS_HandsOffDetnConfidence', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_handsoffdetnconfidenceType eps_handsoffdetnconfidence(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_02_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int eps_02_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'EPS_PINIONAGVALID_VALID', 1: 'EPS_PINIONAGVALID_INVALID', 2: 'EPS_PINIONAGVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_PINIONAGVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPS_PinionAgValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_pinionagvalidType eps_pinionagvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'EPS_DRVOVERRIDEDETN_OVERRIDE_DETECTED', 1: 'EPS_DRVOVERRIDEDETN_OVERRIDE_NOT_DETECTED', 2: 'EPS_DRVOVERRIDEDETN_SIGNAL_NOT_AVAILABLE', 3: 'EPS_DRVOVERRIDEDETN_NO_ACTIVE_ADC_REQUEST'}, 'is_signed_var': False, 'len': 2, 'name': 'EPS_DrvOverRideDetn', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_drvoverridedetnType eps_drvoverridedetn(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_02_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int eps_02_crc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'EPS_MotorTq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
  double eps_motortq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'enum': {0: 'EPS_MOTORTQVALID_VALID', 1: 'EPS_MOTORTQVALID_INVALID', 2: 'EPS_MOTORTQVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_MOTORTQVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPS_MotorTqValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_motortqvalidType eps_motortqvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 15, 'name': 'EPS_PinionAg', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.2]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  double eps_pinionag(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'EPS_ESTRACKFORCEVALID_VALID', 1: 'EPS_ESTRACKFORCEVALID_INVALID', 2: 'EPS_ESTRACKFORCEVALID_SIGNAL_NOT_AVAILABLE', 3: 'EPS_ESTRACKFORCEVALID_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPS_EstRackForceValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02_d6::Eps_estrackforcevalidType eps_estrackforcevalid(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


