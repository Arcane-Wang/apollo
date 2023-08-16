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

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Epsreqc6::ID = 0xC6;

// public
Epsreqc6::Epsreqc6() { Reset(); }

uint32_t Epsreqc6::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Epsreqc6::UpdateData(uint8_t* data) {
  set_p_epspaireq(data, epspaireq_);
  set_p_epsdaireq(data, epsdaireq_);
  set_p_epstoireq(data, epstoireq_);
  set_p_epsreqtyp(data, epsreqtyp_);
  set_p_sysvalid(data, sysvalid_);
  set_p_pilotsym(data, pilotsym_);
  set_p_eps_crc(data, eps_crc_);
  set_p_eps_msgcntr(data, eps_msgcntr_);
  set_p_adc_accsym(data, adc_accsym_);
}

void Epsreqc6::Reset() {
  // TODO(All) :  you should check this manually
  epspaireq_ = 0.0;
  epsdaireq_ = 0.0;
  epstoireq_ = 0.0;
  epsreqtyp_ = Eps_req_c6::EPSREQTYP_NO_REQUEST;
  sysvalid_ = Eps_req_c6::SYSVALID_INVALID;
  pilotsym_ = Eps_req_c6::PILOTSYM_NO_SYMBOL;
  eps_crc_ = 0;
  eps_msgcntr_ = 0;
  adc_accsym_ = Eps_req_c6::ADC_ACCSYM_NO_SYMBOL;
}

Epsreqc6* Epsreqc6::set_epspaireq(
    double epspaireq) {
  epspaireq_ = epspaireq;
  return this;
 }

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'EPSPAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
void Epsreqc6::set_p_epspaireq(uint8_t* data,
    double epspaireq) {
  epspaireq = ProtocolData::BoundedValue(-1638.4, 1638.3, epspaireq);
  int x = (epspaireq - -1638.400000) / 0.100000;
  uint8_t t = 0;

  t = x & 0x7F;
  Byte to_set0(data + 7);
  to_set0.set_value(t, 1, 7);
  x >>= 7;

  t = x & 0xFF;
  Byte to_set1(data + 6);
  to_set1.set_value(t, 0, 8);
}


Epsreqc6* Epsreqc6::set_epsdaireq(
    double epsdaireq) {
  epsdaireq_ = epsdaireq;
  return this;
 }

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'EPSDAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
void Epsreqc6::set_p_epsdaireq(uint8_t* data,
    double epsdaireq) {
  epsdaireq = ProtocolData::BoundedValue(-1638.4, 1638.3, epsdaireq);
  int x = (epsdaireq - -1638.400000) / 0.100000;
  uint8_t t = 0;

  t = x & 0x7F;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 1, 7);
  x >>= 7;

  t = x & 0xFF;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 8);
}


Epsreqc6* Epsreqc6::set_epstoireq(
    double epstoireq) {
  epstoireq_ = epstoireq;
  return this;
 }

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'EPSTOIReq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
void Epsreqc6::set_p_epstoireq(uint8_t* data,
    double epstoireq) {
  epstoireq = ProtocolData::BoundedValue(-10.24, 10.22, epstoireq);
  int x = (epstoireq - -10.240000) / 0.020000;
  uint8_t t = 0;

  t = x & 0x3F;
  Byte to_set0(data + 3);
  to_set0.set_value(t, 2, 6);
  x >>= 6;

  t = x & 0xF;
  Byte to_set1(data + 2);
  to_set1.set_value(t, 0, 4);
}


Epsreqc6* Epsreqc6::set_epsreqtyp(
    Eps_req_c6::EpsreqtypType epsreqtyp) {
  epsreqtyp_ = epsreqtyp;
  return this;
 }

// config detail: {'bit': 23, 'enum': {0: 'EPSREQTYP_NO_REQUEST', 1: 'EPSREQTYP_RESERVED_1_DSR', 2: 'EPSREQTYP_TOI_REQUEST', 3: 'EPSREQTYP_PAI_REQUEST', 4: 'EPSREQTYP_DAI_REQUEST', 5: 'EPSREQTYP_HI_1_REQUEST', 6: 'EPSREQTYP_HI_2_REQUEST', 7: 'EPSREQTYP_RESERVED_7', 8: 'EPSREQTYP_RESERVED_8', 9: 'EPSREQTYP_RESERVED_9', 10: 'EPSREQTYP_RESERVED_10', 11: 'EPSREQTYP_RESERVED_11', 12: 'EPSREQTYP_RESERVED_12', 13: 'EPSREQTYP_RESERVED_13', 14: 'EPSREQTYP_RESERVED_14', 15: 'EPSREQTYP_SIGNAL_NOT_AVAILABLE'}, 'is_signed_var': False, 'len': 4, 'name': 'EPSReqTyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_epsreqtyp(uint8_t* data,
    Eps_req_c6::EpsreqtypType epsreqtyp) {
  int x = epsreqtyp;

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 4);
}


Epsreqc6* Epsreqc6::set_sysvalid(
    Eps_req_c6::SysvalidType sysvalid) {
  sysvalid_ = sysvalid;
  return this;
 }

// config detail: {'bit': 40, 'enum': {0: 'SYSVALID_INVALID', 1: 'SYSVALID_VALID'}, 'is_signed_var': False, 'len': 1, 'name': 'SysValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_sysvalid(uint8_t* data,
    Eps_req_c6::SysvalidType sysvalid) {
  int x = sysvalid;

  Byte to_set(data + 5);
  to_set.set_value(x, 0, 1);
}


Epsreqc6* Epsreqc6::set_pilotsym(
    Eps_req_c6::PilotsymType pilotsym) {
  pilotsym_ = pilotsym;
  return this;
 }

// config detail: {'bit': 25, 'enum': {0: 'PILOTSYM_NO_SYMBOL', 1: 'PILOTSYM_GRAY_SYMBOL', 2: 'PILOTSYM_WHITE_SYMBOL', 3: 'PILOTSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PilotSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_pilotsym(uint8_t* data,
    Eps_req_c6::PilotsymType pilotsym) {
  int x = pilotsym;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 2);
}


Epsreqc6* Epsreqc6::set_eps_crc(
    int eps_crc) {
  eps_crc_ = eps_crc;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Epsreqc6::set_p_eps_crc(uint8_t* data,
    int eps_crc) {
  eps_crc = ProtocolData::BoundedValue(0, 255, eps_crc);
  int x = eps_crc;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}


Epsreqc6* Epsreqc6::set_eps_msgcntr(
    int eps_msgcntr) {
  eps_msgcntr_ = eps_msgcntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Epsreqc6::set_p_eps_msgcntr(uint8_t* data,
    int eps_msgcntr) {
  eps_msgcntr = ProtocolData::BoundedValue(0, 15, eps_msgcntr);
  int x = eps_msgcntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Epsreqc6* Epsreqc6::set_adc_accsym(
    Eps_req_c6::Adc_accsymType adc_accsym) {
  adc_accsym_ = adc_accsym;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'ADC_ACCSYM_NO_SYMBOL', 1: 'ADC_ACCSYM_GRAY_SYMBOL', 2: 'ADC_ACCSYM_WHITE_SYMBOL', 3: 'ADC_ACCSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'ADC_ACCSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_adc_accsym(uint8_t* data,
    Eps_req_c6::Adc_accsymType adc_accsym) {
  int x = adc_accsym;

  Byte to_set(data + 1);
  to_set.set_value(x, 2, 2);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
