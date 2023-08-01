load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "nio_vehicle_factory",
    srcs = [
        "nio_vehicle_factory.cc",
    ],
    hdrs = [
        "nio_vehicle_factory.h",
    ],
    deps = [
        ":nio_controller",
        ":nio_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "nio_message_manager",
    srcs = [
        "nio_message_manager.cc",
    ],
    hdrs = [
        "nio_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/common_msgs/chassis_msgs:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/nio/protocol:canbus_nio_protocol",
    ],
)

cc_library(
    name = "nio_controller",
    srcs = [
        "nio_controller.cc",
    ],
    hdrs = [
        "nio_controller.h",
    ],
    deps = [
        ":nio_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/common_msgs/chassis_msgs:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/nio/protocol:canbus_nio_protocol",
    ],
)

cpplint()
