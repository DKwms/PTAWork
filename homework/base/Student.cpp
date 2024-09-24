#include "Student.h"
Student::Student(string stu_number, string stu_name)
{
	this->stu_number = stu_number;
	this->stu_name = stu_name;
}

void Student::print()
{
	cout << "学号: " << this->stu_number << endl;
	cout << "姓名: " << this->stu_name << endl;
	this->car.print();
}

void Student::save(string FILE_PATH)
{
	ofstream fw;
    fw.open(FILE_PATH,ios::app);
	fw << "--------------------------------------------" << endl;
	fw << "学号: " << this->stu_number << endl;
	fw << "姓名: " << this->stu_name << endl;
	this->car.save(FILE_PATH);
	fw.close();
}

void Student::setStuNumber(string stu_number)
{
	this->stu_number = stu_number;
}

void Student::setStuName(string stu_name)
{
	this->stu_name = stu_name;
}

void Student::setCar(Car car)
{
	this->car = car;
}
