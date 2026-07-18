# Lane Following Design

## Purpose

Lane following is the primary navigation algorithm used by the BirTics WRO Future Engineers 2026 robot.

Its objective is to keep the vehicle centered within the driving lane while maintaining stable and continuous autonomous movement.

---

## Design Overview

The robot uses two TCS3200 color sensors mounted underneath the chassis to monitor the track surface.

During every control cycle, both sensors are read continuously. Their measurements are processed to estimate the robot's position relative to the lane boundaries.

Based on this information, the software calculates the steering correction required to keep the robot on the intended path.

---

## Sensor Inputs

Lane following relies on:

- Two TCS3200 color sensors
- PID steering controller
- MG996R steering servo

Obstacle detection is handled independently by the three VL6180X ToF sensors.

---

## Lane Position Estimation

The software compares the readings obtained from the left and right color sensors.

Differences between the two measurements indicate whether the robot has moved toward one side of the lane.

This information is converted into a steering error that is passed to the PID controller.

---

## Steering Correction

The calculated lane error is processed by the PID controller.

The controller generates a steering command that adjusts the angle of the MG996R servo, allowing the vehicle to return smoothly toward the center of the lane while minimizing oscillations.

---

## Continuous Operation

The lane following algorithm operates continuously throughout the autonomous run.

Each control cycle performs the following sequence:

1. Read both color sensors.
2. Estimate the robot's lane position.
3. Calculate the steering error.
4. Compute the PID correction.
5. Update the steering servo.
6. Repeat.

---

## Testing

The lane following algorithm is evaluated under different driving conditions to verify:

- Stable steering response
- Consistent lane tracking
- Reliable sensor readings
- Smooth vehicle motion

PID parameters are adjusted experimentally to achieve accurate and stable steering performance.
