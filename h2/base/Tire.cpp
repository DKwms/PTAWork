#include "Tire.h"
void Tire::setTireNumber(int tire_number)
{
	this->tire_number = tire_number;
}
void Tire::setTireModel(string tire_model)
{
	this->tire_model = tire_model;
}

void Tire::setTireSize(int tire_size)
{
	this->tire_size = tire_size;
}
void Tire::print()
{
    cout << "轮胎数量: " << this->tire_number <<"个"<< endl;
    cout << "轮胎型号: " << this->tire_model << endl;
    cout << "轮胎尺寸: " << this->tire_size <<"mm"<< endl;
}
void Tire::save()
{
	ofstream fw;
    fw.open("../doc/test.txt",ios::app);
    fw << "轮胎数量: " << this->tire_number << "个" << endl;
    fw << "轮胎型号: " << this->tire_model << endl;
    fw << "轮胎尺寸: " << this->tire_size << "mm" << endl;
	fw.close();
}
