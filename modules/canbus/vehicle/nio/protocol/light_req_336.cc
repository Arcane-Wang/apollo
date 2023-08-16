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

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace nio {

using ::apollo::drivers::canbus::Byte;

const int32_t Lightreq336::ID = 0x336;

// public
Lightreq336::Lightreq336() { Reset(); }

uint32_t Lightreq336::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Lightreq336::UpdateData(uint8_t* data) {
  set_p_brklireq(data, brklireq_);
  set_p_frntwiprsts(data, frntwiprsts_);
  set_p_turnlightind(data, turnlightind_);
  set_p_beamactivests(data, beamactivests_);
  set_p_beamlightreq(data, beamlightreq_);
  set_p_emeglampreq(data, emeglampreq_);
}

void Lightreq336::Reset() {
  // TODO(All) :  you should check this manually
  brklireq_ = Light_req_336::BRKLIREQ_NO_REQUEST;
  frntwiprsts_ = Light_req_336::FRNTWIPRSTS_OFF;
  turnlightind_ = Light_req_336::TURNLIGHTIND_NO_TURN;
  beamactivests_ = Light_req_336::BEAMACTIVESTS_BEAM_STATUS_OFF;
  beamlightreq_ = Light_req_336::BEAMLIGHTREQ_LOW_BEAM_REQUEST;
  emeglampreq_ = Light_req_336::EMEGLAMPREQ_OFF;
}

Lightreq336* Lightreq336::set_brklireq(
    Light_req_336::BrklireqType brklireq) {
  brklireq_ = brklireq;
  return this;
 }

// config detail: {'bit': 23, 'enum': {0: 'BRKLIREQ_NO_REQUEST', 1: 'BRKLIREQ_REQUEST', 2: 'BRKLIREQ_RESERVED', 3: 'BRKLIREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLiReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_brklireq(uint8_t* data,
    Light_req_336::BrklireqType brklireq) {
  int x = brklireq;

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 2);
}


Lightreq336* Lightreq336::set_frntwiprsts(
    Light_req_336::FrntwiprstsType frntwiprsts) {
  frntwiprsts_ = frntwiprsts;
  return this;
 }

// config detail: {'bit': 15, 'enum': {0: 'FRNTWIPRSTS_OFF', 1: 'FRNTWIPRSTS_LOW_SPEED', 2: 'FRNTWIPRSTS_HIGH_SPEED', 3: 'FRNTWIPRSTS_RESERVED3', 4: 'FRNTWIPRSTS_RESERVED4', 5: 'FRNTWIPRSTS_RESERVED5', 6: 'FRNTWIPRSTS_RESERVED6', 7: 'FRNTWIPRSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'Frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_frntwiprsts(uint8_t* data,
    Light_req_336::FrntwiprstsType frntwiprsts) {
  int x = frntwiprsts;

  Byte to_set(data + 1);
  to_set.set_value(x, 5, 3);
}


Lightreq336* Lightreq336::set_turnlightind(
    Light_req_336::TurnlightindType turnlightind) {
  turnlightind_ = turnlightind;
  return this;
 }

// config detail: {'bit': 3, 'enum': {0: 'TURNLIGHTIND_NO_TURN', 1: 'TURNLIGHTIND_TURN_LEFT', 2: 'TURNLIGHTIND_TURN_RIGHT', 3: 'TURNLIGHTIND_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'Turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_turnlightind(uint8_t* data,
    Light_req_336::TurnlightindType turnlightind) {
  int x = turnlightind;

  Byte to_set(data + 0);
  to_set.set_value(x, 2, 2);
}


Lightreq336* Lightreq336::set_beamactivests(
    Light_req_336::BeamactivestsType beamactivests) {
  beamactivests_ = beamactivests;
  return this;
 }

// config detail: {'bit': 12, 'enum': {0: 'BEAMACTIVESTS_BEAM_STATUS_OFF', 1: 'BEAMACTIVESTS_BEAM_STATUS_PASSIVE', 2: 'BEAMACTIVESTS_BEAM_STATUS_ACTIVE', 3: 'BEAMACTIVESTS_RESERVED3', 4: 'BEAMACTIVESTS_RESERVED4', 5: 'BEAMACTIVESTS_RESERVED5', 6: 'BEAMACTIVESTS_RESERVED6', 7: 'BEAMACTIVESTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'BeamactiveSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_beamactivests(uint8_t* data,
    Light_req_336::BeamactivestsType beamactivests) {
  int x = beamactivests;

  Byte to_set(data + 1);
  to_set.set_value(x, 2, 3);
}


Lightreq336* Lightreq336::set_beamlightreq(
    Light_req_336::BeamlightreqType beamlightreq) {
  beamlightreq_ = beamlightreq;
  return this;
 }

// config detail: {'bit': 4, 'enum': {0: 'BEAMLIGHTREQ_LOW_BEAM_REQUEST', 1: 'BEAMLIGHTREQ_HIGH_BEAM_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_beamlightreq(uint8_t* data,
    Light_req_336::BeamlightreqType beamlightreq) {
  int x = beamlightreq;

  Byte to_set(data + 0);
  to_set.set_value(x, 4, 1);
}


Lightreq336* Lightreq336::set_emeglampreq(
    Light_req_336::EmeglampreqType emeglampreq) {
  emeglampreq_ = emeglampreq;
  return this;
 }

// config detail: {'bit': 7, 'enum': {0: 'EMEGLAMPREQ_OFF', 1: 'EMEGLAMPREQ_1_25HZ', 2: 'EMEGLAMPREQ_1HZ', 3: 'EMEGLAMPREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EmeglampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Lightreq336::set_p_emeglampreq(uint8_t* data,
    Light_req_336::EmeglampreqType emeglampreq) {
  int x = emeglampreq;

  Byte to_set(data + 0);
  to_set.set_value(x, 6, 2);
}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
