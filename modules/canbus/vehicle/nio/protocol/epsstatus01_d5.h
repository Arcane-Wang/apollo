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

class Epsstatus01d5 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsstatus01d5();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 26, 'enum': {0: 'EPSWARNLAMP_OFF', 1: 'EPSWARNLAMP_ON', 2: 'EPSWARNLAMP_NOT_AVAILABLE', 3: 'EPSWARNLAMP_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPSwarnLamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::EpswarnlampType epswarnlamp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'ABS_AGREQAVL_NOT_AVAILABLE', 1: 'ABS_AGREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABS_AgreqAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::Abs_agreqavlType abs_agreqavl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 10, 'name': 'TorsBarTq', 'offset': -10.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
  double torsbartq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'enum': {0: 'EPSSTS_INIT', 1: 'EPSSTS_NORMAL', 2: 'EPSSTS_DEGRADED_DUE_TO_TEMP_OR_VOL', 3: 'EPSSTS_TEMPORARY_ERROR', 4: 'EPSSTS_PERMAMEMT_ERROR', 5: 'EPSSTS_RESERVED5', 6: 'EPSSTS_RESERVED6', 7: 'EPSSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::EpsstsType epssts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'enum': {0: 'EPSMOD_NONE', 1: 'EPSMOD_PAI', 2: 'EPSMOD_DAI', 3: 'EPSMOD_TOI', 7: 'EPSMOD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::EpsmodType epsmod(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'STEERAGSPDDIR_LEFT_PLUS', 1: 'STEERAGSPDDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'Steeragspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::SteeragspddirType steeragspddir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'is_signed_var': False, 'len': 9, 'name': 'Steeragspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|2550]', 'physical_unit': 'Deg/sec', 'precision': 5.0, 'type': 'double'}
  double steeragspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'enum': {0: 'STEER_ANGLEDIR_LEFT_PLUS', 1: 'STEER_ANGLEDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'Steer_angledir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::Steer_angledirType steer_angledir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'enum': {0: 'STEER_ANGLEANDSPDVALID_VALID', 1: 'STEER_ANGLEANDSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Steer_angleandspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsstatus01_d5::Steer_angleandspdvalidType steer_angleandspdvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 13, 'name': 'Steer_angle', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|800]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  double steer_angle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_D_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int eps_d_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_D_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int eps_d_crc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


