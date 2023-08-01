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

class Epsstatus01d5 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsstatus01d5();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 26, 'enum': {0: 'EPSwarnLampoff', 1: 'EPSwarnLampon', 2: 'EPSwarnLampNotAvailable', 3: 'EPSwarnLampreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'EPSwarnLamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::EpswarnlampType epswarnlamp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'AbsAgreqavlNotAvailable', 1: 'AbsAgreqavlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'AbsAgreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::AbsagreqavlType absagreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 10, 'name': 'TorsBarTq', 'offset': -10.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'Float64'}
  Float64 torsbartq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'enum': {0: 'EPSstsinit', 1: 'EPSstsnormal', 2: 'EPSstsDegradedDueToTempOrVol', 3: 'EPSstsTemporaryError', 4: 'EPSstsPermamemtError', 5: 'EPSstsreserved5', 6: 'EPSstsreserved6', 7: 'EPSstsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::EpsstsType epssts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'EPSModNone', 1: 'EPSModPAI', 2: 'EPSModDAI', 3: 'EPSModTOI', 7: 'EPSModinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::EpsmodType epsmod(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'SteeragspddirLeftPlus', 1: 'SteeragspddirRightMinus'}, 'is_signed_var': False, 'len': 1, 'name': 'Steeragspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::SteeragspddirType steeragspddir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'is_signed_var': False, 'len': 9, 'name': 'Steeragspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|2550]', 'physical_unit': 'Deg/sec', 'precision': 5.0, 'type': 'Float64'}
  Float64 steeragspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'enum': {0: 'SteerAngledirLeftPlus', 1: 'SteerAngledirRightMinus'}, 'is_signed_var': False, 'len': 1, 'name': 'SteerAngledir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::SteerangledirType steerangledir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'SteerAngleandspdvalidvalid', 1: 'SteerAngleandspdvalidinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'SteerAngleandspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01d5::SteerangleandspdvalidType steerangleandspdvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 13, 'name': 'SteerAngle', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|800]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'Float64'}
  Float64 steerangle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EpsDMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 epsdmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EpsDCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 epsdcrc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


