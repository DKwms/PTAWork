#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class LiquidCrystalDisplay
{
private:
	float size = 11.6;
	string model = "super";
public:
	LiquidCrystalDisplay() {};
	~LiquidCrystalDisplay() {};
	void print();
	void save(string FILE_PATH);
	void setModel(string model);
	void setSize(float size);
};
