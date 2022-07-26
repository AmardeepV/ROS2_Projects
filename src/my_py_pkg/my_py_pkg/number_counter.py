#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class PubSubCounter(Node): 
    def __init__(self):
        super().__init__("number_counter") 
        
        self.counter = 0
        self.number_count_publisher_ = self.create_publisher(Int64, "number_count", 10) 
        self.number_subscriber_ = self.create_subscription(Int64, "number", self.callback, 10)
        self.get_logger().info("number counter SUB has been started")

    def callback(self, msg):
        
        #self.get_logger().info(msg.data)
        self.counter += msg.data
        new_msg = Int64()
        new_msg.data = self.counter
        self.number_count_publisher_.publish(new_msg)

def main(args=None):
    rclpy.init(args=args)
    node = PubSubCounter() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 