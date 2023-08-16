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

const int32_t Accreq7f::ID = 0x7F;

// public
Accreq7f::Accreq7f() { Reset(); }

uint32_t Accreq7f::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Accreq7f::UpdateData(uint8_t* data) {
  set_p_acc_drvoff(data, acc_drvoff_);
  set_p_acc_de_stop(data, acc_de_stop_);
  set_p_acc_maxjerk(data, acc_maxjerk_);
  set_p_acc_minjerk(data, acc_minjerk_);
  set_p_acc_mode(data, acc_mode_);
  set_p_acc_comforlow(data, acc_comforlow_);
  set_p_acc_comforup(data, acc_comforup_);
  set_p_acc_hvydecel(data, acc_hvydecel_);
  set_p_acc_heavymode(data, acc_heavymode_);
  set_p_acc_tara(data, acc_tara_);
  set_p_acc_msgcntr(data, acc_msgcntr_);
  set_p_acc_crc(data, acc_crc_);
}

void Accreq7f::Reset() {
  // TODO(All) :  you should check this manually
  acc_drvoff_ = Accreq_7f::ACC_DRVOFF_NO_REQUEST;
  acc_de_stop_ = Accreq_7f::ACC_DE_STOP_NO_REQUEST;
  acc_maxjerk_ = 0.0;
  acc_minjerk_ = 0.0;
  acc_mode_ = Accreq_7f::ACC_MODE_OFF_MODE;
  acc_comforlow_ = 0.0;
  acc_comforup_ = 0.0;
  acc_hvydecel_ = Accreq_7f::ACC_HVYDECEL_NOT_REQUEST;
  acc_heavymode_ = Accreq_7f::ACC_HEAVYMODE_INACTIVE;
  acc_tara_ = 0.0;
  acc_msgcntr_ = 0;
  acc_crc_ = 0;
}

Accreq7f* Accreq7f::set_acc_drvoff(
    Accreq_7f::Acc_drvoffType acc_drvoff) {
  acc_drvoff_ = acc_drvoff;
  return this;
 }

// config detail: {'bit': 31, 'description': 'drive off request', 'enum': {0: 'ACC_DRVOFF_NO_REQUEST', 1: 'ACC_DRVOFF_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_DrvOff', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc_drvoff(uint8_t* data,
    Accreq_7f::Acc_drvoffType acc_drvoff) {
  int x = acc_drvoff;

  Byte to_set(data + 3);
  to_set.set_value(x, 7, 1);
}


Accreq7f* Accreq7f::set_acc_de_stop(
    Accreq_7f::Acc_de_stopType acc_de_stop) {
  acc_de_stop_ = acc_de_stop;
  return this;
 }

// config detail: {'bit': 28, 'description': 'decelerate to stop', 'enum': {0: 'ACC_DE_STOP_NO_REQUEST', 1: 'ACC_DE_STOP_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_De_stop', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc_de_stop(uint8_t* data,
    Accreq_7f::Acc_de_stopType acc_de_stop) {
  int x = acc_de_stop;

  Byte to_set(data + 3);
  to_set.set_value(x, 4, 1);
}


Accreq7f* Accreq7f::set_acc_maxjerk(
    double acc_maxjerk) {
  acc_maxjerk_ = acc_maxjerk;
  return this;
 }

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MaxJerk', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|25.4]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
void Accreq7f::set_p_acc_maxjerk(uint8_t* data,
    double acc_maxjerk) {
  acc_maxjerk = ProtocolData::BoundedValue(0.0, 25.4, acc_maxjerk);
  int x = acc_maxjerk / 0.200000;

  Byte to_set(data + 5);
  to_set.set_value(x, 1, 7);
}


Accreq7f* Accreq7f::set_acc_minjerk(
    double acc_minjerk) {
  acc_minjerk_ = acc_minjerk;
  return this;
 }

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 7, 'name': 'Acc_MinJerk', 'offset': -25.4, 'order': 'motorola', 'physical_range': '[-25.4|0]', 'physical_unit': '', 'precision': 0.2, 'type': 'double'}
void Accreq7f::set_p_acc_minjerk(uint8_t* data,
    double acc_minjerk) {
  acc_minjerk = ProtocolData::BoundedValue(-25.4, 0.0, acc_minjerk);
  int x = (acc_minjerk - -25.400000) / 0.200000;

  Byte to_set(data + 7);
  to_set.set_value(x, 1, 7);
}


Accreq7f* Accreq7f::set_acc_mode(
    Accreq_7f::Acc_modeType acc_mode) {
  acc_mode_ = acc_mode;
  return this;
 }

// config detail: {'bit': 11, 'enum': {0: 'ACC_MODE_OFF_MODE', 1: 'ACC_MODE_PASSIVE_MODE', 2: 'ACC_MODE_STANDBY_MODE', 3: 'ACC_MODE_ACTIVE_CONTROL_MODE', 4: 'ACC_MODE_BRAKE_ONLY_MODE', 5: 'ACC_MODE_OVERRIDE_MODE', 6: 'ACC_MODE_STANDSTILL_MODE', 7: 'ACC_MODE_FAILURE_MODE'}, 'is_signed_var': False, 'len': 3, 'name': 'Acc_Mode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc_mode(uint8_t* data,
    Accreq_7f::Acc_modeType acc_mode) {
  int x = acc_mode;

  Byte to_set(data + 1);
  to_set.set_value(x, 1, 3);
}


Accreq7f* Accreq7f::set_acc_comforlow(
    double acc_comforlow) {
  acc_comforlow_ = acc_comforlow;
  return this;
 }

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforLow', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc_comforlow(uint8_t* data,
    double acc_comforlow) {
  acc_comforlow = ProtocolData::BoundedValue(-7.0, 5.75, acc_comforlow);
  int x = (acc_comforlow - -7.000000) / 0.050000;

  Byte to_set(data + 6);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc_comforup(
    double acc_comforup) {
  acc_comforup_ = acc_comforup;
  return this;
 }

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'Acc_ComforUp', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc_comforup(uint8_t* data,
    double acc_comforup) {
  acc_comforup = ProtocolData::BoundedValue(-7.0, 5.75, acc_comforup);
  int x = (acc_comforup - -7.000000) / 0.050000;

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc_hvydecel(
    Accreq_7f::Acc_hvydecelType acc_hvydecel) {
  acc_hvydecel_ = acc_hvydecel;
  return this;
 }

// config detail: {'bit': 27, 'description': 'unstable Decel', 'enum': {0: 'ACC_HVYDECEL_NOT_REQUEST', 1: 'ACC_HVYDECEL_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Acc_HvyDecel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc_hvydecel(uint8_t* data,
    Accreq_7f::Acc_hvydecelType acc_hvydecel) {
  int x = acc_hvydecel;

  Byte to_set(data + 3);
  to_set.set_value(x, 3, 1);
}


Accreq7f* Accreq7f::set_acc_heavymode(
    Accreq_7f::Acc_heavymodeType acc_heavymode) {
  acc_heavymode_ = acc_heavymode;
  return this;
 }

// config detail: {'bit': 30, 'enum': {0: 'ACC_HEAVYMODE_INACTIVE', 1: 'ACC_HEAVYMODE_RESERVED1', 2: 'ACC_HEAVYMODE_RESERVED2', 3: 'ACC_HEAVYMODE_ACTIVE'}, 'is_signed_var': False, 'len': 2, 'name': 'Acc_HeavyMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Accreq7f::set_p_acc_heavymode(uint8_t* data,
    Accreq_7f::Acc_heavymodeType acc_heavymode) {
  int x = acc_heavymode;

  Byte to_set(data + 3);
  to_set.set_value(x, 5, 2);
}


Accreq7f* Accreq7f::set_acc_tara(
    double acc_tara) {
  acc_tara_ = acc_tara;
  return this;
 }

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'Acc_TarA', 'offset': -7.0, 'order': 'motorola', 'physical_range': '[-7|5.75]', 'physical_unit': 'm/s2', 'precision': 0.05, 'type': 'double'}
void Accreq7f::set_p_acc_tara(uint8_t* data,
    double acc_tara) {
  acc_tara = ProtocolData::BoundedValue(-7.0, 5.75, acc_tara);
  int x = (acc_tara - -7.000000) / 0.050000;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Accreq7f* Accreq7f::set_acc_msgcntr(
    int acc_msgcntr) {
  acc_msgcntr_ = acc_msgcntr;
  return this;
 }

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'Acc_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Accreq7f::set_p_acc_msgcntr(uint8_t* data,
    int acc_msgcntr) {
  acc_msgcntr = ProtocolData::BoundedValue(0, 15, acc_msgcntr);
  int x = acc_msgcntr;

  Byte to_set(data + 1);
  to_set.set_value(x, 4, 4);
}


Accreq7f* Accreq7f::set_acc_crc(
    int acc_crc) {
  acc_crc_ = acc_crc;
  return this;
 }

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'Acc_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Accreq7f::set_p_acc_crc(uint8_t* data,
    int acc_crc) {
  acc_crc = ProtocolData::BoundedValue(0, 255, acc_crc);
  int x = acc_crc;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
