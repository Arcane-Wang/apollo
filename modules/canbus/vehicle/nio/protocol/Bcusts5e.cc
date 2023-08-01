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

#include "modules/canbus/vehicle/nio/protocol/Bcusts5e.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Bcusts5e::Bcusts5e() {}
const int32_t Bcusts5e::ID = 0x5E;

void Bcusts5e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_Bcusts5e()->set_tcsactv(tcsactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_scmavl(scmavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hfcactv(hfcactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_vdcactv(vdcactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_avhsts(avhsts(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_autobrkgactv(autobrkgactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_vdcdeactv(vdcdeactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_abaactv(abaactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_autobrkgavl(autobrkgavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hbaactv(hbaactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_aebavl(aebavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_aebactv(aebactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_cdpavail(cdpavail(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_abaavl(abaavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hdcsts(hdcsts(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_tcsdeactv(tcsdeactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_awbavl(awbavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_abpavl(abpavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_awbactv(awbactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_ebaavl(ebaavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_qdcaccfail(qdcaccfail(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_abpactv(abpactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_pedpavl(pedpavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_cddsavl(cddsavl(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_standstillsts(standstillsts(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hhcavail(hhcavail(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_absactv(absactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_pedpactv(pedpactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_ebaactv(ebaactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_cdpactv(cdpactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_ebdactv(ebdactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_scmactv(scmactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_dtcactv(dtcactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hrbactv(hrbactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_ecdttempoffs(ecdttempoffs(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_cddsactv(cddsactv(bytes, length));
  chassis->mutable_nio()->mutable_Bcusts5e()->set_hhcactv(hhcactv(bytes, length));
}

// config detail: {'bit': 4, 'enum': {0: 'TCSActvNotActive', 1: 'TCSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'tcsactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::TcsactvType Bcusts5e::tcsactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  Bcusts5e::TcsactvType ret =  static_cast<Bcusts5e::TcsactvType>(x);
  return ret;
}

// config detail: {'bit': 27, 'enum': {0: 'SCMAvlNotAvailable', 1: 'SCMAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'scmavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::ScmavlType Bcusts5e::scmavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  Bcusts5e::ScmavlType ret =  static_cast<Bcusts5e::ScmavlType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'HFCActvNotActive', 1: 'HFCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'hfcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HfcactvType Bcusts5e::hfcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  Bcusts5e::HfcactvType ret =  static_cast<Bcusts5e::HfcactvType>(x);
  return ret;
}

// config detail: {'bit': 6, 'enum': {0: 'VDCActvNotActive', 1: 'VDCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'vdcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::VdcactvType Bcusts5e::vdcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  Bcusts5e::VdcactvType ret =  static_cast<Bcusts5e::VdcactvType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'AVHStsFailureAVHLampOnWithYellowColor', 1: 'AVHStsStandbyAVHLampOff', 2: 'AVHStsActiveAVHLampOnWithGreenColor', 3: 'AVHStsReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'avhsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AvhstsType Bcusts5e::avhsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Bcusts5e::AvhstsType ret =  static_cast<Bcusts5e::AvhstsType>(x);
  return ret;
}

// config detail: {'bit': 41, 'enum': {0: 'AutoBrkgActvNotActive', 1: 'AutoBrkgActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'autobrkgactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AutobrkgactvType Bcusts5e::autobrkgactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 1);

  Bcusts5e::AutobrkgactvType ret =  static_cast<Bcusts5e::AutobrkgactvType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'VDCDeactvNotDeactivated', 1: 'VDCDeactvDeactivated'}, 'is_signed_var': False, 'len': 1, 'name': 'vdcdeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::VdcdeactvType Bcusts5e::vdcdeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  Bcusts5e::VdcdeactvType ret =  static_cast<Bcusts5e::VdcdeactvType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'ABAActvNotActive', 1: 'ABAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'abaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AbaactvType Bcusts5e::abaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Bcusts5e::AbaactvType ret =  static_cast<Bcusts5e::AbaactvType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'AutoBrkgAvlNotAvailable', 1: 'AutoBrkgAvlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'autobrkgavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AutobrkgavlType Bcusts5e::autobrkgavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  Bcusts5e::AutobrkgavlType ret =  static_cast<Bcusts5e::AutobrkgavlType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HBAActvNotActive', 1: 'HBAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'hbaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HbaactvType Bcusts5e::hbaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  Bcusts5e::HbaactvType ret =  static_cast<Bcusts5e::HbaactvType>(x);
  return ret;
}

// config detail: {'bit': 12, 'description': 'Automatic Emergency Braking (AEB) available (Reserved and BCU should send value 0) ', 'enum': {0: 'AEBAvlNotAvailable', 1: 'AEBAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'aebavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AebavlType Bcusts5e::aebavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  Bcusts5e::AebavlType ret =  static_cast<Bcusts5e::AebavlType>(x);
  return ret;
}

// config detail: {'bit': 14, 'description': 'Automatic Emergency Braking (AEB) active (Reserved and BCU should send value 0)  ', 'enum': {0: 'AEBActvNotActive', 1: 'AEBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'aebactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AebactvType Bcusts5e::aebactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  Bcusts5e::AebactvType ret =  static_cast<Bcusts5e::AebactvType>(x);
  return ret;
}

// config detail: {'bit': 54, 'description': 'Controlled Deceleration for Parking brake (CDP) available      ', 'enum': {0: 'CDPAvailNotAvailable', 1: 'CDPAvailavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'cdpavail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::CdpavailType Bcusts5e::cdpavail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  Bcusts5e::CdpavailType ret =  static_cast<Bcusts5e::CdpavailType>(x);
  return ret;
}

// config detail: {'bit': 16, 'description': 'Adaptive Brake Assist (ABA) available      ', 'enum': {0: 'ABAAvlNotAvailable', 1: 'ABAAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'abaavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AbaavlType Bcusts5e::abaavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Bcusts5e::AbaavlType ret =  static_cast<Bcusts5e::AbaavlType>(x);
  return ret;
}

// config detail: {'bit': 18, 'description': 'Hill Descent Control (HDC) status', 'enum': {0: 'HDCStsOff', 1: 'HDCStsFailure', 2: 'HDCStsStandby', 3: 'HDCStsActive'}, 'is_signed_var': False, 'len': 2, 'name': 'hdcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HdcstsType Bcusts5e::hdcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  Bcusts5e::HdcstsType ret =  static_cast<Bcusts5e::HdcstsType>(x);
  return ret;
}

// config detail: {'bit': 3, 'description': 'Traction Control System (TCS) active   ', 'enum': {0: 'TCSDeactvNotDeactivated', 1: 'TCSDeactvDeactivated'}, 'is_signed_var': False, 'len': 1, 'name': 'tcsdeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::TcsdeactvType Bcusts5e::tcsdeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  Bcusts5e::TcsdeactvType ret =  static_cast<Bcusts5e::TcsdeactvType>(x);
  return ret;
}

// config detail: {'bit': 46, 'description': 'Automatic Warn Braking (AWB) available      ', 'enum': {0: 'AWBAvlNotAvailable', 1: 'AWBAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'awbavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AwbavlType Bcusts5e::awbavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 1);

  Bcusts5e::AwbavlType ret =  static_cast<Bcusts5e::AwbavlType>(x);
  return ret;
}

// config detail: {'bit': 10, 'description': 'Automatic Brake Prefill (EBP) available   ', 'enum': {0: 'ABPAvlNotAvailable', 1: 'ABPAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'abpavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AbpavlType Bcusts5e::abpavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Bcusts5e::AbpavlType ret =  static_cast<Bcusts5e::AbpavlType>(x);
  return ret;
}

// config detail: {'bit': 47, 'description': 'Automatic Warn Braking (AWB) active      ', 'enum': {0: 'AWBActvNotActive', 1: 'AWBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'awbactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AwbactvType Bcusts5e::awbactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  Bcusts5e::AwbactvType ret =  static_cast<Bcusts5e::AwbactvType>(x);
  return ret;
}

// config detail: {'bit': 28, 'description': 'Emergency Brake Assist (EBA) available      ', 'enum': {0: 'EBAAvlNotAvailable', 1: 'EBAAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'ebaavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::EbaavlType Bcusts5e::ebaavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  Bcusts5e::EbaavlType ret =  static_cast<Bcusts5e::EbaavlType>(x);
  return ret;
}

// config detail: {'bit': 38, 'description': 'Error detected by ESC for MRR (ACC and AEB) in CAN frame information  such as Timeout, invalid values, CRC or alive counter.  ', 'enum': {0: 'QDCACCFailNoError', 1: 'QDCACCFailError', 2: 'QDCACCFailReserved2', 3: 'QDCACCFailReserved3'}, 'is_signed_var': False, 'len': 2, 'name': 'qdcaccfail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::QdcaccfailType Bcusts5e::qdcaccfail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 2);

  Bcusts5e::QdcaccfailType ret =  static_cast<Bcusts5e::QdcaccfailType>(x);
  return ret;
}

// config detail: {'bit': 11, 'description': 'Automatic Brake Prefill (EBP) active   ', 'enum': {0: 'ABPActvNotActive', 1: 'ABPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'abpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AbpactvType Bcusts5e::abpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Bcusts5e::AbpactvType ret =  static_cast<Bcusts5e::AbpactvType>(x);
  return ret;
}

// config detail: {'bit': 20, 'description': 'Pedestrian Protection (PEDP) available (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPAvlNotAvailable', 1: 'PEDPAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'pedpavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::PedpavlType Bcusts5e::pedpavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Bcusts5e::PedpavlType ret =  static_cast<Bcusts5e::PedpavlType>(x);
  return ret;
}

// config detail: {'bit': 24, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) available     ', 'enum': {0: 'CDDSAvlNotAvailable', 1: 'CDDSAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'cddsavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::CddsavlType Bcusts5e::cddsavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 1);

  Bcusts5e::CddsavlType ret =  static_cast<Bcusts5e::CddsavlType>(x);
  return ret;
}

// config detail: {'bit': 52, 'description': 'Styandstill status from Brake (not wheel speed)   ', 'enum': {0: 'StandstillStsNonHold', 1: 'StandstillStsSoftStop', 2: 'StandstillStsTemporaryHoldByServiceBrakes', 3: 'StandstillStsHoldByServiceBrakes', 4: 'StandstillStsTransitionToANonHold', 5: 'StandstillStsParkedVehicleAutonomousParkBrake', 6: 'StandstillStsReserved6', 7: 'StandstillStsReserved7'}, 'is_signed_var': False, 'len': 3, 'name': 'standstillsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::StandstillstsType Bcusts5e::standstillsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 3);

  Bcusts5e::StandstillstsType ret =  static_cast<Bcusts5e::StandstillstsType>(x);
  return ret;
}

// config detail: {'bit': 53, 'description': 'Hill Hold Control (HHC) available      ', 'enum': {0: 'HHCAvailNotAvailable', 1: 'HHCAvailavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'hhcavail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HhcavailType Bcusts5e::hhcavail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(5, 1);

  Bcusts5e::HhcavailType ret =  static_cast<Bcusts5e::HhcavailType>(x);
  return ret;
}

// config detail: {'bit': 15, 'description': 'Antilock Brake System (ABS) active      ', 'enum': {0: 'ABSActvNotActive', 1: 'ABSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'absactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::AbsactvType Bcusts5e::absactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  Bcusts5e::AbsactvType ret =  static_cast<Bcusts5e::AbsactvType>(x);
  return ret;
}

// config detail: {'bit': 21, 'description': 'Pedestrian Protection (PEDP) active (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPActvNotActive', 1: 'PEDPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'pedpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::PedpactvType Bcusts5e::pedpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  Bcusts5e::PedpactvType ret =  static_cast<Bcusts5e::PedpactvType>(x);
  return ret;
}

// config detail: {'bit': 23, 'description': 'Emergency Brake Assist (EBA) active      ', 'enum': {0: 'EBAActvNotActive', 1: 'EBAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'ebaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::EbaactvType Bcusts5e::ebaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Bcusts5e::EbaactvType ret =  static_cast<Bcusts5e::EbaactvType>(x);
  return ret;
}

// config detail: {'bit': 45, 'description': 'Controled Deceleration for Parking brake (CDP) active      ', 'enum': {0: 'CDPActvNotActive', 1: 'CDPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'cdpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::CdpactvType Bcusts5e::cdpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  Bcusts5e::CdpactvType ret =  static_cast<Bcusts5e::CdpactvType>(x);
  return ret;
}

// config detail: {'bit': 2, 'description': 'Electronic Brake Distribution (EBD) active      ', 'enum': {0: 'EBDActvNotActive', 1: 'EBDActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'ebdactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::EbdactvType Bcusts5e::ebdactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  Bcusts5e::EbdactvType ret =  static_cast<Bcusts5e::EbdactvType>(x);
  return ret;
}

// config detail: {'bit': 19, 'description': 'Secondary Colision Mitigation (SCM) active (Reserved and BCU should send value 0)', 'enum': {0: 'SCMActvNotActive', 1: 'SCMActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'scmactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::ScmactvType Bcusts5e::scmactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  Bcusts5e::ScmactvType ret =  static_cast<Bcusts5e::ScmactvType>(x);
  return ret;
}

// config detail: {'bit': 0, 'description': 'Drag Torque Control (DTC) active    ', 'enum': {0: 'DTCActvNotActive', 1: 'DTCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'dtcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::DtcactvType Bcusts5e::dtcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  Bcusts5e::DtcactvType ret =  static_cast<Bcusts5e::DtcactvType>(x);
  return ret;
}

// config detail: {'bit': 35, 'description': 'Hydraulic Rear wheel Boost (HRB) active      ', 'enum': {0: 'HRBActvNotActive', 1: 'HRBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'hrbactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HrbactvType Bcusts5e::hrbactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  Bcusts5e::HrbactvType ret =  static_cast<Bcusts5e::HrbactvType>(x);
  return ret;
}

// config detail: {'bit': 55, 'description': 'ECDT temperature offset      ', 'enum': {0: 'ECDTTempOffsTemperatureNotHigh', 1: 'ECDTTempOffsTemepratureTooHigh'}, 'is_signed_var': False, 'len': 1, 'name': 'ecdttempoffs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::EcdttempoffsType Bcusts5e::ecdttempoffs(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  Bcusts5e::EcdttempoffsType ret =  static_cast<Bcusts5e::EcdttempoffsType>(x);
  return ret;
}

// config detail: {'bit': 26, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) active   ', 'enum': {0: 'CDDSActvNotActive', 1: 'CDDSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'cddsactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::CddsactvType Bcusts5e::cddsactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  Bcusts5e::CddsactvType ret =  static_cast<Bcusts5e::CddsactvType>(x);
  return ret;
}

// config detail: {'bit': 40, 'description': 'Hill Hold Control (HHC) active ', 'enum': {0: 'HHCActvNotActive', 1: 'HHCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'hhcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts5e::HhcactvType Bcusts5e::hhcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  Bcusts5e::HhcactvType ret =  static_cast<Bcusts5e::HhcactvType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
