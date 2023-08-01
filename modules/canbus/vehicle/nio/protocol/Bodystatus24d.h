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

  // config detail: {'bit': 25, 'enum': {0: 'DoorAjarFrntLeStsOpened', 1: 'DoorAjarFrntLeStsClosed', 2: 'DoorAjarFrntLeStsReserved', 3: 'DoorAjarFrntLeStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::DoorajarfrntlestsType doorajarfrntlests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'DoorAjarFrntRiStsOpened', 1: 'DoorAjarFrntRiStsClosed', 2: 'DoorAjarFrntRiStsReserved', 3: 'DoorAjarFrntRiStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::DoorajarfrntristsType doorajarfrntrists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'DoorAjarReLeStsOpened', 1: 'DoorAjarReLeStsClosed', 2: 'DoorAjarReLeStsReserved', 3: 'DoorAjarReLeStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::DoorajarrelestsType doorajarrelests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'BcmClosureCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 bcmclosurecrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'SeatOccpFrntLeFailNoFailure', 1: 'SeatOccpFrntLeFailFailure', 2: 'SeatOccpFrntLeFailReserved', 3: 'SeatOccpFrntLeFailInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::SeatoccpfrntlefailType seatoccpfrntlefail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'enum': {0: 'SteerWhlHeatStsHeaterOff', 1: 'SteerWhlHeatStsHeaterOn', 2: 'SteerWhlHeatStsReserved', 3: 'SteerWhlHeatStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SteerWhlHeatSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::SteerwhlheatstsType steerwhlheatsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'BcmClosureMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 bcmclosuremsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'enum': {0: 'TrAjarStsOpened', 1: 'TrAjarStsClosed', 2: 'TrAjarStsReserved', 3: 'TrAjarStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'TrAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::TrajarstsType trajarsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HoodAjarStsOpened', 1: 'HoodAjarStsClosed', 2: 'HoodAjarStsReserved', 3: 'HoodAjarStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'HoodAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::HoodajarstsType hoodajarsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'DoorAjarReRiStsOpened', 1: 'DoorAjarReRiStsClosed', 2: 'DoorAjarReRiStsReserved', 3: 'DoorAjarReRiStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::DoorajarreristsType doorajarrerists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'SeatOccpFrntLeStsNoOccupant', 1: 'SeatOccpFrntLeStsOccupant', 2: 'SeatOccpFrntLeStsReserved', 3: 'SeatOccpFrntLeStsInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::SeatoccpfrntlestsType seatoccpfrntlests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'enum': {0: 'CooltLvlLowWarnReqNoRequest', 1: 'CooltLvlLowWarnReqRequest', 2: 'CooltLvlLowWarnReqReserved', 3: 'CooltLvlLowWarnReqInvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'CooltLvlLowWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bodystatus24d::CooltlvllowwarnreqType cooltlvllowwarnreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'VehSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'Float64'}
  Float64 vehspd(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


