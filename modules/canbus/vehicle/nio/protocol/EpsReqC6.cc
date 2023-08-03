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

#include "modules/canbus/vehicle/nio/protocol/EpsReqC6.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Epsreqc6::Epsreqc6() {}
const int32_t Epsreqc6::ID = 0xC6;

void Epsreqc6::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epspaireq(epspaireq(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epsdaireq(epsdaireq(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epstoireq(epstoireq(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epsreqtyp(epsreqtyp(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_sysvalid(sysvalid(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_pilotsym(pilotsym(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epscrc(epscrc(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_epsmsgcntr(epsmsgcntr(bytes, length));
  chassis->mutable_nio()->mutable_EpsReqC6()->set_adcaccsym(adcaccsym(bytes, length));
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'epspaireq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsreqc6::epspaireq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  double ret = x * 0.100000 + -1638.400000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'epsdaireq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
double Epsreqc6::epsdaireq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  double ret = x * 0.100000 + -1638.400000;
  return ret;
}

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'epstoireq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
double Epsreqc6::epstoireq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 0.020000 + -10.240000;
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'EPSReqTypNoRequest', 1: 'EPSReqTypReserved1DSR', 2: 'EPSReqTypTOIRequest', 3: 'EPSReqTypPAIRequest', 4: 'EPSReqTypDAIRequest', 5: 'EPSReqTypHI1Request', 6: 'EPSReqTypHI2Request', 7: 'EPSReqTypReserved7', 8: 'EPSReqTypReserved8', 9: 'EPSReqTypReserved9', 10: 'EPSReqTypReserved10', 11: 'EPSReqTypReserved11', 12: 'EPSReqTypReserved12', 13: 'EPSReqTypReserved13', 14: 'EPSReqTypReserved14', 15: 'EPSReqTypSignalNotAvailable'}, 'is_signed_var': False, 'len': 4, 'name': 'epsreqtyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsreqc6::EpsreqtypType Epsreqc6::epsreqtyp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 4);

  Epsreqc6::EpsreqtypType ret =  static_cast<Epsreqc6::EpsreqtypType>(x);
  return ret;
}

// config detail: {'bit': 40, 'enum': {0: 'SysValidInvalid', 1: 'SysValidValid'}, 'is_signed_var': False, 'len': 1, 'name': 'sysvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsreqc6::SysvalidType Epsreqc6::sysvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  Epsreqc6::SysvalidType ret =  static_cast<Epsreqc6::SysvalidType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'PilotSymNoSymbol', 1: 'PilotSymGraySymbol', 2: 'PilotSymWhiteSymbol', 3: 'PilotSymreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'pilotsym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsreqc6::PilotsymType Epsreqc6::pilotsym(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Epsreqc6::PilotsymType ret =  static_cast<Epsreqc6::PilotsymType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'epscrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsreqc6::epscrc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'epsmsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
int32_t Epsreqc6::epsmsgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int32_t ret = x;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'AdcAccsymNoSymbol', 1: 'AdcAccsymGraySymbol', 2: 'AdcAccsymWhiteSymbol', 3: 'AdcAccsymreserved'}, 'is_signed_var': False, 'len': 2, 'name': 'adcaccsym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Epsreqc6::AdcaccsymType Epsreqc6::adcaccsym(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  Epsreqc6::AdcaccsymType ret =  static_cast<Epsreqc6::AdcaccsymType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
