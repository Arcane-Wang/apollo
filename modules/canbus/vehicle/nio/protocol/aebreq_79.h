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

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'AEBTarDecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
  Aebreq79* set_aebtardecel(double aebtardecel);

  // config detail: {'bit': 28, 'enum': {0: 'ABAREQ_NO_REQUEST', 1: 'ABAREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_abareq(Aebreq_79::AbareqType abareq);

  // config detail: {'bit': 26, 'enum': {0: 'ABASNVTYLVL_LEVEL_0', 1: 'ABASNVTYLVL_LEVEL_1', 2: 'ABASNVTYLVL_LEVEL_2', 3: 'ABASNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'ABASnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_abasnvtylvl(Aebreq_79::AbasnvtylvlType abasnvtylvl);

  // config detail: {'bit': 38, 'enum': {0: 'AWBSNVTYLVL_LEVEL_0', 1: 'AWBSNVTYLVL_LEVEL_1', 2: 'AWBSNVTYLVL_LEVEL_2', 3: 'AWBSNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'AWBSnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_awbsnvtylvl(Aebreq_79::AwbsnvtylvlType awbsnvtylvl);

  // config detail: {'bit': 30, 'enum': {0: 'AWBREQ_NO_REQUEST', 1: 'AWBREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_awbreq(Aebreq_79::AwbreqType awbreq);

  // config detail: {'bit': 18, 'enum': {0: 'SCMDECELREQ_NO_REQUEST', 1: 'SCMDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_scmdecelreq(Aebreq_79::ScmdecelreqType scmdecelreq);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AEB_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Aebreq79* set_aeb_msgcntr(int aeb_msgcntr);

  // config detail: {'bit': 22, 'enum': {0: 'AEBDECELREQ_NO_REQUEST', 1: 'AEBDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_aebdecelreq(Aebreq_79::AebdecelreqType aebdecelreq);

  // config detail: {'bit': 31, 'enum': {0: 'EBADECELREQ_NO_REQUEST', 1: 'EBADECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'EBADecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_ebadecelreq(Aebreq_79::EbadecelreqType ebadecelreq);

  // config detail: {'bit': 16, 'enum': {0: 'ABPREQ_NO_REQUEST', 1: 'ABPREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_abpreq(Aebreq_79::AbpreqType abpreq);

  // config detail: {'bit': 20, 'enum': {0: 'PEDPDECREQ_NO_REQUEST', 1: 'PEDPDECREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPDecReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Aebreq79* set_pedpdecreq(Aebreq_79::PedpdecreqType pedpdecreq);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AEB_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Aebreq79* set_aeb_crc(int aeb_crc);

 private:

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 16, 'name': 'AEBTarDecel', 'offset': -16.0, 'order': 'motorola', 'physical_range': '[-16|15.99]', 'physical_unit': 'm/s2', 'precision': 0.0004882, 'type': 'double'}
  void set_p_aebtardecel(uint8_t* data, double aebtardecel);

  // config detail: {'bit': 28, 'enum': {0: 'ABAREQ_NO_REQUEST', 1: 'ABAREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABAReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_abareq(uint8_t* data, Aebreq_79::AbareqType abareq);

  // config detail: {'bit': 26, 'enum': {0: 'ABASNVTYLVL_LEVEL_0', 1: 'ABASNVTYLVL_LEVEL_1', 2: 'ABASNVTYLVL_LEVEL_2', 3: 'ABASNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'ABASnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_abasnvtylvl(uint8_t* data, Aebreq_79::AbasnvtylvlType abasnvtylvl);

  // config detail: {'bit': 38, 'enum': {0: 'AWBSNVTYLVL_LEVEL_0', 1: 'AWBSNVTYLVL_LEVEL_1', 2: 'AWBSNVTYLVL_LEVEL_2', 3: 'AWBSNVTYLVL_LEVEL_3'}, 'is_signed_var': False, 'len': 2, 'name': 'AWBSnvtyLvl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_awbsnvtylvl(uint8_t* data, Aebreq_79::AwbsnvtylvlType awbsnvtylvl);

  // config detail: {'bit': 30, 'enum': {0: 'AWBREQ_NO_REQUEST', 1: 'AWBREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AWBReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_awbreq(uint8_t* data, Aebreq_79::AwbreqType awbreq);

  // config detail: {'bit': 18, 'enum': {0: 'SCMDECELREQ_NO_REQUEST', 1: 'SCMDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'SCMDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_scmdecelreq(uint8_t* data, Aebreq_79::ScmdecelreqType scmdecelreq);

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 4, 'name': 'AEB_MsgCntr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_aeb_msgcntr(uint8_t* data, int aeb_msgcntr);

  // config detail: {'bit': 22, 'enum': {0: 'AEBDECELREQ_NO_REQUEST', 1: 'AEBDECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBDecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_aebdecelreq(uint8_t* data, Aebreq_79::AebdecelreqType aebdecelreq);

  // config detail: {'bit': 31, 'enum': {0: 'EBADECELREQ_NO_REQUEST', 1: 'EBADECELREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'EBADecelReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_ebadecelreq(uint8_t* data, Aebreq_79::EbadecelreqType ebadecelreq);

  // config detail: {'bit': 16, 'enum': {0: 'ABPREQ_NO_REQUEST', 1: 'ABPREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'ABPReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_abpreq(uint8_t* data, Aebreq_79::AbpreqType abpreq);

  // config detail: {'bit': 20, 'enum': {0: 'PEDPDECREQ_NO_REQUEST', 1: 'PEDPDECREQ_REQUEST'}, 'is_signed_var': False, 'len': 1, 'name': 'PEDPDecReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_pedpdecreq(uint8_t* data, Aebreq_79::PedpdecreqType pedpdecreq);

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'AEB_CRC', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_aeb_crc(uint8_t* data, int aeb_crc);

 private:
  double aebtardecel_;
  Aebreq_79::AbareqType abareq_;
  Aebreq_79::AbasnvtylvlType abasnvtylvl_;
  Aebreq_79::AwbsnvtylvlType awbsnvtylvl_;
  Aebreq_79::AwbreqType awbreq_;
  Aebreq_79::ScmdecelreqType scmdecelreq_;
  int aeb_msgcntr_;
  Aebreq_79::AebdecelreqType aebdecelreq_;
  Aebreq_79::EbadecelreqType ebadecelreq_;
  Aebreq_79::AbpreqType abpreq_;
  Aebreq_79::PedpdecreqType pedpdecreq_;
  int aeb_crc_;
};

}  // namespace nio
}  // namespace canbus
}  // namespace apollo


