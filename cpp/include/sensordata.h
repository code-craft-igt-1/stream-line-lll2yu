#pragma once
#include <string>

namespace StreamingDataSender {

/**
 * @class SensorData
 * @brief Represents a single set of sensor readings.
 *
 * This class encapsulates the data for temperature, pulse rate, and SPO2 levels.
 */
class SensorData {
 public:
    /**
     * @brief Constructor to initialize sensor data.
     * @param temperature Temperature reading.
     * @param pulseRate Pulse rate reading.
     * @param spo2 SPO2 level reading.
     */
    explicit SensorData(float temperature = 0.0f, int pulseRate = 0, int spo2 = 0);

    /**
     * @brief Get the temperature reading.
     * @return Temperature as a float.
     */
    float getTemperature() const;

    /**
     * @brief Get the pulse rate reading.
     * @return Pulse rate as an int.
     */
    int getPulseRate() const;

    /**
     * @brief Get the SPO2 level reading.
     * @return SPO2 level as an int.
     */
    int getSPO2() const;

 private:
    float m_temperature;  ///< Temperature reading
    int m_pulseRate;  ///< Pulse rate reading
    int m_spo2;  ///< SPO2 level reading
};

/**
 * @brief Parses a line of CSV input into a SensorData object.
 * @param line A string containing CSV-formatted sensor data.
 * @return A SensorData object with parsed values.
 */
SensorData parseSensorData(const std::string& line);

}  // namespace StreamingDataSender
