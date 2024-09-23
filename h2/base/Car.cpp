#include "Car.h"
Car::Car(string number, Chassis chassis, Agx agx, BinocularCamera binocular_camera,
	MultilineLidar multiline_lidar, Gyroscope gyroscope,
	LiquidCrystalDisplay liquid_crystal_display, Battery batterie,Tire tire)
{
	this->number = number;
	this->chassis = chassis;
	this->agx = agx;
	this->binocular_camera = binocular_camera;
	this->multiline_lidar = multiline_lidar;
	this->gyroscope = gyroscope;
	this->liquid_crystal_display = liquid_crystal_display;
	this->batterie = batterie;
	this->tire = tire;
}
void Car::print()
{
	cout <<  "智能小车编号: "  << this->number << endl;
}
void Car::setBeUsed()
{
	this->be_used = 1;
}
int Car::getBeUsed()
{
	return this->be_used;
}
string Car::getNumber()
{
	return this->number;
}
void Car::setID(string number)
{
	this->number = number;
}
void Car::save(string FILE_PATH)
{
	ofstream fw;
    fw.open(FILE_PATH,ios::app);
    fw << "智能小车编号: " << this->number << endl;
    //调用其他部件的save方法
    fw << "底盘信息**************" << endl;
    this->chassis.save(FILE_PATH);
    fw << "轮胎信息**************" << endl;
    this->tire.save(FILE_PATH);
    fw << "AGX套件信息**************" << endl;
    this->agx.save(FILE_PATH);
    fw << "双目摄像头信息 **************" << endl;
    this->binocular_camera.save(FILE_PATH);
    fw << "多线激光雷达信息**************" << endl;
    this->multiline_lidar.save(FILE_PATH);
    fw << "9轴陀螺仪信息**************" << endl;
    this->gyroscope.save(FILE_PATH);
    fw << "液晶显示器信息**************" << endl;
    this->liquid_crystal_display.save(FILE_PATH);
    fw << "电池信息**************" << endl;
    this->batterie.save(FILE_PATH);
    fw << "--------------------------------------------" << endl;
    fw << endl;
    fw.close();
}