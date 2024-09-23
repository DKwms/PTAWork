#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class BinocularCamera
{
private:
	string model = "RealSense D435i";
	string camera = "D430";
	string rgb_resolving_power = "1920*1080";
	int rgb_frame_rate = 30;
	int fov = 30;
	int depth_frame_rate = 90;
public:
	BinocularCamera() {};
	~BinocularCamera() {};
	void print();
	void save();
	void setModel(string model);
	void setCamera(string camera);
	void setRgbResolvingPower(string rgb_resolving_power);
	void setRgbFrameRate(int rgb_frame_rate);
	void setFov(int fov);
	void setDepthFrameRate(int depth_frame_rate);
};
