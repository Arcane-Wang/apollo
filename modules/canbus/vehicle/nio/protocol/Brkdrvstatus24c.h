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

class Brkdrvstatus24c : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Brkdrvstatus24c();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 4, 'name': 'BrkMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|16]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 brkmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'BrkpressureStsNotInit', 1: 'BrkpressureStsnormal', 2: 'BrkpressureStsfault'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkpressureSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::BrkpressurestsType brkpressurests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 10, 'name': 'Brkpressure', 'offset': -30.0, 'order': 'motorola', 'physical_range': '[-30|276.6]', 'physical_unit': 'bar', 'precision': 0.3, 'type': 'Float64'}
  Float64 brkpressure(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'LongAccValue', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[2|2]', 'physical_unit': 'g', 'precision': 0.001, 'type': 'Float64'}
  Float64 longaccvalue(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'Vehspdstsvalid', 1: 'Vehspdstsinvalid'}, 'is_signed_var': False, 'len': 1, 'name': 'Vehspdsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::VehspdstsType vehspdsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'enum': {0: 'Vehspddirstandstill', 1: 'Vehspddirforward', 2: 'Vehspddirbackward', 3: 'Vehspddirreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'Vehspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::VehspddirType vehspddir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 22, 'is_signed_var': False, 'len': 13, 'name': 'Vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 1.0, 'type': 'Int32'}
  Int32 vehspd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'enum': {0: 'EPBswstsNotPressed', 1: 'EPBswstspressed', 2: 'EPBswstsreserved', 3: 'EPBswstsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBswsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::EpbswstsType epbswsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'enum': {0: 'DrvStateParked', 1: 'DrvStateReadyForDrving', 2: 'DrvStatedriving', 3: 'DrvStateinvalid', 15: 'DrvStateInvalidOtherValuesReserved'}, 'is_signed_var': False, 'len': 4, 'name': 'DrvState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::DrvstateType drvstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'enum': {0: 'BrkPedlStsNotPressed', 1: 'BrkPedlStspressed', 2: 'BrkPedlStsreserved', 3: 'BrkPedlStsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkPedlSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::BrkpedlstsType brkpedlsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'enum': {0: 'BrkListsNoRequest', 1: 'BrkListsrequest', 2: 'BrkListsreserved', 3: 'BrkListsinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::BrklistsType brklists(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'enum': {0: 'EPBfaillampoff', 1: 'EPBfaillampon', 2: 'EPBfaillampblinking', 3: 'EPBfaillampinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBfaillamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::EpbfaillampType epbfaillamp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'EPBwarnlampOnlyReadyDuringFunction', 1: 'EPBwarnlampDoorOpenDuringAuto', 2: 'EPBwarnlampSeatBeltUnbuckled', 3: 'EPBwarnlampDoorOpenAndBeltUnbuckled'}, 'is_signed_var': False, 'len': 2, 'name': 'EPBwarnlamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brkdrvstatus24c::EpbwarnlampType epbwarnlamp(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


