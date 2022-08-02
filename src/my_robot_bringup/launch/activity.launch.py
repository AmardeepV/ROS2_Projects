from launch import LaunchDescription
from launch_ros.actions import Node



def generate_launch_description():
    ld = LaunchDescription()

    robot_name = ["giskard", "bb8", "daneel", "jander","c3po"]
    robot_news_station = []

    for i in robot_name:
        robot_news_station.append(Node(
            package="my_py_pkg",
            executable="robot_news_station",
            name="robot_news_station_" + i, #  rename the node
            parameters=[                # parameters in lauch file
                {"robot_name": i}
            ]
        ))

    for node in robot_news_station:
        ld.add_action(node)

    return ld