#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node {
public:
    MinimalSubscriber()
        : Node("minimal_subscriber")
    {
        subscription1_ = this->create_subscription<std_msgs::msg::String>("topic", std::bind(&MinimalSubscriber::topic_callback1, this, _1));
        subscription2_ = this->create_subscription<std_msgs::msg::String>("topic", std::bind(&MinimalSubscriber::topic_callback2, this, _1));
    }

private:
    void topic_callback1(const std_msgs::msg::String::SharedPtr msg) 
    {
        RCLCPP_INFO(this->get_logger(), "[Callback1] I heard: '%s'", msg->data.c_str()); 
    }
    void topic_callback2(const std_msgs::msg::String::SharedPtr msg) 
    {
        RCLCPP_INFO(this->get_logger(), "[Callback2] I heard: '%s'", msg->data.c_str()); 
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription1_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription2_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}
