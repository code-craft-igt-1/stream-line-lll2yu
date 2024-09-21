#include <gtest/gtest.h>
#include "./sender.h"


/**
 * @brief Tests if Sender correctly reads and sends data from a CSV file.
 */
TEST(SenderTest, ReadAndSendData) {
    StreamingDataSender::Sender sender;
    sender.readDataFromFile("sensor_data.csv");
    testing::internal::CaptureStdout();
    sender.sendData();
    std::string output = testing::internal::GetCapturedStdout();

    // Define expected output based on known values in "sensor_data.csv"
    std::string expectedOutput = "36.5,72,98\n37,75,97\n36.8,70,99\n37.1,68,96\n36.9,74,95\n";
    EXPECT_EQ(output.substr(0, expectedOutput.size()), expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
