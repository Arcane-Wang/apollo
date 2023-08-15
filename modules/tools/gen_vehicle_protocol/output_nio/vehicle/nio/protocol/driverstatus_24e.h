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

class Driverstatus24e : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Driverstatus24e();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 10, 'enum': {0: 'EPBSTS_UNKNOW', 1: 'EPBSTS_APPLIED', 2: 'EPBSTS_RELEASING', 3: 'EPBSTS_NOT_APPLIED', 4: 'EPBSTS_APPLYING', 5: 'EPBSTS_RESERVED4', 6: 'EPBSTS_RESERVED6', 7: 'EPBSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'EPBsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::EPBstsType EPBsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'enum': {0: 'VCUACCRPEDLOVRD_NO_REQUEST', 1: 'VCUACCRPEDLOVRD_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'VCUAccrPedlOvrd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::VCUAccrPedlOvrdType VCUAccrPedlOvrd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'enum': {0: 'IBESP2_WARNING_IBOOSTER_SYSTEM_OK', 1: 'IBESP2_WARNING_IBOOSTER_IN_REDUCED_PERFORMANCE_YELLOW_LAMP', 2: 'IBESP2_WARNING_IBOOSTER_DEACTIVATED_YELLOW_LAMP', 3: 'IBESP2_WARNING_IBOOSTER_IN_DIAGNOSIS_OR_PLANT_MODE'}, 'is_signed_var': False, 'len': 2, 'name': 'iBESP2_Warning', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::iBESP2_WarningType iBESP2_Warning(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'enum': {0: 'AIRBWARNREQ_WARNING_LAMP_OFF', 1: 'AIRBWARNREQ_WARNING_LAMP_ON_FAULT_DETECTED', 2: 'AIRBWARNREQ_WARNING_LAMP_IS_BLINKING', 3: 'AIRBWARNREQ_WARNING_LAMP_ON_SYSTEM_INITIALIZATION'}, 'is_signed_var': False, 'len': 2, 'name': 'AirbWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::AirbWarnReqType AirbWarnReq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'DriverSts_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   DriverSts_MsgCntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'SEATBLTMIDROWRISTS_SEABELT_MIDDLE_ROW_RIGHT_NOT_BUCKLED', 1: 'SEATBLTMIDROWRISTS_SEATBELT_MIDDLE_ROW_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatBltMidRowRiStsType SeatBltMidRowRiSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'enum': {0: 'SEATBLTMIDROWMIDSTS_SEABELT_MIDDLE_ROW_MIDDLE_NOT_BUCKLED', 1: 'SEATBLTMIDROWMIDSTS_SEATBELT_MIDDLE_ROW_MIDDLE_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowMidSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatBltMidRowMidStsType SeatBltMidRowMidSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'SEATBLTFRNTLESTS_SEABELT_FRONT_LEFT_NOT_BUCKLED', 1: 'SEATBLTFRNTLESTS_SEATBELT_FRONT_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatBltFrntLeStsType SeatBltFrntLeSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_OFF', 1: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON', 2: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON_SYSTEM_INITIALIZATION', 3: 'PASSAIRBGINHBNLAMPREQ_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PassAirbgInhbnLampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::PassAirbgInhbnLampReqType PassAirbgInhbnLampReq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'SEATOCCPTFRNTRISTS_NO_OCCUPANT', 1: 'SEATOCCPTFRNTRISTS_OCCUPANT'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatOccptFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatOccptFrntRiStsType SeatOccptFrntRiSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'CRASHDETD_CRASH_NOT_DETECTED', 1: 'CRASHDETD_CRASH_DETECTED'}, 'is_signed_var': False, 'len': 1, 'name': 'CrashDetd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::CrashDetdType CrashDetd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 22, 'enum': {0: 'SEATBLTFRNTRISTS_SEABELT_FRONT_RIGHT_NOT_BUCKLED', 1: 'SEATBLTFRNTRISTS_SEATBELT_FRONT_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatBltFrntRiStsType SeatBltFrntRiSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'DriverSts_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
   DriverSts_CRC(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'enum': {0: 'SEATBLTMIDROWLESTS_SEABELT_MIDDLE_ROW_LEFT_NOT_BUCKLED', 1: 'SEATBLTMIDROWLESTS_SEATBELT_MIDDLE_ROW_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  ::atlas_messages::driverstatus_24e::SeatBltMidRowLeStsType SeatBltMidRowLeSts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'BMSSOC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 0.5, 'type': 'double'}
   BMSSOC(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


