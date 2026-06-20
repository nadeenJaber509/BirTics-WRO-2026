# Lane Following Design

## Purpose

Lane following is the main driving algorithm used to keep the robot moving safely around the track.

The objective is to keep the robot centered while maintaining stable and smooth movement.

## Main Idea

The robot continuously reads information from sensors and/or the camera.

Based on the detected position, the software calculates an error value and applies steering corrections using the PID controller.

## Sensor Inputs

Possible inputs include:

- Camera for track detection
- Distance sensors for wall measurements
- IMU sensor for orientation support

The final configuration will depend on hardware testing and performance.

## Camera-Based Lane Following

The camera captures images of the track.

The software processes each frame and determines:

- Track center
- Vehicle position relative to the center
- Required steering correction

Error is calculated as:

```text
error = lane_center - vehicle_center
```

The PID controller uses this error to adjust steering.

## Distance Sensor Method

Distance sensors can also help estimate robot position.

Example:

```text
error = left_distance - right_distance
```

If the robot is closer to one side, steering is adjusted toward the center.

## PID Integration

The lane following algorithm sends the calculated error to the PID controller.

The PID controller generates the steering correction needed to keep the robot centered.

## Corner Handling

When approaching a corner:

1. Detect change in track direction.
2. Reduce speed if necessary.
3. Apply smoother steering corrections.
4. Return to normal lane following after the turn.

## Expected Challenges

Possible challenges include:

- Lighting changes
- Camera noise
- Sensor inaccuracies
- Fast corner transitions

These issues will be addressed through testing and tuning.

## Testing Plan

1. Test straight sections.
2. Test corner sections.
3. Tune PID values.
4. Increase speed gradually.
5. Measure lane tracking stability.

## Current Status

The lane following algorithm is currently in the design stage.

Final implementation details will be completed after hardware selection and initial testing.
