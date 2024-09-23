#include "BinocularCamera.h"

void BinocularCamera::print()
{
	cout << "型号: " << this->model << endl;
	cout << "摄像头: " << this->camera << endl;
	cout << "RGB帧分辨率: " << this->rgb_resolving_power << endl;
	cout << "RGB帧率: " << this->rgb_frame_rate << endl;
	cout << "FOV: " << this->fov << endl;
	cout << "深度帧率: " << this->depth_frame_rate << endl;
}

void BinocularCamera::save()
{
	ofstream fw;
    fw.open("../doc/test.txt",ios::app);
    fw << "型号: " << this->model << endl;
    fw << "摄像头: " << this->camera << endl;
    fw << "RGB帧分辨率: " << this->rgb_resolving_power << endl;
    fw << "RGB帧率: " << this->rgb_frame_rate << endl;
    fw << "FOV: " << this->fov << endl;
    fw << "深度帧率: " << this->depth_frame_rate << endl;
	fw.close();
}

void BinocularCamera::setModel(string model)
{
	this->model = model;
}

void BinocularCamera::setCamera(string camera)
{
	this->camera = camera;
}

void BinocularCamera::setRgbResolvingPower(string rgb_resolving_power)
{
	this->rgb_resolving_power = rgb_resolving_power;
}

void BinocularCamera::setRgbFrameRate(int rgb_frame_rate)
{
	this->rgb_frame_rate = rgb_frame_rate;
}

void BinocularCamera::setFov(int fov)
{
	this->fov = fov;
}

void BinocularCamera::setDepthFrameRate(int depth_frame_rate)
{
	this->depth_frame_rate = depth_frame_rate;
}
