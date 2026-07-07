# Main Robot Program

from sensors import read_all_sensors
from pid_controller import PIDController
from state_machine import RobotState


robot_state = RobotState.IDLE_WAIT_START

pid = PIDController(kp=0.0, ki=0.0, kd=0.0)


def initialize_system():
    print("System initialized")


def start_button_pressed():
    # Placeholder until real ESP32 button code is added
    return True


def set_motor_speed(speed):
    # Placeholder until motor driver code is added
    pass


def set_steering_angle(angle):
    # Placeholder until steering actuator code is added
    pass


def stop_robot():
    set_motor_speed(0)


def main():
    global robot_state

    initialize_system()

    while True:
        if robot_state == RobotState.IDLE_WAIT_START:
            if start_button_pressed():
                robot_state = RobotState.LANE_FOLLOW

        elif robot_state == RobotState.LANE_FOLLOW:
            sensor_data = read_all_sensors()

            error = sensor_data["lidar_left"] - sensor_data["lidar_right"]
            correction = pid.calculate(error)

            set_steering_angle(correction)
            set_motor_speed(50)


if __name__ == "__main__":
    main()
