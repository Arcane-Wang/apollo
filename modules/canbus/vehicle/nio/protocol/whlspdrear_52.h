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

class Whlspdrear52 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Whlspdrear52();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'WR_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int wr_crc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'WR_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int wr_msgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'WHLSPDRRSTS_VALID', 1: 'WHLSPDRRSTS_INVALID', 2: 'WHLSPDRRSTS_INITIAL', 3: 'WHLSPDRRSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRRsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdrear_52::WhlspdrrstsType whlspdrrsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'enum': {0: 'WHLSPDRRDIR_STANDSTILL', 1: 'WHLSPDRRDIR_FORWARD', 2: 'WHLSPDRRDIR_BACKWARD', 3: 'WHLSPDRRDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRRdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdrear_52::WhlspdrrdirType whlspdrrdir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdRR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
  double whlspdrr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'WHLSPDRLSTS_VALID', 1: 'WHLSPDRLSTS_INVALID', 2: 'WHLSPDRLSTS_INITIAL', 3: 'WHLSPDRLSTS_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRLsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdrear_52::WhlspdrlstsType whlspdrlsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'WHLSPDRLDIR_STANDSTILL', 1: 'WHLSPDRLDIR_FORWARD', 2: 'WHLSPDRLDIR_BACKWARD', 3: 'WHLSPDRLDIR_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'WhlspdRLdir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Whlspdrear_52::WhlspdrldirType whlspdrldir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'WhlspdRL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
  double whlspdrl(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


