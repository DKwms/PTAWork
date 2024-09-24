
#include "homework/homework2.h"
#include "homework/homework3.h"


/**
 * 发布订阅模式测试
 */
void doHomework3()
{
    homework3 homework3;
    homework3.manaTest();
}

void doHomework2()
{
    homework2 homework2;
    // 学生信息录入操作
    // init();
    // 执行doReadDate 之前必须进行init操作，进行学生车辆的录入
    homework2.doReadDate();
}

int main()
{
    doHomework3();
    return 0;
}
