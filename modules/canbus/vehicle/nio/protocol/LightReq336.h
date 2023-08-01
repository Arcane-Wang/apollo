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
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 23, 'enum': {0: 'BrkLiReqNoRequest', 1: 'BrkLiReqrequest', 2: 'BrkLiReqreserved', 3: 'BrkLiReqinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'BrkLiReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::BrklireqType brklireq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'enum': {0: 'Frntwiprstsoff', 1: 'FrntwiprstsLowSpeed', 2: 'FrntwiprstsHighSpeed', 3: 'Frntwiprstsreserved3', 4: 'Frntwiprstsreserved4', 5: 'Frntwiprstsreserved5', 6: 'Frntwiprstsreserved6', 7: 'Frntwiprstsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'Frntwiprsts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::FrntwiprstsType frntwiprsts(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'enum': {0: 'TurnlightindNoTurn', 1: 'TurnlightindTurnLeft', 2: 'TurnlightindTurnRight', 3: 'Turnlightindinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'Turnlightind', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::TurnlightindType turnlightind(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'enum': {0: 'BeamactiveStsBeamStatusOff', 1: 'BeamactiveStsBeamStatusPassive', 2: 'BeamactiveStsBeamStatusActive', 3: 'BeamactiveStsreserved3', 4: 'BeamactiveStsreserved4', 5: 'BeamactiveStsreserved5', 6: 'BeamactiveStsreserved6', 7: 'BeamactiveStsinvalid'}, 'is_signed_var': False, 'len': 3, 'name': 'BeamactiveSts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::BeamactivestsType beamactivests(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 4, 'enum': {0: 'BeamlightreqLowBeamRequest', 1: 'BeamlightreqHighBeamRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'Beamlightreq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::BeamlightreqType beamlightreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'enum': {0: 'EmeglampReqoff', 1: 'EmeglampReq125Hz', 2: 'EmeglampReq1Hz', 3: 'EmeglampReqinvalid'}, 'is_signed_var': False, 'len': 2, 'name': 'EmeglampReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Lightreq336::EmeglampreqType emeglampreq(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


