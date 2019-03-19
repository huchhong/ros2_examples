import os
from launch import LaunchDescription
import launch.actions
import launch_ros.actions


def generate_launch_description():
    params_file = launch.substitutions.LaunchConfiguration('params', default=
        [launch.substitutions.ThisLaunchFileDir(), '/params.yaml'])

    return LaunchDescription([
        launch_ros.actions.Node(
            package="param_test",
            node_executable="dynamic_params_client",
            node_name="dynamic_params_client",
            node_namespace="",
            output="screen",
            parameters=[params_file]
        )
    ])
