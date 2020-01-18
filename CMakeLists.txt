cmake_minimum_required(VERSION 3.5)
project(OpenCVEncoder)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(OpenCVEncoder main.cpp OpenCVWrapper.cpp OpenCVWrapper.h)

target_link_libraries(OpenCVEncoder ${OpenCV_LIBS})