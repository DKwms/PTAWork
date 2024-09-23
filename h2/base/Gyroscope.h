#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Gyroscope
{
private:
    string model = "CH110";
    string manufactor = "NXP";
public:
    Gyroscope() {};
    ~Gyroscope() {};
    void print();
    void save();
    void setModel(string model);
    void setManufactor(string manufactor);
};
