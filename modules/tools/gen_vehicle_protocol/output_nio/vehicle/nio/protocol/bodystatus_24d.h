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

class Bodystatus24d : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bodystatus24d();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 25, 'enum': {0: 'DOORAJARFRNTLESTS_OPENED', 1: 'DOORAJARFRNTLESTS_CLOSED', 2: 'DOORAJARFRNTLESTS_RESERVED', 3: 'DOORAJARFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::DoorAjarFrntLeStsType DoorAjarFrntLeSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'DOORAJARFRNTRISTS_OPENED', 1: 'DOORAJARFRNTRISTS_CLOSED', 2: 'DOORAJARFRNTRISTS_RESERVED', 3: 'DOORAJARFRNTRISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::DoorAjarFrntRiStsType DoorAjarFrntRiSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'DOORAJARRELESTS_OPENED', 1: 'DOORAJARRELESTS_CLOSED', 2: 'DOORAJARRELESTS_RESERVED', 3: 'DOORAJARRELESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::DoorAjarReLeStsType DoorAjarReLeSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'BCM_CLOSURE_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   BCM_CLOSURE_CRC(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'SEATOCCPFRNTLEFAIL_NO_FAILURE', 1: 'SEATOCCPFRNTLEFAIL_FAILURE', 2: 'SEATOCCPFRNTLEFAIL_RESERVED', 3: 'SEATOCCPFRNTLEFAIL_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::SeatOccpFrntLeFailType SeatOccpFrntLeFail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'enum': {0: 'STEERWHLHEATSTS_HEATER_OFF', 1: 'STEERWHLHEATSTS_HEATER_ON', 2: 'STEERWHLHEATSTS_RESERVED', 3: 'STEERWHLHEATSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SteerWhlHeatSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::SteerWhlHeatStsType SteerWhlHeatSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'BCM_CLOSURE_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   BCM_CLOSURE_MsgCntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'enum': {0: 'TRAJARSTS_OPENED', 1: 'TRAJARSTS_CLOSED', 2: 'TRAJARSTS_RESERVED', 3: 'TRAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'TrAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::TrAjarStsType TrAjarSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HOODAJARSTS_OPENED', 1: 'HOODAJARSTS_CLOSED', 2: 'HOODAJARSTS_RESERVED', 3: 'HOODAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'HoodAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::HoodAjarStsType HoodAjarSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'DOORAJARRERISTS_OPENED', 1: 'DOORAJARRERISTS_CLOSED', 2: 'DOORAJARRERISTS_RESERVED', 3: 'DOORAJARRERISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::DoorAjarReRiStsType DoorAjarReRiSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'SEATOCCPFRNTLESTS_NO_OCCUPANT', 1: 'SEATOCCPFRNTLESTS_OCCUPANT', 2: 'SEATOCCPFRNTLESTS_RESERVED', 3: 'SEATOCCPFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::SeatOccpFrntLeStsType SeatOccpFrntLeSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'enum': {0: 'COOLTLVLLOWWARNREQ_NO_REQUEST', 1: 'COOLTLVLLOWWARNREQ_REQUEST', 2: 'COOLTLVLLOWWARNREQ_RESERVED', 3: 'COOLTLVLLOWWARNREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'CooltLvlLowWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::bodystatus_24d::CooltLvlLowWarnReqType CooltLvlLowWarnReq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'VehSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
   VehSpd(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


