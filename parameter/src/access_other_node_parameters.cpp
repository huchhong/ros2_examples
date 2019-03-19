#include <memory>
#include <sstream>
#include <vector>
#include <chrono>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
    // Force flush of the stdout buffer.
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("access_other_node_parameters");
    RCLCPP_INFO(node->get_logger(), "access parameters of other node");

    auto parameters_client = std::make_shared<rclcpp::SyncParametersClient>(node, "set_and_get_parameters");
    while (!parameters_client->wait_for_service(3s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Existing.");
            return 0;
        }
        RCLCPP_INFO(node->get_logger(), "service not available, waiting again...");
    }

    std::stringstream ss;
    for (auto& parameter: parameters_client->get_parameters({"foo", "baz", "bar", "foobar", "map_file", "non_exist"})) {
        ss << "\nParameter name: " << parameter.get_name();
        ss << "\nParameter value (" << parameter.get_type_name() << "): " << 
            parameter.value_to_string();
    }
    RCLCPP_INFO(node->get_logger(), ss.str().c_str());

    rclcpp::shutdown();

    return 0;
}

