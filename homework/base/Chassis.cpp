#include "Chassis.h"

Chassis::Chassis(string number)
{
	this->number = number;
}
void Chassis::save(string FILE_PATH)
{
	ofstream fw;
    fw.open(FILE_PATH,ios::app);
    fw << "编号: " << this->number << endl;
    fw << "型号: " << this->model << endl;
    fw << "轴距: " << this->wheelbase <<"mm"<< endl;
    fw << "轮距: " << this->track_width <<"mm"<< endl;
    fw << "最小离地间隙: " << this->minimum_ground_clearance <<"mm"<< endl;
    fw << "最小转弯半径: " << this->minimum_turning_radius <<"m"<< endl;
    fw << "驱动模式: " << this->driving_form << endl;
    fw << "最大行程: " << this->maximum_endurance <<"KM"<< endl;
	fw.close();
}
void Chassis::print()
{
    cout << "底盘信息**************" << endl;
    cout << "编号: " << this->number << endl;
    cout << "型号: " << this->model << endl;
    cout << "轴距: " << this->wheelbase << endl;
    cout << "轮距: " << this->track_width << endl;
    cout << "最小离地间隙: " << this->minimum_ground_clearance << endl;
    cout << "最小转弯半径: " << this->minimum_turning_radius << endl;
    cout << "驱动模式: " << this->driving_form << endl;
    cout << "最大行程: " << this->maximum_endurance << endl;
}

void Chassis::setNumber(string number)
{
	this->number = number;
}

void Chassis::setModel(string model)
{
	this->model = model;
}

void Chassis::setWheelBase(int wheelbase)
{
	this->wheelbase = wheelbase;
}

void Chassis::setTrackWidth(int track_width)
{
	this->track_width = track_width;
}

void Chassis::setMinimumGroundClearance(int minimum_ground_clearance)
{
	this->minimum_ground_clearance = minimum_ground_clearance;
}

void Chassis::setMinimumTurningRadius(int minimum_turning_radius)
{
	this->minimum_turning_radius = minimum_ground_clearance;
}

void Chassis::setDrivingForm(string driving_form)
{
	this->driving_form = driving_form;
}

void Chassis::setMaximumEndurance(int maximum_endurance)
{
	this->maximum_endurance = maximum_endurance;
}


