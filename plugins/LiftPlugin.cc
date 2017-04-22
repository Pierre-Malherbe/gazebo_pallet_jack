#include "LiftPlugin.hh"

using namespace gazebo;

 // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(LiftPlugin)
  
LiftPlugin::LiftPlugin():ModelPlugin(){
}

void LiftPlugin::Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
{
  // in Load method get the joint and subscribe to the topic
  //get joint
  this->prismaticJoint = _parent->GetJoint("chassis_lift_joint");
  
  
  // Init ROS and advertise a topic
   if(!ros::isInitialized()){
      // launch ros
	int argc = 0;
	char **argv = NULL;
	ros::init(argc, argv, "gazebo_client", ros::init_options::NoSigintHandler);
    }
    
    // get ros node handler
    ros::NodeHandle node;
    
    //subscribe
    this-> subscriber = node.subscribe<std_msgs::Bool>("/pallet_jack/load", 1, &LiftPlugin::OnUpdate,this);
    
    std::cout<<"Load executed from Lift Plugin\n";
}

// On update method called when someone publishes on topic
void LiftPlugin::OnUpdate(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data){
    bool result = prismaticJoint->SetPosition(3,0.5);
    std::cout<<"RESULT" <<result;
  }
  else{
    std::cout << "No Load";
  }
}


LiftPlugin::~LiftPlugin()
{

}

