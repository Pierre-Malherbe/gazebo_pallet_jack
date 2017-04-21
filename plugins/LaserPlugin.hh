#ifndef _GAZEBO_LASER_PLUGIN_HH
#define _GAZEBO_LASER_PLUGIN_HH

#include <string>

#include <gazebo/gazebo.hh>
#include <gazebo/sensors/sensors.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

namespace gazebo
{
	// \brief A plugin that reads from laser and publishes on a topic
	class LaserPlugin : public SensorPlugin
{
	// Constructor
public: LaserPlugin();
public: virtual ~LaserPlugin();

public: virtual void Load(sensors::SensorPtr _sensor,sdf::ElementPtr _sdf);

private: virtual void OnUpdate();

private: sensors::GpuRaySensorPtr parentSensor;

private: event::ConnectionPtr updateConnection;

private: transport::PublisherPtr publisher;

};
}
#endif
