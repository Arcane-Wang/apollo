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

#include "modules/canbus/vehicle/nio/protocol/aebreq_79.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Aebreq79::ID = 0x79;

// public
Aebreq79::Aebreq79() { Reset(); }

uint32_t Aebreq79::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Aebreq79::UpdateData(uint8_t* data) {
  set_p_a_e_b_tar_decel(data, a_e_b_tar_decel_);
  set_p_a_b_a_req(data, a_b_a_req_);
  set_p_a_b_a_snvty_lvl(data, a_b_a_snvty_lvl_);
  set_p_a_w_b_snvty_lvl(data, a_w_b_snvty_lvl_);
  set_p_a_w_b_req(data, a_w_b_req_);
  set_p_s_c_m_decel_req(data, s_c_m_decel_req_);
  set_p_a_e_b__msg_cntr(data, a_e_b__msg_cntr_);
  set_p_a_e_b_decel_req(data, a_e_b_decel_req_);
  set_p_e_b_a_decel_req(data, e_b_a_decel_req_);
  set_p_a_b_p_req(data, a_b_p_req_);
  set_p_p_e_d_p_dec_req(data, p_e_d_p_dec_req_);
  set_p_a_e_b__c_r_c(data, a_e_b__c_r_c_);
}

void Aebreq79::Reset() {
  // TODO(All) :  you should check this manually
  a_e_b_tar_decel_ = 0;
  a_b_a_req_ = atlas_messages::aebreq_79::ABAReqType::A_B_A_R_E_Q__N_O__R_E_Q_U_E_S_T;
  a_b_a_snvty_lvl_ = atlas_messages::aebreq_79::ABASnvtyLvlType::A_B_A_S_N_V_T_Y_L_V_L__L_E_V_E_L_0;
  a_w_b_snvty_lvl_ = atlas_messages::aebreq_79::AWBSnvtyLvlType::A_W_B_S_N_V_T_Y_L_V_L__L_E_V_E_L_0;
  a_w_b_req_ = atlas_messages::aebreq_79::AWBReqType::A_W_B_R_E_Q__N_O__R_E_Q_U_E_S_T;
  s_c_m_decel_req_ = atlas_messages::aebreq_79::SCMDecelReqType::S_C_M_D_E_C_E_L_R_E_Q__N_O__R_E_Q_U_E_S_T;
  a_e_b__msg_cntr_ = 0;
  a_e_b_decel_req_ = atlas_messages::aebreq_79::AEBDecelReqType::A_E_B_D_E_C_E_L_R_E_Q__N_O__R_E_Q_U_E_S_T;
  e_b_a_decel_req_ = atlas_messages::aebreq_79::EBADecelReqType::E_B_A_D_E_C_E_L_R_E_Q__N_O__R_E_Q_U_E_S_T;
  a_b_p_req_ = atlas_messages::aebreq_79::ABPReqType::A_B_P_R_E_Q__N_O__R_E_Q_U_E_S_T;
  p_e_d_p_dec_req_ = atlas_messages::aebreq_79::PEDPDecReqType::P_E_D_P_D_E_C_R_E_Q__N_O__R_E_Q_U_E_S_T;
  a_e_b__c_r_c_ = 0;
}

Aebreq79* Aebreq79::set_a_e_b_tar_decel(
     a_e_b_tar_decel) {
  a_e_b_tar_decel_ = a_e_b_tar_decel;
  return this;
 }

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'AEBTarDecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
void Aebreq79::set_p_a_e_b_tar_decel(uint8_t* data,
     a_e_b_tar_decel) {
  a_e_b_tar_decel = ProtocolData::BoundedValue(-16, 15.99, a_e_b_tar_decel);
  int x =  (a_e_b_tar_decel - -16.000000) / 0.000488;
  uint8_t t = 0;

  t = x & 0xF;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 4, 4);
  x >>= 4;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xF;
  Byte to_set2(data + 4);
  to_set2.set_value(t, 0, 4);
}


Aebreq79* Aebreq79::set_a_b_a_req(
    ::atlas_messages::aebreq_79::ABAReqType a_b_a_req) {
  a_b_a_req_ = a_b_a_req;
  return this;
 }

// config detail: {'bit': 28, 'enum': {0: 'ABAREQ_NO_REQUEST', 1: 'ABAREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_b_a_req(uint8_t* data,
    ::atlas_messages::aebreq_79::ABAReqType a_b_a_req) {
  int x = static_cast<uint32_t>( a_b_a_req );

  Byte to_set(data + 3);
  to_set.set_value(x, 4, 1);
}


Aebreq79* Aebreq79::set_a_b_a_snvty_lvl(
    ::atlas_messages::aebreq_79::ABASnvtyLvlType a_b_a_snvty_lvl) {
  a_b_a_snvty_lvl_ = a_b_a_snvty_lvl;
  return this;
 }

// config detail: {'bit': 26, 'enum': {0: 'ABASNVTYLVL_LEVEL_0', 1: 'ABASNVTYLVL_LEVEL_1', 2: 'ABASNVTYLVL_LEVEL_2', 3: 'ABASNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'ABASnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_b_a_snvty_lvl(uint8_t* data,
    ::atlas_messages::aebreq_79::ABASnvtyLvlType a_b_a_snvty_lvl) {
  int x = static_cast<uint32_t>( a_b_a_snvty_lvl );

  Byte to_set(data + 3);
  to_set.set_value(x, 1, 2);
}


Aebreq79* Aebreq79::set_a_w_b_snvty_lvl(
    ::atlas_messages::aebreq_79::AWBSnvtyLvlType a_w_b_snvty_lvl) {
  a_w_b_snvty_lvl_ = a_w_b_snvty_lvl;
  return this;
 }

// config detail: {'bit': 38, 'enum': {0: 'AWBSNVTYLVL_LEVEL_0', 1: 'AWBSNVTYLVL_LEVEL_1', 2: 'AWBSNVTYLVL_LEVEL_2', 3: 'AWBSNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'AWBSnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_w_b_snvty_lvl(uint8_t* data,
    ::atlas_messages::aebreq_79::AWBSnvtyLvlType a_w_b_snvty_lvl) {
  int x = static_cast<uint32_t>( a_w_b_snvty_lvl );

  Byte to_set(data + 4);
  to_set.set_value(x, 5, 2);
}


Aebreq79* Aebreq79::set_a_w_b_req(
    ::atlas_messages::aebreq_79::AWBReqType a_w_b_req) {
  a_w_b_req_ = a_w_b_req;
  return this;
 }

// config detail: {'bit': 30, 'enum': {0: 'AWBREQ_NO_REQUEST', 1: 'AWBREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_w_b_req(uint8_t* data,
    ::atlas_messages::aebreq_79::AWBReqType a_w_b_req) {
  int x = static_cast<uint32_t>( a_w_b_req );

  Byte to_set(data + 3);
  to_set.set_value(x, 6, 1);
}


Aebreq79* Aebreq79::set_s_c_m_decel_req(
    ::atlas_messages::aebreq_79::SCMDecelReqType s_c_m_decel_req) {
  s_c_m_decel_req_ = s_c_m_decel_req;
  return this;
 }

// config detail: {'bit': 18, 'enum': {0: 'SCMDECELREQ_NO_REQUEST', 1: 'SCMDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_s_c_m_decel_req(uint8_t* data,
    ::atlas_messages::aebreq_79::SCMDecelReqType s_c_m_decel_req) {
  int x = static_cast<uint32_t>( s_c_m_decel_req );

  Byte to_set(data + 2);
  to_set.set_value(x, 2, 1);
}


Aebreq79* Aebreq79::set_a_e_b__msg_cntr(
     a_e_b__msg_cntr) {
  a_e_b__msg_cntr_ = a_e_b__msg_cntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AEB_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Aebreq79::set_p_a_e_b__msg_cntr(uint8_t* data,
     a_e_b__msg_cntr) {
  a_e_b__msg_cntr = ProtocolData::BoundedValue(0, 15, a_e_b__msg_cntr);
  int x =  a_e_b__msg_cntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Aebreq79* Aebreq79::set_a_e_b_decel_req(
    ::atlas_messages::aebreq_79::AEBDecelReqType a_e_b_decel_req) {
  a_e_b_decel_req_ = a_e_b_decel_req;
  return this;
 }

// config detail: {'bit': 22, 'enum': {0: 'AEBDECELREQ_NO_REQUEST', 1: 'AEBDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_e_b_decel_req(uint8_t* data,
    ::atlas_messages::aebreq_79::AEBDecelReqType a_e_b_decel_req) {
  int x = static_cast<uint32_t>( a_e_b_decel_req );

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 1);
}


Aebreq79* Aebreq79::set_e_b_a_decel_req(
    ::atlas_messages::aebreq_79::EBADecelReqType e_b_a_decel_req) {
  e_b_a_decel_req_ = e_b_a_decel_req;
  return this;
 }

// config detail: {'bit': 31, 'enum': {0: 'EBADECELREQ_NO_REQUEST', 1: 'EBADECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'EBADecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_e_b_a_decel_req(uint8_t* data,
    ::atlas_messages::aebreq_79::EBADecelReqType e_b_a_decel_req) {
  int x = static_cast<uint32_t>( e_b_a_decel_req );

  Byte to_set(data + 3);
  to_set.set_value(x, 7, 1);
}


Aebreq79* Aebreq79::set_a_b_p_req(
    ::atlas_messages::aebreq_79::ABPReqType a_b_p_req) {
  a_b_p_req_ = a_b_p_req;
  return this;
 }

// config detail: {'bit': 16, 'enum': {0: 'ABPREQ_NO_REQUEST', 1: 'ABPREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_a_b_p_req(uint8_t* data,
    ::atlas_messages::aebreq_79::ABPReqType a_b_p_req) {
  int x = static_cast<uint32_t>( a_b_p_req );

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 1);
}


Aebreq79* Aebreq79::set_p_e_d_p_dec_req(
    ::atlas_messages::aebreq_79::PEDPDecReqType p_e_d_p_dec_req) {
  p_e_d_p_dec_req_ = p_e_d_p_dec_req;
  return this;
 }

// config detail: {'bit': 20, 'enum': {0: 'PEDPDECREQ_NO_REQUEST', 1: 'PEDPDECREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPDecReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Aebreq79::set_p_p_e_d_p_dec_req(uint8_t* data,
    ::atlas_messages::aebreq_79::PEDPDecReqType p_e_d_p_dec_req) {
  int x = static_cast<uint32_t>( p_e_d_p_dec_req );

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 1);
}


Aebreq79* Aebreq79::set_a_e_b__c_r_c(
     a_e_b__c_r_c) {
  a_e_b__c_r_c_ = a_e_b__c_r_c;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AEB_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Aebreq79::set_p_a_e_b__c_r_c(uint8_t* data,
     a_e_b__c_r_c) {
  a_e_b__c_r_c = ProtocolData::BoundedValue(0, 255, a_e_b__c_r_c);
  int x =  a_e_b__c_r_c;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
