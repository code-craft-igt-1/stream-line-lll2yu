#ifndef PROCESSOR_TPP
#define PROCESSOR_TPP

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>
void SensorProcessor::computeMinMaxAvg(const std::vector<T>& values, T& minVal, T& maxVal, float& avgVal) const {
    minVal = *std::min_element(values.begin(), values.end());
    maxVal = *std::max_element(values.begin(), values.end());
    avgVal = std::accumulate(values.begin(), values.end(), 0.0f) / values.size();
}

template <typename T>
void SensorProcessor::printStat(const std::string& label, const T& minVal, const T& maxVal, float avgVal) const {
    std::cout << label << ": Max = " << maxVal
              << ", Min = " << minVal
              << ", Avg (last " << windowSize << ") = " << avgVal << std::endl;
}

#endif  // PROCESSOR_TPP
