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

#include "modules/canbus/vehicle/nio/protocol/avp_req_15e.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Avpreq15e::ID = 0x15e;

// public
Avpreq15e::Avpreq15e() { Reset(); }

uint32_t Avpreq15e::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Avpreq15e::UpdateData(uint8_t* data) {
  set_p_avp__apa_park_mod(data, avp__apa_park_mod_);
  set_p_avp__n_b_s_sts(data, avp__n_b_s_sts_);
  set_p_avp__a_d_c_v_c_u_n_b_s_s_ts(data, avp__a_d_c_v_c_u_n_b_s_s_ts_);
  set_p_avp__apa_sts(data, avp__apa_sts_);
  set_p_avp__brk_mod_sts(data, avp__brk_mod_sts_);
  set_p_avp__spd_lmt(data, avp__spd_lmt_);
  set_p_avp__gear_req_ac_tv(data, avp__gear_req_ac_tv_);
  set_p_avp__msg_cntr(data, avp__msg_cntr_);
  set_p_avp__c_r_c(data, avp__c_r_c_);
  set_p_avp__dst_req(data, avp__dst_req_);
  set_p_avp__tar_gear_req(data, avp__tar_gear_req_);
  set_p_av_p__crtl_mode(data, av_p__crtl_mode_);
}

void Avpreq15e::Reset() {
  // TODO(All) :  you should check this manually
  avp__apa_park_mod_ = atlas_messages::avp_req_15e::Avp_ApaParkModType::A_V_P__A_P_A_P_A_R_K_M_O_D__O_F_F;
  avp__n_b_s_sts_ = atlas_messages::avp_req_15e::Avp_NBSStsType::A_V_P__N_B_S_S_T_S__N_B_S__O_F_F;
  avp__a_d_c_v_c_u_n_b_s_s_ts_ = atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType::A_V_P__A_D_C_V_C_U_N_B_S_S_T_S__N_B_S__O_F_F;
  avp__apa_sts_ = atlas_messages::avp_req_15e::Avp_ApaStsType::A_V_P__A_P_A_S_T_S__I_N_I_T_I_A_L;
  avp__brk_mod_sts_ = atlas_messages::avp_req_15e::Avp_BrkModStsType::A_V_P__B_R_K_M_O_D_S_T_S__N_O__B_R_A_K_E;
  avp__spd_lmt_ = 0;
  avp__gear_req_ac_tv_ = 0;
  avp__msg_cntr_ = 0;
  avp__c_r_c_ = 0;
  avp__dst_req_ = 0;
  avp__tar_gear_req_ = atlas_messages::avp_req_15e::Avp_TarGearReqType::A_V_P__T_A_R_G_E_A_R_R_E_Q__N_O__G_E_A_R__R_E_Q_U_E_S_T;
  av_p__crtl_mode_ = atlas_messages::avp_req_15e::AvP_CrtlModeType::A_V_P__C_R_T_L_M_O_D_E__N_O;
}

Avpreq15e* Avpreq15e::set_avp__apa_park_mod(
    ::atlas_messages::avp_req_15e::Avp_ApaParkModType avp__apa_park_mod) {
  avp__apa_park_mod_ = avp__apa_park_mod;
  return this;
 }

// config detail: {'bit': 39, 'enum': {0: 'AVP_APAPARKMOD_OFF', 1: 'AVP_APAPARKMOD_SAPA', 2: 'AVP_APAPARKMOD_VPPS', 3: 'AVP_APAPARKMOD_NBS', 4: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X5', 6: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_ApaParkMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__apa_park_mod(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_ApaParkModType avp__apa_park_mod) {
  int x = static_cast<uint32_t>( avp__apa_park_mod );

  Byte to_set(data + 4);
  to_set.set_value(x, 5, 3);
}


Avpreq15e* Avpreq15e::set_avp__n_b_s_sts(
    ::atlas_messages::avp_req_15e::Avp_NBSStsType avp__n_b_s_sts) {
  avp__n_b_s_sts_ = avp__n_b_s_sts;
  return this;
 }

// config detail: {'bit': 19, 'enum': {0: 'AVP_NBSSTS_NBS_OFF', 1: 'AVP_NBSSTS_NBS_INITIAL', 2: 'AVP_NBSSTS_NBS_STANDBY', 3: 'AVP_NBSSTS_NBS_MOVING', 4: 'AVP_NBSSTS_NBS_ABORT', 5: 'AVP_NBSSTS_NBS_FAIL', 6: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_NBSSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__n_b_s_sts(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_NBSStsType avp__n_b_s_sts) {
  int x = static_cast<uint32_t>( avp__n_b_s_sts );

  Byte to_set(data + 2);
  to_set.set_value(x, 1, 3);
}


Avpreq15e* Avpreq15e::set_avp__a_d_c_v_c_u_n_b_s_s_ts(
    ::atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType avp__a_d_c_v_c_u_n_b_s_s_ts) {
  avp__a_d_c_v_c_u_n_b_s_s_ts_ = avp__a_d_c_v_c_u_n_b_s_s_ts;
  return this;
 }

// config detail: {'bit': 23, 'enum': {0: 'AVP_ADCVCUNBSSTS_NBS_OFF', 1: 'AVP_ADCVCUNBSSTS_NBS_INTIAL', 2: 'AVP_ADCVCUNBSSTS_NBS_STANDBY', 3: 'AVP_ADCVCUNBSSTS_NBS_MOVING', 4: 'AVP_ADCVCUNBSSTS_NBS_ABORT', 5: 'AVP_ADCVCUNBSSTS_NBS_FAIL', 6: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7', 8: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ADCVCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__a_d_c_v_c_u_n_b_s_s_ts(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType avp__a_d_c_v_c_u_n_b_s_s_ts) {
  int x = static_cast<uint32_t>( avp__a_d_c_v_c_u_n_b_s_s_ts );

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 4);
}


Avpreq15e* Avpreq15e::set_avp__apa_sts(
    ::atlas_messages::avp_req_15e::Avp_ApaStsType avp__apa_sts) {
  avp__apa_sts_ = avp__apa_sts;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'AVP_APASTS_INITIAL', 1: 'AVP_APASTS_STANDBY', 2: 'AVP_APASTS_SEARCH', 3: 'AVP_APASTS_PRE_GUIDENCE', 4: 'AVP_APASTS_GUIDANCE', 5: 'AVP_APASTS_RESERVED', 6: 'AVP_APASTS_ABORT', 7: 'AVP_APASTS_FAULT', 8: 'AVP_APASTS_PUB_ROAD', 9: 'AVP_APASTS_OFFMODE', 10: 'AVP_APASTS_RESERVED10', 11: 'AVP_APASTS_RESERVED11', 12: 'AVP_APASTS_RESERVED12', 13: 'AVP_APASTS_RESERVED13', 14: 'AVP_APASTS_RESERVED14', 15: 'AVP_APASTS_RESERVED15'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ApaSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__apa_sts(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_ApaStsType avp__apa_sts) {
  int x = static_cast<uint32_t>( avp__apa_sts );

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 4);
}


Avpreq15e* Avpreq15e::set_avp__brk_mod_sts(
    ::atlas_messages::avp_req_15e::Avp_BrkModStsType avp__brk_mod_sts) {
  avp__brk_mod_sts_ = avp__brk_mod_sts;
  return this;
 }

// config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AVP_BRKMODSTS_NO_BRAKE', 1: 'AVP_BRKMODSTS_COMFORT', 2: 'AVP_BRKMODSTS_EMERGENCY', 3: 'AVP_BRKMODSTS_RESERVED'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_BrkModSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__brk_mod_sts(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_BrkModStsType avp__brk_mod_sts) {
  int x = static_cast<uint32_t>( avp__brk_mod_sts );

  Byte to_set(data + 7);
  to_set.set_value(x, 1, 3);
}


Avpreq15e* Avpreq15e::set_avp__spd_lmt(
     avp__spd_lmt) {
  avp__spd_lmt_ = avp__spd_lmt;
  return this;
 }

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'Avp_SpdLmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
void Avpreq15e::set_p_avp__spd_lmt(uint8_t* data,
     avp__spd_lmt) {
  avp__spd_lmt = ProtocolData::BoundedValue(-3.2, 3.1, avp__spd_lmt);
  int x =  (avp__spd_lmt - -3.200000) / 0.100000;

  Byte to_set(data + 3);
  to_set.set_value(x, 2, 6);
}


Avpreq15e* Avpreq15e::set_avp__gear_req_ac_tv(
     avp__gear_req_ac_tv) {
  avp__gear_req_ac_tv_ = avp__gear_req_ac_tv;
  return this;
 }

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'Avp_GearReqAcTv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Avpreq15e::set_p_avp__gear_req_ac_tv(uint8_t* data,
     avp__gear_req_ac_tv) {
  avp__gear_req_ac_tv = ProtocolData::BoundedValue(0, 1, avp__gear_req_ac_tv);
  int x =  avp__gear_req_ac_tv;

  Byte to_set(data + 3);
  to_set.set_value(x, 1, 1);
}


Avpreq15e* Avpreq15e::set_avp__msg_cntr(
     avp__msg_cntr) {
  avp__msg_cntr_ = avp__msg_cntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Avp_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp__msg_cntr(uint8_t* data,
     avp__msg_cntr) {
  avp__msg_cntr = ProtocolData::BoundedValue(0, 15, avp__msg_cntr);
  int x =  avp__msg_cntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Avpreq15e* Avpreq15e::set_avp__c_r_c(
     avp__c_r_c) {
  avp__c_r_c_ = avp__c_r_c;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Avp_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp__c_r_c(uint8_t* data,
     avp__c_r_c) {
  avp__c_r_c = ProtocolData::BoundedValue(0, 255, avp__c_r_c);
  int x =  avp__c_r_c;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}


Avpreq15e* Avpreq15e::set_avp__dst_req(
     avp__dst_req) {
  avp__dst_req_ = avp__dst_req;
  return this;
 }

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'Avp_DstReq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int'}
void Avpreq15e::set_p_avp__dst_req(uint8_t* data,
     avp__dst_req) {
  avp__dst_req = ProtocolData::BoundedValue(-4095, 4096, avp__dst_req);
  int x =  (avp__dst_req - -4095.000000);
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0x1F;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 5);
}


Avpreq15e* Avpreq15e::set_avp__tar_gear_req(
    ::atlas_messages::avp_req_15e::Avp_TarGearReqType avp__tar_gear_req) {
  avp__tar_gear_req_ = avp__tar_gear_req;
  return this;
 }

// config detail: {'bit': 63, 'enum': {0: 'AVP_TARGEARREQ_NO_GEAR_REQUEST', 1: 'AVP_TARGEARREQ_D', 2: 'AVP_TARGEARREQ_R', 3: 'AVP_TARGEARREQ_N', 4: 'AVP_TARGEARREQ_P'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_TarGearReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_avp__tar_gear_req(uint8_t* data,
    ::atlas_messages::avp_req_15e::Avp_TarGearReqType avp__tar_gear_req) {
  int x = static_cast<uint32_t>( avp__tar_gear_req );

  Byte to_set(data + 7);
  to_set.set_value(x, 5, 3);
}


Avpreq15e* Avpreq15e::set_av_p__crtl_mode(
    ::atlas_messages::avp_req_15e::AvP_CrtlModeType av_p__crtl_mode) {
  av_p__crtl_mode_ = av_p__crtl_mode;
  return this;
 }

// config detail: {'bit': 55, 'enum': {0: 'AVP_CRTLMODE_NO', 1: 'AVP_CRTLMODE_DIST_CRTL', 2: 'AVP_CRTLMODE_SPD_CRTL', 3: 'AVP_CRTLMODE_RES'}, 'is_signed_var': False, 'len': 4, 'name': 'AvP_CrtlMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Avpreq15e::set_p_av_p__crtl_mode(uint8_t* data,
    ::atlas_messages::avp_req_15e::AvP_CrtlModeType av_p__crtl_mode) {
  int x = static_cast<uint32_t>( av_p__crtl_mode );

  Byte to_set(data + 6);
  to_set.set_value(x, 4, 4);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
