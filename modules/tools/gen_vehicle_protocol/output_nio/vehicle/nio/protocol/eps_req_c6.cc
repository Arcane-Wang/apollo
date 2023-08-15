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

const int32_t Epsreqc6::ID = 0xc6;

// public
Epsreqc6::Epsreqc6() { Reset(); }

uint32_t Epsreqc6::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Epsreqc6::UpdateData(uint8_t* data) {
  set_p_e_p_s_p_a_i_req(data, e_p_s_p_a_i_req_);
  set_p_e_p_s_d_a_i_req(data, e_p_s_d_a_i_req_);
  set_p_e_p_s_t_o_i_req(data, e_p_s_t_o_i_req_);
  set_p_e_p_s_req_typ(data, e_p_s_req_typ_);
  set_p_sys_valid(data, sys_valid_);
  set_p_pilot_sym(data, pilot_sym_);
  set_p_e_p_s__c_r_c(data, e_p_s__c_r_c_);
  set_p_e_p_s__msg_cntr(data, e_p_s__msg_cntr_);
  set_p_a_d_c__a_c_c_sym(data, a_d_c__a_c_c_sym_);
}

void Epsreqc6::Reset() {
  // TODO(All) :  you should check this manually
  e_p_s_p_a_i_req_ = 0;
  e_p_s_d_a_i_req_ = 0;
  e_p_s_t_o_i_req_ = 0;
  e_p_s_req_typ_ = atlas_messages::eps_req_c6::EPSReqTypType::E_P_S_R_E_Q_T_Y_P__N_O__R_E_Q_U_E_S_T;
  sys_valid_ = atlas_messages::eps_req_c6::SysValidType::S_Y_S_V_A_L_I_D__I_N_V_A_L_I_D;
  pilot_sym_ = atlas_messages::eps_req_c6::PilotSymType::P_I_L_O_T_S_Y_M__N_O__S_Y_M_B_O_L;
  e_p_s__c_r_c_ = 0;
  e_p_s__msg_cntr_ = 0;
  a_d_c__a_c_c_sym_ = atlas_messages::eps_req_c6::ADC_ACCSymType::A_D_C__A_C_C_S_Y_M__N_O__S_Y_M_B_O_L;
}

Epsreqc6* Epsreqc6::set_e_p_s_p_a_i_req(
     e_p_s_p_a_i_req) {
  e_p_s_p_a_i_req_ = e_p_s_p_a_i_req;
  return this;
 }

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'EPSPAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
void Epsreqc6::set_p_e_p_s_p_a_i_req(uint8_t* data,
     e_p_s_p_a_i_req) {
  e_p_s_p_a_i_req = ProtocolData::BoundedValue(-1638.4, 1638.3, e_p_s_p_a_i_req);
  int x =  (e_p_s_p_a_i_req - -1638.400000) / 0.100000;
  uint8_t t = 0;

  t = x & 0x7F;
  Byte to_set0(data + 7);
  to_set0.set_value(t, 1, 7);
  x >>= 7;

  t = x & 0xFF;
  Byte to_set1(data + 6);
  to_set1.set_value(t, 0, 8);
}


Epsreqc6* Epsreqc6::set_e_p_s_d_a_i_req(
     e_p_s_d_a_i_req) {
  e_p_s_d_a_i_req_ = e_p_s_d_a_i_req;
  return this;
 }

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'EPSDAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
void Epsreqc6::set_p_e_p_s_d_a_i_req(uint8_t* data,
     e_p_s_d_a_i_req) {
  e_p_s_d_a_i_req = ProtocolData::BoundedValue(-1638.4, 1638.3, e_p_s_d_a_i_req);
  int x =  (e_p_s_d_a_i_req - -1638.400000) / 0.100000;
  uint8_t t = 0;

  t = x & 0x7F;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 1, 7);
  x >>= 7;

  t = x & 0xFF;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 8);
}


Epsreqc6* Epsreqc6::set_e_p_s_t_o_i_req(
     e_p_s_t_o_i_req) {
  e_p_s_t_o_i_req_ = e_p_s_t_o_i_req;
  return this;
 }

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'EPSTOIReq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
void Epsreqc6::set_p_e_p_s_t_o_i_req(uint8_t* data,
     e_p_s_t_o_i_req) {
  e_p_s_t_o_i_req = ProtocolData::BoundedValue(-10.24, 10.22, e_p_s_t_o_i_req);
  int x =  (e_p_s_t_o_i_req - -10.240000) / 0.020000;
  uint8_t t = 0;

  t = x & 0x3F;
  Byte to_set0(data + 3);
  to_set0.set_value(t, 2, 6);
  x >>= 6;

  t = x & 0xF;
  Byte to_set1(data + 2);
  to_set1.set_value(t, 0, 4);
}


Epsreqc6* Epsreqc6::set_e_p_s_req_typ(
    ::atlas_messages::eps_req_c6::EPSReqTypType e_p_s_req_typ) {
  e_p_s_req_typ_ = e_p_s_req_typ;
  return this;
 }

// config detail: {'bit': 23, 'enum': {0: 'EPSREQTYP_NO_REQUEST', 1: 'EPSREQTYP_RESERVED_1_DSR', 2: 'EPSREQTYP_TOI_REQUEST', 3: 'EPSREQTYP_PAI_REQUEST', 4: 'EPSREQTYP_DAI_REQUEST', 5: 'EPSREQTYP_HI_1_REQUEST', 6: 'EPSREQTYP_HI_2_REQUEST', 7: 'EPSREQTYP_RESERVED_7', 8: 'EPSREQTYP_RESERVED_8', 9: 'EPSREQTYP_RESERVED_9', 10: 'EPSREQTYP_RESERVED_10', 11: 'EPSREQTYP_RESERVED_11', 12: 'EPSREQTYP_RESERVED_12', 13: 'EPSREQTYP_RESERVED_13', 14: 'EPSREQTYP_RESERVED_14', 15: 'EPSREQTYP_SIGNAL_NOT_AVAILABLE'}, 'is_signed_var': False, 'len': 4, 'name': 'EPSReqTyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_e_p_s_req_typ(uint8_t* data,
    ::atlas_messages::eps_req_c6::EPSReqTypType e_p_s_req_typ) {
  int x = static_cast<uint32_t>( e_p_s_req_typ );

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 4);
}


Epsreqc6* Epsreqc6::set_sys_valid(
    ::atlas_messages::eps_req_c6::SysValidType sys_valid) {
  sys_valid_ = sys_valid;
  return this;
 }

// config detail: {'bit': 40, 'enum': {0: 'SYSVALID_INVALID', 1: 'SYSVALID_VALID'}, 'is_signed_var': False, 'len': 1, 'name': 'SysValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_sys_valid(uint8_t* data,
    ::atlas_messages::eps_req_c6::SysValidType sys_valid) {
  int x = static_cast<uint32_t>( sys_valid );

  Byte to_set(data + 5);
  to_set.set_value(x, 0, 1);
}


Epsreqc6* Epsreqc6::set_pilot_sym(
    ::atlas_messages::eps_req_c6::PilotSymType pilot_sym) {
  pilot_sym_ = pilot_sym;
  return this;
 }

// config detail: {'bit': 25, 'enum': {0: 'PILOTSYM_NO_SYMBOL', 1: 'PILOTSYM_GRAY_SYMBOL', 2: 'PILOTSYM_WHITE_SYMBOL', 3: 'PILOTSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PilotSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_pilot_sym(uint8_t* data,
    ::atlas_messages::eps_req_c6::PilotSymType pilot_sym) {
  int x = static_cast<uint32_t>( pilot_sym );

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 2);
}


Epsreqc6* Epsreqc6::set_e_p_s__c_r_c(
     e_p_s__c_r_c) {
  e_p_s__c_r_c_ = e_p_s__c_r_c;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Epsreqc6::set_p_e_p_s__c_r_c(uint8_t* data,
     e_p_s__c_r_c) {
  e_p_s__c_r_c = ProtocolData::BoundedValue(0, 255, e_p_s__c_r_c);
  int x =  e_p_s__c_r_c;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}


Epsreqc6* Epsreqc6::set_e_p_s__msg_cntr(
     e_p_s__msg_cntr) {
  e_p_s__msg_cntr_ = e_p_s__msg_cntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Epsreqc6::set_p_e_p_s__msg_cntr(uint8_t* data,
     e_p_s__msg_cntr) {
  e_p_s__msg_cntr = ProtocolData::BoundedValue(0, 15, e_p_s__msg_cntr);
  int x =  e_p_s__msg_cntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Epsreqc6* Epsreqc6::set_a_d_c__a_c_c_sym(
    ::atlas_messages::eps_req_c6::ADC_ACCSymType a_d_c__a_c_c_sym) {
  a_d_c__a_c_c_sym_ = a_d_c__a_c_c_sym;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'ADC_ACCSYM_NO_SYMBOL', 1: 'ADC_ACCSYM_GRAY_SYMBOL', 2: 'ADC_ACCSYM_WHITE_SYMBOL', 3: 'ADC_ACCSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'ADC_ACCSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Epsreqc6::set_p_a_d_c__a_c_c_sym(uint8_t* data,
    ::atlas_messages::eps_req_c6::ADC_ACCSymType a_d_c__a_c_c_sym) {
  int x = static_cast<uint32_t>( a_d_c__a_c_c_sym );

  Byte to_set(data + 1);
  to_set.set_value(x, 2, 2);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
