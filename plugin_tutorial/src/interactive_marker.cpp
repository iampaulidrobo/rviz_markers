#include "rclcpp/rclcpp.hpp"
#include "interactive_markers/interactive_marker_server.hpp"

#include <memory>


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("interactive_marker_server");
    interactive_markers::InteractiveMarkerServer iserver("first_i", node);
    visualization_msgs::msg::InteractiveMarker int_marker;
    int_marker.header.frame_id = "map";
    int_marker.header.stamp = node->now();
    int_marker.name = "my_marker";
    int_marker.description = "Simple 1-DOF Control";

    // create a grey box marker
    visualization_msgs::msg::Marker box_marker;
    box_marker.type = visualization_msgs::msg::Marker::CUBE;
    box_marker.scale.x = 0.45;
    box_marker.scale.y = 0.45;
    box_marker.scale.z = 0.45;
    box_marker.color.r = 0.5;
    box_marker.color.g = 0.5;
    box_marker.color.b = 0.5;
    box_marker.color.a = 1.0;

    // create a non-interactive control which contains the box
    visualization_msgs::msg::InteractiveMarkerControl box_control;
    box_control.always_visible = true;
    box_control.markers.push_back(box_marker);

    // add the control to the interactive marker
    int_marker.controls.push_back(box_control);

    // create a control which will move the box
    // this control does not contain any markers,
    // which will cause RViz to insert two arrows
    visualization_msgs::msg::InteractiveMarkerControl rotate_control;
    rotate_control.name = "move_x";
    rotate_control.interaction_mode =
        visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;


    // add the control to the interactive marker
    int_marker.controls.push_back(rotate_control);

    // add the interactive marker to our collection &
    // tell the server to call processFeedback() when feedback arrives for it
    iserver.insert(int_marker);

    // 'commit' changes and send to all clients
    iserver.applyChanges();
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "interactive_marker_server ready . . .");

    rclcpp::spin(node);
    rclcpp::shutdown();
}