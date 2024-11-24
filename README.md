VEX Robotics Project README
This repository contains the code for a VEX Robotics project, primarily focusing on controlling a robot using a variety of sensors, motors, and pneumatic systems. The code includes functionality for driving the robot, controlling an arm mechanism, handling intake and outtake systems, and managing vision and odometry.

Features
1. Driver Control
Joystick Control:
Axis 3 (Vertical): Controls the robot's forward and backward movement.
Axis 1 (Horizontal): Controls the robot's left and right movement.
Button Controls:
R1: Activates the intake motor.
R2: Activates the outtake motor.
L1: Moves the robot's arm downward.
L2: Controls a mobile goal clamp mechanism.
Arm Control:
Button Right: Moves the arm upwards.
Button Y: Moves the arm downwards.
2. Autonomous Mode
Pre-Autonomous Initialization: The robot initializes sensors and calibration routines.
Autonomous Sequences: The robot can execute predefined tasks during autonomous mode, such as:
Red and Blue side autonomous routines (for example, redl, redr, bluel, bluer).
3. Intake and Outtake Mechanism
Intake: Activates the intake motor for collecting objects.
Outtake: Activates the outtake motor for releasing objects.
Clamp: Controls a pneumatic system for clamping items.
4. Arm Mechanism
Arm Up and Down: The arm can be raised and lowered using dedicated buttons or functions.
Advanced Arm Control: Includes additional toggling features to control the arm’s state for complex movements.
5. Vision and Sensors
Distance Sensor: The robot includes a distance sensor (aaasssddd) to detect objects within a specified range.
Inertial Sensor: Used for odometry, determining the robot’s position and heading for navigation.
6. Odometry
The robot tracks its position using encoders on the left and right motors, as well as the inertial sensor. This enables the robot to perform accurate movements and turns based on its current position and orientation.
7. Pneumatic Control
Pneumatic actuators are used to control the intake and clamp systems, providing efficient handling of objects during the competition.
Setup and Initialization
Hardware Components:
Motors:
leftmo: A motor group consisting of three motors controlling the left side of the chassis.
rightmo: A motor group consisting of three motors controlling the right side of the chassis.
inta1, inta2: Motors controlling the intake system.
arm: Motor controlling the robotic arm.
Sensors:
bob: Inertial sensor used for heading and position tracking.
aaasssddd: Distance sensor to detect objects within a range.
Pneumatics:
intakee, mogoclp, shgrjn: Pneumatic systems for intake, clamp, and other actions.
Software Dependencies:
VEXcode: The code is intended to be run on the VEX V5 robot platform using VEXcode Pro V5.
VEX Robotics Library: This library is used to control motors, sensors, and other devices on the robot.
Initialization Functions:
vexcodeInit: Initializes all the hardware and sets up the necessary devices before starting the competition or user control.
pre_auton: Performs setup tasks before the autonomous phase, such as calibrating sensors.
Code Explanation
1. Driver Control (driver())
The driver controls the robot using joysticks for movement and buttons for arm and intake control. The robot can move forward, backward, left, and right based on joystick inputs.
2. Autonomous Mode (autonomous())
The robot executes predefined tasks during the autonomous phase. Tasks are selected based on the autonomous option set.
3. Arm Movement (armup(), armdown())
Functions for controlling the arm's movement, either up or down.
4. Intake and Mogo Clamp (intake(), mogo_clamp())
Toggle mechanisms to start and stop the intake motor and clamp system.
5. Odometry (odom())
This function tracks the robot's position using encoder values from the left and right motors and the inertial sensor, allowing the robot to know its position on the field.
Future Improvements
Vision System: Adding a vision sensor to recognize objects and determine their positions relative to the robot.
More Autonomous Sequences: Additional strategies and routines for different competition scenarios.
PID Tuning: Implement PID control for precise movement and positioning.
