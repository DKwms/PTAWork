//
// Created by ROG on 2024/9/24.
//

#include "homework2.h"
#define std_byte std_byte_avoid_conflict
#include <windows.h>
#undef std_byte
#include "./base/Chassis.h"
#include "./base/Car.h"
#include "./base/Student.h"
#include "./base/Agx.h"
#include "./base/Tire.h"
#include "./base/Battery.h"
#include "./base/BinocularCamera.h"
#include "./base/Gyroscope.h"
#include "./base/LiquidCrystalDisplay.h"
#include "./base/MultilineLidar.h"
#include "conio.h"
#include <iostream>
#include<string>
using namespace std;

// 当前页
int curPage = 0;
// 总页数 = message.size();
int totalPage = 10;
// 学生信息数据
string message[10];

// 自定义信息文件存储路径
const string FILE_PATH = "D:\\cppProject\\homework\\doc\\home2.txt";

// windows键盘钩子函数
static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{

    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT* p = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
        {
            // n;
             if(p->vkCode==78)
             {
                 curPage--;
                 if(curPage<0) curPage = 0;
                 cout<<message[curPage]<<endl;;
                 return -1;
             }
             //p
             if(p->vkCode==80)
             {
                 curPage++;
                 if(curPage>9) curPage = 9;
                 cout<<curPage<<endl;
                 cout<<message[curPage]<<endl;;
                 return -1;
             }
        }
        else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
        {

        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
/**
 * 前置加载，用于获取数据
 */
void homework2::preReadData()
{
    ifstream fr;
    fr.open(FILE_PATH, ios::in);
    string buf;
    string::size_type idx;
    int i = 0;
    while (getline(fr, buf))
    {
        if (i == 10)
            break;
        message[i]=message[i]+buf+'\n';
        idx = buf.find("充电时长");
        if (idx != string::npos)
        {
            getline(fr, buf);
            message[i] = message[i] + buf;
            i++;
        }
    }
}
/**
 * 加载钩子函数和获取数据
 */
void homework2::doReadDate()
{
    this->preReadData();

    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

    if (hhkLowLevelKybd == NULL)
    {
        std::cerr << "Hook failed!" << std::endl;
        return;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hhkLowLevelKybd);
}
int homework2::init()
{
    std::ofstream fw;
    // 创建文件
    fw.open(FILE_PATH, std::ios::out);

    if (fw.is_open()) {
        std::cout << "文件打开成功" << std::endl;
        fw.close();
    } else {
        std::cerr << "文件错误" << std::endl;
        return 0;
    }

    string chassis_number;
    string car_number;
    Car cars[10];
    Agx agxs[10];
    BinocularCamera binocular_cameras[10];
    MultilineLidar multiline_lidar[10];
    Gyroscope gyroscope[10];
    LiquidCrystalDisplay liquid_crystal_display[10];
    Battery batteries[10];
    Tire tires[10];
    // 初始化
    for (int i = 0; i < 10; i++)
    {
        agxs[i] = Agx();
        binocular_cameras[i] = BinocularCamera();
        multiline_lidar[i] = MultilineLidar();
        gyroscope[i] = Gyroscope();
        liquid_crystal_display[i] = LiquidCrystalDisplay();
        batteries[i] = Battery();
        tires[i] = Tire();
    }

    // 车辆信息录入
    for (int i = 0; i < 10; i++)
    {
        cout << "创建第:" << i+1 << "辆车" << endl;
        cout << "输入智能小车编号(16位数字+字母)" << endl;
        cin >> car_number;
        car_number = "cqusn"+car_number;
        cout << "请输入底盘编号(8位数字+字母)" << endl;
        cin >> chassis_number;
        chassis_number = "dp" + chassis_number;

        Chassis chassis(chassis_number);
        Car car(car_number, chassis, agxs[i], binocular_cameras[i],
                multiline_lidar[i],gyroscope[i], liquid_crystal_display[i], batteries[i],tires[i]);
        cars[i] = car;
    }

    // 学生信息录入
    string stu_number, stu_name;
    Student student;
    for (int i = 1; i <= 10; i++)
    {
        cout << "请输入第: " << i << "位学生的学号及姓名" << endl;
        cin >> stu_number >> stu_name;
        cout << "请为该学生分配小车，目前空闲的小车编号如下:" << endl;
        for (int j = 0; j < 10; j++)
        {
            if (!cars[j].getBeUsed())
                cout <<j+1<<"." <<cars[j].getNumber()<< endl;
        }
        cout << endl;
        cin >> car_number;
        for (int j = 0; j < 10; j++)
        {
            if (cars[j].getNumber() == car_number)
            {
                cars[j].setBeUsed();
                student = Student(stu_number, stu_name);
                student.setCar(cars[j]);
            }
        }
        student.save(FILE_PATH);
    }
    return 0;
}

