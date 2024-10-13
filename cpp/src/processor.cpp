#include "../include/processor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

SensorProcessor::SensorProcessor(int window) : windowSize(window) {}

SensorData SensorProcessor::parseCSVLine(const std::string& line) const {
    std::istringstream ss(line);
    SensorData data;
    std::string temp, pulse, spo2;

    if (std::getline(ss, temp, ',') && std::getline(ss, pulse, ',') && std::getline(ss, spo2, ',')) {
        data.temperature = std::stof(temp);
        data.pulseRate = std::stoi(pulse);
        data.spo2 = std::stoi(spo2);
    } else {
        throw std::runtime_error("Error parsing sensor data in CSV format");
    }

    return data;
}

void SensorProcessor::process(SensorData data) {
    readings.push_back(data);
    if (readings.size() > windowSize) readings.erase(readings.begin());

    std::vector<float> temps;
    std::vector<int> pulses, spo2s;
    for (const auto& reading : readings) {
        temps.push_back(reading.temperature);
        pulses.push_back(reading.pulseRate);
        spo2s.push_back(reading.spo2);
    }

    float tempAvg, pulseAvg, spo2Avg;
    float tempMin, tempMax;
    int pulseMin, pulseMax, spo2Min, spo2Max;

    computeMinMaxAvg(temps, tempMin, tempMax, tempAvg);
    computeMinMaxAvg(pulses, pulseMin, pulseMax, pulseAvg);
    computeMinMaxAvg(spo2s, spo2Min, spo2Max, spo2Avg);

    printStat("Temperature", tempMin, tempMax, tempAvg);
    printStat("Pulse Rate", pulseMin, pulseMax, pulseAvg);
    printStat("SPO2", spo2Min, spo2Max, spo2Avg);
}

int main() {
    SensorProcessor processor(5);
    std::string line;

    while (std::getline(std::cin, line)) {
        try {
            SensorData data = processor.parseCSVLine(line);
            processor.process(data);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
