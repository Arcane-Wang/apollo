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

#include "modules/canbus/vehicle/nio/protocol/bodystatus_24d.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Bodystatus24d::Bodystatus24d() {}
const int32_t Bodystatus24d::ID = 0x24d;

void Bodystatus24d::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasBodystatus24d() ) {
           chassis->Builder().getNio().initBodystatus24d();
        }
    }
  chassis->Builder().getNio().getbodystatus_24d().setDoorAjarFrntLeSts(DoorAjarFrntLeSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setDoorAjarFrntRiSts(DoorAjarFrntRiSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setDoorAjarReLeSts(DoorAjarReLeSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setBCM_CLOSURE_CRC(BCM_CLOSURE_CRC(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setSeatOccpFrntLeFail(SeatOccpFrntLeFail(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setSteerWhlHeatSts(SteerWhlHeatSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setBCM_CLOSURE_MsgCntr(BCM_CLOSURE_MsgCntr(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setTrAjarSts(TrAjarSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setHoodAjarSts(HoodAjarSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setDoorAjarReRiSts(DoorAjarReRiSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setSeatOccpFrntLeSts(SeatOccpFrntLeSts(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setCooltLvlLowWarnReq(CooltLvlLowWarnReq(bytes, length));
  chassis->Builder().getNio().getbodystatus_24d().setVehSpd(VehSpd(bytes, length));
}

// config detail: {'bit': 25, 'enum': {0: 'DOORAJARFRNTLESTS_OPENED', 1: 'DOORAJARFRNTLESTS_CLOSED', 2: 'DOORAJARFRNTLESTS_RESERVED', 3: 'DOORAJARFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::DoorAjarFrntLeStsType Bodystatus24d::DoorAjarFrntLeSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  ::atlas_messages::bodystatus_24d::DoorAjarFrntLeStsType ret =  static_cast<::atlas_messages::bodystatus_24d::DoorAjarFrntLeStsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'DOORAJARFRNTRISTS_OPENED', 1: 'DOORAJARFRNTRISTS_CLOSED', 2: 'DOORAJARFRNTRISTS_RESERVED', 3: 'DOORAJARFRNTRISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::DoorAjarFrntRiStsType Bodystatus24d::DoorAjarFrntRiSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 2);

  ::atlas_messages::bodystatus_24d::DoorAjarFrntRiStsType ret =  static_cast<::atlas_messages::bodystatus_24d::DoorAjarFrntRiStsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'DOORAJARRELESTS_OPENED', 1: 'DOORAJARRELESTS_CLOSED', 2: 'DOORAJARRELESTS_RESERVED', 3: 'DOORAJARRELESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::DoorAjarReLeStsType Bodystatus24d::DoorAjarReLeSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::bodystatus_24d::DoorAjarReLeStsType ret =  static_cast<::atlas_messages::bodystatus_24d::DoorAjarReLeStsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'BCM_CLOSURE_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Bodystatus24d::BCM_CLOSURE_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'SEATOCCPFRNTLEFAIL_NO_FAILURE', 1: 'SEATOCCPFRNTLEFAIL_FAILURE', 2: 'SEATOCCPFRNTLEFAIL_RESERVED', 3: 'SEATOCCPFRNTLEFAIL_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::SeatOccpFrntLeFailType Bodystatus24d::SeatOccpFrntLeFail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  ::atlas_messages::bodystatus_24d::SeatOccpFrntLeFailType ret =  static_cast<::atlas_messages::bodystatus_24d::SeatOccpFrntLeFailType>(x);
  return ret;
}

// config detail: {'bit': 37, 'enum': {0: 'STEERWHLHEATSTS_HEATER_OFF', 1: 'STEERWHLHEATSTS_HEATER_ON', 2: 'STEERWHLHEATSTS_RESERVED', 3: 'STEERWHLHEATSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SteerWhlHeatSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::SteerWhlHeatStsType Bodystatus24d::SteerWhlHeatSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::bodystatus_24d::SteerWhlHeatStsType ret =  static_cast<::atlas_messages::bodystatus_24d::SteerWhlHeatStsType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'BCM_CLOSURE_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Bodystatus24d::BCM_CLOSURE_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 29, 'enum': {0: 'TRAJARSTS_OPENED', 1: 'TRAJARSTS_CLOSED', 2: 'TRAJARSTS_RESERVED', 3: 'TRAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'TrAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::TrAjarStsType Bodystatus24d::TrAjarSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::bodystatus_24d::TrAjarStsType ret =  static_cast<::atlas_messages::bodystatus_24d::TrAjarStsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HOODAJARSTS_OPENED', 1: 'HOODAJARSTS_CLOSED', 2: 'HOODAJARSTS_RESERVED', 3: 'HOODAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'HoodAjarSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::HoodAjarStsType Bodystatus24d::HoodAjarSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::bodystatus_24d::HoodAjarStsType ret =  static_cast<::atlas_messages::bodystatus_24d::HoodAjarStsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'DOORAJARRERISTS_OPENED', 1: 'DOORAJARRERISTS_CLOSED', 2: 'DOORAJARRERISTS_RESERVED', 3: 'DOORAJARRERISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'DoorAjarReRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::DoorAjarReRiStsType Bodystatus24d::DoorAjarReRiSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::bodystatus_24d::DoorAjarReRiStsType ret =  static_cast<::atlas_messages::bodystatus_24d::DoorAjarReRiStsType>(x);
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'SEATOCCPFRNTLESTS_NO_OCCUPANT', 1: 'SEATOCCPFRNTLESTS_OCCUPANT', 2: 'SEATOCCPFRNTLESTS_RESERVED', 3: 'SEATOCCPFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'SeatOccpFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::SeatOccpFrntLeStsType Bodystatus24d::SeatOccpFrntLeSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::bodystatus_24d::SeatOccpFrntLeStsType ret =  static_cast<::atlas_messages::bodystatus_24d::SeatOccpFrntLeStsType>(x);
  return ret;
}

// config detail: {'bit': 21, 'enum': {0: 'COOLTLVLLOWWARNREQ_NO_REQUEST', 1: 'COOLTLVLLOWWARNREQ_REQUEST', 2: 'COOLTLVLLOWWARNREQ_RESERVED', 3: 'COOLTLVLLOWWARNREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'CooltLvlLowWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bodystatus_24d::CooltLvlLowWarnReqType Bodystatus24d::CooltLvlLowWarnReq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 2);

  ::atlas_messages::bodystatus_24d::CooltLvlLowWarnReqType ret =  static_cast<::atlas_messages::bodystatus_24d::CooltLvlLowWarnReqType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'VehSpd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
 Bodystatus24d::VehSpd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

   ret = x * 0.056250;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
