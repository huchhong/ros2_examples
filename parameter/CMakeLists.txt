cmake_minimum_required(VERSION 3.5)
project(param_test)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

find_package(rclcpp REQUIRED)
#find_package(nav2_dynamic_params REQUIRED)

add_executable(set_and_get_parameters src/set_and_get_parameters.cpp)
add_executable(access_other_node_parameters src/access_other_node_parameters.cpp)
add_executable(stub_node src/stub_node.cpp)
#add_executable(dynamic_params_client src/dynamic_client.cpp)

set(dependencies
    rclcpp)
    #nav2_dynamic_params)

ament_target_dependencies(set_and_get_parameters
    ${dependencies})
ament_target_dependencies(access_other_node_parameters
    ${dependencies})
ament_target_dependencies(stub_node
    ${dependencies})
#ament_target_dependencies(dynamic_params_client
    #${dependencies})

install(TARGETS set_and_get_parameters access_other_node_parameters stub_node #dynamic_params_client
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
    DESTINATION share/${PROJECT_NAME})

ament_export_dependencies(${dependencies})

ament_package()

