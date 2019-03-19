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
            node_name="set_and_get_parameters",
            node_namespace="",
            output="screen",
            parameters=[{'map_file': map_yaml_file}]
        ),
        launch_ros.actions.Node(
            package="param_test",
            node_executable="access_other_node_parameters",
            node_name="access_other_node_parameters",
            node_namespace="",
            output="screen",
        ),
        # launch_ros.actions.Node(
            # package="param_test",
            # node_executable="stub_node",
            # node_name="stub_node",
            # node_namespace="",
            # output="screen",
        # )
    ])
