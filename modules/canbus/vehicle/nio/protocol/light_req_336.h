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

class Lightreq336 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Lightreq336();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 23, 'enum': {0: 'BRKLIREQ_NO_REQUEST', 1: 'BRKLIREQ_REQUEST', 2: 'BRKLIREQ_RESERVED', 3: 'BRKLIREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLiReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_brklireq(Light_req_336::BrklireqType brklireq);

  // config detail: {'bit': 15, 'enum': {0: 'FRNTWIPRSTS_OFF', 1: 'FRNTWIPRSTS_LOW_SPEED', 2: 'FRNTWIPRSTS_HIGH_SPEED', 3: 'FRNTWIPRSTS_RESERVED3', 4: 'FRNTWIPRSTS_RESERVED4', 5: 'FRNTWIPRSTS_RESERVED5', 6: 'FRNTWIPRSTS_RESERVED6', 7: 'FRNTWIPRSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'Frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_frntwiprsts(Light_req_336::FrntwiprstsType frntwiprsts);

  // config detail: {'bit': 3, 'enum': {0: 'TURNLIGHTIND_NO_TURN', 1: 'TURNLIGHTIND_TURN_LEFT', 2: 'TURNLIGHTIND_TURN_RIGHT', 3: 'TURNLIGHTIND_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'Turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_turnlightind(Light_req_336::TurnlightindType turnlightind);

  // config detail: {'bit': 12, 'enum': {0: 'BEAMACTIVESTS_BEAM_STATUS_OFF', 1: 'BEAMACTIVESTS_BEAM_STATUS_PASSIVE', 2: 'BEAMACTIVESTS_BEAM_STATUS_ACTIVE', 3: 'BEAMACTIVESTS_RESERVED3', 4: 'BEAMACTIVESTS_RESERVED4', 5: 'BEAMACTIVESTS_RESERVED5', 6: 'BEAMACTIVESTS_RESERVED6', 7: 'BEAMACTIVESTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'BeamactiveSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_beamactivests(Light_req_336::BeamactivestsType beamactivests);

  // config detail: {'bit': 4, 'enum': {0: 'BEAMLIGHTREQ_LOW_BEAM_REQUEST', 1: 'BEAMLIGHTREQ_HIGH_BEAM_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_beamlightreq(Light_req_336::BeamlightreqType beamlightreq);

  // config detail: {'bit': 7, 'enum': {0: 'EMEGLAMPREQ_OFF', 1: 'EMEGLAMPREQ_1_25HZ', 2: 'EMEGLAMPREQ_1HZ', 3: 'EMEGLAMPREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EmeglampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336* set_emeglampreq(Light_req_336::EmeglampreqType emeglampreq);

 private:

  // config detail: {'bit': 23, 'enum': {0: 'BRKLIREQ_NO_REQUEST', 1: 'BRKLIREQ_REQUEST', 2: 'BRKLIREQ_RESERVED', 3: 'BRKLIREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLiReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_brklireq(uint8_t* data, Light_req_336::BrklireqType brklireq);

  // config detail: {'bit': 15, 'enum': {0: 'FRNTWIPRSTS_OFF', 1: 'FRNTWIPRSTS_LOW_SPEED', 2: 'FRNTWIPRSTS_HIGH_SPEED', 3: 'FRNTWIPRSTS_RESERVED3', 4: 'FRNTWIPRSTS_RESERVED4', 5: 'FRNTWIPRSTS_RESERVED5', 6: 'FRNTWIPRSTS_RESERVED6', 7: 'FRNTWIPRSTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'Frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_frntwiprsts(uint8_t* data, Light_req_336::FrntwiprstsType frntwiprsts);

  // config detail: {'bit': 3, 'enum': {0: 'TURNLIGHTIND_NO_TURN', 1: 'TURNLIGHTIND_TURN_LEFT', 2: 'TURNLIGHTIND_TURN_RIGHT', 3: 'TURNLIGHTIND_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'Turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_turnlightind(uint8_t* data, Light_req_336::TurnlightindType turnlightind);

  // config detail: {'bit': 12, 'enum': {0: 'BEAMACTIVESTS_BEAM_STATUS_OFF', 1: 'BEAMACTIVESTS_BEAM_STATUS_PASSIVE', 2: 'BEAMACTIVESTS_BEAM_STATUS_ACTIVE', 3: 'BEAMACTIVESTS_RESERVED3', 4: 'BEAMACTIVESTS_RESERVED4', 5: 'BEAMACTIVESTS_RESERVED5', 6: 'BEAMACTIVESTS_RESERVED6', 7: 'BEAMACTIVESTS_INVALID'}, 'is_signed_var': False, 'len': 3, 'name': 'BeamactiveSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_beamactivests(uint8_t* data, Light_req_336::BeamactivestsType beamactivests);

  // config detail: {'bit': 4, 'enum': {0: 'BEAMLIGHTREQ_LOW_BEAM_REQUEST', 1: 'BEAMLIGHTREQ_HIGH_BEAM_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'Beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_beamlightreq(uint8_t* data, Light_req_336::BeamlightreqType beamlightreq);

  // config detail: {'bit': 7, 'enum': {0: 'EMEGLAMPREQ_OFF', 1: 'EMEGLAMPREQ_1_25HZ', 2: 'EMEGLAMPREQ_1HZ', 3: 'EMEGLAMPREQ_INVALID'}, 'is_signed_var': False, 'len': 2, 'name': 'EmeglampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_emeglampreq(uint8_t* data, Light_req_336::EmeglampreqType emeglampreq);

 private:
  Light_req_336::BrklireqType brklireq_;
  Light_req_336::FrntwiprstsType frntwiprsts_;
  Light_req_336::TurnlightindType turnlightind_;
  Light_req_336::BeamactivestsType beamactivests_;
  Light_req_336::BeamlightreqType beamlightreq_;
  Light_req_336::EmeglampreqType emeglampreq_;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


