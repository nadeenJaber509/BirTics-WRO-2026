# Sensor Module

def read_tof_left():
    pass

def read_tof_right():
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
        "tof_left": read_tof_left(),
        "tof_right": read_tof_right(),
        "color_left": read_color_left(),
        "color_right": read_color_right(),
        "imu": read_imu(),
        "ir": read_ir_sensor()
    }
