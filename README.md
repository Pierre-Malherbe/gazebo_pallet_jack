# gazebo_pallet_jack
Design of an autonomous pallet jack using gazebo

## Instructions
To control the robot from the keyboard there's the need to install teleop-twist:
```
sudo apt-get install ros-kinetic-teleop-twist-keyboard
```

If apt does not find the package:
```
apt-cache search ros-kinetic-teleop
```

and find another package with a similar name.

To run:
```
roslaunch gazebo_ros empty_world.launch
```

Add the model to the world and check if the topic cmd_vel has been created under the name of the robot.

```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=robot0/cmd_vel
```

Where robot_0 must be substituted with the name of the robot.
In this way teleop publishes on the right topic.

### Laser Scan 
Laser Scan publish messages of type sensor_msgs/LaserScan.msg
The sensor class is GpuRaySensor.
Reference: 
- http://docs.ros.org/kinetic/api/sensor_msgs/html/msg/LaserScan.html
- http://answers.ros.org/question/198843/need-explanation-on-sensor_msgslaserscanmsg/
- http://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/group__gazebo__sensors.html

### Plugin Library Path

```
export LD_LIBRARY_PATH=~/path_to_build/build:$LD_LIBRARY_PATH
```

Reference: 
- http://wiki.ros.org/stdr_simulator/Tutorials/Teleop%20with%20teleop_twist_keyboard

- http://www.theconstructsim.com/how-to-build-a-differential-drive-simulation/

- http://answers.gazebosim.org/question/12366/clarification-on-moving-joint-with-model-plugin/

Emanuele Ghelfi
Emiliano Gagliardi

