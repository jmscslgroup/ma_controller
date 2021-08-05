#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ma_controller";

// For Block ma_controller/Subscribe4
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Sub_ma_controller_3;

// For Block ma_controller/Subscribe5
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Sub_ma_controller_4;

// For Block ma_controller/Publish Region1/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Pub_ma_controller_14;

// For Block ma_controller/Publish Region2/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ma_controller_geometry_msgs_Twist> Pub_ma_controller_20;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

