#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class RobotNewsStation(Node): 
    def __init__(self):
        super().__init__("robot_news_station") 
        
        self.robot_name = "Jarvis"
        self.publisher_ = self.create_publisher(String, "robot_news", 10)  # message type has to be same in publishers and subscriber
        self.timers_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot news station has been started")

    def publish_news(self):
        msg  = String()
        msg.data = "Hello from " + str(self.robot_name)
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStation() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 