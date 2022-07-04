#include "rclcpp/rclcpp.hpp"
#include "interactive_markers/interactive_marker_server.hpp"

#include <memory>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("interactive_marker_server");
  /////////////////////////////////////////////////////////////ICUBE 3DOF/////////////////////////////////////////////////////////////////////////////////
  interactive_markers::InteractiveMarkerServer iserver("first_i", node);
  visualization_msgs::msg::InteractiveMarker int_marker;
  int_marker.header.frame_id = "map";
  int_marker.header.stamp = node->now();
  int_marker.name = "6dof";
  int_marker.description = "6dof Control";

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
  rotate_control.orientation.w = 1;
  rotate_control.orientation.x = 1;
  rotate_control.orientation.y = 0;
  rotate_control.orientation.z = 0;

  rotate_control.name = "move_x";
  rotate_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
  int_marker.controls.push_back(rotate_control);

  rotate_control.orientation.w = 1;
  rotate_control.orientation.x = 0;
  rotate_control.orientation.y = 0;
  rotate_control.orientation.z = 1;
  rotate_control.name = "move_y";
  rotate_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
  int_marker.controls.push_back(rotate_control);

  rotate_control.orientation.w = 1;
  rotate_control.orientation.x = 0;
  rotate_control.orientation.y = 1;
  rotate_control.orientation.z = 0;
  rotate_control.name = "move_z";
  rotate_control.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;
  int_marker.controls.push_back(rotate_control);
  // tell the server to call processFeedback() when feedback arrives for it
  iserver.insert(int_marker);

  // 'commit' changes and send to all clients
  iserver.applyChanges();
  /////////////////////////////////////////////////////////////IISPHERE 3DOF/////////////////////////////////////////////////////////////////////////////////
  interactive_markers::InteractiveMarkerServer iiserver("first_i2", node);
  visualization_msgs::msg::InteractiveMarker int_marker2;
  int_marker2.header.frame_id = "map";
  int_marker2.header.stamp = node->now();
  int_marker2.name = "SPHERE";
  int_marker2.description = "SPHERE Control";
  int_marker2.pose.position.x = 2;
  visualization_msgs::msg::Marker box_marker2;
  // box_marker2.pose.position.x = 2;
  box_marker2.type = visualization_msgs::msg::Marker::SPHERE;
  box_marker2.scale.x = 0.45;
  box_marker2.scale.y = 0.45;
  box_marker2.scale.z = 0.45;
  box_marker2.color.r = 1;
  box_marker2.color.g = 0;
  box_marker2.color.b = 0;
  box_marker2.color.a = 1.0;
  visualization_msgs::msg::InteractiveMarkerControl box_control2;
  box_control2.always_visible = true;
  box_control2.markers.push_back(box_marker2);
  int_marker2.controls.push_back(box_control2);
  visualization_msgs::msg::InteractiveMarkerControl rotate_control2;
  rotate_control2.orientation.w = 1;
  rotate_control2.orientation.x = 1;
  rotate_control2.orientation.y = 0;
  rotate_control2.orientation.z = 0;
  rotate_control2.name = "rotate_x";

  rotate_control2.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::ROTATE_AXIS;
  int_marker2.controls.push_back(rotate_control2);

  rotate_control2.orientation.w = 1;
  rotate_control2.orientation.x = 0;
  rotate_control2.orientation.y = 0;
  rotate_control2.orientation.z = 1;
  rotate_control2.name = "rotate_y";
  rotate_control2.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::ROTATE_AXIS;
  int_marker2.controls.push_back(rotate_control2);

  rotate_control2.orientation.w = 1;
  rotate_control2.orientation.x = 0;
  rotate_control2.orientation.y = 1;
  rotate_control2.orientation.z = 0;
  rotate_control2.name = "rotate_z";
  rotate_control2.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::ROTATE_AXIS;
  int_marker2.controls.push_back(rotate_control2);

  // add the interactive marker to our collection &

  iiserver.insert(int_marker2);

  // 'commit' changes and send to all clients
  iiserver.applyChanges();
  /////////////////////////////////////////////////////////////IIISPHERE Along PLANE/////////////////////////////////////////////////////////////////////////////////
  interactive_markers::InteractiveMarkerServer iiiserver("first_i3", node);
  visualization_msgs::msg::InteractiveMarker int_marker3;
  int_marker3.header.frame_id = "map";
  int_marker3.header.stamp = node->now();
  int_marker3.name = "Arrow";
  int_marker3.description = "Arrow Control";
  int_marker3.pose.position.x = -2;
  visualization_msgs::msg::Marker box_marker3;
  // box_marker2.pose.position.x = 2;
  box_marker3.type = visualization_msgs::msg::Marker::ARROW;
  box_marker3.scale.x = 0.45;
  box_marker3.scale.y = 0.45;
  box_marker3.scale.z = 0.45;
  box_marker3.color.r = 1;
  box_marker3.color.g = 0;
  box_marker3.color.b = 0;
  box_marker3.color.a = 1.0;
  visualization_msgs::msg::InteractiveMarkerControl box_control3;
  box_control3.always_visible = true;
  box_control3.markers.push_back(box_marker3);
  int_marker3.controls.push_back(box_control3);
  visualization_msgs::msg::InteractiveMarkerControl rotate_control3;
  rotate_control3.orientation.w = 1;
  rotate_control3.orientation.x = 0;
  rotate_control3.orientation.y = 0;
  rotate_control3.orientation.z = 1;
  rotate_control3.name = "move_3d";
  rotate_control3.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_PLANE;
  int_marker3.controls.push_back(rotate_control3);

  // add the interactive marker to our collection &

  iiiserver.insert(int_marker3);

  // 'commit' changes and send to all clients
  iiiserver.applyChanges();

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "interactive_marker_server ready . . .");

  rclcpp::spin(node);
  rclcpp::shutdown();
}