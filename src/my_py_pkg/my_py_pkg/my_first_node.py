#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class MyNode(Node):

    def __init__(self):
        self.counter = 0
        super().__init__("py_test")  # name of the node
        self.get_logger().info("Hello ROS2")
        self.create_timer(0.5, self.timer_callback)

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info(f"Hello, {self.counter} ")


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()

if __name__ == "__main__":
    main()