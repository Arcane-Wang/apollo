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

#include "modules/canbus/vehicle/nio/protocol/bcusts_5e.h"

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
  chassis->mutable_nio()->mutable_bcusts_5e()->set_tcsactv(tcsactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_scmavl(scmavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hfcactv(hfcactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_vdcactv(vdcactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_avhsts(avhsts(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_autobrkgactv(autobrkgactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_vdcdeactv(vdcdeactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_abaactv(abaactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_autobrkgavl(autobrkgavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hbaactv(hbaactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_aebavl(aebavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_aebactv(aebactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_cdpavail(cdpavail(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_abaavl(abaavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hdcsts(hdcsts(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_tcsdeactv(tcsdeactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_awbavl(awbavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_abpavl(abpavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_awbactv(awbactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_ebaavl(ebaavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_qdcaccfail(qdcaccfail(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_abpactv(abpactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_pedpavl(pedpavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_cddsavl(cddsavl(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_standstillsts(standstillsts(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hhcavail(hhcavail(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_absactv(absactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_pedpactv(pedpactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_ebaactv(ebaactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_cdpactv(cdpactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_ebdactv(ebdactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_scmactv(scmactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_dtcactv(dtcactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hrbactv(hrbactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_ecdttempoffs(ecdttempoffs(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_cddsactv(cddsactv(bytes, length));
  chassis->mutable_nio()->mutable_bcusts_5e()->set_hhcactv(hhcactv(bytes, length));
}

// config detail: {'bit': 4, 'enum': {0: 'TCSACTV_NOT_ACTIVE', 1: 'TCSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'tcsactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::TcsactvType Bcusts5e::tcsactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  Bcusts_5e::TcsactvType ret =  static_cast<Bcusts_5e::TcsactvType>(x);
  return ret;
}

// config detail: {'bit': 27, 'enum': {0: 'SCMAVL_NOT_AVAILABLE', 1: 'SCMAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'scmavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::ScmavlType Bcusts5e::scmavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  Bcusts_5e::ScmavlType ret =  static_cast<Bcusts_5e::ScmavlType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'HFCACTV_NOT_ACTIVE', 1: 'HFCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'hfcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HfcactvType Bcusts5e::hfcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  Bcusts_5e::HfcactvType ret =  static_cast<Bcusts_5e::HfcactvType>(x);
  return ret;
}

// config detail: {'bit': 6, 'enum': {0: 'VDCACTV_NOT_ACTIVE', 1: 'VDCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'vdcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::VdcactvType Bcusts5e::vdcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  Bcusts_5e::VdcactvType ret =  static_cast<Bcusts_5e::VdcactvType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'AVHSTS_FAILURE_AVH_LAMP_ON_WITH_YELLOW_COLOR', 1: 'AVHSTS_STANDBY_AVH_LAMP_OFF', 2: 'AVHSTS_ACTIVE_AVH_LAMP_ON_WITH_GREEN_COLOR', 3: 'AVHSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'avhsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AvhstsType Bcusts5e::avhsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Bcusts_5e::AvhstsType ret =  static_cast<Bcusts_5e::AvhstsType>(x);
  return ret;
}

// config detail: {'bit': 41, 'enum': {0: 'AUTOBRKGACTV_NOT_ACTIVE', 1: 'AUTOBRKGACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'autobrkgactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AutobrkgactvType Bcusts5e::autobrkgactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 1);

  Bcusts_5e::AutobrkgactvType ret =  static_cast<Bcusts_5e::AutobrkgactvType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'VDCDEACTV_NOT_DEACTIVATED', 1: 'VDCDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'vdcdeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::VdcdeactvType Bcusts5e::vdcdeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  Bcusts_5e::VdcdeactvType ret =  static_cast<Bcusts_5e::VdcdeactvType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'ABAACTV_NOT_ACTIVE', 1: 'ABAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'abaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AbaactvType Bcusts5e::abaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Bcusts_5e::AbaactvType ret =  static_cast<Bcusts_5e::AbaactvType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'AUTOBRKGAVL_NOT_AVAILABLE', 1: 'AUTOBRKGAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'autobrkgavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AutobrkgavlType Bcusts5e::autobrkgavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  Bcusts_5e::AutobrkgavlType ret =  static_cast<Bcusts_5e::AutobrkgavlType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HBAACTV_NOT_ACTIVE', 1: 'HBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'hbaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HbaactvType Bcusts5e::hbaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  Bcusts_5e::HbaactvType ret =  static_cast<Bcusts_5e::HbaactvType>(x);
  return ret;
}

// config detail: {'bit': 12, 'description': 'Automatic Emergency Braking (AEB) available (Reserved and BCU should send value 0) ', 'enum': {0: 'AEBAVL_NOT_AVAILABLE', 1: 'AEBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'aebavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AebavlType Bcusts5e::aebavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  Bcusts_5e::AebavlType ret =  static_cast<Bcusts_5e::AebavlType>(x);
  return ret;
}

// config detail: {'bit': 14, 'description': 'Automatic Emergency Braking (AEB) active (Reserved and BCU should send value 0)  ', 'enum': {0: 'AEBACTV_NOT_ACTIVE', 1: 'AEBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'aebactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AebactvType Bcusts5e::aebactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  Bcusts_5e::AebactvType ret =  static_cast<Bcusts_5e::AebactvType>(x);
  return ret;
}

// config detail: {'bit': 54, 'description': 'Controlled Deceleration for Parking brake (CDP) available      ', 'enum': {0: 'CDPAVAIL_NOT_AVAILABLE', 1: 'CDPAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'cdpavail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::CdpavailType Bcusts5e::cdpavail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  Bcusts_5e::CdpavailType ret =  static_cast<Bcusts_5e::CdpavailType>(x);
  return ret;
}

// config detail: {'bit': 16, 'description': 'Adaptive Brake Assist (ABA) available      ', 'enum': {0: 'ABAAVL_NOT_AVAILABLE', 1: 'ABAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'abaavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AbaavlType Bcusts5e::abaavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  Bcusts_5e::AbaavlType ret =  static_cast<Bcusts_5e::AbaavlType>(x);
  return ret;
}

// config detail: {'bit': 18, 'description': 'Hill Descent Control (HDC) status', 'enum': {0: 'HDCSTS_OFF', 1: 'HDCSTS_FAILURE', 2: 'HDCSTS_STANDBY', 3: 'HDCSTS_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'hdcsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HdcstsType Bcusts5e::hdcsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  Bcusts_5e::HdcstsType ret =  static_cast<Bcusts_5e::HdcstsType>(x);
  return ret;
}

// config detail: {'bit': 3, 'description': 'Traction Control System (TCS) active   ', 'enum': {0: 'TCSDEACTV_NOT_DEACTIVATED', 1: 'TCSDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'tcsdeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::TcsdeactvType Bcusts5e::tcsdeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  Bcusts_5e::TcsdeactvType ret =  static_cast<Bcusts_5e::TcsdeactvType>(x);
  return ret;
}

// config detail: {'bit': 46, 'description': 'Automatic Warn Braking (AWB) available      ', 'enum': {0: 'AWBAVL_NOT_AVAILABLE', 1: 'AWBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'awbavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AwbavlType Bcusts5e::awbavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 1);

  Bcusts_5e::AwbavlType ret =  static_cast<Bcusts_5e::AwbavlType>(x);
  return ret;
}

// config detail: {'bit': 10, 'description': 'Automatic Brake Prefill (EBP) available   ', 'enum': {0: 'ABPAVL_NOT_AVAILABLE', 1: 'ABPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'abpavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AbpavlType Bcusts5e::abpavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Bcusts_5e::AbpavlType ret =  static_cast<Bcusts_5e::AbpavlType>(x);
  return ret;
}

// config detail: {'bit': 47, 'description': 'Automatic Warn Braking (AWB) active      ', 'enum': {0: 'AWBACTV_NOT_ACTIVE', 1: 'AWBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'awbactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AwbactvType Bcusts5e::awbactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  Bcusts_5e::AwbactvType ret =  static_cast<Bcusts_5e::AwbactvType>(x);
  return ret;
}

// config detail: {'bit': 28, 'description': 'Emergency Brake Assist (EBA) available      ', 'enum': {0: 'EBAAVL_NOT_AVAILABLE', 1: 'EBAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ebaavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::EbaavlType Bcusts5e::ebaavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  Bcusts_5e::EbaavlType ret =  static_cast<Bcusts_5e::EbaavlType>(x);
  return ret;
}

// config detail: {'bit': 38, 'description': 'Error detected by ESC for MRR (ACC and AEB) in CAN frame information  such as Timeout, invalid values, CRC or alive counter.  ', 'enum': {0: 'QDCACCFAIL_NO_ERROR', 1: 'QDCACCFAIL_ERROR', 2: 'QDCACCFAIL_RESERVED2', 3: 'QDCACCFAIL_RESERVED3'}, 'is_signed_var': False, 'len': 2, 'name': 'qdcaccfail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::QdcaccfailType Bcusts5e::qdcaccfail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 2);

  Bcusts_5e::QdcaccfailType ret =  static_cast<Bcusts_5e::QdcaccfailType>(x);
  return ret;
}

// config detail: {'bit': 11, 'description': 'Automatic Brake Prefill (EBP) active   ', 'enum': {0: 'ABPACTV_NOT_ACTIVE', 1: 'ABPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'abpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AbpactvType Bcusts5e::abpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  Bcusts_5e::AbpactvType ret =  static_cast<Bcusts_5e::AbpactvType>(x);
  return ret;
}

// config detail: {'bit': 20, 'description': 'Pedestrian Protection (PEDP) available (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPAVL_NOT_AVAILABLE', 1: 'PEDPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'pedpavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::PedpavlType Bcusts5e::pedpavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  Bcusts_5e::PedpavlType ret =  static_cast<Bcusts_5e::PedpavlType>(x);
  return ret;
}

// config detail: {'bit': 24, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) available     ', 'enum': {0: 'CDDSAVL_NOT_AVAILABLE', 1: 'CDDSAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'cddsavl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::CddsavlType Bcusts5e::cddsavl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 1);

  Bcusts_5e::CddsavlType ret =  static_cast<Bcusts_5e::CddsavlType>(x);
  return ret;
}

// config detail: {'bit': 52, 'description': 'Styandstill status from Brake (not wheel speed)   ', 'enum': {0: 'STANDSTILLSTS_NON_HOLD', 1: 'STANDSTILLSTS_SOFT_STOP', 2: 'STANDSTILLSTS_TEMPORARY_HOLD_BY_SERVICE_BRAKES', 3: 'STANDSTILLSTS_HOLD_BY_SERVICE_BRAKES', 4: 'STANDSTILLSTS_TRANSITION_TO_A_NON_HOLD', 5: 'STANDSTILLSTS_PARKED_VEHICLE_AUTONOMOUS_PARK_BRAKE', 6: 'STANDSTILLSTS_RESERVED6', 7: 'STANDSTILLSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'standstillsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::StandstillstsType Bcusts5e::standstillsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 3);

  Bcusts_5e::StandstillstsType ret =  static_cast<Bcusts_5e::StandstillstsType>(x);
  return ret;
}

// config detail: {'bit': 53, 'description': 'Hill Hold Control (HHC) available      ', 'enum': {0: 'HHCAVAIL_NOT_AVAILABLE', 1: 'HHCAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'hhcavail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HhcavailType Bcusts5e::hhcavail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(5, 1);

  Bcusts_5e::HhcavailType ret =  static_cast<Bcusts_5e::HhcavailType>(x);
  return ret;
}

// config detail: {'bit': 15, 'description': 'Antilock Brake System (ABS) active      ', 'enum': {0: 'ABSACTV_NOT_ACTIVE', 1: 'ABSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'absactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::AbsactvType Bcusts5e::absactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  Bcusts_5e::AbsactvType ret =  static_cast<Bcusts_5e::AbsactvType>(x);
  return ret;
}

// config detail: {'bit': 21, 'description': 'Pedestrian Protection (PEDP) active (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPACTV_NOT_ACTIVE', 1: 'PEDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'pedpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::PedpactvType Bcusts5e::pedpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  Bcusts_5e::PedpactvType ret =  static_cast<Bcusts_5e::PedpactvType>(x);
  return ret;
}

// config detail: {'bit': 23, 'description': 'Emergency Brake Assist (EBA) active      ', 'enum': {0: 'EBAACTV_NOT_ACTIVE', 1: 'EBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ebaactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::EbaactvType Bcusts5e::ebaactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  Bcusts_5e::EbaactvType ret =  static_cast<Bcusts_5e::EbaactvType>(x);
  return ret;
}

// config detail: {'bit': 45, 'description': 'Controled Deceleration for Parking brake (CDP) active      ', 'enum': {0: 'CDPACTV_NOT_ACTIVE', 1: 'CDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'cdpactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::CdpactvType Bcusts5e::cdpactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  Bcusts_5e::CdpactvType ret =  static_cast<Bcusts_5e::CdpactvType>(x);
  return ret;
}

// config detail: {'bit': 2, 'description': 'Electronic Brake Distribution (EBD) active      ', 'enum': {0: 'EBDACTV_NOT_ACTIVE', 1: 'EBDACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ebdactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::EbdactvType Bcusts5e::ebdactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  Bcusts_5e::EbdactvType ret =  static_cast<Bcusts_5e::EbdactvType>(x);
  return ret;
}

// config detail: {'bit': 19, 'description': 'Secondary Colision Mitigation (SCM) active (Reserved and BCU should send value 0)', 'enum': {0: 'SCMACTV_NOT_ACTIVE', 1: 'SCMACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'scmactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::ScmactvType Bcusts5e::scmactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  Bcusts_5e::ScmactvType ret =  static_cast<Bcusts_5e::ScmactvType>(x);
  return ret;
}

// config detail: {'bit': 0, 'description': 'Drag Torque Control (DTC) active    ', 'enum': {0: 'DTCACTV_NOT_ACTIVE', 1: 'DTCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'dtcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::DtcactvType Bcusts5e::dtcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  Bcusts_5e::DtcactvType ret =  static_cast<Bcusts_5e::DtcactvType>(x);
  return ret;
}

// config detail: {'bit': 35, 'description': 'Hydraulic Rear wheel Boost (HRB) active      ', 'enum': {0: 'HRBACTV_NOT_ACTIVE', 1: 'HRBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'hrbactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HrbactvType Bcusts5e::hrbactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  Bcusts_5e::HrbactvType ret =  static_cast<Bcusts_5e::HrbactvType>(x);
  return ret;
}

// config detail: {'bit': 55, 'description': 'ECDT temperature offset      ', 'enum': {0: 'ECDTTEMPOFFS_TEMPERATURE_NOT_HIGH', 1: 'ECDTTEMPOFFS_TEMEPRATURE_TOO_HIGH'}, 'is_signed_var': False, 'len': 1, 'name': 'ecdttempoffs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::EcdttempoffsType Bcusts5e::ecdttempoffs(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  Bcusts_5e::EcdttempoffsType ret =  static_cast<Bcusts_5e::EcdttempoffsType>(x);
  return ret;
}

// config detail: {'bit': 26, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) active   ', 'enum': {0: 'CDDSACTV_NOT_ACTIVE', 1: 'CDDSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'cddsactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::CddsactvType Bcusts5e::cddsactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  Bcusts_5e::CddsactvType ret =  static_cast<Bcusts_5e::CddsactvType>(x);
  return ret;
}

// config detail: {'bit': 40, 'description': 'Hill Hold Control (HHC) active ', 'enum': {0: 'HHCACTV_NOT_ACTIVE', 1: 'HHCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'hhcactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bcusts_5e::HhcactvType Bcusts5e::hhcactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  Bcusts_5e::HhcactvType ret =  static_cast<Bcusts_5e::HhcactvType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
