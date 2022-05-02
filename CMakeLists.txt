cmake_minimum_required(VERSION 3.18.4)
project(kiroulpa)

set(CMAKE_CXX_STANDARD 14)

# Linking all the libraries in the lib folder
link_directories(/usr/local/lib)

# Adding executables
add_executable(kiroulpa
        src/main.cpp
        src/ValeursResistances.cpp src/ValeursResistances.h)

# Linking wiringPi to the binary
target_link_libraries(kiroulpa wiringPi)

target_link_libraries(kiroulpa dxl_sbc_cpp)