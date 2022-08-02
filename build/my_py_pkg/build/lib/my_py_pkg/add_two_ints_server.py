#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts

class AddTwoInt(Node):
    def __init__(self):
        super().__init__("add_two_ints_server") 
        self.server_ = self.create_service(AddTwoInts, "add_two_ints", self.callback_add_two_ints)
        self.get_logger().info("Add two ints server has been started")


    def callback_add_two_ints(self, request, respose):
        respose.sum  = request.a + request.b
        self.get_logger().info(str(request.a) + "+" + str(request.b) + "=" + str(respose.sum))
        return respose

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoInt()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
