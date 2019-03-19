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

    auto node = rclcpp::Node::make_shared("set_and_get_parameters");

    auto parameters_client = std::make_shared<rclcpp::SyncParametersClient>(node);
    while (!parameters_client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Existing.");
            return 0;
        }
        RCLCPP_INFO(node->get_logger(), "service not available, waiting again...");
    }

    auto set_parameters_results = parameters_client->set_parameters({
            rclcpp::Parameter("foo", 2),
            rclcpp::Parameter("bar", "hello"),
            rclcpp::Parameter("baz", 1.45),
            rclcpp::Parameter("foobar", true)
            });

    for (auto& result: set_parameters_results) {
        if (!result.successful) {
            RCLCPP_ERROR(node->get_logger(), "Failed to set parameter: %s", result.reason.c_str());
        }
    }

    std::stringstream ss;
    for (auto& parameter: parameters_client->get_parameters({"foo", "baz", "bar", "foobar"})) {
        ss << "\nParameter name: " << parameter.get_name();
        ss << "\nParameter value (" << parameter.get_type_name() << "): " << 
            parameter.value_to_string();
    }
    RCLCPP_INFO(node->get_logger(), ss.str().c_str());

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
