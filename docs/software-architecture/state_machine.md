# Robot State Machine

## Overview

The BirTics autonomous vehicle is implemented as a finite state machine (FSM). Each state represents a specific operating mode of the robot and defines how the software responds to sensor inputs before transitioning to the next state.

Using a state machine keeps the software modular, predictable, and easy to debug.

---

# Robot States

## 1. IDLE

The robot is powered on and initializes all hardware components.

During this state, the software checks that all sensors are responding correctly before entering the waiting state.

↓

## 2. WAIT_FOR_START

The robot remains stationary while waiting for the official start signal.

Once the start button is pressed, autonomous operation begins.

↓

## 3. LANE_FOLLOWING

The robot continuously reads the two TCS3200 color sensors to remain centered within the driving lane.

While following the lane, the software also monitors the ToF sensors for nearby obstacles.

↓

## 4. OBSTACLE_AVOIDANCE

When an obstacle is detected by the ToF sensors, the robot temporarily leaves normal lane following.

During this state, the software calculates a safe path around the obstacle before returning to the lane.

↓

## 5. MISSION_COMPLETE

After the required competition task has been completed, the robot safely stops and disables further motion.
