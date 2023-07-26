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

class Bcusts5e : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bcusts5e();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 4, 'enum': {0: 'TCSACTV_NOT_ACTIVE', 1: 'TCSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::TcsactvType tcsactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 27, 'enum': {0: 'SCMAVL_NOT_AVAILABLE', 1: 'SCMAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::ScmavlType scmavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'enum': {0: 'HFCACTV_NOT_ACTIVE', 1: 'HFCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HFCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HfcactvType hfcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'enum': {0: 'VDCACTV_NOT_ACTIVE', 1: 'VDCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::VdcactvType vdcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'AVHSTS_FAILURE_AVH_LAMP_ON_WITH_YELLOW_COLOR', 1: 'AVHSTS_STANDBY_AVH_LAMP_OFF', 2: 'AVHSTS_ACTIVE_AVH_LAMP_ON_WITH_GREEN_COLOR', 3: 'AVHSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'AVHSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AvhstsType avhsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'enum': {0: 'AUTOBRKGACTV_NOT_ACTIVE', 1: 'AUTOBRKGACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AutobrkgactvType autobrkgactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'enum': {0: 'VDCDEACTV_NOT_DEACTIVATED', 1: 'VDCDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::VdcdeactvType vdcdeactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'ABAACTV_NOT_ACTIVE', 1: 'ABAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AbaactvType abaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'enum': {0: 'AUTOBRKGAVL_NOT_AVAILABLE', 1: 'AUTOBRKGAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AutobrkgavlType autobrkgavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HBAACTV_NOT_ACTIVE', 1: 'HBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HbaactvType hbaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'description': 'Automatic Emergency Braking (AEB) available (Reserved and BCU should send value 0) ', 'enum': {0: 'AEBAVL_NOT_AVAILABLE', 1: 'AEBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AebavlType aebavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 14, 'description': 'Automatic Emergency Braking (AEB) active (Reserved and BCU should send value 0)  ', 'enum': {0: 'AEBACTV_NOT_ACTIVE', 1: 'AEBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AebactvType aebactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 54, 'description': 'Controlled Deceleration for Parking brake (CDP) available      ', 'enum': {0: 'CDPAVAIL_NOT_AVAILABLE', 1: 'CDPAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::CdpavailType cdpavail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': 'Adaptive Brake Assist (ABA) available      ', 'enum': {0: 'ABAAVL_NOT_AVAILABLE', 1: 'ABAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AbaavlType abaavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'description': 'Hill Descent Control (HDC) status', 'enum': {0: 'HDCSTS_OFF', 1: 'HDCSTS_FAILURE', 2: 'HDCSTS_STANDBY', 3: 'HDCSTS_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'HDCSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HdcstsType hdcsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'description': 'Traction Control System (TCS) active   ', 'enum': {0: 'TCSDEACTV_NOT_DEACTIVATED', 1: 'TCSDEACTV_DEACTIVATED'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::TcsdeactvType tcsdeactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 46, 'description': 'Automatic Warn Braking (AWB) available      ', 'enum': {0: 'AWBAVL_NOT_AVAILABLE', 1: 'AWBAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AwbavlType awbavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'description': 'Automatic Brake Prefill (EBP) available   ', 'enum': {0: 'ABPAVL_NOT_AVAILABLE', 1: 'ABPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AbpavlType abpavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'description': 'Automatic Warn Braking (AWB) active      ', 'enum': {0: 'AWBACTV_NOT_ACTIVE', 1: 'AWBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AwbactvType awbactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'description': 'Emergency Brake Assist (EBA) available      ', 'enum': {0: 'EBAAVL_NOT_AVAILABLE', 1: 'EBAAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::EbaavlType ebaavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'description': 'Error detected by ESC for MRR (ACC and AEB) in CAN frame information  such as Timeout, invalid values, CRC or alive counter.  ', 'enum': {0: 'QDCACCFAIL_NO_ERROR', 1: 'QDCACCFAIL_ERROR', 2: 'QDCACCFAIL_RESERVED2', 3: 'QDCACCFAIL_RESERVED3'}, 'is_signed_var': False, 'len': 2, 'name': 'QDCACCFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::QdcaccfailType qdcaccfail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'description': 'Automatic Brake Prefill (EBP) active   ', 'enum': {0: 'ABPACTV_NOT_ACTIVE', 1: 'ABPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AbpactvType abpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'description': 'Pedestrian Protection (PEDP) available (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPAVL_NOT_AVAILABLE', 1: 'PEDPAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::PedpavlType pedpavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) available     ', 'enum': {0: 'CDDSAVL_NOT_AVAILABLE', 1: 'CDDSAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::CddsavlType cddsavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'description': 'Styandstill status from Brake (not wheel speed)   ', 'enum': {0: 'STANDSTILLSTS_NON_HOLD', 1: 'STANDSTILLSTS_SOFT_STOP', 2: 'STANDSTILLSTS_TEMPORARY_HOLD_BY_SERVICE_BRAKES', 3: 'STANDSTILLSTS_HOLD_BY_SERVICE_BRAKES', 4: 'STANDSTILLSTS_TRANSITION_TO_A_NON_HOLD', 5: 'STANDSTILLSTS_PARKED_VEHICLE_AUTONOMOUS_PARK_BRAKE', 6: 'STANDSTILLSTS_RESERVED6', 7: 'STANDSTILLSTS_RESERVED7'}, 'is_signed_var': False, 'len': 3, 'name': 'StandstillSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::StandstillstsType standstillsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'description': 'Hill Hold Control (HHC) available      ', 'enum': {0: 'HHCAVAIL_NOT_AVAILABLE', 1: 'HHCAVAIL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HhcavailType hhcavail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'description': 'Antilock Brake System (ABS) active      ', 'enum': {0: 'ABSACTV_NOT_ACTIVE', 1: 'ABSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::AbsactvType absactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'description': 'Pedestrian Protection (PEDP) active (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPACTV_NOT_ACTIVE', 1: 'PEDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::PedpactvType pedpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': 'Emergency Brake Assist (EBA) active      ', 'enum': {0: 'EBAACTV_NOT_ACTIVE', 1: 'EBAACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::EbaactvType ebaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 45, 'description': 'Controled Deceleration for Parking brake (CDP) active      ', 'enum': {0: 'CDPACTV_NOT_ACTIVE', 1: 'CDPACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::CdpactvType cdpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'description': 'Electronic Brake Distribution (EBD) active      ', 'enum': {0: 'EBDACTV_NOT_ACTIVE', 1: 'EBDACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'EBDActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::EbdactvType ebdactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'description': 'Secondary Colision Mitigation (SCM) active (Reserved and BCU should send value 0)', 'enum': {0: 'SCMACTV_NOT_ACTIVE', 1: 'SCMACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::ScmactvType scmactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': 'Drag Torque Control (DTC) active    ', 'enum': {0: 'DTCACTV_NOT_ACTIVE', 1: 'DTCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'DTCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::DtcactvType dtcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'description': 'Hydraulic Rear wheel Boost (HRB) active      ', 'enum': {0: 'HRBACTV_NOT_ACTIVE', 1: 'HRBACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HRBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HrbactvType hrbactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'description': 'ECDT temperature offset      ', 'enum': {0: 'ECDTTEMPOFFS_TEMPERATURE_NOT_HIGH', 1: 'ECDTTEMPOFFS_TEMEPRATURE_TOO_HIGH'}, 'is_signed_var': False, 'len': 1, 'name': 'ECDTTempOffs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::EcdttempoffsType ecdttempoffs(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) active   ', 'enum': {0: 'CDDSACTV_NOT_ACTIVE', 1: 'CDDSACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::CddsactvType cddsactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'description': 'Hill Hold Control (HHC) active ', 'enum': {0: 'HHCACTV_NOT_ACTIVE', 1: 'HHCACTV_ACTIVE'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts_5e::HhcactvType hhcactv(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


