# PID Steering Controller

## Purpose

The PID steering controller will be used to keep the robot stable while following the track.  
Instead of making sudden left or right turns, PID allows the robot to make smooth steering corrections.

This is important because the WRO track has straight sections, corners, and random layouts, so the robot needs stable movement.

## Why We Use PID

A simple control method may cause the robot to shake or move in a zig-zag pattern.

PID is better because it corrects the robot movement based on:

- The current error
- The accumulated error
- The rate of change of the error

This helps the robot stay closer to the desired path.

## Input Sources

The PID error can be calculated using one or more of these inputs:

- Camera lane center detection
- Left and right distance sensor readings
- Wall distance measurements
- IMU readings for turning stability

The final input method will depend on the selected hardware and testing results.

## Error Calculation

If camera vision is used:

```text
error = desired_lane_center - detected_lane_center
```

If distance sensors are used:

```text
error = left_distance - right_distance
```

The goal is to keep the error close to zero.

## PID Formula

```text
steering_correction = (Kp * error) + (Ki * accumulated_error) + (Kd * error_change)
```

Where:

- Kp controls how strongly the robot reacts to the current error.
- Ki corrects long-term accumulated error.
- Kd reduces sudden changes and helps smooth the steering.

## Steering Output

The calculated PID correction will be sent to the steering actuator.

```text
steering_angle = center_angle + steering_correction
```

If the robot moves too far left, the controller will steer it right.

If the robot moves too far right, the controller will steer it left.

## Initial Testing Plan

The PID controller will be tested gradually:

1. Start with low speed.
2. Test movement on a straight section.
3. Tune Kp first until the robot reacts correctly.
4. Add Kd to reduce shaking.
5. Use Ki only if needed.
6. Test corners after straight movement becomes stable.
7. Record problems and update the values based on testing.

## Expected Challenges

Possible problems during testing:

- Robot oscillates too much.
- Robot reacts too slowly.
- Sensor readings are noisy.
- Camera detection changes because of lighting.
- Turns are too sharp or too wide.

These issues will be handled by tuning PID values and improving sensor filtering.

## Current Status

The PID controller is still in the design and research stage.  
Final PID values will be selected after testing the real robot on the track.

```text
Kp = To be determined during testing
Ki = To be determined during testing
Kd = To be determined during testing
```

## Relation to Other Software Modules

The PID controller will be used mainly by:

- Lane following module
- Wall following module
- Corner handling logic
- Parking alignment logic

This makes PID one of the main control algorithms in the robot software.
