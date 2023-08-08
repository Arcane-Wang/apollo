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

#include "modules/canbus/vehicle/nio/protocol/light_req_336.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

Lightreq336::Lightreq336() {}
const int32_t Lightreq336::ID = 0x336;

void Lightreq336::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_nio()->mutable_light_req_336()->set_brklireq(brklireq(bytes, length));
  chassis->mutable_nio()->mutable_light_req_336()->set_frntwiprsts(frntwiprsts(bytes, length));
  chassis->mutable_nio()->mutable_light_req_336()->set_turnlightind(turnlightind(bytes, length));
  chassis->mutable_nio()->mutable_light_req_336()->set_beamactivests(beamactivests(bytes, length));
  chassis->mutable_nio()->mutable_light_req_336()->set_beamlightreq(beamlightreq(bytes, length));
  chassis->mutable_nio()->mutable_light_req_336()->set_emeglampreq(emeglampreq(bytes, length));
}

// config detail: {'bit': 23, 'enum': {0: 'BRKLIREQ_NO_REQUEST', 1: 'BRKLIREQ_REQUEST', 2: 'BRKLIREQ_RESERVED', 3: 'BRKLIREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'brklireq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::BrklireqType Lightreq336::brklireq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Light_req_336::BrklireqType ret =  static_cast<Light_req_336::BrklireqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'FRNTWIPRSTS_OFF', 1: 'FRNTWIPRSTS_LOW_SPEED', 2: 'FRNTWIPRSTS_HIGH_SPEED', 3: 'FRNTWIPRSTS_RESERVED3', 4: 'FRNTWIPRSTS_RESERVED4', 5: 'FRNTWIPRSTS_RESERVED5', 6: 'FRNTWIPRSTS_RESERVED6', 7: 'FRNTWIPRSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::FrntwiprstsType Lightreq336::frntwiprsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 3);

  Light_req_336::FrntwiprstsType ret =  static_cast<Light_req_336::FrntwiprstsType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'TURNLIGHTIND_NO_TURN', 1: 'TURNLIGHTIND_TURN_LEFT', 2: 'TURNLIGHTIND_TURN_RIGHT', 3: 'TURNLIGHTIND_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::TurnlightindType Lightreq336::turnlightind(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 2);

  Light_req_336::TurnlightindType ret =  static_cast<Light_req_336::TurnlightindType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'BEAMACTIVESTS_BEAM_STATUS_OFF', 1: 'BEAMACTIVESTS_BEAM_STATUS_PASSIVE', 2: 'BEAMACTIVESTS_BEAM_STATUS_ACTIVE', 3: 'BEAMACTIVESTS_RESERVED3', 4: 'BEAMACTIVESTS_RESERVED4', 5: 'BEAMACTIVESTS_RESERVED5', 6: 'BEAMACTIVESTS_RESERVED6', 7: 'BEAMACTIVESTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'beamactivests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::BeamactivestsType Lightreq336::beamactivests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 3);

  Light_req_336::BeamactivestsType ret =  static_cast<Light_req_336::BeamactivestsType>(x);
  return ret;
}

// config detail: {'bit': 4, 'enum': {0: 'BEAMLIGHTREQ_LOW_BEAM_REQUEST', 1: 'BEAMLIGHTREQ_HIGH_BEAM_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::BeamlightreqType Lightreq336::beamlightreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  Light_req_336::BeamlightreqType ret =  static_cast<Light_req_336::BeamlightreqType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'EMEGLAMPREQ_OFF', 1: 'EMEGLAMPREQ_1_25HZ', 2: 'EMEGLAMPREQ_1HZ', 3: 'EMEGLAMPREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'emeglampreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Light_req_336::EmeglampreqType Lightreq336::emeglampreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Light_req_336::EmeglampreqType ret =  static_cast<Light_req_336::EmeglampreqType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
