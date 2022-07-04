
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
       
        publisherMarker_ = this->create_publisher<visualization_msgs::msg::Marker>("DisplayBasicShape", 10);
        timer_ = this->create_wall_timer(
            3000ms, std::bind(&MarkerDisplay::timer_callback, this));
           
    }

private:
    void timer_callback()
    {
        auto node=shared_from_this();
        DisplayMarker=toMarker("map","mk",1,node);
        publisherMarker_->publish(DisplayMarker);
        f=f+0.1;

    }
inline visualization_msgs::msg::Marker toMarker(
  const std::string & frame,
  const std::string & ns,
  const double & scale,
  rclcpp::Node::SharedPtr node)
{
  visualization_msgs::msg::Marker marker;

  marker.header.frame_id = frame;
  marker.header.stamp = node->now();
  marker.ns = ns;
  marker.type = visualization_msgs::msg::Marker::CUBE;
  marker.pose.position.x = 0.0;
  marker.pose.position.y = f/2;
  marker.pose.position.z = f;
  //marker.pose.orientation.w = 1.;
  
  marker.scale.x = 1;
  marker.scale.y = 0.1;
  marker.scale.z = 0.1;
  marker.color.r = 1.0;
  marker.color.g = 1;
  marker.color.b = 1.0;
  marker.color.a = 1.;
  marker.action = visualization_msgs::msg::Marker::ADD;
 // marker.lifetime = rclcpp::Duration::from_seconds(3);
 marker.lifetime = rclcpp::Duration::max();
 
//  finalmarker=finalmarker+marker;
 

  return marker;
}
rclcpp::TimerBase::SharedPtr timer_;
visualization_msgs::msg::Marker DisplayMarker;
float f=0.0;
rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisherMarker_;;
}
;

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MarkerDisplay>());
    rclcpp::shutdown();
    return 0;
}
