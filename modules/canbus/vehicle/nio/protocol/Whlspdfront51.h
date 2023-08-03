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

class Whlspdfront51 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Whlspdfront51();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'WfMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t wfmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WfCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t wfcrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'WhlspdFRstsvalid', 1: 'WhlspdFRstsinvalid', 2: 'WhlspdFRstsinitial', 3: 'WhlspdFRstsreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdfront51::WhlspdfrstsType whlspdfrsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'enum': {0: 'WhlspdFRdirstandstill', 1: 'WhlspdFRdirforward', 2: 'WhlspdFRdirbackward', 3: 'WhlspdFRdirinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFRdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdfront51::WhlspdfrdirType whlspdfrdir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
  double whlspdfr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'WhlspdFLstsvalid', 1: 'WhlspdFLstsinvalid', 2: 'WhlspdFLstsinitial', 3: 'WhlspdFLstsreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdfront51::WhlspdflstsType whlspdflsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'WhlspdFLdirstandstill', 1: 'WhlspdFLdirforward', 2: 'WhlspdFLdirbackward', 3: 'WhlspdFLdirinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdFLdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdfront51::WhlspdfldirType whlspdfldir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdFL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
  double whlspdfl(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


