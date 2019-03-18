import os
from launch import LaunchDescription
import launch.actions
import launch_ros.actions


def generate_launch_description():
    map_yaml_file = launch.substitutions.LaunchConfiguration('map', default="asdf")

    return LaunchDescription([
        launch_ros.actions.Node(
            package="param_test",
            node_executable="set_and_get_parameters",
            node_name="set_get_parameters",
            node_namespace="robot1",
            output="screen",
            parameters=[{'map_file': map_yaml_file}]
        )
    ])
