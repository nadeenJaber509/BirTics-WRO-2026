# Main Robot Program
#
# This file represents the high-level software design.
# The executable ESP32 firmware is implemented in code/esp32/.

from sensors import read_all_sensors
from pid_controller import PIDController
from state_machine import RobotState


robot_state = RobotState.IDLE

pid = PIDController(
    kp=0.0,
    ki=0.0,
    kd=0.0,
)

SERVO_CENTER_ANGLE = 90
NORMAL_MOTOR_SPEED = 50


def initialize_system():
    """Initialize the robot hardware and software modules."""
    print("System initialized")


def start_button_pressed():
    """Placeholder for the physical ESP32 start button."""
    return True


def set_motor_speed(speed):
    """Placeholder for DC motor control through the L298N."""
    print(f"Motor speed: {speed}")


def set_steering_angle(angle):
    """Placeholder for MG996R steering-servo control."""
    print(f"Steering angle: {angle}")


def stop_robot():
    """Stop the drive motor and center the steering."""
    set_motor_speed(0)
    set_steering_angle(SERVO_CENTER_ANGLE)


def calculate_lane_error(sensor_data):
    """
    Calculate lane-position error from the two TCS3200 sensors.

    Positive and negative values represent displacement toward
    opposite sides of the lane.
    """
    left_color = sensor_data["color_left"]
    right_color = sensor_data["color_right"]

    return left_color - right_color


def obstacle_detected(sensor_data):
    """
    Determine whether an obstacle is close enough to require
    an avoidance maneuver.
    """
    return sensor_data["tof_center"] < sensor_data["obstacle_threshold"]


def mission_completed():
    """Placeholder for the final mission-completion condition."""
    return False


def run_lane_following(sensor_data):
    """Calculate and apply the normal lane-following command."""
    lane_error = calculate_lane_error(sensor_data)
    correction = pid.calculate(lane_error)

    steering_angle = SERVO_CENTER_ANGLE + correction

    set_steering_angle(steering_angle)
    set_motor_speed(NORMAL_MOTOR_SPEED)


def run_obstacle_avoidance(sensor_data):
    """
    Placeholder for the final obstacle-avoidance algorithm.

    The left, center, and right ToF readings will be used to
    select and execute a safe path.
    """
    left_distance = sensor_data["tof_left"]
    right_distance = sensor_data["tof_right"]

    if left_distance > right_distance:
        set_steering_angle(SERVO_CENTER_ANGLE - 25)
    else:
        set_steering_angle(SERVO_CENTER_ANGLE + 25)

    set_motor_speed(30)


def main():
    global robot_state

    initialize_system()
    robot_state = RobotState.WAIT_FOR_START

    while robot_state != RobotState.MISSION_COMPLETE:

        if robot_state == RobotState.WAIT_FOR_START:
            stop_robot()

            if start_button_pressed():
                robot_state = RobotState.LANE_FOLLOWING

        elif robot_state == RobotState.LANE_FOLLOWING:
            sensor_data = read_all_sensors()

            if mission_completed():
                robot_state = RobotState.MISSION_COMPLETE

            elif obstacle_detected(sensor_data):
                robot_state = RobotState.OBSTACLE_AVOIDANCE

            else:
                run_lane_following(sensor_data)

        elif robot_state == RobotState.OBSTACLE_AVOIDANCE:
            sensor_data = read_all_sensors()
            run_obstacle_avoidance(sensor_data)

            if not obstacle_detected(sensor_data):
                robot_state = RobotState.LANE_FOLLOWING

    stop_robot()


if __name__ == "__main__":
    main()
