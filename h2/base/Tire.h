#pragma once
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class Tire
{
private:
	int tire_number = 4;
	string tire_model = "??¡¤???????????";
	int tire_size = 175;
public:
	void setTireNumber(int tire_number);
	void setTireModel(string tire_model);
	void setTireSize(int tire_size);
	void print();
	void save();
};