cmake_minimum_required(VERSION 3.28)
project(homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework
        homework/base/Tire.h
        homework/base/Tire.cpp
        homework/base/Student.h
        homework/base/Student.cpp
        homework/base/MultilineLidar.h
        homework/base/MultilineLidar.cpp
        homework/base/LiquidCrystalDisplay.cpp
        homework/base/LiquidCrystalDisplay.h
        homework/base/Gyroscope.cpp
        homework/base/Gyroscope.h
        homework/base/Chassis.cpp
        homework/base/Chassis.h
        homework/base/Car.cpp
        homework/base/Car.h
        homework/base/BinocularCamera.cpp
        homework/base/BinocularCamera.h
        homework/base/Battery.cpp
        homework/base/Battery.h
        homework/base/Agx.cpp
        homework/base/Agx.h
        main.cpp
        homework/homework2.cpp
        homework/homework2.h
        homework/homework3.cpp
        homework/homework3.h
        homework/base/pattern/Publisher.cpp
        homework/base/pattern/Publisher.h
        homework/base/pattern/Subscriber.h
        homework/base/pattern/Event.h
)
