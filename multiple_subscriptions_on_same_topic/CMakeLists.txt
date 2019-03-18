cmake_minimum_required(VERSION 3.5)
project(sub_pub_test)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(sub_multi_times_test src/sub_multi_times_test.cpp)

set(dependencies
    rclcpp
    std_msgs)

ament_target_dependencies(sub_multi_times_test
    ${dependencies})

install(TARGETS sub_multi_times_test
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(${dependencies})

ament_package()

