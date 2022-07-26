#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class NumPublisher(Node): 
    def __init__(self):
        super().__init__("num_publisher") 

        self.publisher_ = self.create_publisher(Int64, "number", 10)  # message type has to be same in publishers and subscriber
        self.timers_ = self.create_timer(0.5, self.publish_value)
        self.get_logger().info("Number publisher has been started")

    def publish_value(self):
        value = Int64()
        value.data = 1 # int64 has data field so the value has to be rapped with data
        self.publisher_.publish(value)
        

def main(args=None):
    rclpy.init(args=args)
    node = NumPublisher() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 