#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>

struct SensorData {
    float temperature;
    int pulseRate;
    int spo2;
};

class SensorProcessor {
private:
    std::vector<SensorData> readings;
    int windowSize;

    template <typename T>
    void computeMinMaxAvg(const std::vector<T>& values, T& minVal, T& maxVal, float& avgVal) const;

    template <typename T>
    void printStat(const std::string& label, const T& minVal, const T& maxVal, float avgVal) const;

public:
    explicit SensorProcessor(int window);
    void process(SensorData data);
    SensorData parseCSVLine(const std::string& line) const;  // Moved to public section
};

#include "processor.tpp"  // Template implementation
#endif  // PROCESSOR_H
