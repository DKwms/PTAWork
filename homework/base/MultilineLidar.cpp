#include "MultilineLidar.h"

void MultilineLidar::print()
{
    cout << "型号: " << this->model << endl;
    cout << "通道数: " << this->channels << endl;
    cout << "测试范围: " << this->test_scope << "m" << endl;
    cout << "功耗: " << this->power << "w" << endl;
}

void MultilineLidar::save(string FILE_PATH)
{
    ofstream fw;
    fw.open(FILE_PATH,ios::app);
    fw << "型号: " << this->model << endl;
    fw << "通道数: " << this->channels << endl;
    fw << "测试范围: " << this->test_scope <<"m"<< endl;
    fw << "功耗: " << this->power <<"w"<< endl;
    fw.close();
}

void MultilineLidar::setModel(string model)
{
    this->model = model;
}

void MultilineLidar::setChannels(int channels)
{
    this->channels = channels;
}

void MultilineLidar::setTestScope(int test_scope)
{
    this->test_scope = test_scope;
}

void MultilineLidar::setPower(int power)
{
    this->power = power;
}
