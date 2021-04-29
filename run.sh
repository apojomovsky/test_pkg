SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

DOCKER_MOUNT_ARGS="\
    -v ${SCRIPT_DIR}:/catkin_ws/src/test_pkg"

xhost +
docker run --privileged --rm \
        ${DOCKER_MOUNT_ARGS} \
        -e DISPLAY=${DISPLAY} \
        -it osrf/ros:melodic-desktop-bionic
xhost -

