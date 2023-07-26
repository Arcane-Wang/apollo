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

#include "modules/canbus/vehicle/nio/protocol/acmbody_4a.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Acmbody4a::Acmbody4a() {}
const int32_t Acmbody4a::ID = 0x4A;

void Acmbody4a::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_acmbody_4a()->set_acm_msgcntr(acm_msgcntr(bytes, length));
  chassis->mutable_nio()->mutable_acmbody_4a()->set_acm_crc(acm_crc(bytes, length));
  chassis->mutable_nio()->mutable_acmbody_4a()->set_latitudea(latitudea(bytes, length));
  chassis->mutable_nio()->mutable_acmbody_4a()->set_yawrate(yawrate(bytes, length));
  chassis->mutable_nio()->mutable_acmbody_4a()->set_seatoccptfrntlests(seatoccptfrntlests(bytes, length));
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'acm_msgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '0', 'precision': 1.0, 'type': 'int'}
int Acmbody4a::acm_msgcntr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'acm_crc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '0', 'precision': 1.0, 'type': 'int'}
int Acmbody4a::acm_crc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'latitudea', 'offset': -2.0, 'order': 'motorola', 'physical_range': '[-2|2]', 'physical_unit': '', 'precision': 0.001, 'type': 'double'}
double Acmbody4a::latitudea(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000 + -2.000000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'yawrate', 'offset': -180.0, 'order': 'motorola', 'physical_range': '[-180|180]', 'physical_unit': 'Deg/sec', 'precision': 0.01, 'type': 'double'}
double Acmbody4a::yawrate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000 + -180.000000;
  return ret;
}

// config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'seatoccptfrntlests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acmbody4a::seatoccptfrntlests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
