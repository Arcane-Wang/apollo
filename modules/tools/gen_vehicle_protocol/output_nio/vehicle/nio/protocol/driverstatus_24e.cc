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

#include "modules/canbus/vehicle/nio/protocol/driverstatus_24e.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Driverstatus24e::Driverstatus24e() {}
const int32_t Driverstatus24e::ID = 0x24e;

void Driverstatus24e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasDriverstatus24e() ) {
           chassis->Builder().getNio().initDriverstatus24e();
        }
    }
  chassis->Builder().getNio().getdriverstatus_24e().setEPBsts(EPBsts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setVCUAccrPedlOvrd(VCUAccrPedlOvrd(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setiBESP2_Warning(iBESP2_Warning(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setAirbWarnReq(AirbWarnReq(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setDriverSts_MsgCntr(DriverSts_MsgCntr(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatBltMidRowRiSts(SeatBltMidRowRiSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatBltMidRowMidSts(SeatBltMidRowMidSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatBltFrntLeSts(SeatBltFrntLeSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setPassAirbgInhbnLampReq(PassAirbgInhbnLampReq(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatOccptFrntRiSts(SeatOccptFrntRiSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setCrashDetd(CrashDetd(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatBltFrntRiSts(SeatBltFrntRiSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setDriverSts_CRC(DriverSts_CRC(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setSeatBltMidRowLeSts(SeatBltMidRowLeSts(bytes, length));
  chassis->Builder().getNio().getdriverstatus_24e().setBMSSOC(BMSSOC(bytes, length));
}

// config detail: {'bit': 10, 'enum': {0: 'EPBSTS_UNKNOW', 1: 'EPBSTS_APPLIED', 2: 'EPBSTS_RELEASING', 3: 'EPBSTS_NOT_APPLIED', 4: 'EPBSTS_APPLYING', 5: 'EPBSTS_RESERVED4', 6: 'EPBSTS_RESERVED6', 7: 'EPBSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'EPBsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::EPBstsType Driverstatus24e::EPBsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 3);

  ::atlas_messages::driverstatus_24e::EPBstsType ret =  static_cast<::atlas_messages::driverstatus_24e::EPBstsType>(x);
  return ret;
}

// config detail: {'bit': 29, 'enum': {0: 'VCUACCRPEDLOVRD_NO_REQUEST', 1: 'VCUACCRPEDLOVRD_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'VCUAccrPedlOvrd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::VCUAccrPedlOvrdType Driverstatus24e::VCUAccrPedlOvrd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::driverstatus_24e::VCUAccrPedlOvrdType ret =  static_cast<::atlas_messages::driverstatus_24e::VCUAccrPedlOvrdType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'IBESP2_WARNING_IBOOSTER_SYSTEM_OK', 1: 'IBESP2_WARNING_IBOOSTER_IN_REDUCED_PERFORMANCE_YELLOW_LAMP', 2: 'IBESP2_WARNING_IBOOSTER_DEACTIVATED_YELLOW_LAMP', 3: 'IBESP2_WARNING_IBOOSTER_IN_DIAGNOSIS_OR_PLANT_MODE'}, 'is_signed_var': False, 'len': 2, 'name': 'iBESP2_Warning', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::iBESP2_WarningType Driverstatus24e::iBESP2_Warning(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  ::atlas_messages::driverstatus_24e::iBESP2_WarningType ret =  static_cast<::atlas_messages::driverstatus_24e::iBESP2_WarningType>(x);
  return ret;
}

// config detail: {'bit': 26, 'enum': {0: 'AIRBWARNREQ_WARNING_LAMP_OFF', 1: 'AIRBWARNREQ_WARNING_LAMP_ON_FAULT_DETECTED', 2: 'AIRBWARNREQ_WARNING_LAMP_IS_BLINKING', 3: 'AIRBWARNREQ_WARNING_LAMP_ON_SYSTEM_INITIALIZATION'}, 'is_signed_var': False, 'len': 2, 'name': 'AirbWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::AirbWarnReqType Driverstatus24e::AirbWarnReq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::driverstatus_24e::AirbWarnReqType ret =  static_cast<::atlas_messages::driverstatus_24e::AirbWarnReqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'DriverSts_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Driverstatus24e::DriverSts_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'SEATBLTMIDROWRISTS_SEABELT_MIDDLE_ROW_RIGHT_NOT_BUCKLED', 1: 'SEATBLTMIDROWRISTS_SEATBELT_MIDDLE_ROW_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatBltMidRowRiStsType Driverstatus24e::SeatBltMidRowRiSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::driverstatus_24e::SeatBltMidRowRiStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatBltMidRowRiStsType>(x);
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'SEATBLTMIDROWMIDSTS_SEABELT_MIDDLE_ROW_MIDDLE_NOT_BUCKLED', 1: 'SEATBLTMIDROWMIDSTS_SEATBELT_MIDDLE_ROW_MIDDLE_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowMidSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatBltMidRowMidStsType Driverstatus24e::SeatBltMidRowMidSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  ::atlas_messages::driverstatus_24e::SeatBltMidRowMidStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatBltMidRowMidStsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'SEATBLTFRNTLESTS_SEABELT_FRONT_LEFT_NOT_BUCKLED', 1: 'SEATBLTFRNTLESTS_SEATBELT_FRONT_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatBltFrntLeStsType Driverstatus24e::SeatBltFrntLeSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::driverstatus_24e::SeatBltFrntLeStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatBltFrntLeStsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_OFF', 1: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON', 2: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON_SYSTEM_INITIALIZATION', 3: 'PASSAIRBGINHBNLAMPREQ_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PassAirbgInhbnLampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::PassAirbgInhbnLampReqType Driverstatus24e::PassAirbgInhbnLampReq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::driverstatus_24e::PassAirbgInhbnLampReqType ret =  static_cast<::atlas_messages::driverstatus_24e::PassAirbgInhbnLampReqType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'SEATOCCPTFRNTRISTS_NO_OCCUPANT', 1: 'SEATOCCPTFRNTRISTS_OCCUPANT'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatOccptFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatOccptFrntRiStsType Driverstatus24e::SeatOccptFrntRiSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::driverstatus_24e::SeatOccptFrntRiStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatOccptFrntRiStsType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'CRASHDETD_CRASH_NOT_DETECTED', 1: 'CRASHDETD_CRASH_DETECTED'}, 'is_signed_var': False, 'len': 1, 'name': 'CrashDetd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::CrashDetdType Driverstatus24e::CrashDetd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::driverstatus_24e::CrashDetdType ret =  static_cast<::atlas_messages::driverstatus_24e::CrashDetdType>(x);
  return ret;
}

// config detail: {'bit': 22, 'enum': {0: 'SEATBLTFRNTRISTS_SEABELT_FRONT_RIGHT_NOT_BUCKLED', 1: 'SEATBLTFRNTRISTS_SEATBELT_FRONT_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatBltFrntRiStsType Driverstatus24e::SeatBltFrntRiSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 1);

  ::atlas_messages::driverstatus_24e::SeatBltFrntRiStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatBltFrntRiStsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'DriverSts_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Driverstatus24e::DriverSts_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}

// config detail: {'bit': 21, 'enum': {0: 'SEATBLTMIDROWLESTS_SEABELT_MIDDLE_ROW_LEFT_NOT_BUCKLED', 1: 'SEATBLTMIDROWLESTS_SEATBELT_MIDDLE_ROW_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::driverstatus_24e::SeatBltMidRowLeStsType Driverstatus24e::SeatBltMidRowLeSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::driverstatus_24e::SeatBltMidRowLeStsType ret =  static_cast<::atlas_messages::driverstatus_24e::SeatBltMidRowLeStsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'BMSSOC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 0.5, 'type': 'double'}
 Driverstatus24e::BMSSOC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

   ret = x * 0.500000;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
