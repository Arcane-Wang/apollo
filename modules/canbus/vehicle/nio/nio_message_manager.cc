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

#include "modules/canbus/vehicle/nio/nio_message_manager.h"



#include "modules/canbus/vehicle/nio/protocol/Accreq7f.h"
#include "modules/canbus/vehicle/nio/protocol/Acmbody4a.h"
#include "modules/canbus/vehicle/nio/protocol/Aebreq79.h"
#include "modules/canbus/vehicle/nio/protocol/Avpreq15e.h"
#include "modules/canbus/vehicle/nio/protocol/Bcusts5e.h"
#include "modules/canbus/vehicle/nio/protocol/Bodystatus24d.h"
#include "modules/canbus/vehicle/nio/protocol/Brkdrvstatus24c.h"
#include "modules/canbus/vehicle/nio/protocol/Driverstatus24e.h"
#include "modules/canbus/vehicle/nio/protocol/Epsreqc6.h"
#include "modules/canbus/vehicle/nio/protocol/Epsstatus01d5.h"
#include "modules/canbus/vehicle/nio/protocol/Epsstatus02d6.h"
#include "modules/canbus/vehicle/nio/protocol/Lightreq336.h"
#include "modules/canbus/vehicle/nio/protocol/Motorsts018e.h"
#include "modules/canbus/vehicle/nio/protocol/Motorsts0286.h"
#include "modules/canbus/vehicle/nio/protocol/Pulsecnt65.h"
#include "modules/canbus/vehicle/nio/protocol/Scmsts7b.h"
#include "modules/canbus/vehicle/nio/protocol/Vcusts01218.h"
#include "modules/canbus/vehicle/nio/protocol/Vcusts0221c.h"
#include "modules/canbus/vehicle/nio/protocol/Vehiclelights2c7.h"
#include "modules/canbus/vehicle/nio/protocol/Whlspdfront51.h"
#include "modules/canbus/vehicle/nio/protocol/Whlspdrear52.h"

namespace apollo {
namespace canbus {
namespace nio {

NioMessageManager::NioMessageManager() {
  // Control Messages


  // Report Messages
  AddRecvProtocolData<Accreq7f, true>();
  AddRecvProtocolData<Acmbody4a, true>();
  AddRecvProtocolData<Aebreq79, true>();
  AddRecvProtocolData<Avpreq15e, true>();
  AddRecvProtocolData<Bcusts5e, true>();
  AddRecvProtocolData<Bodystatus24d, true>();
  AddRecvProtocolData<Brkdrvstatus24c, true>();
  AddRecvProtocolData<Driverstatus24e, true>();
  AddRecvProtocolData<Epsreqc6, true>();
  AddRecvProtocolData<Epsstatus01d5, true>();
  AddRecvProtocolData<Epsstatus02d6, true>();
  AddRecvProtocolData<Lightreq336, true>();
  AddRecvProtocolData<Motorsts018e, true>();
  AddRecvProtocolData<Motorsts0286, true>();
  AddRecvProtocolData<Pulsecnt65, true>();
  AddRecvProtocolData<Scmsts7b, true>();
  AddRecvProtocolData<Vcusts01218, true>();
  AddRecvProtocolData<Vcusts0221c, true>();
  AddRecvProtocolData<Vehiclelights2c7, true>();
  AddRecvProtocolData<Whlspdfront51, true>();
  AddRecvProtocolData<Whlspdrear52, true>();
}

NioMessageManager::~NioMessageManager() {}

}  // namespace nio
}  // namespace canbus
}  // namespace apollo
