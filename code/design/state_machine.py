# Robot State Machine

from enum import Enum, auto


class RobotState(Enum):
    IDLE = auto()
    WAIT_FOR_START = auto()
    LANE_FOLLOWING = auto()
    OBSTACLE_AVOIDANCE = auto()
    MISSION_COMPLETE = auto()
