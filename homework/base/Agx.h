#pragma once
#include<string>
#include <iostream>
#include <fstream>
using namespace std;
class Agx
{
private:
    string model = "AGX Xavier";
    int ai = 32;
    int cudas = 512;
    int tensor_core = 64;
    int video_storage = 32;
    int storage = 32;
public:
    Agx() {};
    ~Agx() {};
    void print();
    void save(string FILE_PATH);
    void setModel(string model);
    void setAi(int ai);
    void setCudas(int cudas);
    void setVideoStorage(int video_storage);
    void setStorage(int storage);
};
