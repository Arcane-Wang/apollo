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
const int32_t Bcusts5e::ID = 0x5e;

void Bcusts5e::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasBcusts5e() ) {
           chassis->Builder().getNio().initBcusts5e();
        }
    }
  chassis->Builder().getNio().getbcusts_5e().setTCSActv(TCSActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setSCMAvl(SCMAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHFCActv(HFCActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setVDCActv(VDCActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAVHSts(AVHSts(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAutoBrkgActv(AutoBrkgActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setVDCDeactv(VDCDeactv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setABAActv(ABAActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAutoBrkgAvl(AutoBrkgAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHBAActv(HBAActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAEBAvl(AEBAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAEBActv(AEBActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setCDPAvail(CDPAvail(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setABAAvl(ABAAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHDCSts(HDCSts(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setTCSDeactv(TCSDeactv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAWBAvl(AWBAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setABPAvl(ABPAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setAWBActv(AWBActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setEBAAvl(EBAAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setQDCACCFail(QDCACCFail(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setABPActv(ABPActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setPEDPAvl(PEDPAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setCDDSAvl(CDDSAvl(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setStandstillSts(StandstillSts(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHHCAvail(HHCAvail(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setABSActv(ABSActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setPEDPActv(PEDPActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setEBAActv(EBAActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setCDPActv(CDPActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setEBDActv(EBDActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setSCMActv(SCMActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setDTCActv(DTCActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHRBActv(HRBActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setECDTTempOffs(ECDTTempOffs(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setCDDSActv(CDDSActv(bytes, length));
  chassis->Builder().getNio().getbcusts_5e().setHHCActv(HHCActv(bytes, length));
}

// config detail: {'bit': 4, 'enum': {0: 'TCSACTV_NOT_ACTIVE', 1: 'TCSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::TCSActvType Bcusts5e::TCSActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  ::atlas_messages::bcusts_5e::TCSActvType ret =  static_cast<::atlas_messages::bcusts_5e::TCSActvType>(x);
  return ret;
}

// config detail: {'bit': 27, 'enum': {0: 'SCMAVL_NOT_AVAILABLE', 1: 'SCMAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::SCMAvlType Bcusts5e::SCMAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::bcusts_5e::SCMAvlType ret =  static_cast<::atlas_messages::bcusts_5e::SCMAvlType>(x);
  return ret;
}

// config detail: {'bit': 34, 'enum': {0: 'HFCACTV_NOT_ACTIVE', 1: 'HFCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HFCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HFCActvType Bcusts5e::HFCActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::bcusts_5e::HFCActvType ret =  static_cast<::atlas_messages::bcusts_5e::HFCActvType>(x);
  return ret;
}

// config detail: {'bit': 6, 'enum': {0: 'VDCACTV_NOT_ACTIVE', 1: 'VDCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::VDCActvType Bcusts5e::VDCActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  ::atlas_messages::bcusts_5e::VDCActvType ret =  static_cast<::atlas_messages::bcusts_5e::VDCActvType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'AVHSTS_FAILURE_AVH_LAMP_ON_WITH_YELLOW_COLOR', 1: 'AVHSTS_STANDBY_AVH_LAMP_OFF', 2: 'AVHSTS_ACTIVE_AVH_LAMP_ON_WITH_GREEN_COLOR', 3: 'AVHSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'AVHSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AVHStsType Bcusts5e::AVHSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  ::atlas_messages::bcusts_5e::AVHStsType ret =  static_cast<::atlas_messages::bcusts_5e::AVHStsType>(x);
  return ret;
}

// config detail: {'bit': 41, 'enum': {0: 'AUTOBRKGACTV_NOT_ACTIVE', 1: 'AUTOBRKGACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AutoBrkgActvType Bcusts5e::AutoBrkgActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 1);

  ::atlas_messages::bcusts_5e::AutoBrkgActvType ret =  static_cast<::atlas_messages::bcusts_5e::AutoBrkgActvType>(x);
  return ret;
}

// config detail: {'bit': 5, 'enum': {0: 'VDCDEACTV_NOT_DEACTIVATED', 1: 'VDCDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::VDCDeactvType Bcusts5e::VDCDeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::bcusts_5e::VDCDeactvType ret =  static_cast<::atlas_messages::bcusts_5e::VDCDeactvType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'ABAACTV_NOT_ACTIVE', 1: 'ABAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ABAActvType Bcusts5e::ABAActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  ::atlas_messages::bcusts_5e::ABAActvType ret =  static_cast<::atlas_messages::bcusts_5e::ABAActvType>(x);
  return ret;
}

// config detail: {'bit': 42, 'enum': {0: 'AUTOBRKGAVL_NOT_AVAILABLE', 1: 'AUTOBRKGAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AutoBrkgAvlType Bcusts5e::AutoBrkgAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::bcusts_5e::AutoBrkgAvlType ret =  static_cast<::atlas_messages::bcusts_5e::AutoBrkgAvlType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HBAACTV_NOT_ACTIVE', 1: 'HBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HBAActvType Bcusts5e::HBAActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::bcusts_5e::HBAActvType ret =  static_cast<::atlas_messages::bcusts_5e::HBAActvType>(x);
  return ret;
}

// config detail: {'bit': 12, 'description': 'Automatic Emergency Braking (AEB) available (Reserved and BCU should send value 0) ', 'enum': {0: 'AEBAVL_NOT_AVAILABLE', 1: 'AEBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AEBAvlType Bcusts5e::AEBAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  ::atlas_messages::bcusts_5e::AEBAvlType ret =  static_cast<::atlas_messages::bcusts_5e::AEBAvlType>(x);
  return ret;
}

// config detail: {'bit': 14, 'description': 'Automatic Emergency Braking (AEB) active (Reserved and BCU should send value 0)  ', 'enum': {0: 'AEBACTV_NOT_ACTIVE', 1: 'AEBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AEBActvType Bcusts5e::AEBActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  ::atlas_messages::bcusts_5e::AEBActvType ret =  static_cast<::atlas_messages::bcusts_5e::AEBActvType>(x);
  return ret;
}

// config detail: {'bit': 54, 'description': 'Controlled Deceleration for Parking brake (CDP) available      ', 'enum': {0: 'CDPAVAIL_NOT_AVAILABLE', 1: 'CDPAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::CDPAvailType Bcusts5e::CDPAvail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  ::atlas_messages::bcusts_5e::CDPAvailType ret =  static_cast<::atlas_messages::bcusts_5e::CDPAvailType>(x);
  return ret;
}

// config detail: {'bit': 16, 'description': 'Adaptive Brake Assist (ABA) available      ', 'enum': {0: 'ABAAVL_NOT_AVAILABLE', 1: 'ABAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ABAAvlType Bcusts5e::ABAAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  ::atlas_messages::bcusts_5e::ABAAvlType ret =  static_cast<::atlas_messages::bcusts_5e::ABAAvlType>(x);
  return ret;
}

// config detail: {'bit': 18, 'description': 'Hill Descent Control (HDC) status', 'enum': {0: 'HDCSTS_OFF', 1: 'HDCSTS_FAILURE', 2: 'HDCSTS_STANDBY', 3: 'HDCSTS_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'HDCSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HDCStsType Bcusts5e::HDCSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::bcusts_5e::HDCStsType ret =  static_cast<::atlas_messages::bcusts_5e::HDCStsType>(x);
  return ret;
}

// config detail: {'bit': 3, 'description': 'Traction Control System (TCS) active   ', 'enum': {0: 'TCSDEACTV_NOT_DEACTIVATED', 1: 'TCSDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::TCSDeactvType Bcusts5e::TCSDeactv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::bcusts_5e::TCSDeactvType ret =  static_cast<::atlas_messages::bcusts_5e::TCSDeactvType>(x);
  return ret;
}

// config detail: {'bit': 46, 'description': 'Automatic Warn Braking (AWB) available      ', 'enum': {0: 'AWBAVL_NOT_AVAILABLE', 1: 'AWBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AWBAvlType Bcusts5e::AWBAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 1);

  ::atlas_messages::bcusts_5e::AWBAvlType ret =  static_cast<::atlas_messages::bcusts_5e::AWBAvlType>(x);
  return ret;
}

// config detail: {'bit': 10, 'description': 'Automatic Brake Prefill (EBP) available   ', 'enum': {0: 'ABPAVL_NOT_AVAILABLE', 1: 'ABPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ABPAvlType Bcusts5e::ABPAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::bcusts_5e::ABPAvlType ret =  static_cast<::atlas_messages::bcusts_5e::ABPAvlType>(x);
  return ret;
}

// config detail: {'bit': 47, 'description': 'Automatic Warn Braking (AWB) active      ', 'enum': {0: 'AWBACTV_NOT_ACTIVE', 1: 'AWBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::AWBActvType Bcusts5e::AWBActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::bcusts_5e::AWBActvType ret =  static_cast<::atlas_messages::bcusts_5e::AWBActvType>(x);
  return ret;
}

// config detail: {'bit': 28, 'description': 'Emergency Brake Assist (EBA) available      ', 'enum': {0: 'EBAAVL_NOT_AVAILABLE', 1: 'EBAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::EBAAvlType Bcusts5e::EBAAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  ::atlas_messages::bcusts_5e::EBAAvlType ret =  static_cast<::atlas_messages::bcusts_5e::EBAAvlType>(x);
  return ret;
}

// config detail: {'bit': 38, 'description': 'Error detected by ESC for MRR (ACC and AEB) in CAN frame information  such as Timeout, invalid values, CRC or alive counter.  ', 'enum': {0: 'QDCACCFAIL_NO_ERROR', 1: 'QDCACCFAIL_ERROR', 2: 'QDCACCFAIL_RESERVED2', 3: 'QDCACCFAIL_RESERVED3'}, 'is_signed_var': False, 'len': 2, 'name': 'QDCACCFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::QDCACCFailType Bcusts5e::QDCACCFail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 2);

  ::atlas_messages::bcusts_5e::QDCACCFailType ret =  static_cast<::atlas_messages::bcusts_5e::QDCACCFailType>(x);
  return ret;
}

// config detail: {'bit': 11, 'description': 'Automatic Brake Prefill (EBP) active   ', 'enum': {0: 'ABPACTV_NOT_ACTIVE', 1: 'ABPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ABPActvType Bcusts5e::ABPActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::bcusts_5e::ABPActvType ret =  static_cast<::atlas_messages::bcusts_5e::ABPActvType>(x);
  return ret;
}

// config detail: {'bit': 20, 'description': 'Pedestrian Protection (PEDP) available (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPAVL_NOT_AVAILABLE', 1: 'PEDPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::PEDPAvlType Bcusts5e::PEDPAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  ::atlas_messages::bcusts_5e::PEDPAvlType ret =  static_cast<::atlas_messages::bcusts_5e::PEDPAvlType>(x);
  return ret;
}

// config detail: {'bit': 24, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) available     ', 'enum': {0: 'CDDSAVL_NOT_AVAILABLE', 1: 'CDDSAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::CDDSAvlType Bcusts5e::CDDSAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 1);

  ::atlas_messages::bcusts_5e::CDDSAvlType ret =  static_cast<::atlas_messages::bcusts_5e::CDDSAvlType>(x);
  return ret;
}

// config detail: {'bit': 52, 'description': 'Styandstill status from Brake (not wheel speed)   ', 'enum': {0: 'STANDSTILLSTS_NON_HOLD', 1: 'STANDSTILLSTS_SOFT_STOP', 2: 'STANDSTILLSTS_TEMPORARY_HOLD_BY_SERVICE_BRAKES', 3: 'STANDSTILLSTS_HOLD_BY_SERVICE_BRAKES', 4: 'STANDSTILLSTS_TRANSITION_TO_A_NON_HOLD', 5: 'STANDSTILLSTS_PARKED_VEHICLE_AUTONOMOUS_PARK_BRAKE', 6: 'STANDSTILLSTS_RESERVED6', 7: 'STANDSTILLSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'StandstillSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::StandstillStsType Bcusts5e::StandstillSts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 3);

  ::atlas_messages::bcusts_5e::StandstillStsType ret =  static_cast<::atlas_messages::bcusts_5e::StandstillStsType>(x);
  return ret;
}

// config detail: {'bit': 53, 'description': 'Hill Hold Control (HHC) available      ', 'enum': {0: 'HHCAVAIL_NOT_AVAILABLE', 1: 'HHCAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HHCAvailType Bcusts5e::HHCAvail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::bcusts_5e::HHCAvailType ret =  static_cast<::atlas_messages::bcusts_5e::HHCAvailType>(x);
  return ret;
}

// config detail: {'bit': 15, 'description': 'Antilock Brake System (ABS) active      ', 'enum': {0: 'ABSACTV_NOT_ACTIVE', 1: 'ABSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ABSActvType Bcusts5e::ABSActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::bcusts_5e::ABSActvType ret =  static_cast<::atlas_messages::bcusts_5e::ABSActvType>(x);
  return ret;
}

// config detail: {'bit': 21, 'description': 'Pedestrian Protection (PEDP) active (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPACTV_NOT_ACTIVE', 1: 'PEDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::PEDPActvType Bcusts5e::PEDPActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::bcusts_5e::PEDPActvType ret =  static_cast<::atlas_messages::bcusts_5e::PEDPActvType>(x);
  return ret;
}

// config detail: {'bit': 23, 'description': 'Emergency Brake Assist (EBA) active      ', 'enum': {0: 'EBAACTV_NOT_ACTIVE', 1: 'EBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::EBAActvType Bcusts5e::EBAActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::bcusts_5e::EBAActvType ret =  static_cast<::atlas_messages::bcusts_5e::EBAActvType>(x);
  return ret;
}

// config detail: {'bit': 45, 'description': 'Controled Deceleration for Parking brake (CDP) active      ', 'enum': {0: 'CDPACTV_NOT_ACTIVE', 1: 'CDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::CDPActvType Bcusts5e::CDPActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  ::atlas_messages::bcusts_5e::CDPActvType ret =  static_cast<::atlas_messages::bcusts_5e::CDPActvType>(x);
  return ret;
}

// config detail: {'bit': 2, 'description': 'Electronic Brake Distribution (EBD) active      ', 'enum': {0: 'EBDACTV_NOT_ACTIVE', 1: 'EBDACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBDActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::EBDActvType Bcusts5e::EBDActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::bcusts_5e::EBDActvType ret =  static_cast<::atlas_messages::bcusts_5e::EBDActvType>(x);
  return ret;
}

// config detail: {'bit': 19, 'description': 'Secondary Colision Mitigation (SCM) active (Reserved and BCU should send value 0)', 'enum': {0: 'SCMACTV_NOT_ACTIVE', 1: 'SCMACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::SCMActvType Bcusts5e::SCMActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::bcusts_5e::SCMActvType ret =  static_cast<::atlas_messages::bcusts_5e::SCMActvType>(x);
  return ret;
}

// config detail: {'bit': 0, 'description': 'Drag Torque Control (DTC) active    ', 'enum': {0: 'DTCACTV_NOT_ACTIVE', 1: 'DTCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'DTCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::DTCActvType Bcusts5e::DTCActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  ::atlas_messages::bcusts_5e::DTCActvType ret =  static_cast<::atlas_messages::bcusts_5e::DTCActvType>(x);
  return ret;
}

// config detail: {'bit': 35, 'description': 'Hydraulic Rear wheel Boost (HRB) active      ', 'enum': {0: 'HRBACTV_NOT_ACTIVE', 1: 'HRBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HRBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HRBActvType Bcusts5e::HRBActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::bcusts_5e::HRBActvType ret =  static_cast<::atlas_messages::bcusts_5e::HRBActvType>(x);
  return ret;
}

// config detail: {'bit': 55, 'description': 'ECDT temperature offset      ', 'enum': {0: 'ECDTTEMPOFFS_TEMPERATURE_NOT_HIGH', 1: 'ECDTTEMPOFFS_TEMEPRATURE_TOO_HIGH'}, 'is_signed_var': False, 'len': 1, 'name': 'ECDTTempOffs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::ECDTTempOffsType Bcusts5e::ECDTTempOffs(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  ::atlas_messages::bcusts_5e::ECDTTempOffsType ret =  static_cast<::atlas_messages::bcusts_5e::ECDTTempOffsType>(x);
  return ret;
}

// config detail: {'bit': 26, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) active   ', 'enum': {0: 'CDDSACTV_NOT_ACTIVE', 1: 'CDDSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::CDDSActvType Bcusts5e::CDDSActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::bcusts_5e::CDDSActvType ret =  static_cast<::atlas_messages::bcusts_5e::CDDSActvType>(x);
  return ret;
}

// config detail: {'bit': 40, 'description': 'Hill Hold Control (HHC) active ', 'enum': {0: 'HHCACTV_NOT_ACTIVE', 1: 'HHCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::bcusts_5e::HHCActvType Bcusts5e::HHCActv(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  ::atlas_messages::bcusts_5e::HHCActvType ret =  static_cast<::atlas_messages::bcusts_5e::HHCActvType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
