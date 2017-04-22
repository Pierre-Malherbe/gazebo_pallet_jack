#ifndef _GAZEBO_LIFT_PLUGIN_HH
#define _GAZEBO_LIFT_PLUGIN_HH

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <sstream>
#include <stdio.h>

namespace gazebo {
  class LiftPlugin : public ModelPlugin{
    
  public: LiftPlugin();
  public: virtual ~LiftPlugin();
  public: virtual void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf);
  private: void OnUpdate(const std_msgs::Bool::ConstPtr& msg);  
  
  private: ros::Subscriber subscriber;
  private: physics::JointPtr prismaticJoint;
  
};
}

#endif