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

#include "modules/canbus/vehicle/nio/protocol/bodystatus_24d.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Bodystatus24d::Bodystatus24d() {}
const int32_t Bodystatus24d::ID = 0x24D;

void Bodystatus24d::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_doorajarfrntlests(doorajarfrntlests(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_doorajarfrntrists(doorajarfrntrists(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_doorajarrelests(doorajarrelests(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_bcm_closure_crc(bcm_closure_crc(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_seatoccpfrntlefail(seatoccpfrntlefail(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_steerwhlheatsts(steerwhlheatsts(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_bcm_closure_msgcntr(bcm_closure_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_trajarsts(trajarsts(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_hoodajarsts(hoodajarsts(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_doorajarrerists(doorajarrerists(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_seatoccpfrntlests(seatoccpfrntlests(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_cooltlvllowwarnreq(cooltlvllowwarnreq(bytes, length));
  chassis->mutable_nio()->mutable_bodystatus_24d()->set_vehspd(vehspd(bytes, length));
}

// config detail: {'bit': 25, 'enum': {0: 'DOORAJARFRNTLESTS_OPENED', 1: 'DOORAJARFRNTLESTS_CLOSED', 2: 'DOORAJARFRNTLESTS_RESERVED', 3: 'DOORAJARFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'doorajarfrntlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::DoorajarfrntlestsType Bodystatus24d::doorajarfrntlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Bodystatus_24d::DoorajarfrntlestsType ret =  static_cast<Bodystatus_24d::DoorajarfrntlestsType>(x);
  return ret;
}

// config detail: {'bit': 19, 'enum': {0: 'DOORAJARFRNTRISTS_OPENED', 1: 'DOORAJARFRNTRISTS_CLOSED', 2: 'DOORAJARFRNTRISTS_RESERVED', 3: 'DOORAJARFRNTRISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'doorajarfrntrists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::DoorajarfrntristsType Bodystatus24d::doorajarfrntrists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 2);

  Bodystatus_24d::DoorajarfrntristsType ret =  static_cast<Bodystatus_24d::DoorajarfrntristsType>(x);
  return ret;
}

// config detail: {'bit': 31, 'enum': {0: 'DOORAJARRELESTS_OPENED', 1: 'DOORAJARRELESTS_CLOSED', 2: 'DOORAJARRELESTS_RESERVED', 3: 'DOORAJARRELESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'doorajarrelests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::DoorajarrelestsType Bodystatus24d::doorajarrelests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 2);

  Bodystatus_24d::DoorajarrelestsType ret =  static_cast<Bodystatus_24d::DoorajarrelestsType>(x);
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'bcm_closure_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Bodystatus24d::bcm_closure_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 11, 'enum': {0: 'SEATOCCPFRNTLEFAIL_NO_FAILURE', 1: 'SEATOCCPFRNTLEFAIL_FAILURE', 2: 'SEATOCCPFRNTLEFAIL_RESERVED', 3: 'SEATOCCPFRNTLEFAIL_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'seatoccpfrntlefail', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::SeatoccpfrntlefailType Bodystatus24d::seatoccpfrntlefail(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 2);

  Bodystatus_24d::SeatoccpfrntlefailType ret =  static_cast<Bodystatus_24d::SeatoccpfrntlefailType>(x);
  return ret;
}

// config detail: {'bit': 37, 'enum': {0: 'STEERWHLHEATSTS_HEATER_OFF', 1: 'STEERWHLHEATSTS_HEATER_ON', 2: 'STEERWHLHEATSTS_RESERVED', 3: 'STEERWHLHEATSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'steerwhlheatsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::SteerwhlheatstsType Bodystatus24d::steerwhlheatsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  Bodystatus_24d::SteerwhlheatstsType ret =  static_cast<Bodystatus_24d::SteerwhlheatstsType>(x);
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'bcm_closure_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Bodystatus24d::bcm_closure_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 29, 'enum': {0: 'TRAJARSTS_OPENED', 1: 'TRAJARSTS_CLOSED', 2: 'TRAJARSTS_RESERVED', 3: 'TRAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'trajarsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::TrajarstsType Bodystatus24d::trajarsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 2);

  Bodystatus_24d::TrajarstsType ret =  static_cast<Bodystatus_24d::TrajarstsType>(x);
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'HOODAJARSTS_OPENED', 1: 'HOODAJARSTS_CLOSED', 2: 'HOODAJARSTS_RESERVED', 3: 'HOODAJARSTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'hoodajarsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::HoodajarstsType Bodystatus24d::hoodajarsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 2);

  Bodystatus_24d::HoodajarstsType ret =  static_cast<Bodystatus_24d::HoodajarstsType>(x);
  return ret;
}

// config detail: {'bit': 23, 'enum': {0: 'DOORAJARRERISTS_OPENED', 1: 'DOORAJARRERISTS_CLOSED', 2: 'DOORAJARRERISTS_RESERVED', 3: 'DOORAJARRERISTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'doorajarrerists', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::DoorajarreristsType Bodystatus24d::doorajarrerists(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Bodystatus_24d::DoorajarreristsType ret =  static_cast<Bodystatus_24d::DoorajarreristsType>(x);
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'SEATOCCPFRNTLESTS_NO_OCCUPANT', 1: 'SEATOCCPFRNTLESTS_OCCUPANT', 2: 'SEATOCCPFRNTLESTS_RESERVED', 3: 'SEATOCCPFRNTLESTS_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'seatoccpfrntlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::SeatoccpfrntlestsType Bodystatus24d::seatoccpfrntlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  Bodystatus_24d::SeatoccpfrntlestsType ret =  static_cast<Bodystatus_24d::SeatoccpfrntlestsType>(x);
  return ret;
}

// config detail: {'bit': 21, 'enum': {0: 'COOLTLVLLOWWARNREQ_NO_REQUEST', 1: 'COOLTLVLLOWWARNREQ_REQUEST', 2: 'COOLTLVLLOWWARNREQ_RESERVED', 3: 'COOLTLVLLOWWARNREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'cooltlvllowwarnreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Bodystatus_24d::CooltlvllowwarnreqType Bodystatus24d::cooltlvllowwarnreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 2);

  Bodystatus_24d::CooltlvllowwarnreqType ret =  static_cast<Bodystatus_24d::CooltlvllowwarnreqType>(x);
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 13, 'name': 'vehspd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|360]', 'physical_unit': 'km/h', 'precision': 0.05625, 'type': 'double'}
double Bodystatus24d::vehspd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
