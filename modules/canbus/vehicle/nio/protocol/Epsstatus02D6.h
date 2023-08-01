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

  // config detail: {'bit': 61, 'enum': {0: 'EpsTqreqavlNotAvailable', 1: 'EpsTqreqavlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'EpsTqreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpstqreqavlType epstqreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 60, 'enum': {0: 'EpsPinionangreqavlNotAvailable', 1: 'EpsPinionangreqavlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'EpsPinionangreqavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpspinionangreqavlType epspinionangreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 10, 'name': 'EpsEstrackforce', 'offset': -20.48, 'order': 'motorola', 'physical_range': '[-20.48|20.44]', 'physical_unit': 'KN', 'precision': 0.04, 'type': 'Float64'}
  Float64 epsestrackforce(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'EpsHandsoffdetnconfidenceHandsOn', 1: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel1', 2: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel2', 3: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel3', 4: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel4', 5: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel5', 6: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel6', 7: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel7', 8: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel8', 9: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel9', 10: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel10', 11: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel11', 12: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel12', 13: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel13', 14: 'EpsHandsoffdetnconfidenceHandsOffConfidenceLevel14', 15: 'EpsHandsoffdetnconfidenceSignalNotAvalible'}, 'is_signed_var': False, 'len': 4, 'name': 'EpsHandsoffdetnconfidence', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpshandsoffdetnconfidenceType epshandsoffdetnconfidence(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Eps02Msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 eps02msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'EpsPinionagvalidValid', 1: 'EpsPinionagvalidInvalid', 2: 'EpsPinionagvalidSignalNotAvailable', 3: 'EpsPinionagvalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'EpsPinionagvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpspinionagvalidType epspinionagvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'EpsDrvoverridedetnOverrideDetected', 1: 'EpsDrvoverridedetnOverrideNotDetected', 2: 'EpsDrvoverridedetnSignalNotAvailable', 3: 'EpsDrvoverridedetnNoActiveADCRequest'}, 'is_signed_var': False, 'len': 2, 'name': 'EpsDrvoverridedetn', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpsdrvoverridedetnType epsdrvoverridedetn(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Eps02Crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 eps02crc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'EpsMotortq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'Float64'}
  Float64 epsmotortq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'enum': {0: 'EpsMotortqvalidValid', 1: 'EpsMotortqvalidInvalid', 2: 'EpsMotortqvalidSignalNotAvailable', 3: 'EpsMotortqvalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'EpsMotortqvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpsmotortqvalidType epsmotortqvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 15, 'name': 'EpsPinionag', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.2]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'Float64'}
  Float64 epspinionag(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'EpsEstrackforcevalidValid', 1: 'EpsEstrackforcevalidInvalid', 2: 'EpsEstrackforcevalidSignalNotAvailable', 3: 'EpsEstrackforcevalidReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'EpsEstrackforcevalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus02d6::EpsestrackforcevalidType epsestrackforcevalid(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


