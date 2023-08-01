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

class Epsreqc6 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsreqc6();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'EPSPAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'Float64'}
  Float64 epspaireq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'EPSDAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'Float64'}
  Float64 epsdaireq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'EPSTOIReq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'Float64'}
  Float64 epstoireq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'enum': {0: 'EPSReqTypNoRequest', 1: 'EPSReqTypReserved1DSR', 2: 'EPSReqTypTOIRequest', 3: 'EPSReqTypPAIRequest', 4: 'EPSReqTypDAIRequest', 5: 'EPSReqTypHI1Request', 6: 'EPSReqTypHI2Request', 7: 'EPSReqTypReserved7', 8: 'EPSReqTypReserved8', 9: 'EPSReqTypReserved9', 10: 'EPSReqTypReserved10', 11: 'EPSReqTypReserved11', 12: 'EPSReqTypReserved12', 13: 'EPSReqTypReserved13', 14: 'EPSReqTypReserved14', 15: 'EPSReqTypSignalNotAvailable'}, 'is_signed_var': False, 'len': 4, 'name': 'EPSReqTyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6::EpsreqtypType epsreqtyp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'enum': {0: 'SysValidInvalid', 1: 'SysValidValid'}, 'is_signed_var': False, 'len': 1, 'name': 'SysValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6::SysvalidType sysvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'enum': {0: 'PilotSymNoSymbol', 1: 'PilotSymGraySymbol', 2: 'PilotSymWhiteSymbol', 3: 'PilotSymreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'PilotSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6::PilotsymType pilotsym(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EpsCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 epscrc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EpsMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'Int32'}
  Int32 epsmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'enum': {0: 'AdcAccsymNoSymbol', 1: 'AdcAccsymGraySymbol', 2: 'AdcAccsymWhiteSymbol', 3: 'AdcAccsymreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'AdcAccsym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6::AdcaccsymType adcaccsym(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


