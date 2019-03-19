#include "nav2_dynamic_params/dynamic_params_client.hpp"
#include "rclcpp/rclcpp.hpp"

class DNode : public rclcpp::Node {
public:
    DNode();

private:
    void reconfigureCB();

    std::unique_ptr<nav2_dynamic_params::DynamicParamsClient> dynamic_param_client_;
    rclcpp::Node::SharedPtr node_;
};

DNode::DNode()
    : rclcpp::Node("dynamic_param_client")
{
    RCLCPP_INFO(get_logger(), "dnode constructor");

    node_ = std::shared_ptr<rclcpp::Node>(this, [](rclcpp::Node*) {});
    dynamic_param_client_ = std::make_unique<nav2_dynamic_params::DynamicParamsClient>(node_);
    dynamic_param_client_->add_parameters({ "aaa", "bbb", "ccc", "ddd" });
    dynamic_param_client_->set_callback(std::bind(&DNode::reconfigureCB, this));

    set_parameters({rclcpp::Parameter("aaa", 11)}); 
    set_parameters({rclcpp::Parameter("bbb", 22), rclcpp::Parameter("ccc", 33)}); 
    set_parameters_atomically({rclcpp::Parameter("bbb", 23), rclcpp::Parameter("ccc", 24)}); 
}

void DNode::reconfigureCB()
{
    int a, b, c, d;
    dynamic_param_client_->get_event_param("aaa", a);
    dynamic_param_client_->get_event_param("bbb", b);
    dynamic_param_client_->get_event_param("ccc", c);
    dynamic_param_client_->get_event_param("ddd", d);

    RCLCPP_INFO(get_logger(), "a: %d, b: %d, c: %d, d: %d", a, b, c, d);
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DNode>());
    rclcpp::shutdown();

    return 0;
}
