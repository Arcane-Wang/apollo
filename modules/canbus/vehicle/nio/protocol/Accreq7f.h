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

class Accreq7f : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Accreq7f();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'AccDrvoffNoRequest', 1: 'AccDrvoffRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'AccDrvoff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq7f::AccdrvoffType accdrvoff(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'AccDeStopNoRequest', 1: 'AccDeStoprequest'}, 'is_signed_var': False, 'len': 1, 'name': 'AccDeStop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq7f::AccdestopType accdestop(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'AccMaxjerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'Float64'}
  Float64 accmaxjerk(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'AccMinjerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'Float64'}
  Float64 accminjerk(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'AccModeOffMode', 1: 'AccModePassiveMode', 2: 'AccModeStandbyMode', 3: 'AccModeActiveControlMode', 4: 'AccModeBrakeOnlyMode', 5: 'AccModeOverrideMode', 6: 'AccModeStandstillMode', 7: 'AccModeFailureMode'}, 'is_signed_var': False, 'len': 3, 'name': 'AccMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq7f::AccmodeType accmode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'AccComforlow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
  Float64 acccomforlow(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'AccComforup', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
  Float64 acccomforup(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'AccHvydecelNotRequest', 1: 'AccHvydecelrequest'}, 'is_signed_var': False, 'len': 1, 'name': 'AccHvydecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq7f::AcchvydecelType acchvydecel(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 30, 'enum': {0: 'AccHeavymodeinactive', 1: 'AccHeavymodereserved1', 2: 'AccHeavymodereserved2', 3: 'AccHeavymodeactive'}, 'is_signed_var': False, 'len': 2, 'name': 'AccHeavymode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Accreq7f::AccheavymodeType accheavymode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'AccTara', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'Float64'}
  Float64 acctara(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AccMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 accmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AccCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 acccrc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


