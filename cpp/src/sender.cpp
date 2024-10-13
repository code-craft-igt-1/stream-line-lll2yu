#include "../include/sender.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


namespace StreamingDataSender {

void Sender::readDataFromFile(const std::string& csvFileName) {
    std::ifstream csvFile(csvFileName);
    if (!csvFile.is_open()) {
        std::cerr << "Failed to open file: " << csvFileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(csvFile, line)) {
        m_sensordata.push_back(parseSensorData(line));
    }
}

void Sender::sendData() const {
    for (const auto& sensordata : m_sensordata) {
        std::cout << sensordata.getTemperature() << ","
                  << sensordata.getPulseRate() << ","
                  << sensordata.getSPO2() << std::endl;
    }
}

}  // namespace StreamingDataSender
