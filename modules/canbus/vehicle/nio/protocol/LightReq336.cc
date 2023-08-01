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

#include "modules/canbus/vehicle/nio/protocol/LightReq336.h"

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
  chassis->mutable_nio()->mutable_LightReq336()->set_brklireq(brklireq(bytes, length));
  chassis->mutable_nio()->mutable_LightReq336()->set_frntwiprsts(frntwiprsts(bytes, length));
  chassis->mutable_nio()->mutable_LightReq336()->set_turnlightind(turnlightind(bytes, length));
  chassis->mutable_nio()->mutable_LightReq336()->set_beamactivests(beamactivests(bytes, length));
  chassis->mutable_nio()->mutable_LightReq336()->set_beamlightreq(beamlightreq(bytes, length));
  chassis->mutable_nio()->mutable_LightReq336()->set_emeglampreq(emeglampreq(bytes, length));
}

// config detail: {'bit': 23, 'enum': {0: 'BrkLiReqNoRequest', 1: 'BrkLiReqrequest', 2: 'BrkLiReqreserved', 3: 'BrkLiReqinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'brklireq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::BrklireqType Lightreq336::brklireq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  Lightreq336::BrklireqType ret =  static_cast<Lightreq336::BrklireqType>(x);
  return ret;
}

// config detail: {'bit': 15, 'enum': {0: 'Frntwiprstsoff', 1: 'FrntwiprstsLowSpeed', 2: 'FrntwiprstsHighSpeed', 3: 'Frntwiprstsreserved3', 4: 'Frntwiprstsreserved4', 5: 'Frntwiprstsreserved5', 6: 'Frntwiprstsreserved6', 7: 'Frntwiprstsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::FrntwiprstsType Lightreq336::frntwiprsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 3);

  Lightreq336::FrntwiprstsType ret =  static_cast<Lightreq336::FrntwiprstsType>(x);
  return ret;
}

// config detail: {'bit': 3, 'enum': {0: 'TurnlightindNoTurn', 1: 'TurnlightindTurnLeft', 2: 'TurnlightindTurnRight', 3: 'Turnlightindinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::TurnlightindType Lightreq336::turnlightind(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 2);

  Lightreq336::TurnlightindType ret =  static_cast<Lightreq336::TurnlightindType>(x);
  return ret;
}

// config detail: {'bit': 12, 'enum': {0: 'BeamactiveStsBeamStatusOff', 1: 'BeamactiveStsBeamStatusPassive', 2: 'BeamactiveStsBeamStatusActive', 3: 'BeamactiveStsreserved3', 4: 'BeamactiveStsreserved4', 5: 'BeamactiveStsreserved5', 6: 'BeamactiveStsreserved6', 7: 'BeamactiveStsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'beamactivests', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::BeamactivestsType Lightreq336::beamactivests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 3);

  Lightreq336::BeamactivestsType ret =  static_cast<Lightreq336::BeamactivestsType>(x);
  return ret;
}

// config detail: {'bit': 4, 'enum': {0: 'BeamlightreqLowBeamRequest', 1: 'BeamlightreqHighBeamRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::BeamlightreqType Lightreq336::beamlightreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  Lightreq336::BeamlightreqType ret =  static_cast<Lightreq336::BeamlightreqType>(x);
  return ret;
}

// config detail: {'bit': 7, 'enum': {0: 'EmeglampReqoff', 1: 'EmeglampReq125Hz', 2: 'EmeglampReq1Hz', 3: 'EmeglampReqinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'emeglampreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lightreq336::EmeglampreqType Lightreq336::emeglampreq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Lightreq336::EmeglampreqType ret =  static_cast<Lightreq336::EmeglampreqType>(x);
  return ret;
}
}  // namespace nio
}  // namespace canbus
}  // namespace apollo
