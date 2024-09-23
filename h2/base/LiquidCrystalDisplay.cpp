#include "LiquidCrystalDisplay.h"

void LiquidCrystalDisplay::print()
{
    cout << "ߴ: " << this->size << endl;
    cout << "ͺ: " << this->size << endl;
}

void LiquidCrystalDisplay::save()
{
	ofstream fw;
    fw.open("../doc/test.txt",ios::app);
    fw << "ߴ: " << this->size << endl;
    fw << "ͺ: " << this->size << endl;
	fw.close();
}

void LiquidCrystalDisplay::setModel(string model)
{
	this->model = model;
}

void LiquidCrystalDisplay::setSize(float size)
{
	this->size = size;
}
