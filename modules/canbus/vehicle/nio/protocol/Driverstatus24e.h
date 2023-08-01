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

  // config detail: {'bit': 10, 'enum': {0: 'EPBstsunknow', 1: 'EPBstsapplied', 2: 'EPBstsreleasing', 3: 'EPBstsNotApplied', 4: 'EPBstsapplying', 5: 'EPBstsreserved4', 6: 'EPBstsreserved6', 7: 'EPBstsreserved7'}, 'is_signed_var': False, 'len': 3, 'name': 'EPBsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::EpbstsType epbsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'enum': {0: 'VCUAccrPedlOvrdNoRequest', 1: 'VCUAccrPedlOvrdrequest'}, 'is_signed_var': False, 'len': 1, 'name': 'VCUAccrPedlOvrd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::VcuaccrpedlovrdType vcuaccrpedlovrd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'enum': {0: 'Ibesp2WarningIBoosterSystemOK', 1: 'Ibesp2WarningIBoosterInReducedPerformanceYellowLamp', 2: 'Ibesp2WarningIBoosterDeactivatedYellowLamp', 3: 'Ibesp2WarningIBoosterInDiagnosisOrPlantMode'}, 'is_signed_var': False, 'len': 2, 'name': 'Ibesp2Warning', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::Ibesp2warningType ibesp2warning(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'enum': {0: 'AirbWarnReqWarningLampOff', 1: 'AirbWarnReqWarningLampOnFaultDetected', 2: 'AirbWarnReqWarningLampIsBlinking', 3: 'AirbWarnReqWarningLampOnSystemInitialization'}, 'is_signed_var': False, 'len': 2, 'name': 'AirbWarnReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::AirbwarnreqType airbwarnreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'DriverstsMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 driverstsmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'enum': {0: 'SeatBltMidRowRiStsSeabeltMiddleRowRightNotBuckled', 1: 'SeatBltMidRowRiStsSeatbeltMiddleRowRightBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatbltmidrowristsType seatbltmidrowrists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'enum': {0: 'SeatBltMidRowMidStsSeabeltMiddleRowMiddleNotBuckled', 1: 'SeatBltMidRowMidStsSeatbeltMiddleRowMiddleBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowMidSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatbltmidrowmidstsType seatbltmidrowmidsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'SeatBltFrntLeStsSeabeltFrontLeftNotBuckled', 1: 'SeatBltFrntLeStsSeatbeltFrontLeftBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatbltfrntlestsType seatbltfrntlests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOff', 1: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOn', 2: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOnSystemInitialization', 3: 'PassAirbgInhbnLampReqReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'PassAirbgInhbnLampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::PassairbginhbnlampreqType passairbginhbnlampreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'SeatOccptFrntRiStsNoOccupant', 1: 'SeatOccptFrntRiStsOccupant'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatOccptFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatoccptfrntristsType seatoccptfrntrists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'CrashDetdCrashNotDetected', 1: 'CrashDetdCrashDetected'}, 'is_signed_var': False, 'len': 1, 'name': 'CrashDetd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::CrashdetdType crashdetd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 22, 'enum': {0: 'SeatBltFrntRiStsSeabeltFrontRightNotBuckled', 1: 'SeatBltFrntRiStsSeatbeltFrontRightBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltFrntRiSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatbltfrntristsType seatbltfrntrists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'DriverstsCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 driverstscrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'enum': {0: 'SeatBltMidRowLeStsSeabeltMiddleRowLeftNotBuckled', 1: 'SeatBltMidRowLeStsSeatbeltMiddleRowLeftBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'SeatBltMidRowLeSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Driverstatus24e::SeatbltmidrowlestsType seatbltmidrowlests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'BMSSOC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 0.5, 'type': 'Float64'}
  Float64 bmssoc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


