// demo1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define Year 2021
int main()
{
    std::cout << "火星导弹系统!\n";
    std::cout << std::endl;
    std::cout << "\\1\\加载导弹" << std::endl;
    std::cout << "\\2\\发射导弹" << std::endl;
    std::cout << "\\3\\一切玩完" << std::endl; //c++
    //printf("sd"); //c
    //system("pause"); //暂停
    //system("shutdown");//关机
    //system("cls"); //清除屏幕;
    //system("C:\\Users\\lenovo\\Desktop\\demo.html");
    //system("color 13");
    int  hp{ 12 };
    //printf();
    std::cout << hp << Year << std::endl;
    //编译；预处理；汇编文件；二进制文件，目标文件；

    //打印int类型的最大值；
    std::cout << INT_MAX << std::endl;

    //控制cout的显示精度
    //1、强制以小数的方式显示
    //std::cout << std::_Iosb::fixed;
    //2、控制显示精度
    //std::cout << setprecision(2);
    double doubleNum = 100.0 / 3.0;
    std::cout << doubleNum << endl;
    cout << "dd" << endl;
    //算数运算符与表达式；
    //一元运算符：++、--
    //二元运算符：+ 、-、*、
    //
    int num1 = 5, num2 = 2;
    cout << num1 / num2 << endl;
    cout << num1 % num2 << endl; //取模
    //取模：取某个数字的个位 5%10；
    num1 = num2++ - --num2; // 
    cout << num1 << num2 << endl; //0,2 
    //变量就是一块内存空间； 对象-指针；
    //常用数据类型：int、float、double、char、string；
    //算数运算符；
    //类型转换；
    //++在前，先算加加，在后，表达式运行完在加加；
    //

    //表达式；
    //单等号 = 赋值运算符；复合运算符；
    //关系运算符； > ;< ; >=;<=;
    cout << (12 >= 10) << endl;
    //逻辑运算符； && 、 || 、 ! ; (与或非);
    //位运算符 & 按位与； | 按位或 ； ~ 按位非；
    cout << (2 << 3) << endl;  //左移3位；
    //sizeof 运算符 可以获取数据类型占用内存空间的大小；
    //sizeof(type_name);
    int sd = 12;
    cout << sizeof(sd) << endl;

    //条件结构;
    //if 先判断后执行；
    //switch 后的表达式只能是整型或字符型；
    //case后的表达式的值不能相同；
    //while(...){...}   
    //do while
    //for

    //数组及常用算法；由数据类型相同的一组元素组成；
    //数组：内存中一串延续的空间;;数组长度固定不变，避免数组越界；
    //

    /*
    int num[] = { 12,34,556 };
    cout << num[2] << endl;
    //datattype arrayName[size];

    //计算数组的长度
    int  nums[] = { 2,3,54,5,6,7 };
    int numsLen = sizeof(nums) / sizeof(int);
    cout << numsLen << endl;

    int newnums[] = {2,53,77,33,3};
    int temp;
    //外层循环控制比较的轮数；
    //内层循环控制每轮的比较和交换
    for (int i = 0; i < 5-1; i++) {
        for (int j = 0; j < 5-i-1; j++) {
            if (newnums[j] < newnums[j + 1]) {
            //交换
                temp = newnums[j];
                newnums[j] = newnums[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    cout << newnums[0] << endl;

    //选择排序；
    int min = newnums[0];
    int minIndex = 0;
    for (int i = 0; i < 5; i++) {
        min = nums[i];
        minIndex = i;
        for (int j = 0; j < 5 ; j++) {
            if (newnums[j] < min) {
                min = newnums[j];
                minIndex = j;
            }
        }
        if (minIndex > i) {
            temp = newnums[minIndex];
            nums[minIndex] = nums[i];
            nums[i]= temp;
        }
    }

    //逆序
    for (int i = 0; i < 5/2; i++) {
        temp = newnums[i];
        newnums[i] = newnums[5 - i - 1];
        newnums[5 - i - 1] = temp;
    }
    */
    //指针是一个值为内存地址的变量（或数据对象）；
    //
    //数据类型*指针变量名；
    int nu = 2;
    int* ptr_num;
    ptr_num = &nu;
    cout << ptr_num << endl;
    cout << *ptr_num << endl;


}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
