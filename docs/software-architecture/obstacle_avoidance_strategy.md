# Obstacle Avoidance Strategy

## Purpose

The obstacle avoidance strategy is responsible for detecting traffic signs and passing them according to the WRO Future Engineers rules.

The robot must:

- Pass red pillars from the right side.
- Pass green pillars from the left side.

## Detection Method

The robot will use a camera and computer vision techniques to detect colored pillars.

Possible detection steps:

1. Capture image from camera.
2. Convert image to HSV color space.
3. Detect red and green color regions.
4. Find pillar position.
5. Determine the required avoidance path.

## Red Pillar Strategy

When a red pillar is detected:

1. Confirm detection.
2. Estimate pillar position.
3. Move to the right side of the pillar.
4. Pass the pillar safely.
5. Return to normal lane following.

## Green Pillar Strategy

When a green pillar is detected:

1. Confirm detection.
2. Estimate pillar position.
3. Move to the left side of the pillar.
4. Pass the pillar safely.
5. Return to normal lane following.

## Safety Conditions

The robot should:

- Avoid touching the pillar.
- Avoid moving the pillar outside its allowed area.
- Maintain stable steering while passing.
- Return smoothly to the driving path.

## State Machine Integration

Obstacle avoidance is connected to the software state machine.

FOLLOW_TRACK
    ↓
DETECT_PILLAR
    ↓
RED or GREEN
    ↓
AVOID_PILLAR
    ↓
FOLLOW_TRACK

## Testing Plan

The obstacle avoidance algorithm will be tested using:

- Different pillar positions.
- Different lighting conditions.
- Different robot speeds.

Results will be documented and used to improve reliability.

## Current Status

The obstacle avoidance strategy is currently in the design phase.

The final implementation will be developed after hardware selection and camera integration.
