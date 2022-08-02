from launch import LaunchDescription
from launch_ros.actions import Node



def generate_launch_description():
    ld = LaunchDescription()
    remap_number_topic = ("number", "my_number")

    number_publisher_node = Node(
        package="my_py_pkg",
        executable="num_publisher",
        name="my_number_publisher", #  rename the node
        remappings=[                # remapping the topic
            remap_number_topic
        ],
        parameters=[                # parameters in lauch file
            {"number": 4},
            {"publish_frequecy": 5.0}
        ]
    )
    number_counter_node = Node(
        package="my_py_pkg",
        executable="number_counter",
        name="my_number_counter",
        remappings=[
            remap_number_topic,
            ("number_count", "my_number_count")
        ]
    )
    ld.add_action(number_publisher_node)
    ld.add_action(number_counter_node)
    return ld