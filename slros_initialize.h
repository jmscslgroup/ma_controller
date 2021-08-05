#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ma_controller/Subscribe4
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Sub_ma_controller_3;

// For Block ma_controller/Subscribe5
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Sub_ma_controller_4;

// For Block ma_controller/Publish Region1/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Pub_ma_controller_14;

// For Block ma_controller/Publish Region2/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Pub_ma_controller_20;

void slros_node_init(int argc, char** argv);

#endif
