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
    Chassis chassis;//����
    Tire tire;//��̥
    Agx agx;//Agx�׼�
    BinocularCamera binocular_camera;//˫Ŀ����ͷ
    MultilineLidar multiline_lidar;//���߼����״�
    Gyroscope gyroscope;//9��������
    LiquidCrystalDisplay liquid_crystal_display;//Һ����ʾ��
    Battery batterie;//���
    string number;//����С�����
    int be_used = 0;//��ʶ�����ж�С���Ƿ��Ѿ�����
public:
    Car() {}
    ~Car() {}
    Car(string number, Chassis chassis, Agx agx, BinocularCamera binocular_camera,
        MultilineLidar multiline_lidar, Gyroscope gyroscope,
        LiquidCrystalDisplay liquid_crystal_display, Battery batterie, Tire tire);
    void print();
    void setBeUsed();
    int getBeUsed();
    //����С�����
    void setID(string number);
    //��ȡС�����
    string getNumber();
    //ʵ������С����Ϣ�ı����ļ�����
    void save();
};

