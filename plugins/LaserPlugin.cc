#include "LaserPlugin.hh"

#define THRESHOLD 0.2

using namespace gazebo;

GZ_REGISTER_SENSOR_PLUGIN(LaserPlugin)

LaserPlugin::LaserPlugin():SensorPlugin(){
}

LaserPlugin::~LaserPlugin(){
}


void LaserPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
    // get parent sensor
    this->parentSensor = std::dynamic_pointer_cast<sensors::GpuRaySensor>(_sensor);
    
    // Make sure the parent sensor is valid.
    if (!this->parentSensor)
    {
      gzerr << "ContactPlugin requires a ContactSensor.\n";
      return;
    }
    

    // Connect to the sensor update event.
    this->updateConnection = this->parentSensor->ConnectUpdated(std::bind(&LaserPlugin::OnUpdate, this));

    // Make sure the parent sensor is active.
    this->parentSensor->SetActive(true);
    
    // Init ROS and advertise a topic
    if(!ros::isInitialized()){
      // launch ros
	int argc = 0;
	char **argv = NULL;
	ros::init(argc, argv, "gazebo_client", ros::init_options::NoSigintHandler);
    }
    
    // get ros node handler
    ros::NodeHandle node;
    
    publisher = node.advertise<std_msgs::Bool>("/pallet_jack/load");
    
    std::cout << "executed load method\n\n";
}

void LaserPlugin::OnUpdate()
{
    std::cout << "onUpdate\n\n";
    bool is_loaded = (parentSensor->RangeMin() < THRESHOLD);
    std_msgs::Bool msg;
    msg.data = is_loaded;
    publisher.publish(msg);
}