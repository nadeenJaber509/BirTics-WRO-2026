# Algorithms Plan

## 1. Lane Following Algorithm

The robot will follow the track using distance sensors and/or camera input.

Basic idea:

- Read left and right distance.
- Calculate the error.
- Use PID control to correct steering.
- Keep the robot centered between the walls.

## 2. PID Steering

PID will be used to make steering smoother and reduce shaking.

Error = target position - current position

The steering correction depends on:
- P: current error
- I: accumulated error
- D: change in error

## 3. Pillar Detection

The camera will detect red and green pillars using color detection.

Red pillar:
- Robot must pass it from the right side.

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
