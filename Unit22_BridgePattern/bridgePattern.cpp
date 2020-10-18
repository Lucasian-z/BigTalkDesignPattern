#include <iostream>
#include <string>
using namespace std;

/* 桥接模式将j抽象部分与它的实现部分分离，使它们都可以独立地变化
合成/聚合复用原则
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/04 13:06:46
*/

class HandsetSoft {
public:
    virtual void run() = 0;
};

class HandsetGame : public HandsetSoft {
public:
    void run() override {
        cout << "运行手机游戏" << endl;
    }
};

class HandsetAddressList : public HandsetSoft {
public:
    void run() override {
        cout << "运行手机通讯录" << endl;
    }
};

class HandsetBrand {
protected:
    HandsetSoft* _soft;
public:
    void setHandsetSoft(HandsetSoft* soft) {
        _soft = soft;
    }
    virtual void run() = 0;
};

class HandsetBrandM : public HandsetBrand {
public:
    void run() override {
        _soft->run();
    }
};
class HandsetBrandN : public HandsetBrand {
public:
    void run() override {
        _soft->run();
    }
};

int main()
{
    HandsetBrand* xiaomi = new HandsetBrandN();
    xiaomi->setHandsetSoft(new HandsetGame());
    xiaomi->run();
    xiaomi->setHandsetSoft(new HandsetAddressList());
    xiaomi->run();
    return 0;
}