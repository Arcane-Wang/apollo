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

class Aebreq79 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Aebreq79();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'AEBTarDecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
  double aebtardecel(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'enum': {0: 'ABAReqNoRequest', 1: 'ABAReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AbareqType abareq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'enum': {0: 'ABASnvtyLvlLevel0', 1: 'ABASnvtyLvlLevel1', 2: 'ABASnvtyLvlLevel2', 3: 'ABASnvtyLvlLevel3'}, 'is_signed_var': False, 'len': 2, 'name': 'ABASnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AbasnvtylvlType abasnvtylvl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'enum': {0: 'AWBSnvtyLvlLevel0', 1: 'AWBSnvtyLvlLevel1', 2: 'AWBSnvtyLvlLevel2', 3: 'AWBSnvtyLvlLevel3'}, 'is_signed_var': False, 'len': 2, 'name': 'AWBSnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AwbsnvtylvlType awbsnvtylvl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 30, 'enum': {0: 'AWBReqNoRequest', 1: 'AWBReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AwbreqType awbreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'enum': {0: 'SCMDecelReqNoRequest', 1: 'SCMDecelReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::ScmdecelreqType scmdecelreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AebMsgcntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t aebmsgcntr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 22, 'enum': {0: 'AEBDecelReqNoRequest', 1: 'AEBDecelReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AebdecelreqType aebdecelreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'enum': {0: 'EBADecelReqNoRequest', 1: 'EBADecelReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'EBADecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::EbadecelreqType ebadecelreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'enum': {0: 'ABPReqNoRequest', 1: 'ABPReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::AbpreqType abpreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'enum': {0: 'PEDPDecReqNoRequest', 1: 'PEDPDecReqRequest'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPDecReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79::PedpdecreqType pedpdecreq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AebCrc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int32_t'}
  int32_t aebcrc(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


