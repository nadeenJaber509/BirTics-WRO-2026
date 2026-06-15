# Software Research Notes

## OpenCV Lane Detection

Lane detection is used to keep the robot centered on the track.
The camera captures images continuously and software analyzes the track boundaries.
The steering angle is adjusted according to the detected lane position.

## OpenCV Color Detection

Color detection is used to identify red and green traffic signs.
The robot must pass red pillars from the right side and green pillars from the left side.
OpenCV can detect colors using the HSV color space.

## PID Steering Control

PID control helps keep the robot stable while driving.
The controller calculates steering corrections based on the error between the desired path and the current position.

## State Machine

The software will be organized using a state machine.

States:

- IDLE
- FOLLOW_TRACK
- DETECT_PILLAR
- AVOID_PILLAR
- LAP_COUNTING
- PARKING
- STOP

## Notes

Further research and testing will be added during development.
