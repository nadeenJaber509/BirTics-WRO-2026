# Algorithms Plan

This document describes the high-level autonomous driving algorithm implemented on the BirTics WRO Future Engineers 2026 robot. The software is designed to continuously process sensor data, make driving decisions in real time, and safely complete the competition track.

---

# 1. System Initialization

After power-up, the ESP32 initializes all hardware components, including:

- Three VL6180X Time-of-Flight (ToF) distance sensors
- Two TCS3200 color sensors
- MG996R steering servo
- DC drive motor
- L298N motor driver

Each sensor is checked before the robot enters the waiting state.

---

# 2. Start Sequence

The robot waits for the official start signal.

Once the start button is pressed, autonomous operation begins.

---

# 3. Lane Following

The robot continuously reads both color sensors to detect the track boundaries.

The steering angle is adjusted to keep the vehicle centered inside the driving lane.

The lane following algorithm runs continuously throughout the entire competition except when obstacle avoidance temporarily takes priority.

---

# 4. Steering Control

The steering system uses a PID controller to improve stability.

For every control cycle:

- Calculate steering error
- Compute PID correction
- Update steering servo angle

This reduces oscillation and provides smoother vehicle motion.

---

# 5. Obstacle Detection

The three ToF sensors continuously monitor the area in front of the vehicle.

The software determines:

- Whether an obstacle is present
- Its approximate position relative to the vehicle
- The appropriate avoidance maneuver

---

# 6. Obstacle Avoidance

When an obstacle is detected:

1. Reduce vehicle speed.
2. Calculate a safe steering path.
3. Drive around the obstacle.
4. Return smoothly to the driving lane.
5. Resume normal lane following.

---

# 7. Continuous Navigation

During the entire run, the robot repeatedly performs the following loop:

- Read sensors
- Process sensor data
- Detect lane boundaries
- Detect obstacles
- Update steering
- Control vehicle speed
- Repeat

This real-time loop allows the robot to react continuously to changes on the track.

---

# 8. Mission Completion

The robot continues autonomous navigation until the competition task has been completed according to the official WRO Future Engineers rules.

At the end of the run, the vehicle stops safely.
Green pillar:
- Robot must pass it from the left side.

## 4. Obstacle Avoidance Strategy

When a pillar is detected:

1. Identify its color.
2. Decide the correct side.
3. Move with a safe offset.
4. Pass the pillar.
5. Return to normal lane following.

## 5. Lap Counting

The robot needs to complete 3 laps.

Possible counting method:
- Detect corners or sections.
- Count 4 corners as 1 lap.
- Stop or move to parking after 3 laps.

## 6. Parking Strategy

After completing the obstacle challenge laps, the robot will search for the parking area.

Parking steps:
1. Detect parking boundaries.
2. Align parallel to the wall.
3. Move slowly into the parking area.
4. Stop inside the parking zone.
