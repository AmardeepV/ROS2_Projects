#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from my_robot_interfaces.msg import LedStates
from my_robot_interfaces.srv import SetLed

class LedPanelNode(Node): 
    def __init__(self):
        super().__init__("led_panel_node") 
        self.declare_parameter("led_states", [0, 0, 0])

        self.led_states_ = self.get_parameter("led_states").value
        self.led_state_publisher_ = self.create_publisher(LedStates, "led_state", 10)  # message type has to be same in publishers and subscriber
        self.timers_ = self.create_timer(4, self.led_state_value)
        self.set_led_service = self.create_service(SetLed,"set_led", self.callback_set_led)
        self.get_logger().info("Led state has been started")

        
    def led_state_value(self):
        value = LedStates()
        value.led_states = self.led_states_
        self.led_state_publisher_.publish(value)
        
    def callback_set_led(self, request, response):
        led_number = request.led_number
        state = request.state

        if led_number > len(self.led_states_) or led_number <= 0:
            response.success = False            
            return response
        
        if state not in [0, 1]:
            response.success = False
            return response

        self.led_states_[led_number -1] = state
        response.success = True
        self.led_state_value()
        return response


def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 