cmake_minimum_required(VERSION 3.0.2)
project(test_pkg)

find_package(catkin REQUIRED COMPONENTS
	message_generation
	std_msgs
  roscpp
  rospy)

add_message_files(DIRECTORY msg)

add_service_files(DIRECTORY srv)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
  roscpp
  rospy
  std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(example src/example.cpp)
target_link_libraries(example ${catkin_LIBRARIES})

catkin_install_python(PROGRAMS scripts/example.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(
    TARGETS example
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)