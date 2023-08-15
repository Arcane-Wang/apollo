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

#include "modules/canbus/vehicle/nio/protocol/accreq_7f.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Accreq7f::ID = 0x7f;

// public
Accreq7f::Accreq7f() { Reset(); }

uint32_t Accreq7f::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Accreq7f::UpdateData(uint8_t* data) {
  set_p_acc__drv_off(data, acc__drv_off_);
  set_p_acc__de_stop(data, acc__de_stop_);
  set_p_acc__max_jerk(data, acc__max_jerk_);
  set_p_acc__min_jerk(data, acc__min_jerk_);
  set_p_acc__mode(data, acc__mode_);
  set_p_acc__comfor_low(data, acc__comfor_low_);
  set_p_acc__comfor_up(data, acc__comfor_up_);
  set_p_acc__hvy_decel(data, acc__hvy_decel_);
  set_p_acc__heavy_mode(data, acc__heavy_mode_);
  set_p_acc__tar_a(data, acc__tar_a_);
  set_p_acc__msg_cntr(data, acc__msg_cntr_);
  set_p_acc__c_r_c(data, acc__c_r_c_);
}

void Accreq7f::Reset() {
  // TODO(All) :  you should check this manually
  acc__drv_off_ = atlas_messages::accreq_7f::Acc_DrvOffType::A_C_C__D_R_V_O_F_F__N_O__R_E_Q_U_E_S_T;
  acc__de_stop_ = atlas_messages::accreq_7f::Acc_De_stopType::A_C_C__D_E__S_T_O_P__N_O__R_E_Q_U_E_S_T;
  acc__max_jerk_ = 0;
  acc__min_jerk_ = 0;
  acc__mode_ = atlas_messages::accreq_7f::Acc_ModeType::A_C_C__M_O_D_E__O_F_F__M_O_D_E;
  acc__comfor_low_ = 0;
  acc__comfor_up_ = 0;
  acc__hvy_decel_ = atlas_messages::accreq_7f::Acc_HvyDecelType::A_C_C__H_V_Y_D_E_C_E_L__N_O_T__R_E_Q_U_E_S_T;
  acc__heavy_mode_ = atlas_messages::accreq_7f::Acc_HeavyModeType::A_C_C__H_E_A_V_Y_M_O_D_E__I_N_A_C_T_I_V_E;
  acc__tar_a_ = 0;
  acc__msg_cntr_ = 0;
  acc__c_r_c_ = 0;
}

Accreq7f* Accreq7f::set_acc__drv_off(
    ::atlas_messages::accreq_7f::Acc_DrvOffType acc__drv_off) {
  acc__drv_off_ = acc__drv_off;
  return this;
 }

// config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'ACC_DRVOFF_NO_REQUEST', 1: 'ACC_DRVOFF_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_DrvOff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc__drv_off(uint8_t* data,
    ::atlas_messages::accreq_7f::Acc_DrvOffType acc__drv_off) {
  int x = static_cast<uint32_t>( acc__drv_off );

  Byte to_set(data + 3);
  to_set.set_value(x, 7, 1);
}


Accreq7f* Accreq7f::set_acc__de_stop(
    ::atlas_messages::accreq_7f::Acc_De_stopType acc__de_stop) {
  acc__de_stop_ = acc__de_stop;
  return this;
 }

// config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'ACC_DE_STOP_NO_REQUEST', 1: 'ACC_DE_STOP_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_De_stop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc__de_stop(uint8_t* data,
    ::atlas_messages::accreq_7f::Acc_De_stopType acc__de_stop) {
  int x = static_cast<uint32_t>( acc__de_stop );

  Byte to_set(data + 3);
  to_set.set_value(x, 4, 1);
}


Accreq7f* Accreq7f::set_acc__max_jerk(
     acc__max_jerk) {
  acc__max_jerk_ = acc__max_jerk;
  return this;
 }

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MaxJerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
void Accreq7f::set_p_acc__max_jerk(uint8_t* data,
     acc__max_jerk) {
  acc__max_jerk = ProtocolData::BoundedValue(0, 25.4, acc__max_jerk);
  int x =  acc__max_jerk / 0.200000;

  Byte to_set(data + 5);
  to_set.set_value(x, 1, 7);
}


Accreq7f* Accreq7f::set_acc__min_jerk(
     acc__min_jerk) {
  acc__min_jerk_ = acc__min_jerk;
  return this;
 }

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MinJerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
void Accreq7f::set_p_acc__min_jerk(uint8_t* data,
     acc__min_jerk) {
  acc__min_jerk = ProtocolData::BoundedValue(-25.4, 0, acc__min_jerk);
  int x =  (acc__min_jerk - -25.400000) / 0.200000;

  Byte to_set(data + 7);
  to_set.set_value(x, 1, 7);
}


Accreq7f* Accreq7f::set_acc__mode(
    ::atlas_messages::accreq_7f::Acc_ModeType acc__mode) {
  acc__mode_ = acc__mode;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'ACC_MODE_OFF_MODE', 1: 'ACC_MODE_PASSIVE_MODE', 2: 'ACC_MODE_STANDBY_MODE', 3: 'ACC_MODE_ACTIVE_CONTROL_MODE', 4: 'ACC_MODE_BRAKE_ONLY_MODE', 5: 'ACC_MODE_OVERRIDE_MODE', 6: 'ACC_MODE_STANDSTILL_MODE', 7: 'ACC_MODE_FAILURE_MODE'}, 'is_signed_var': False, 'len': 3, 'name': 'Acc_Mode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc__mode(uint8_t* data,
    ::atlas_messages::accreq_7f::Acc_ModeType acc__mode) {
  int x = static_cast<uint32_t>( acc__mode );

  Byte to_set(data + 1);
  to_set.set_value(x, 1, 3);
}


Accreq7f* Accreq7f::set_acc__comfor_low(
     acc__comfor_low) {
  acc__comfor_low_ = acc__comfor_low;
  return this;
 }

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforLow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc__comfor_low(uint8_t* data,
     acc__comfor_low) {
  acc__comfor_low = ProtocolData::BoundedValue(-7, 5.75, acc__comfor_low);
  int x =  (acc__comfor_low - -7.000000) / 0.050000;

  Byte to_set(data + 6);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc__comfor_up(
     acc__comfor_up) {
  acc__comfor_up_ = acc__comfor_up;
  return this;
 }

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforUp', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc__comfor_up(uint8_t* data,
     acc__comfor_up) {
  acc__comfor_up = ProtocolData::BoundedValue(-7, 5.75, acc__comfor_up);
  int x =  (acc__comfor_up - -7.000000) / 0.050000;

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc__hvy_decel(
    ::atlas_messages::accreq_7f::Acc_HvyDecelType acc__hvy_decel) {
  acc__hvy_decel_ = acc__hvy_decel;
  return this;
 }

// config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'ACC_HVYDECEL_NOT_REQUEST', 1: 'ACC_HVYDECEL_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_HvyDecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc__hvy_decel(uint8_t* data,
    ::atlas_messages::accreq_7f::Acc_HvyDecelType acc__hvy_decel) {
  int x = static_cast<uint32_t>( acc__hvy_decel );

  Byte to_set(data + 3);
  to_set.set_value(x, 3, 1);
}


Accreq7f* Accreq7f::set_acc__heavy_mode(
    ::atlas_messages::accreq_7f::Acc_HeavyModeType acc__heavy_mode) {
  acc__heavy_mode_ = acc__heavy_mode;
  return this;
 }

// config detail: {'bit': 30, 'enum': {0: 'ACC_HEAVYMODE_INACTIVE', 1: 'ACC_HEAVYMODE_RESERVED1', 2: 'ACC_HEAVYMODE_RESERVED2', 3: 'ACC_HEAVYMODE_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'Acc_HeavyMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc__heavy_mode(uint8_t* data,
    ::atlas_messages::accreq_7f::Acc_HeavyModeType acc__heavy_mode) {
  int x = static_cast<uint32_t>( acc__heavy_mode );

  Byte to_set(data + 3);
  to_set.set_value(x, 5, 2);
}


Accreq7f* Accreq7f::set_acc__tar_a(
     acc__tar_a) {
  acc__tar_a_ = acc__tar_a;
  return this;
 }

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'Acc_TarA', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc__tar_a(uint8_t* data,
     acc__tar_a) {
  acc__tar_a = ProtocolData::BoundedValue(-7, 5.75, acc__tar_a);
  int x =  (acc__tar_a - -7.000000) / 0.050000;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc__msg_cntr(
     acc__msg_cntr) {
  acc__msg_cntr_ = acc__msg_cntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Acc_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Accreq7f::set_p_acc__msg_cntr(uint8_t* data,
     acc__msg_cntr) {
  acc__msg_cntr = ProtocolData::BoundedValue(0, 15, acc__msg_cntr);
  int x =  acc__msg_cntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Accreq7f* Accreq7f::set_acc__c_r_c(
     acc__c_r_c) {
  acc__c_r_c_ = acc__c_r_c;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Acc_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Accreq7f::set_p_acc__c_r_c(uint8_t* data,
     acc__c_r_c) {
  acc__c_r_c = ProtocolData::BoundedValue(0, 255, acc__c_r_c);
  int x =  acc__c_r_c;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
