from data_reader import read_sensor_data_from_file


def send_sensor_data(file_path):
    """
    Send sensor data from a file to the console.

    @param file_path: The path to the CSV file containing sensor data.
    """
    for temperature, pulse_rate, spo2 in read_sensor_data_from_file(file_path):
        print(f"{temperature},{pulse_rate},{spo2}")


if __name__ == "__main__": # pragma: no cover
    send_sensor_data('sensor_data.csv')
