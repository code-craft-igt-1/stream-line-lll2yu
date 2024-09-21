cmake_minimum_required(VERSION 3.14)
project(StreamingSensorDataSender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP true
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp" "test/*.cpp")

add_executable(test-Sender ${SOURCES})
target_link_libraries(test-Sender GTest::gtest_main)

add_custom_command(TARGET test-Sender POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${PROJECT_SOURCE_DIR}/sensor_data.csv $<TARGET_FILE_DIR:test-Sender>)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test-Sender)