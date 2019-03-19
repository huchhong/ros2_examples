# parameter usage example

## access parameters of other node

- access_other_node_parameters.cpp
- set_and_get_parameters.cpp
- access_other_node_param_launch.py

## usage of dynamic params client in nav2 stack

- dynamic_params_cient_launch.py

This example has shown some useful messages:

1. reconfigureCB will be invoked firstly for parameter settings from launch file.
2. set_parameters will invoke reconfigureCB each time for everty parameter in its argument.
3. set_parameters_atomically will invoke reconfigureCB once for all parameters in its argument. This shall be every useful.
