cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)

include_directories(${GAZEBO_INCLUDE_DIRS}
		    ${CMAKE_CURRENT_BINARY_DIR}/msgs)
		    
link_directories(${GAZEBO_LIBRARY_DIRS}
		 ${CMAKE_CURRENT_BINARY_DIR}/msgs)
		 
add_subdirectory(msgs)

list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(laser_plugin SHARED LaserPlugin.cc)

target_link_libraries(laser_plugin pallet_jack_msgs ${GAZEBO_libraries})

add_dependencies(laser_plugin pallet_jack_msgs)