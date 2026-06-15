# Robot State Machine

## Overview

The robot software is organized as a state machine to ensure reliable and autonomous behavior during both challenges.

## States

### 1. IDLE
Robot is powered on and waiting for the start button.

↓

### 2. FOLLOW_TRACK
Robot follows the track using camera and distance sensors.

↓

### 3. DETECT_PILLAR
Robot searches for red and green traffic signs.

↓

### 4. AVOID_PILLAR
Red pillar → pass from the right side.

Green pillar → pass from the left side.

↓

### 5. LAP_COUNTING
Robot counts completed laps and track sections.

↓

### 6. PARKING
Robot aligns itself and performs parallel parking.

↓

### 7. STOP
Robot stops after completing the challenge.
