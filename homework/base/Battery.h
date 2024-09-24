#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Battery
{
private:
	string parameter = "24V/15Ah";
	int output_voltage = 24;
	int charge_time = 2;
public:
	Battery() {};
	~Battery() {};
	void print();
	void save(string FILE_PATH);
	void setParameter(string parameter);
	void setOutputVoltage(int output_voltage);
	void setChargeTime(int charge_time);
};
