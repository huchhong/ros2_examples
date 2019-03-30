import os
from launch import LaunchDescription
import launch.actions
import launch_ros.actions


def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package="examples_rclcpp_minimal_service",
            node_executable="service_main",
            node_name="service_main",
            node_namespace="",
            output="screen",
            parameters=[]
        ),
        launch_ros.actions.Node(
            package="examples_rclcpp_minimal_client",
            node_executable="client_main",
            node_name="client_main",
            node_namespace="",
            output="screen",
            parameters=[]
        )
    ])
