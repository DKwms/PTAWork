#include "Battery.h"

void Battery::print()
{
    cout << "参数: " << this->parameter << endl;
    cout << "对外供电: " << this->output_voltage << "V" << endl;
    cout << "充电时长: " << this->charge_time << "H" << endl;
}

void Battery::save()
{
    ofstream fw;
    fw.open("../doc/test.txt", ios::app);
    fw << "参数: " << this->parameter << endl;
    fw << "对外供电: " << this->output_voltage << "V" << endl;
    fw << "充电时长: " << this->charge_time << "H" << endl;
    fw.close();

}

void Battery::setParameter(string parameter)
{
    this->parameter = parameter;
}

void Battery::setOutputVoltage(int output_voltage)
{
    this->output_voltage = output_voltage;
}

void Battery::setChargeTime(int charge_time)
{
    this->charge_time = charge_time;
}