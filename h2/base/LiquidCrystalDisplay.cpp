#include "LiquidCrystalDisplay.h"

void LiquidCrystalDisplay::print()
{
    cout << "ߴ: " << this->size << endl;
    cout << "ͺ: " << this->size << endl;
}

void LiquidCrystalDisplay::save(string FILE_PATH)
{
	ofstream fw;
    fw.open(FILE_PATH,ios::app);
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
