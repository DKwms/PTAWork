#pragma once
#include <iostream>
#include <fstream>
#include<string>

#include "pattern/Event.h"
#include "pattern/Subscriber.h"
using namespace std;

class Chassis:public Subscriber
{
private:
    string number;
    string model = "SCOUT MINI";
    int wheelbase = 451;
    int track_width = 490;
    int minimum_ground_clearance = 115;
    int minimum_turning_radius = 0;
    string driving_form = "��������";
    int maximum_endurance = 10;
    int status;
public:
    Chassis() {}
    ~Chassis() {}
    Chassis(string number);
    void save(string FILE_PATH);
    void print();
    void setNumber(string number);
    void setModel(string model);
    void setWheelBase(int wheelbase);
    void setTrackWidth(int track_width);
    void setMinimumGroundClearance(int minimum_ground_clearance);
    void setMinimumTurningRadius(int minimum_turning_radius);
    void setDrivingForm(string driving_form);
    void setMaximumEndurance(int maximum_endurance);
    void setStatus(int sCode);

    void notify(const Event& event);

};
