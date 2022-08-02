#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus

class HwStatus(Node): 
    def __init__(self):
        super().__init__("hw_status_publisher") 

        self.hw_status_publisher_ = self.create_publisher(HardwareStatus, "hardware_status", 10)  # message type has to be same in publishers and subscriber
        self.timers_ = self.create_timer(0.5, self.hw_status_value)
        self.get_logger().info("HW status publisher has been started")

    def hw_status_value(self):
        value = HardwareStatus()
        value.temperature = 42
        value.are_motors_ready = True
        value.debug_message = "Everything is working fine but make sure the temperature doesn't exceed 50"
        self.hw_status_publisher_.publish(value)
        

def main(args=None):
    rclpy.init(args=args)
    node = HwStatus() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 