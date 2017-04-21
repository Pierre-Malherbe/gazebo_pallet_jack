#include "LaserPlugin.hh"

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
    
    // get the publisher
    transport::NodePtr node(new transport::Node());
    node -> Init();
    publisher = node -> Advertise<msgs::bool>("load");
}

void LaserPlugin::OnUpdate()
{
  
}