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
}
