#!/usr/bin/env python

from __future__ import print_function

from test_pkg.srv import Wall, WallResponse
import rospy

def handle_example(req):
    print("Not doing anything")
    return WallResponse()


def example_server():
    rospy.init_node('example_server')
    s = rospy.Service('example', Wall, handle_example)
    print("Ready to run.")
    rospy.spin()

if __name__ == "__main__":
    example_server()
