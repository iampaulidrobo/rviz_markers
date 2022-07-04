cmake_minimum_required(VERSION 3.5)
project(plugin_tutorial)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

find_package(geometry_msgs REQUIRED)

find_package(interactive_markers REQUIRED)
add_executable(basic_shapes src/basic_shapes.cpp)
ament_target_dependencies(basic_shapes rclcpp std_msgs visualization_msgs)

add_executable(points_and_line src/points_and_line.cpp)
ament_target_dependencies(points_and_line rclcpp std_msgs visualization_msgs)

add_executable(interactive_marker src/interactive_marker.cpp)
ament_target_dependencies(interactive_marker rclcpp interactive_markers)

add_executable(interactive_marker_advance src/interactive_marker_advance.cpp)
ament_target_dependencies(interactive_marker_advance rclcpp interactive_markers)

install(TARGETS
  basic_shapes
  points_and_line
  interactive_marker
  interactive_marker_advance
DESTINATION lib/${PROJECT_NAME})
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
