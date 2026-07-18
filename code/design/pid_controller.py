# PID Controller


class PIDController:
    """
    High-level PID controller used for steering correction.

    The real implementation will run on the ESP32 firmware.
    """

    def __init__(self, kp, ki, kd):

        self.kp = kp
        self.ki = ki
        self.kd = kd

        self.previous_error = 0.0
        self.integral = 0.0

    def reset(self):
        """
        Reset the controller state.
        """

        self.previous_error = 0.0
        self.integral = 0.0

    def calculate(self, error):

        # Integral term
        self.integral += error

        # Derivative term
        derivative = error - self.previous_error

        # PID output
        output = (
            self.kp * error +
            self.ki * self.integral +
            self.kd * derivative
        )

        self.previous_error = error

        return output
