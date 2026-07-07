# Obstacle Detection Module

OBSTACLE_DISTANCE_THRESHOLD = 250  # mm, to be tuned during testing


def obstacle_detected(sensor_data):
    """
    Detect obstacle using the middle LiDAR sensor.
    """
    middle_distance = sensor_data["lidar_middle"]

    if middle_distance is None:
        return False

    return middle_distance < OBSTACLE_DISTANCE_THRESHOLD


def detect_pillar_color(sensor_data):
    """
    Detect pillar color using left and right color sensors.
    Placeholder values until real TCS34725 readings are added.
    """
    left_color = sensor_data["color_left"]
    right_color = sensor_data["color_right"]

    if left_color == "red" or right_color == "red":
        return "red"

    if left_color == "green" or right_color == "green":
        return "green"

    return "unknown"


def get_avoidance_direction(pillar_color):
    """
    WRO rule:
    Red pillar -> pass from right.
    Green pillar -> pass from left.
    """
    if pillar_color == "red":
        return "right"

    if pillar_color == "green":
        return "left"

    return "unknown"


def analyze_obstacle(sensor_data):
    """
    Full obstacle analysis.
    """
    if not obstacle_detected(sensor_data):
        return {
            "detected": False,
            "color": "none",
            "avoidance_direction": "none"
        }

    pillar_color = detect_pillar_color(sensor_data)
    avoidance_direction = get_avoidance_direction(pillar_color)

    return {
        "detected": True,
        "color": pillar_color,
        "avoidance_direction": avoidance_direction
    }
