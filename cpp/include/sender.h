#pragma once
#include <vector>
#include <string>
#include "./sensordata.h"

namespace StreamingDataSender {

/**
 * @class Sender
 * @brief Manages the sending of sensor data readings.
 *
 * The Sender class reads sensor data from a file or generates it and sends it to the console output.
 */
class Sender {
 public:
    /**
     * @brief Reads sensor data from a CSV file.
     * @param csvFileName The path to the CSV file containing sensor data.
     */
    void readDataFromFile(const std::string& csvFileName);

    /**
     * @brief Sends sensor data to console output.
     */
    void sendData() const;

 private:
    std::vector<SensorData> m_sensordata;  ///< Collection of sensor data readings
};

}  // namespace StreamingDataSender
