# gazebo_sfm_tb3_ros2
## About

SFM (Social Force Model) and turtlebot3 on gazebo using ros2  

## Demo

https://user-images.githubusercontent.com/46204057/212112813-9d413414-d63f-4006-a79c-d2b3bb4cc78c.mp4

## Environment
- Ubuntu 20.04
- ROS Foxy

## Dependencies
 - [lightsfm](https://github.com/robotics-upo/lightsfm)
 - [turtlebot3_simulation](https://github.com/ROBOTIS-GIT/turtlebot3_simulations)
   + turtlebot3_gazebo
   + turtlebot3_fake

### lightsfm

```shell
$ git clone https://github.com/robotics-upo/lightsfm.git
$ cd lightsfm
$ make
$ sudo make install
```

### turtlebot3_simulation

```shell
$ cd {your_ros2_ws}/src
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
$ cd {your_ros2_ws}/
$ colcon build
$ source install/setup.bash
```

## Usage
### git clone and colcon build

```shell
$ cd {your_ros2_ws}/src
$ git clone https://github.com/koichirokato/gazebo_sfm_tb3_ros2.git
$ cd {your_ros2_ws}/
$ colcon build
$ source install/setup.bash
```

### ROS launch

```
# You have to set value of TURTLEBOT3_MODEL before ros2 launch command.
$ export TURTLEBOT3_MODEL=burger
$ ros2 launch gazebo_sfm_tb3_ros2 turtlebot3_world_dynamic.launch.py
```

## Reference
- Turtlebot3 sfm gazebo environment (ROS1): [turtlebot3_simulations_jp_custom](https://github.com/ROBOTIS-JAPAN-GIT/turtlebot3_simulations_jp_custom)
- Turtlebot3 gazebo environment (ROS2) : [turtlebot3_simulations](https://github.com/ROBOTIS-GIT/turtlebot3_simulations/tree/foxy-devel)
