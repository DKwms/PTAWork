#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include "Chassis.h"
#include "Agx.h"
#include "Tire.h"
#include "Battery.h"
#include "BinocularCamera.h"
#include "Gyroscope.h"
#include "LiquidCrystalDisplay.h"
#include "MultilineLidar.h"
using namespace std;
class Car
{
private:
    Chassis chassis;//底盘
    Tire tire;//轮胎
    Agx agx;//Agx套件
    BinocularCamera binocular_camera;//双目摄像头
    MultilineLidar multiline_lidar;//多线激光雷达
    Gyroscope gyroscope;//9轴陀螺仪
    LiquidCrystalDisplay liquid_crystal_display;//液晶显示屏
    Battery batterie;//电池
    string number;//智能小车编号
    int be_used = 0;//标识符，判断小车是否已经分配
public:
    Car() {}
    ~Car() {}
    Car(string number, Chassis chassis, Agx agx, BinocularCamera binocular_camera,
        MultilineLidar multiline_lidar, Gyroscope gyroscope,
        LiquidCrystalDisplay liquid_crystal_display, Battery batterie, Tire tire);
    void print();
    void setBeUsed();
    int getBeUsed();
    //设置小车编号
    void setID(string number);
    //获取小车编号
    string getNumber();
    //实现智能小车信息的本地文件保存
    void save();
};

