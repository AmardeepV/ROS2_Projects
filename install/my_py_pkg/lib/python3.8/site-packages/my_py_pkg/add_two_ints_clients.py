#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial

from example_interfaces.srv import AddTwoInts

class AddTwoIntsClient(Node): 
    def __init__(self):
        super().__init__("add_two_ints_clients") 
        self.add_two_ints_client(8,3)


    def add_two_ints_client(self, x, y):
        client = self.create_client(AddTwoInts, "add_two_int") # creating client  with the same name as service
        while not client.wait_for_service(1.0):  # it will check if the service matching the type and name of the cliet is available once a second.
            self.get_logger().warn("Waiting for the server Add_Two_Ints......")

        request = AddTwoInts.Request()
        request.a = x
        request.b = y

        future = client.call_async(request)  # async type call
        # the partial will allow to use more argument to the callabck function
        future.add_done_callback(partial(self.callback_call_add_two_ints, a=x,b=y)) 
        #This function will be called when the future will get the result means when 
        #the client get connected to the server and after that it will call the callback
        #function.

    def callback_call_add_two_ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger.info(str(a) + "+" + str(b) + "=" + str(response.sum))

        except Exception as e:
            self.get_logger().error("Service call faield %r" % (e,))


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClient() 
    rclpy.spin(node)  # allow to be alive wait for the callback
    rclpy.shutdown()


if __name__ == "__main__":
    main()
 