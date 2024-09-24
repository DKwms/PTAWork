#include "Gyroscope.h"

void Gyroscope::print()
{
    cout << "ͺ: " << this->model << endl;
    cout << ": " << this->manufactor << endl;
}

void Gyroscope::save(string FILE_PATH)
{
	ofstream fw;
    fw.open(FILE_PATH,ios::app);
    fw << "ͺ: " << this->model << endl;
    fw << ": " << this->manufactor << endl;
    fw.close();
}

void Gyroscope::setModel(string model)
{
	this->model = model;
}

void Gyroscope::setManufactor(string manufactor)
{
	this->manufactor = manufactor;
}
