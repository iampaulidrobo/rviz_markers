
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
///
#include "rviz_common/ros_integration/ros_node_abstraction.hpp"

#include <QApplication>
#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QVBoxLayout>

#include <QtWidgets/QComboBox>
#include <QMessageBox>
using std::placeholders::_1;
using namespace std;
string pp = "NULL";
class Gui : public rclcpp::Node, public QMainWindow
{
public:
    Gui(QApplication *app)
        : Node("Gui_node"), count_(0)
    {
        setFixedSize(500, 300);
        moveforward->setGeometry(QRect(100, 100, 200, 100));
        connect(moveforward, &QPushButton::released, this, &Gui::pushhandler);

 ////////////////////////////////ROS/////////////////////////////////////////////////////////////////////////

        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic", 10, std::bind(&Gui::topic_callback, this, _1));

        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&Gui::timer_callback, this));
    }
    QPushButton *moveforward = new QPushButton("Update_pub_status", this);


private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {

        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        pp = msg->data.c_str();
    }
    void pushhandler()
    {
        moveforward->setText(pp.c_str());
    }
    void timer_callback()
    {

        auto message = std_msgs::msg::String();
        message.data = "My, GUI! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
    QApplication *app_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);

    auto myviz = std::make_shared<Gui>(&app);
    myviz->show();

    while (rclcpp::ok())
    {
        rclcpp::spin_some(myviz);

        app.processEvents();
    }

    return 0;
}
