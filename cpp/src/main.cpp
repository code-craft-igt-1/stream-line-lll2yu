#include "../include/sender.h"

int main() {
    StreamingDataSender::Sender sender;
    sender.readDataFromFile("sensor_data.csv");
    sender.sendData();
}
