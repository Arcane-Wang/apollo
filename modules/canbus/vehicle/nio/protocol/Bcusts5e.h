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

  // config detail: {'bit': 4, 'enum': {0: 'TCSActvNotActive', 1: 'TCSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::TcsactvType tcsactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 27, 'enum': {0: 'SCMAvlNotAvailable', 1: 'SCMAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::ScmavlType scmavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'enum': {0: 'HFCActvNotActive', 1: 'HFCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'HFCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HfcactvType hfcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'enum': {0: 'VDCActvNotActive', 1: 'VDCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::VdcactvType vdcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'AVHStsFailureAVHLampOnWithYellowColor', 1: 'AVHStsStandbyAVHLampOff', 2: 'AVHStsActiveAVHLampOnWithGreenColor', 3: 'AVHStsReserved'}, 'is_signed_var': False, 'len': 2, 'name': 'AVHSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AvhstsType avhsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'enum': {0: 'AutoBrkgActvNotActive', 1: 'AutoBrkgActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AutobrkgactvType autobrkgactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'enum': {0: 'VDCDeactvNotDeactivated', 1: 'VDCDeactvDeactivated'}, 'is_signed_var': False, 'len': 1, 'name': 'VDCDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::VdcdeactvType vdcdeactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'ABAActvNotActive', 1: 'ABAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AbaactvType abaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'enum': {0: 'AutoBrkgAvlNotAvailable', 1: 'AutoBrkgAvlAvailable'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoBrkgAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AutobrkgavlType autobrkgavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'HBAActvNotActive', 1: 'HBAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'HBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HbaactvType hbaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'description': 'Automatic Emergency Braking (AEB) available (Reserved and BCU should send value 0) ', 'enum': {0: 'AEBAvlNotAvailable', 1: 'AEBAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AebavlType aebavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 14, 'description': 'Automatic Emergency Braking (AEB) active (Reserved and BCU should send value 0)  ', 'enum': {0: 'AEBActvNotActive', 1: 'AEBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AebactvType aebactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 54, 'description': 'Controlled Deceleration for Parking brake (CDP) available      ', 'enum': {0: 'CDPAvailNotAvailable', 1: 'CDPAvailavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::CdpavailType cdpavail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': 'Adaptive Brake Assist (ABA) available      ', 'enum': {0: 'ABAAvlNotAvailable', 1: 'ABAAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AbaavlType abaavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'description': 'Hill Descent Control (HDC) status', 'enum': {0: 'HDCStsOff', 1: 'HDCStsFailure', 2: 'HDCStsStandby', 3: 'HDCStsActive'}, 'is_signed_var': False, 'len': 2, 'name': 'HDCSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HdcstsType hdcsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'description': 'Traction Control System (TCS) active   ', 'enum': {0: 'TCSDeactvNotDeactivated', 1: 'TCSDeactvDeactivated'}, 'is_signed_var': False, 'len': 1, 'name': 'TCSDeactv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::TcsdeactvType tcsdeactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 46, 'description': 'Automatic Warn Braking (AWB) available      ', 'enum': {0: 'AWBAvlNotAvailable', 1: 'AWBAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AwbavlType awbavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'description': 'Automatic Brake Prefill (EBP) available   ', 'enum': {0: 'ABPAvlNotAvailable', 1: 'ABPAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AbpavlType abpavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'description': 'Automatic Warn Braking (AWB) active      ', 'enum': {0: 'AWBActvNotActive', 1: 'AWBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AwbactvType awbactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'description': 'Emergency Brake Assist (EBA) available      ', 'enum': {0: 'EBAAvlNotAvailable', 1: 'EBAAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::EbaavlType ebaavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'description': 'Error detected by ESC for MRR (ACC and AEB) in CAN frame information  such as Timeout, invalid values, CRC or alive counter.  ', 'enum': {0: 'QDCACCFailNoError', 1: 'QDCACCFailError', 2: 'QDCACCFailReserved2', 3: 'QDCACCFailReserved3'}, 'is_signed_var': False, 'len': 2, 'name': 'QDCACCFail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::QdcaccfailType qdcaccfail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'description': 'Automatic Brake Prefill (EBP) active   ', 'enum': {0: 'ABPActvNotActive', 1: 'ABPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AbpactvType abpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'description': 'Pedestrian Protection (PEDP) available (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPAvlNotAvailable', 1: 'PEDPAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::PedpavlType pedpavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) available     ', 'enum': {0: 'CDDSAvlNotAvailable', 1: 'CDDSAvlavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::CddsavlType cddsavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'description': 'Styandstill status from Brake (not wheel speed)   ', 'enum': {0: 'StandstillStsNonHold', 1: 'StandstillStsSoftStop', 2: 'StandstillStsTemporaryHoldByServiceBrakes', 3: 'StandstillStsHoldByServiceBrakes', 4: 'StandstillStsTransitionToANonHold', 5: 'StandstillStsParkedVehicleAutonomousParkBrake', 6: 'StandstillStsReserved6', 7: 'StandstillStsReserved7'}, 'is_signed_var': False, 'len': 3, 'name': 'StandstillSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::StandstillstsType standstillsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'description': 'Hill Hold Control (HHC) available      ', 'enum': {0: 'HHCAvailNotAvailable', 1: 'HHCAvailavailable'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCAvail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HhcavailType hhcavail(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'description': 'Antilock Brake System (ABS) active      ', 'enum': {0: 'ABSActvNotActive', 1: 'ABSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'ABSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::AbsactvType absactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'description': 'Pedestrian Protection (PEDP) active (Reserved and BCU should send value 0)', 'enum': {0: 'PEDPActvNotActive', 1: 'PEDPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::PedpactvType pedpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': 'Emergency Brake Assist (EBA) active      ', 'enum': {0: 'EBAActvNotActive', 1: 'EBAActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'EBAActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::EbaactvType ebaactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 45, 'description': 'Controled Deceleration for Parking brake (CDP) active      ', 'enum': {0: 'CDPActvNotActive', 1: 'CDPActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'CDPActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::CdpactvType cdpactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'description': 'Electronic Brake Distribution (EBD) active      ', 'enum': {0: 'EBDActvNotActive', 1: 'EBDActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'EBDActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::EbdactvType ebdactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'description': 'Secondary Colision Mitigation (SCM) active (Reserved and BCU should send value 0)', 'enum': {0: 'SCMActvNotActive', 1: 'SCMActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::ScmactvType scmactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': 'Drag Torque Control (DTC) active    ', 'enum': {0: 'DTCActvNotActive', 1: 'DTCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'DTCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::DtcactvType dtcactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'description': 'Hydraulic Rear wheel Boost (HRB) active      ', 'enum': {0: 'HRBActvNotActive', 1: 'HRBActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'HRBActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HrbactvType hrbactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'description': 'ECDT temperature offset      ', 'enum': {0: 'ECDTTempOffsTemperatureNotHigh', 1: 'ECDTTempOffsTemepratureTooHigh'}, 'is_signed_var': False, 'len': 1, 'name': 'ECDTTempOffs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::EcdttempoffsType ecdttempoffs(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'description': 'Controlled Deceleration for DAS (Driver Assistant System) active   ', 'enum': {0: 'CDDSActvNotActive', 1: 'CDDSActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'CDDSActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::CddsactvType cddsactv(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'description': 'Hill Hold Control (HHC) active ', 'enum': {0: 'HHCActvNotActive', 1: 'HHCActvActive'}, 'is_signed_var': False, 'len': 1, 'name': 'HHCActv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Bcusts5e::HhcactvType hhcactv(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


