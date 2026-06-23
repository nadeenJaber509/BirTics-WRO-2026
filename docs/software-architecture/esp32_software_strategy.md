# ESP32-Only Software Strategy

## Purpose

This document describes the software strategy for using the ESP32 as the main controller of the robot.

The team selected the ESP32-only option as the first implementation because it is lower cost, simpler to wire, and suitable for the selected sensor-based system.

## Selected Controller

The ESP32 DevKit V1 will be used as the main controller.

It will read sensor values, make driving decisions, and send control signals to the motor driver and steering actuator.

## Main Hardware Inputs

The ESP32 will receive data from:

- VL53L0X Time-of-Flight distance sensors
- TCS34725 RGB color sensors
- TCRT5000 IR reflective sensor
- MPU-6050 IMU sensor
- Start button

## Main Hardware Outputs

The ESP32 will control:

- DC motor speed and direction through the L298N motor driver
- Steering actuator using PWM
- Stop behavior after completing the mission

## Main Software Modules

The software will be divided into modules:

- Start and safety logic
- Sensor reading
- Wall following
- PID steering control
- Color detection
- Obstacle avoidance
- Lap counting
- Parking logic
- Motor and steering control

## Driving Strategy

The robot will use sensor-based navigation instead of camera-based OpenCV.

The main movement algorithm will depend on distance readings from the ToF sensors.

The robot will try to keep a safe distance from the walls and use PID control to make steering smoother.

## Obstacle Strategy

The TCS34725 color sensors will be used to detect red and green pillars.

- Red pillar: pass from the right side.
- Green pillar: pass from the left side.

The robot will use a safe offset maneuver to avoid moving the pillars.

## IMU Usage

The MPU-6050 IMU will support turning stability and help detect heading changes during corners.

It may also support lap counting by detecting repeated turns.

## Lap Counting Strategy

The robot must complete three laps.

Possible lap counting methods:

- Count corners using IMU heading changes.
- Count sections using turning events.
- Combine IMU data with distance sensor patterns.

The final method will be selected after testing.

## Parking Strategy

After completing the obstacle challenge laps, the robot will search for the parking area and align itself using distance sensors.

The parking algorithm will be developed in stages:

1. Detect parking area.
2. Align parallel to the wall.
3. Move slowly into the parking area.
4. Stop inside the parking zone.

## Why Not OpenCV in the First Version

OpenCV and camera-based processing require stronger processing power, such as Raspberry Pi.

Since the selected first implementation uses ESP32 only, computer vision will remain an optional future improvement.

## Current Status

This strategy is the current software direction for the ESP32-only implementation.

The next step is to create ESP32 code modules and test each sensor separately before full integration.
