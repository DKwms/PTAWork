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

// ��ǰҳ
int curPage = 0;
// ��ҳ�� = message.size();
int totalPage = 10;
// ѧ����Ϣ����
string message[10];

// �Զ�����Ϣ�ļ��洢·��
const string FILE_PATH = "D:\\cppProject\\homework\\doc\\home2.txt";

// windows���̹��Ӻ���
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
 * ǰ�ü��أ����ڻ�ȡ����
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
        idx = buf.find("���ʱ��");
        if (idx != string::npos)
        {
            getline(fr, buf);
            message[i] = message[i] + buf;
            i++;
        }
    }
}
/**
 * ���ع��Ӻ����ͻ�ȡ����
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
    // �����ļ�
    fw.open(FILE_PATH, std::ios::out);

    if (fw.is_open()) {
        std::cout << "�ļ��򿪳ɹ�" << std::endl;
        fw.close();
    } else {
        std::cerr << "�ļ�����" << std::endl;
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
    // ��ʼ��
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

    // ������Ϣ¼��
    for (int i = 0; i < 10; i++)
    {
        cout << "������:" << i+1 << "����" << endl;
        cout << "��������С�����(16λ����+��ĸ)" << endl;
        cin >> car_number;
        car_number = "cqusn"+car_number;
        cout << "��������̱��(8λ����+��ĸ)" << endl;
        cin >> chassis_number;
        chassis_number = "dp" + chassis_number;

        Chassis chassis(chassis_number);
        Car car(car_number, chassis, agxs[i], binocular_cameras[i],
                multiline_lidar[i],gyroscope[i], liquid_crystal_display[i], batteries[i],tires[i]);
        cars[i] = car;
    }

    // ѧ����Ϣ¼��
    string stu_number, stu_name;
    Student student;
    for (int i = 1; i <= 10; i++)
    {
        cout << "�������: " << i << "λѧ����ѧ�ż�����" << endl;
        cin >> stu_number >> stu_name;
        cout << "��Ϊ��ѧ������С����Ŀǰ���е�С���������:" << endl;
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

