#pragma once
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class MultilineLidar//߼״
{
private:
    string model = "RS-Helios-16p";
    int channels = 16;
    int test_scope = 100;
    int power = 8;
public:
    MultilineLidar() {};
    ~MultilineLidar() {}
    void save(string FILE_PATH);
    void print();
    void setModel(string model);
    void setChannels(int channels);
    void setTestScope(int test_scope);
    void setPower(int power);

};
