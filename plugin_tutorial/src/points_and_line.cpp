

#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"

#include <visualization_msgs/msg/marker.hpp>
using namespace std::chrono_literals;
class MarkerDisplay : public rclcpp::Node
{

public:
    MarkerDisplay()
        : Node("marker_display")
    {

        memsg = this->create_publisher<visualization_msgs::msg::Marker>("DisplayShape", 10);
        timer_ = this->create_wall_timer(
            5000ms, std::bind(&MarkerDisplay::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto node = shared_from_this();
        visualization_msgs::msg::Marker line_strip;
        line_strip.header.frame_id = "map";
        line_strip.header.stamp = node->now();
        line_strip.ns = "ns";
        line_strip.action = visualization_msgs::msg::Marker::ADD;

        line_strip.pose.orientation.x = 0;
        line_strip.pose.orientation.y = 0;
        line_strip.pose.orientation.z = 0;
        line_strip.pose.orientation.w = 0;
        line_strip.id = 0;
        line_strip.type = visualization_msgs::msg::Marker::CUBE_LIST;
        line_strip.scale.x = 0.1;
        line_strip.scale.y = 0.1;
        line_strip.scale.z = 0.1;

        // line_strip.frame_locked =false;

        line_strip.color.r = 1.0;
        line_strip.color.b = 1.0;
        line_strip.color.g = 1.0;
        line_strip.color.a = 1.0;
        geometry_msgs::msg::Point arrp;
        arrp.x = 0.1;
        arrp.y = 0;
        arrp.z = 0;
        line_strip.points.push_back(arrp);

        arrp.x = 0.2;
        arrp.y = 0;
        arrp.z = 0;
        line_strip.points.push_back(arrp);

        arrp.x = 0.3;
        arrp.y = 0;
        arrp.z = 0;
        line_strip.points.push_back(arrp);

        arrp.x = 0.4;
        arrp.y = 0;
        arrp.z = 1;
        line_strip.points.push_back(arrp);
        // int j = 0;
        // for (float i = 0; i < 10; i = i + 0.1)
        // {
        //     if (j == 0 || j == 1)
        //     {
        //         arrp.x = 0;
        //         arrp.y = 0;
        //         arrp.z = i;
        //         line_strip.points.push_back(arrp);
        //     }
        //     if (j == 2 || j == 3)
        //     {
        //         arrp.x = 0;
        //         arrp.y = 0.1;
        //         arrp.z = i;
        //         line_strip.points.push_back(arrp);
        //         if(j==3){
        //             j=0;
        //         }
        //     }
        //     j++;
        // }

        memsg->publish(line_strip);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr memsg;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MarkerDisplay>());
    rclcpp::shutdown();
    return 0;
}
