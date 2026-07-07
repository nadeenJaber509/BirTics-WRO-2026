# Robot State Machine

from enum import Enum


class RobotState(Enum):
    IDLE_WAIT_START = 0
    LANE_FOLLOW = 1
    PILLAR_AVOID_RED_RIGHT = 2
    PILLAR_AVOID_GREEN_LEFT = 3
    LAP_COUNT_FINISH = 4
    PARKING = 5
    STOP = 6
