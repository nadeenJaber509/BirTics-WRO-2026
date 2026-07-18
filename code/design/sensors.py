# Sensor Module
#
# High-level sensor interface for the software design model.
# The executable sensor drivers are implemented in code/esp32/.

from typing import TypedDict


class SensorData(TypedDict):
    tof_left: int
    tof_center: int
    tof_right: int
    color_left: int
    color_right: int
    obstacle_threshold: int


OBSTACLE_THRESHOLD_MM = 100


def initialize_sensors() -> None:
    """
    Represent initialization of the robot sensors.

    In the ESP32 firmware, the three VL6180X sensors are initialized
    separately using their SHUT pins and assigned unique I2C addresses.
    """
    print("Initializing three VL6180X ToF sensors")
    print("Initializing two TCS3200 color sensors")


def read_tof_left() -> int:
    """Return the left VL6180X distance measurement in millimetres."""
    # Placeholder for the real ESP32 sensor driver.
    return 255


def read_tof_center() -> int:
    """Return the center VL6180X distance measurement in millimetres."""
    # Placeholder for the real ESP32 sensor driver.
    return 255


def read_tof_right() -> int:
    """Return the right VL6180X distance measurement in millimetres."""
    # Placeholder for the real ESP32 sensor driver.
    return 255


def read_color_left() -> int:
    """
    Return the processed reading from the left TCS3200 sensor.

    The real firmware will measure the sensor output frequency and
    convert it into a value suitable for lane-position estimation.
    """
    return 0


def read_color_right() -> int:
    """
    Return the processed reading from the right TCS3200 sensor.

    The real firmware will measure the sensor output frequency and
    convert it into a value suitable for lane-position estimation.
    """
    return 0


def read_all_sensors() -> SensorData:
    """Read and return all sensors required by the navigation software."""
    return {
        "tof_left": read_tof_left(),
        "tof_center": read_tof_center(),
        "tof_right": read_tof_right(),
        "color_left": read_color_left(),
        "color_right": read_color_right(),
        "obstacle_threshold": OBSTACLE_THRESHOLD_MM,
    }
