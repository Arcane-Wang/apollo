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
const int32_t Driverstatus24e::ID = 0x24E;

void Driverstatus24e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_epbsts(epbsts(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_vcuaccrpedlovrd(vcuaccrpedlovrd(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_ibesp2_warning(ibesp2_warning(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_airbwarnreq(airbwarnreq(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_driversts_msgcntr(driversts_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatbltmidrowrists(seatbltmidrowrists(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatbltmidrowmidsts(seatbltmidrowmidsts(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatbltfrntlests(seatbltfrntlests(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_passairbginhbnlampreq(passairbginhbnlampreq(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatoccptfrntrists(seatoccptfrntrists(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_crashdetd(crashdetd(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatbltfrntrists(seatbltfrntrists(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_driversts_crc(driversts_crc(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_seatbltmidrowlests(seatbltmidrowlests(bytes, length));
  chassis->mutable_nio()->mutable_driverstatus_24e()->set_bmssoc(bmssoc(bytes, length));
}

// config detail: {'bit': 10, 'enum': {0: 'EPBSTS_UNKNOW', 1: 'EPBSTS_APPLIED', 2: 'EPBSTS_RELEASING', 3: 'EPBSTS_NOT_APPLIED', 4: 'EPBSTS_APPLYING', 5: 'EPBSTS_RESERVED4', 6: 'EPBSTS_RESERVED6', 7: 'EPBSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'epbsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::EpbstsType Driverstatus24e::epbsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 3);

  Driverstatus_24e::EpbstsType ret =  static_cast<Driverstatus_24e::EpbstsType>(x);
  return ret;
}

// config detail: {'bit': 29, 'enum': {0: 'VCUACCRPEDLOVRD_NO_REQUEST', 1: 'VCUACCRPEDLOVRD_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'vcuaccrpedlovrd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::VcuaccrpedlovrdType Driverstatus24e::vcuaccrpedlovrd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 1);

  Driverstatus_24e::VcuaccrpedlovrdType ret =  static_cast<Driverstatus_24e::VcuaccrpedlovrdType>(x);
  return ret;
}

// config detail: {'bit': 28, 'enum': {0: 'IBESP2_WARNING_IBOOSTER_SYSTEM_OK', 1: 'IBESP2_WARNING_IBOOSTER_IN_REDUCED_PERFORMANCE_YELLOW_LAMP', 2: 'IBESP2_WARNING_IBOOSTER_DEACTIVATED_YELLOW_LAMP', 3: 'IBESP2_WARNING_IBOOSTER_IN_DIAGNOSIS_OR_PLANT_MODE'}, 'is_signed_var': False, 'len': 2, 'name': 'ibesp2_warning', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::Ibesp2_warningType Driverstatus24e::ibesp2_warning(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 2);

  Driverstatus_24e::Ibesp2_warningType ret =  static_cast<Driverstatus_24e::Ibesp2_warningType>(x);
  return ret;
}

// config detail: {'bit': 26, 'enum': {0: 'AIRBWARNREQ_WARNING_LAMP_OFF', 1: 'AIRBWARNREQ_WARNING_LAMP_ON_FAULT_DETECTED', 2: 'AIRBWARNREQ_WARNING_LAMP_IS_BLINKING', 3: 'AIRBWARNREQ_WARNING_LAMP_ON_SYSTEM_INITIALIZATION'}, 'is_signed_var': False, 'len': 2, 'name': 'airbwarnreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::AirbwarnreqType Driverstatus24e::airbwarnreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  Driverstatus_24e::AirbwarnreqType ret =  static_cast<Driverstatus_24e::AirbwarnreqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'driversts_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Driverstatus24e::driversts_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'SEATBLTMIDROWRISTS_SEABELT_MIDDLE_ROW_RIGHT_NOT_BUCKLED', 1: 'SEATBLTMIDROWRISTS_SEATBELT_MIDDLE_ROW_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatbltmidrowristsType Driverstatus24e::seatbltmidrowrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  Driverstatus_24e::SeatbltmidrowristsType ret =  static_cast<Driverstatus_24e::SeatbltmidrowristsType>(x);
  return ret;
}

// config detail: {'bit': 20, 'enum': {0: 'SEATBLTMIDROWMIDSTS_SEABELT_MIDDLE_ROW_MIDDLE_NOT_BUCKLED', 1: 'SEATBLTMIDROWMIDSTS_SEATBELT_MIDDLE_ROW_MIDDLE_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowmidsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatbltmidrowmidstsType Driverstatus24e::seatbltmidrowmidsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Driverstatus_24e::SeatbltmidrowmidstsType ret =  static_cast<Driverstatus_24e::SeatbltmidrowmidstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'SEATBLTFRNTLESTS_SEABELT_FRONT_LEFT_NOT_BUCKLED', 1: 'SEATBLTFRNTLESTS_SEATBELT_FRONT_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltfrntlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatbltfrntlestsType Driverstatus24e::seatbltfrntlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Driverstatus_24e::SeatbltfrntlestsType ret =  static_cast<Driverstatus_24e::SeatbltfrntlestsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_OFF', 1: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON', 2: 'PASSAIRBGINHBNLAMPREQ_PASSENGER_AIRBAG_INHIBITION_LAMP_ON_SYSTEM_INITIALIZATION', 3: 'PASSAIRBGINHBNLAMPREQ_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'passairbginhbnlampreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::PassairbginhbnlampreqType Driverstatus24e::passairbginhbnlampreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Driverstatus_24e::PassairbginhbnlampreqType ret =  static_cast<Driverstatus_24e::PassairbginhbnlampreqType>(x);
  return ret;
}

// config detail: {'bit': 18, 'enum': {0: 'SEATOCCPTFRNTRISTS_NO_OCCUPANT', 1: 'SEATOCCPTFRNTRISTS_OCCUPANT'}, 'is_signed_var': False, 'len': 1, 'name': 'seatoccptfrntrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatoccptfrntristsType Driverstatus24e::seatoccptfrntrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  Driverstatus_24e::SeatoccptfrntristsType ret =  static_cast<Driverstatus_24e::SeatoccptfrntristsType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'CRASHDETD_CRASH_NOT_DETECTED', 1: 'CRASHDETD_CRASH_DETECTED'}, 'is_signed_var': False, 'len': 1, 'name': 'crashdetd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::CrashdetdType Driverstatus24e::crashdetd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Driverstatus_24e::CrashdetdType ret =  static_cast<Driverstatus_24e::CrashdetdType>(x);
  return ret;
}

// config detail: {'bit': 22, 'enum': {0: 'SEATBLTFRNTRISTS_SEABELT_FRONT_RIGHT_NOT_BUCKLED', 1: 'SEATBLTFRNTRISTS_SEATBELT_FRONT_RIGHT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltfrntrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatbltfrntristsType Driverstatus24e::seatbltfrntrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 1);

  Driverstatus_24e::SeatbltfrntristsType ret =  static_cast<Driverstatus_24e::SeatbltfrntristsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'driversts_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Driverstatus24e::driversts_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 21, 'enum': {0: 'SEATBLTMIDROWLESTS_SEABELT_MIDDLE_ROW_LEFT_NOT_BUCKLED', 1: 'SEATBLTMIDROWLESTS_SEATBELT_MIDDLE_ROW_LEFT_BUCKLED'}, 'is_signed_var': False, 'len': 1, 'name': 'seatbltmidrowlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Driverstatus_24e::SeatbltmidrowlestsType Driverstatus24e::seatbltmidrowlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  Driverstatus_24e::SeatbltmidrowlestsType ret =  static_cast<Driverstatus_24e::SeatbltmidrowlestsType>(x);
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
