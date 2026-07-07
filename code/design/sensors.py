# Sensor Module

def select_multiplexer_channel(channel):
    pass

def read_lidar_left():
    select_multiplexer_channel(0)
    pass

def read_lidar_middle():
    select_multiplexer_channel(1)
    pass

def read_lidar_right():
    select_multiplexer_channel(2)
    pass

def read_color_left():
    pass

def read_color_right():
    pass

def read_imu():
    pass

def read_ir_sensor():
    pass

def read_all_sensors():
    return {
        "lidar_left": read_lidar_left(),
        "lidar_middle": read_lidar_middle(),
        "lidar_right": read_lidar_right(),
        "color_left": read_color_left(),
        "color_right": read_color_right(),
        "imu": read_imu(),
        "ir": read_ir_sensor()
    }
