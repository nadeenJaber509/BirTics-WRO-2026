# Lane Following Module

from pid_controller import PIDController


class LaneFollower:

    def __init__(self):
        self.pid = PIDController(
            kp=0.0,
            ki=0.0,
            kd=0.0
        )

    def calculate_error(self, left_distance, right_distance):
        """
        Robot should stay centered between walls.
        """
        return left_distance - right_distance

    def calculate_steering(self, left_distance, right_distance):

        error = self.calculate_error(
            left_distance,
            right_distance
        )

        correction = self.pid.calculate(error)

        return correction

    def follow_lane(self, sensor_data):

        left = sensor_data["lidar_left"]
        right = sensor_data["lidar_right"]

        steering = self.calculate_steering(
            left,
            right
        )

        return steering
