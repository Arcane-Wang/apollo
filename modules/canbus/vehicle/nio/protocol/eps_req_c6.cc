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

#include "modules/canbus/vehicle/nio/protocol/eps_req_c6.h"

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
  chassis->mutable_nio()->mutable_eps_req_c6()->set_epspaireq(epspaireq(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_epsdaireq(epsdaireq(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_epstoireq(epstoireq(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_epsreqtyp(epsreqtyp(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_sysvalid(sysvalid(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_pilotsym(pilotsym(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_eps_crc(eps_crc(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_eps_msgcntr(eps_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_eps_req_c6()->set_adc_accsym(adc_accsym(bytes, length));
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

// config detail: {'bit': 23, 'enum': {0: 'EPSREQTYP_NO_REQUEST', 1: 'EPSREQTYP_RESERVED_1_DSR', 2: 'EPSREQTYP_TOI_REQUEST', 3: 'EPSREQTYP_PAI_REQUEST', 4: 'EPSREQTYP_DAI_REQUEST', 5: 'EPSREQTYP_HI_1_REQUEST', 6: 'EPSREQTYP_HI_2_REQUEST', 7: 'EPSREQTYP_RESERVED_7', 8: 'EPSREQTYP_RESERVED_8', 9: 'EPSREQTYP_RESERVED_9', 10: 'EPSREQTYP_RESERVED_10', 11: 'EPSREQTYP_RESERVED_11', 12: 'EPSREQTYP_RESERVED_12', 13: 'EPSREQTYP_RESERVED_13', 14: 'EPSREQTYP_RESERVED_14', 15: 'EPSREQTYP_SIGNAL_NOT_AVAILABLE'}, 'is_signed_var': False, 'len': 4, 'name': 'epsreqtyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Eps_req_c6::EpsreqtypType Epsreqc6::epsreqtyp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 4);

  Eps_req_c6::EpsreqtypType ret =  static_cast<Eps_req_c6::EpsreqtypType>(x);
  return ret;
}

// config detail: {'bit': 40, 'enum': {0: 'SYSVALID_INVALID', 1: 'SYSVALID_VALID'}, 'is_signed_var': False, 'len': 1, 'name': 'sysvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Eps_req_c6::SysvalidType Epsreqc6::sysvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  Eps_req_c6::SysvalidType ret =  static_cast<Eps_req_c6::SysvalidType>(x);
  return ret;
}

// config detail: {'bit': 25, 'enum': {0: 'PILOTSYM_NO_SYMBOL', 1: 'PILOTSYM_GRAY_SYMBOL', 2: 'PILOTSYM_WHITE_SYMBOL', 3: 'PILOTSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'pilotsym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Eps_req_c6::PilotsymType Epsreqc6::pilotsym(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Eps_req_c6::PilotsymType ret =  static_cast<Eps_req_c6::PilotsymType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'eps_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsreqc6::eps_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'eps_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Epsreqc6::eps_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'ADC_ACCSYM_NO_SYMBOL', 1: 'ADC_ACCSYM_GRAY_SYMBOL', 2: 'ADC_ACCSYM_WHITE_SYMBOL', 3: 'ADC_ACCSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'adc_accsym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Eps_req_c6::Adc_accsymType Epsreqc6::adc_accsym(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  Eps_req_c6::Adc_accsymType ret =  static_cast<Eps_req_c6::Adc_accsymType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
