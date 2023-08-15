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

#include "modules/canbus/vehicle/nio/protocol/epsstatus01_d5.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Epsstatus01d5::Epsstatus01d5() {}
const int32_t Epsstatus01d5::ID = 0xd5;

void Epsstatus01d5::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
   if ( !chassis->Builder().hasNio() ) {
        chassis->Builder().initNio();
        if ( !chassis->Builder().getNio().hasEpsstatus01D5() ) {
           chassis->Builder().getNio().initEpsstatus01D5();
        }
    }
  chassis->Builder().getNio().getepsstatus01_d5().setEPSwarnLamp(EPSwarnLamp(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setABS_AgreqAvl(ABS_AgreqAvl(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setTorsBarTq(TorsBarTq(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setEPSsts(EPSsts(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setEPSMod(EPSMod(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setSteeragspddir(Steeragspddir(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setSteeragspd(Steeragspd(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setSteer_angledir(Steer_angledir(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setSteer_angleandspdvalid(Steer_angleandspdvalid(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setSteer_angle(Steer_angle(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setEPS_D_MsgCntr(EPS_D_MsgCntr(bytes, length));
  chassis->Builder().getNio().getepsstatus01_d5().setEPS_D_CRC(EPS_D_CRC(bytes, length));
}

// config detail: {'bit': 26, 'enum': {0: 'EPSWARNLAMP_OFF', 1: 'EPSWARNLAMP_ON', 2: 'EPSWARNLAMP_NOT_AVAILABLE', 3: 'EPSWARNLAMP_RESERVED'}, 'is_signed_var': False, 'len': 2, 'name': 'EPSwarnLamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::EPSwarnLampType Epsstatus01d5::EPSwarnLamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 2);

  ::atlas_messages::epsstatus01_d5::EPSwarnLampType ret =  static_cast<::atlas_messages::epsstatus01_d5::EPSwarnLampType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'ABS_AGREQAVL_NOT_AVAILABLE', 1: 'ABS_AGREQAVL_AVAILABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ABS_AgreqAvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::ABS_AgreqAvlType Epsstatus01d5::ABS_AgreqAvl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  ::atlas_messages::epsstatus01_d5::ABS_AgreqAvlType ret =  static_cast<::atlas_messages::epsstatus01_d5::ABS_AgreqAvlType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 10, 'name': 'TorsBarTq', 'offset': -10.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'Nm', 'precision': 0.02, 'type': 'double'}
 Epsstatus01d5::TorsBarTq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

   ret = x * 0.020000 + -10.000000;
  return ret;
}

// config detail: {'bit': 36, 'enum': {0: 'EPSSTS_INIT', 1: 'EPSSTS_NORMAL', 2: 'EPSSTS_DEGRADED_DUE_TO_TEMP_OR_VOL', 3: 'EPSSTS_TEMPORARY_ERROR', 4: 'EPSSTS_PERMAMEMT_ERROR', 5: 'EPSSTS_RESERVED5', 6: 'EPSSTS_RESERVED6', 7: 'EPSSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::EPSstsType Epsstatus01d5::EPSsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 3);

  ::atlas_messages::epsstatus01_d5::EPSstsType ret =  static_cast<::atlas_messages::epsstatus01_d5::EPSstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'EPSMOD_NONE', 1: 'EPSMOD_PAI', 2: 'EPSMOD_DAI', 3: 'EPSMOD_TOI', 7: 'EPSMOD_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'EPSMod', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::EPSModType Epsstatus01d5::EPSMod(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  ::atlas_messages::epsstatus01_d5::EPSModType ret =  static_cast<::atlas_messages::epsstatus01_d5::EPSModType>(x);
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'STEERAGSPDDIR_LEFT_PLUS', 1: 'STEERAGSPDDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'Steeragspddir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::SteeragspddirType Epsstatus01d5::Steeragspddir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  ::atlas_messages::epsstatus01_d5::SteeragspddirType ret =  static_cast<::atlas_messages::epsstatus01_d5::SteeragspddirType>(x);
  return ret;
}

// config detail: {'bit': 52, 'is_signed_var': False, 'len': 9, 'name': 'Steeragspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|2550]', 'physical_unit': 'Deg/sec', 'precision': 5.0, 'type': 'double'}
 Epsstatus01d5::Steeragspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 5);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

   ret = x * 5.000000;
  return ret;
}

// config detail: {'bit': 10, 'enum': {0: 'STEER_ANGLEDIR_LEFT_PLUS', 1: 'STEER_ANGLEDIR_RIGHT_MINUS'}, 'is_signed_var': False, 'len': 1, 'name': 'Steer_angledir', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::Steer_angledirType Epsstatus01d5::Steer_angledir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  ::atlas_messages::epsstatus01_d5::Steer_angledirType ret =  static_cast<::atlas_messages::epsstatus01_d5::Steer_angledirType>(x);
  return ret;
}

// config detail: {'bit': 9, 'enum': {0: 'STEER_ANGLEANDSPDVALID_VALID', 1: 'STEER_ANGLEANDSPDVALID_INVALID'}, 'is_signed_var': False, 'len': 1, 'name': 'Steer_angleandspdvalid', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
::atlas_messages::epsstatus01_d5::Steer_angleandspdvalidType Epsstatus01d5::Steer_angleandspdvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  ::atlas_messages::epsstatus01_d5::Steer_angleandspdvalidType ret =  static_cast<::atlas_messages::epsstatus01_d5::Steer_angleandspdvalidType>(x);
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 13, 'name': 'Steer_angle', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|800]', 'physical_unit': 'Deg', 'precision': 0.1, 'type': 'double'}
 Epsstatus01d5::Steer_angle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

   ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'EPS_D_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Epsstatus01d5::EPS_D_MsgCntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

   ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'EPS_D_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
 Epsstatus01d5::EPS_D_CRC(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

   ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
