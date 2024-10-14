def read_sensor_data_from_file(file_path):
    """
    Read sensor(temperature, pulse rate, SPO2) data from a file.

    @param file_path: The path to the file containing sensor data.
    @yield: A tuple of values representing
            temperature(float), pulse rate(int), and SPO2(int).
    """
    with open(file_path, 'r') as file:
        for line in file:
            yield (lambda temperature, pulse_rate, spo2:
                   (float(temperature),
                    int(pulse_rate),
                    int(spo2)))(*line.strip().split(','))
