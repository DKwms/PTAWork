#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include "Car.h"
using namespace std;

class Student
{
private:
	string stu_number;
	string stu_name;
	Car car;
public:
	Student() {}
	~Student() {}
	Student(string stu_number, string stu_name);
	void print();
	void save();
	void setStuNumber(string stu_number);
	void setStuName(string stu_name);
	void setCar(Car car);
};