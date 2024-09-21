#include "./sensordata.h"
#include <sstream>

namespace StreamingDataSender {

SensorData::SensorData(float temperature, int pulseRate, int spo2)
    : m_temperature(temperature), m_pulseRate(pulseRate), m_spo2(spo2) {}

float SensorData::getTemperature() const {
    return m_temperature;
}

int SensorData::getPulseRate() const {
    return m_pulseRate;
}

int SensorData::getSPO2() const {
    return m_spo2;
}

SensorData parseSensorData(const std::string& line) {
    std::stringstream readingsStream(line);
    float temperature;
    int pulseRate, spo2;
    char delimiter;

    readingsStream >> temperature >> delimiter >> pulseRate >> delimiter >> spo2;
    return SensorData(temperature, pulseRate, spo2);
}

}  // namespace StreamingDataSender
