#include "rclcpp/rclcpp.hpp"
#include "nav2_dynamic_params/dynamic_params_client.hpp"

class DNode : public rclcpp::Node {
public:
};

int main(int argc, char**argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DNode>());
    rclcpp::shutdown();

    return 0;
}
