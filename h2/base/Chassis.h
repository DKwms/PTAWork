#pragma once
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class Chassis //µ×ÅÌÀà
{
private:
    string number;//µ×ÅÌ±àºÅ
    string model = "SCOUT MINI";//ĞÍºÅ
    int wheelbase = 451;
    int track_width = 490;
    int minimum_ground_clearance = 115;
    int minimum_turning_radius = 0;
    string driving_form = "ËÄÂÖËÄÇı";
    int maximum_endurance = 10;
public:
    Chassis() {}
    ~Chassis() {}
    Chassis(string number);
    void save();
    void print();
    void setNumber(string number);
    void setModel(string model);
    void setWheelBase(int wheelbase);
    void setTrackWidth(int track_width);
    void setMinimumGroundClearance(int minimum_ground_clearance);
    void setMinimumTurningRadius(int minimum_turning_radius);
    void setDrivingForm(string driving_form);
    void setMaximumEndurance(int maximum_endurance);

};
