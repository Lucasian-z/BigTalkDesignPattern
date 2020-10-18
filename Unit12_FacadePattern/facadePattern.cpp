#include <iostream>
#include <string>
using namespace std;

/* 外观模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/26 19:17:46
*/

//回家打开电视，打开空调，打开电脑；离家全部关闭
class Tv {
public:
    void turnOn() {
        cout << "电视已打开" << endl;
    }
    void turnOff() {
        cout << "电视已关闭" << endl;
    }
};
class Air {
public:
    void turnOn() {
        cout << "空调已打开" << endl;
    }
    void turnOff() {
        cout << "空调已关闭" << endl;
    }
};
class Computer {
public:
    void turnOn() {
        cout << "电脑已打开" << endl;
    }
    void turnOff() {
        cout << "电脑已关闭" << endl;
    }
};

class Home {
private:
    Tv *tv;
    Air *air;
    Computer *computer;
public:
    Home() {
        tv = new Tv();
        air = new Air();
        computer = new Computer();
    }
    void Open() {
        tv->turnOn();
        air->turnOn();
        computer->turnOn();
    }
    void Off() {
        tv->turnOff();
        air->turnOff();
        computer->turnOff();
    }
};


int main()
{
    Home *home = new Home();
    home->Open();
    home->Off();
    return 0;
}