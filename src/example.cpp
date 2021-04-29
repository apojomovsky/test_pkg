#include <ros/ros.h>
#include "test_pkg/Wall.h"

bool example_cb(test_pkg::Wall::Request  &req,
         test_pkg::Wall::Response &res)
{
  ROS_INFO("Doing nothing");
  std::cout << req.positions.size() << std::endl;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "example_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("example", example_cb);
  ROS_INFO("Ready to run.");
  ros::spin();

  return 0;
}
