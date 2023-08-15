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

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'EPSPAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  Epsreqc6* set_e_p_s_p_a_i_req( e_p_s_p_a_i_req);

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'EPSDAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  Epsreqc6* set_e_p_s_d_a_i_req( e_p_s_d_a_i_req);

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'EPSTOIReq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
  Epsreqc6* set_e_p_s_t_o_i_req( e_p_s_t_o_i_req);

  // config detail: {'bit': 23, 'enum': {0: 'EPSREQTYP_NO_REQUEST', 1: 'EPSREQTYP_RESERVED_1_DSR', 2: 'EPSREQTYP_TOI_REQUEST', 3: 'EPSREQTYP_PAI_REQUEST', 4: 'EPSREQTYP_DAI_REQUEST', 5: 'EPSREQTYP_HI_1_REQUEST', 6: 'EPSREQTYP_HI_2_REQUEST', 7: 'EPSREQTYP_RESERVED_7', 8: 'EPSREQTYP_RESERVED_8', 9: 'EPSREQTYP_RESERVED_9', 10: 'EPSREQTYP_RESERVED_10', 11: 'EPSREQTYP_RESERVED_11', 12: 'EPSREQTYP_RESERVED_12', 13: 'EPSREQTYP_RESERVED_13', 14: 'EPSREQTYP_RESERVED_14', 15: 'EPSREQTYP_SIGNAL_NOT_AVAILABLE'}, 'is_signed_var': False, 'len': 4, 'name': 'EPSReqTyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6* set_e_p_s_req_typ(::atlas_messages::eps_req_c6::EPSReqTypType e_p_s_req_typ);

  // config detail: {'bit': 40, 'enum': {0: 'SYSVALID_INVALID', 1: 'SYSVALID_VALID'}, 'is_signed_var': False, 'len': 1, 'name': 'SysValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6* set_sys_valid(::atlas_messages::eps_req_c6::SysValidType sys_valid);

  // config detail: {'bit': 25, 'enum': {0: 'PILOTSYM_NO_SYMBOL', 1: 'PILOTSYM_GRAY_SYMBOL', 2: 'PILOTSYM_WHITE_SYMBOL', 3: 'PILOTSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PilotSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6* set_pilot_sym(::atlas_messages::eps_req_c6::PilotSymType pilot_sym);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Epsreqc6* set_e_p_s__c_r_c( e_p_s__c_r_c);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Epsreqc6* set_e_p_s__msg_cntr( e_p_s__msg_cntr);

  // config detail: {'bit': 11, 'enum': {0: 'ADC_ACCSYM_NO_SYMBOL', 1: 'ADC_ACCSYM_GRAY_SYMBOL', 2: 'ADC_ACCSYM_WHITE_SYMBOL', 3: 'ADC_ACCSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'ADC_ACCSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Epsreqc6* set_a_d_c__a_c_c_sym(::atlas_messages::eps_req_c6::ADC_ACCSymType a_d_c__a_c_c_sym);

 private:

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 15, 'name': 'EPSPAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  void set_p_e_p_s_p_a_i_req(uint8_t* data,  e_p_s_p_a_i_req);

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 15, 'name': 'EPSDAIReq', 'offset': -1638.4, 'order': 'motorola', 'physical_range': '[-1638.4|1638.3]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
  void set_p_e_p_s_d_a_i_req(uint8_t* data,  e_p_s_d_a_i_req);

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 10, 'name': 'EPSTOIReq', 'offset': -10.24, 'order': 'motorola', 'physical_range': '[-10.24|10.22]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
  void set_p_e_p_s_t_o_i_req(uint8_t* data,  e_p_s_t_o_i_req);

  // config detail: {'bit': 23, 'enum': {0: 'EPSREQTYP_NO_REQUEST', 1: 'EPSREQTYP_RESERVED_1_DSR', 2: 'EPSREQTYP_TOI_REQUEST', 3: 'EPSREQTYP_PAI_REQUEST', 4: 'EPSREQTYP_DAI_REQUEST', 5: 'EPSREQTYP_HI_1_REQUEST', 6: 'EPSREQTYP_HI_2_REQUEST', 7: 'EPSREQTYP_RESERVED_7', 8: 'EPSREQTYP_RESERVED_8', 9: 'EPSREQTYP_RESERVED_9', 10: 'EPSREQTYP_RESERVED_10', 11: 'EPSREQTYP_RESERVED_11', 12: 'EPSREQTYP_RESERVED_12', 13: 'EPSREQTYP_RESERVED_13', 14: 'EPSREQTYP_RESERVED_14', 15: 'EPSREQTYP_SIGNAL_NOT_AVAILABLE'}, 'is_signed_var': False, 'len': 4, 'name': 'EPSReqTyp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_e_p_s_req_typ(uint8_t* data, ::atlas_messages::eps_req_c6::EPSReqTypType e_p_s_req_typ);

  // config detail: {'bit': 40, 'enum': {0: 'SYSVALID_INVALID', 1: 'SYSVALID_VALID'}, 'is_signed_var': False, 'len': 1, 'name': 'SysValid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_sys_valid(uint8_t* data, ::atlas_messages::eps_req_c6::SysValidType sys_valid);

  // config detail: {'bit': 25, 'enum': {0: 'PILOTSYM_NO_SYMBOL', 1: 'PILOTSYM_GRAY_SYMBOL', 2: 'PILOTSYM_WHITE_SYMBOL', 3: 'PILOTSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'PilotSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_pilot_sym(uint8_t* data, ::atlas_messages::eps_req_c6::PilotSymType pilot_sym);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_e_p_s__c_r_c(uint8_t* data,  e_p_s__c_r_c);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_e_p_s__msg_cntr(uint8_t* data,  e_p_s__msg_cntr);

  // config detail: {'bit': 11, 'enum': {0: 'ADC_ACCSYM_NO_SYMBOL', 1: 'ADC_ACCSYM_GRAY_SYMBOL', 2: 'ADC_ACCSYM_WHITE_SYMBOL', 3: 'ADC_ACCSYM_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'ADC_ACCSym', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_a_d_c__a_c_c_sym(uint8_t* data, ::atlas_messages::eps_req_c6::ADC_ACCSymType a_d_c__a_c_c_sym);

 private:
   e_p_s_p_a_i_req_;
   e_p_s_d_a_i_req_;
   e_p_s_t_o_i_req_;
  ::atlas_messages::eps_req_c6::EPSReqTypType e_p_s_req_typ_;
  ::atlas_messages::eps_req_c6::SysValidType sys_valid_;
  ::atlas_messages::eps_req_c6::PilotSymType pilot_sym_;
   e_p_s__c_r_c_;
   e_p_s__msg_cntr_;
  ::atlas_messages::eps_req_c6::ADC_ACCSymType a_d_c__a_c_c_sym_;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


