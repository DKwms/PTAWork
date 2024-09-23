cmake_minimum_required(VERSION 3.28)
project(homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework
        h2/base/Tire.h
        h2/base/Tire.cpp
        h2/base/Student.h
        h2/base/Student.cpp
        h2/base/MultilineLidar.h
        h2/base/MultilineLidar.cpp
        h2/base/LiquidCrystalDisplay.cpp
        h2/base/LiquidCrystalDisplay.h
        h2/base/Gyroscope.cpp
        h2/base/Gyroscope.h
        h2/base/Chassis.cpp
        h2/base/Chassis.h
        h2/base/Car.cpp
        h2/base/Car.h
        h2/base/BinocularCamera.cpp
        h2/base/BinocularCamera.h
        h2/base/Battery.cpp
        h2/base/Battery.h
        h2/base/Agx.cpp
        h2/base/Agx.h
        main.cpp
)
