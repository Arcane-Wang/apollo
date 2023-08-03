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

#include "modules/canbus/vehicle/nio/protocol/Driverstatus24e.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Driverstatus24e::Driverstatus24e() {}
const int32_t Driverstatus24e::ID = 0x24E;

void Driverstatus24e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_epbsts(epbsts(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_vcuaccrpedlovrd(vcuaccrpedlovrd(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_ibesp2warning(ibesp2warning(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_airbwarnreq(airbwarnreq(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_driverstsmsgcntr(driverstsmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatbltmidrowrists(seatbltmidrowrists(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatbltmidrowmidsts(seatbltmidrowmidsts(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatbltfrntlests(seatbltfrntlests(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_passairbginhbnlampreq(passairbginhbnlampreq(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatoccptfrntrists(seatoccptfrntrists(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_crashdetd(crashdetd(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatbltfrntrists(seatbltfrntrists(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_driverstscrc(driverstscrc(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_seatbltmidrowlests(seatbltmidrowlests(bytes, length));
  chassis->mutable_nio()->mutable_Driverstatus24e()->set_bmssoc(bmssoc(bytes, length));
}

// config detail: {'bit': 10, 'enum': {0: 'EPBstsunknow', 1: 'EPBstsapplied', 2: 'EPBstsreleasing', 3: 'EPBstsNotApplied', 4: 'EPBstsapplying', 5: 'EPBstsreserved4', 6: 'EPBstsreserved6', 7: 'EPBstsreserved7'}, 'is_signed_var': False, 'len': 3, 'name': 'epbsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::EpbstsType Driverstatus24e::epbsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 3);

  Driverstatus24e::EpbstsType ret =  static_cast<Driverstatus24e::EpbstsType>(x);
  return ret;
}

// config detail: {'bit': 29, 'enum': {0: 'VCUAccrPedlOvrdNoRequest', 1: 'VCUAccrPedlOvrdrequest'}, 'is_signed_var': False, 'len': 1, 'name': 'vcuaccrpedlovrd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::VcuaccrpedlovrdType Driverstatus24e::vcuaccrpedlovrd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 1);

  Driverstatus24e::VcuaccrpedlovrdType ret =  static_cast<Driverstatus24e::VcuaccrpedlovrdType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'Ibesp2WarningIBoosterSystemOK', 1: 'Ibesp2WarningIBoosterInReducedPerformanceYellowLamp', 2: 'Ibesp2WarningIBoosterDeactivatedYellowLamp', 3: 'Ibesp2WarningIBoosterInDiagnosisOrPlantMode'}, 'is_signed_var': False, 'len': 2, 'name': 'ibesp2warning', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::Ibesp2warningType Driverstatus24e::ibesp2warning(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  Driverstatus24e::Ibesp2warningType ret =  static_cast<Driverstatus24e::Ibesp2warningType>(x);
  return ret;
}

// config detail: {'bit': 26, 'enum': {0: 'AirbWarnReqWarningLampOff', 1: 'AirbWarnReqWarningLampOnFaultDetected', 2: 'AirbWarnReqWarningLampIsBlinking', 3: 'AirbWarnReqWarningLampOnSystemInitialization'}, 'is_signed_var': False, 'len': 2, 'name': 'airbwarnreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::AirbwarnreqType Driverstatus24e::airbwarnreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  Driverstatus24e::AirbwarnreqType ret =  static_cast<Driverstatus24e::AirbwarnreqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'driverstsmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Driverstatus24e::driverstsmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'SeatBltMidRowRiStsSeabeltMiddleRowRightNotBuckled', 1: 'SeatBltMidRowRiStsSeatbeltMiddleRowRightBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatbltmidrowristsType Driverstatus24e::seatbltmidrowrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  Driverstatus24e::SeatbltmidrowristsType ret =  static_cast<Driverstatus24e::SeatbltmidrowristsType>(x);
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'SeatBltMidRowMidStsSeabeltMiddleRowMiddleNotBuckled', 1: 'SeatBltMidRowMidStsSeatbeltMiddleRowMiddleBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowmidsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatbltmidrowmidstsType Driverstatus24e::seatbltmidrowmidsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Driverstatus24e::SeatbltmidrowmidstsType ret =  static_cast<Driverstatus24e::SeatbltmidrowmidstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'SeatBltFrntLeStsSeabeltFrontLeftNotBuckled', 1: 'SeatBltFrntLeStsSeatbeltFrontLeftBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltfrntlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatbltfrntlestsType Driverstatus24e::seatbltfrntlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Driverstatus24e::SeatbltfrntlestsType ret =  static_cast<Driverstatus24e::SeatbltfrntlestsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOff', 1: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOn', 2: 'PassAirbgInhbnLampReqPassengerAirbagInhibitionLampOnSystemInitialization', 3: 'PassAirbgInhbnLampReqReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'passairbginhbnlampreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::PassairbginhbnlampreqType Driverstatus24e::passairbginhbnlampreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Driverstatus24e::PassairbginhbnlampreqType ret =  static_cast<Driverstatus24e::PassairbginhbnlampreqType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'SeatOccptFrntRiStsNoOccupant', 1: 'SeatOccptFrntRiStsOccupant'}, 'is_signed_var': False, 'len': 1, 'name': 'seatoccptfrntrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatoccptfrntristsType Driverstatus24e::seatoccptfrntrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  Driverstatus24e::SeatoccptfrntristsType ret =  static_cast<Driverstatus24e::SeatoccptfrntristsType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'CrashDetdCrashNotDetected', 1: 'CrashDetdCrashDetected'}, 'is_signed_var': False, 'len': 1, 'name': 'crashdetd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::CrashdetdType Driverstatus24e::crashdetd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Driverstatus24e::CrashdetdType ret =  static_cast<Driverstatus24e::CrashdetdType>(x);
  return ret;
}

// config detail: {'bit': 22, 'enum': {0: 'SeatBltFrntRiStsSeabeltFrontRightNotBuckled', 1: 'SeatBltFrntRiStsSeatbeltFrontRightBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltfrntrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatbltfrntristsType Driverstatus24e::seatbltfrntrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 1);

  Driverstatus24e::SeatbltfrntristsType ret =  static_cast<Driverstatus24e::SeatbltfrntristsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'driverstscrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Driverstatus24e::driverstscrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 21, 'enum': {0: 'SeatBltMidRowLeStsSeabeltMiddleRowLeftNotBuckled', 1: 'SeatBltMidRowLeStsSeatbeltMiddleRowLeftBuckled'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus24e::SeatbltmidrowlestsType Driverstatus24e::seatbltmidrowlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  Driverstatus24e::SeatbltmidrowlestsType ret =  static_cast<Driverstatus24e::SeatbltmidrowlestsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'bmssoc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '', 'precision': 0.5, 'type': 'double'}
double Driverstatus24e::bmssoc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.500000;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
