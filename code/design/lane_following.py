# Lane Following Module

from pid_controller import PIDController


class LaneFollower:
    """
    High-level lane following algorithm.

    The robot estimates its position within the lane using
    two TCS3200 color sensors and computes a steering
    correction using a PID controller.
    """

    def __init__(self):

        self.pid = PIDController(
            kp=0.0,
            ki=0.0,
            kd=0.0
        )

    def calculate_error(self, left_color, right_color):
        """
        Calculate the lane-position error from the two
        color sensor readings.
        """

        return left_color - right_color

    def calculate_steering(self, left_color, right_color):

        error = self.calculate_error(
            left_color,
            right_color
        )

        steering_correction = self.pid.calculate(error)

        return steering_correction

    def follow_lane(self, sensor_data):

        left_color = sensor_data["color_left"]
        right_color = sensor_data["color_right"]

        steering = self.calculate_steering(
            left_color,
            right_color
        )

        return steering
