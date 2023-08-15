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

class Avpreq15e : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Avpreq15e();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 39, 'enum': {0: 'AVP_APAPARKMOD_OFF', 1: 'AVP_APAPARKMOD_SAPA', 2: 'AVP_APAPARKMOD_VPPS', 3: 'AVP_APAPARKMOD_NBS', 4: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X5', 6: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_ApaParkMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__apa_park_mod(::atlas_messages::avp_req_15e::Avp_ApaParkModType avp__apa_park_mod);

  // config detail: {'bit': 19, 'enum': {0: 'AVP_NBSSTS_NBS_OFF', 1: 'AVP_NBSSTS_NBS_INITIAL', 2: 'AVP_NBSSTS_NBS_STANDBY', 3: 'AVP_NBSSTS_NBS_MOVING', 4: 'AVP_NBSSTS_NBS_ABORT', 5: 'AVP_NBSSTS_NBS_FAIL', 6: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_NBSSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__n_b_s_sts(::atlas_messages::avp_req_15e::Avp_NBSStsType avp__n_b_s_sts);

  // config detail: {'bit': 23, 'enum': {0: 'AVP_ADCVCUNBSSTS_NBS_OFF', 1: 'AVP_ADCVCUNBSSTS_NBS_INTIAL', 2: 'AVP_ADCVCUNBSSTS_NBS_STANDBY', 3: 'AVP_ADCVCUNBSSTS_NBS_MOVING', 4: 'AVP_ADCVCUNBSSTS_NBS_ABORT', 5: 'AVP_ADCVCUNBSSTS_NBS_FAIL', 6: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7', 8: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ADCVCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__a_d_c_v_c_u_n_b_s_s_ts(::atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType avp__a_d_c_v_c_u_n_b_s_s_ts);

  // config detail: {'bit': 11, 'enum': {0: 'AVP_APASTS_INITIAL', 1: 'AVP_APASTS_STANDBY', 2: 'AVP_APASTS_SEARCH', 3: 'AVP_APASTS_PRE_GUIDENCE', 4: 'AVP_APASTS_GUIDANCE', 5: 'AVP_APASTS_RESERVED', 6: 'AVP_APASTS_ABORT', 7: 'AVP_APASTS_FAULT', 8: 'AVP_APASTS_PUB_ROAD', 9: 'AVP_APASTS_OFFMODE', 10: 'AVP_APASTS_RESERVED10', 11: 'AVP_APASTS_RESERVED11', 12: 'AVP_APASTS_RESERVED12', 13: 'AVP_APASTS_RESERVED13', 14: 'AVP_APASTS_RESERVED14', 15: 'AVP_APASTS_RESERVED15'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ApaSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__apa_sts(::atlas_messages::avp_req_15e::Avp_ApaStsType avp__apa_sts);

  // config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AVP_BRKMODSTS_NO_BRAKE', 1: 'AVP_BRKMODSTS_COMFORT', 2: 'AVP_BRKMODSTS_EMERGENCY', 3: 'AVP_BRKMODSTS_RESERVED'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_BrkModSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__brk_mod_sts(::atlas_messages::avp_req_15e::Avp_BrkModStsType avp__brk_mod_sts);

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'Avp_SpdLmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
  Avpreq15e* set_avp__spd_lmt( avp__spd_lmt);

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'Avp_GearReqAcTv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Avpreq15e* set_avp__gear_req_ac_tv( avp__gear_req_ac_tv);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Avp_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Avpreq15e* set_avp__msg_cntr( avp__msg_cntr);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Avp_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Avpreq15e* set_avp__c_r_c( avp__c_r_c);

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'Avp_DstReq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int'}
  Avpreq15e* set_avp__dst_req( avp__dst_req);

  // config detail: {'bit': 63, 'enum': {0: 'AVP_TARGEARREQ_NO_GEAR_REQUEST', 1: 'AVP_TARGEARREQ_D', 2: 'AVP_TARGEARREQ_R', 3: 'AVP_TARGEARREQ_N', 4: 'AVP_TARGEARREQ_P'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_TarGearReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_avp__tar_gear_req(::atlas_messages::avp_req_15e::Avp_TarGearReqType avp__tar_gear_req);

  // config detail: {'bit': 55, 'enum': {0: 'AVP_CRTLMODE_NO', 1: 'AVP_CRTLMODE_DIST_CRTL', 2: 'AVP_CRTLMODE_SPD_CRTL', 3: 'AVP_CRTLMODE_RES'}, 'is_signed_var': False, 'len': 4, 'name': 'AvP_CrtlMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Avpreq15e* set_av_p__crtl_mode(::atlas_messages::avp_req_15e::AvP_CrtlModeType av_p__crtl_mode);

 private:

  // config detail: {'bit': 39, 'enum': {0: 'AVP_APAPARKMOD_OFF', 1: 'AVP_APAPARKMOD_SAPA', 2: 'AVP_APAPARKMOD_VPPS', 3: 'AVP_APAPARKMOD_NBS', 4: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X5', 6: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_APAPARKMOD_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_ApaParkMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__apa_park_mod(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_ApaParkModType avp__apa_park_mod);

  // config detail: {'bit': 19, 'enum': {0: 'AVP_NBSSTS_NBS_OFF', 1: 'AVP_NBSSTS_NBS_INITIAL', 2: 'AVP_NBSSTS_NBS_STANDBY', 3: 'AVP_NBSSTS_NBS_MOVING', 4: 'AVP_NBSSTS_NBS_ABORT', 5: 'AVP_NBSSTS_NBS_FAIL', 6: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_NBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_NBSSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__n_b_s_sts(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_NBSStsType avp__n_b_s_sts);

  // config detail: {'bit': 23, 'enum': {0: 'AVP_ADCVCUNBSSTS_NBS_OFF', 1: 'AVP_ADCVCUNBSSTS_NBS_INTIAL', 2: 'AVP_ADCVCUNBSSTS_NBS_STANDBY', 3: 'AVP_ADCVCUNBSSTS_NBS_MOVING', 4: 'AVP_ADCVCUNBSSTS_NBS_ABORT', 5: 'AVP_ADCVCUNBSSTS_NBS_FAIL', 6: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X6', 7: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X7', 8: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'AVP_ADCVCUNBSSTS_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ADCVCUNBSSTs', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__a_d_c_v_c_u_n_b_s_s_ts(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType avp__a_d_c_v_c_u_n_b_s_s_ts);

  // config detail: {'bit': 11, 'enum': {0: 'AVP_APASTS_INITIAL', 1: 'AVP_APASTS_STANDBY', 2: 'AVP_APASTS_SEARCH', 3: 'AVP_APASTS_PRE_GUIDENCE', 4: 'AVP_APASTS_GUIDANCE', 5: 'AVP_APASTS_RESERVED', 6: 'AVP_APASTS_ABORT', 7: 'AVP_APASTS_FAULT', 8: 'AVP_APASTS_PUB_ROAD', 9: 'AVP_APASTS_OFFMODE', 10: 'AVP_APASTS_RESERVED10', 11: 'AVP_APASTS_RESERVED11', 12: 'AVP_APASTS_RESERVED12', 13: 'AVP_APASTS_RESERVED13', 14: 'AVP_APASTS_RESERVED14', 15: 'AVP_APASTS_RESERVED15'}, 'is_signed_var': False, 'len': 4, 'name': 'Avp_ApaSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__apa_sts(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_ApaStsType avp__apa_sts);

  // config detail: {'bit': 59, 'description': '0 No 1 Comfort 2 Emergency 3 Reseved', 'enum': {0: 'AVP_BRKMODSTS_NO_BRAKE', 1: 'AVP_BRKMODSTS_COMFORT', 2: 'AVP_BRKMODSTS_EMERGENCY', 3: 'AVP_BRKMODSTS_RESERVED'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_BrkModSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__brk_mod_sts(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_BrkModStsType avp__brk_mod_sts);

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 6, 'name': 'Avp_SpdLmt', 'offset': -3.2, 'order': 'motorola', 'physical_range': '[-3.2|3.1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
  void set_p_avp__spd_lmt(uint8_t* data,  avp__spd_lmt);

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 1, 'name': 'Avp_GearReqAcTv', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_avp__gear_req_ac_tv(uint8_t* data,  avp__gear_req_ac_tv);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Avp_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_avp__msg_cntr(uint8_t* data,  avp__msg_cntr);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Avp_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_avp__c_r_c(uint8_t* data,  avp__c_r_c);

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 13, 'name': 'Avp_DstReq', 'offset': -4095.0, 'order': 'motorola', 'physical_range': '[-4095|4096]', 'physical_unit': 'cm', 'precision': 1.0, 'type': 'int'}
  void set_p_avp__dst_req(uint8_t* data,  avp__dst_req);

  // config detail: {'bit': 63, 'enum': {0: 'AVP_TARGEARREQ_NO_GEAR_REQUEST', 1: 'AVP_TARGEARREQ_D', 2: 'AVP_TARGEARREQ_R', 3: 'AVP_TARGEARREQ_N', 4: 'AVP_TARGEARREQ_P'}, 'is_signed_var': False, 'len': 3, 'name': 'Avp_TarGearReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_avp__tar_gear_req(uint8_t* data, ::atlas_messages::avp_req_15e::Avp_TarGearReqType avp__tar_gear_req);

  // config detail: {'bit': 55, 'enum': {0: 'AVP_CRTLMODE_NO', 1: 'AVP_CRTLMODE_DIST_CRTL', 2: 'AVP_CRTLMODE_SPD_CRTL', 3: 'AVP_CRTLMODE_RES'}, 'is_signed_var': False, 'len': 4, 'name': 'AvP_CrtlMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_av_p__crtl_mode(uint8_t* data, ::atlas_messages::avp_req_15e::AvP_CrtlModeType av_p__crtl_mode);

 private:
  ::atlas_messages::avp_req_15e::Avp_ApaParkModType avp__apa_park_mod_;
  ::atlas_messages::avp_req_15e::Avp_NBSStsType avp__n_b_s_sts_;
  ::atlas_messages::avp_req_15e::Avp_ADCVCUNBSSTsType avp__a_d_c_v_c_u_n_b_s_s_ts_;
  ::atlas_messages::avp_req_15e::Avp_ApaStsType avp__apa_sts_;
  ::atlas_messages::avp_req_15e::Avp_BrkModStsType avp__brk_mod_sts_;
   avp__spd_lmt_;
   avp__gear_req_ac_tv_;
   avp__msg_cntr_;
   avp__c_r_c_;
   avp__dst_req_;
  ::atlas_messages::avp_req_15e::Avp_TarGearReqType avp__tar_gear_req_;
  ::atlas_messages::avp_req_15e::AvP_CrtlModeType av_p__crtl_mode_;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


