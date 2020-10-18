#include <iostream>
#include <map>
#include <string>
using namespace std;

/* 运用简单工厂模式设计一个简易计算器
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/19 17:53:12
*/

class Operation {
private:
    double _numberA = 0;
    double _numberB = 0;
public:
    double getNumberA() {
        return _numberA;
    }
    double getNumberB() {
        return _numberB;
    }
    void setNumberA(double a) {
        _numberA = a;
    }
    void setNumberB(double b) {
        _numberB = b;
    }
    virtual double getResult() = 0;//纯虚函数,派生类必须重写此函数,此处的基类称为抽象类
};

class operationAdd : public Operation {
public:
    double getResult() override {//重写虚函数
        return getNumberA() + getNumberB();
    }
};

class operationSub : public Operation {
public:
    double getResult() override {
        return getNumberA() - getNumberB();
    }
};

class operationMul : public Operation {
public:
    double getResult() override {
        return getNumberA() * getNumberB();
    }
};

class operationDiv : public Operation {
public:
    double getResult() override {
        double a = getNumberA(), b = getNumberB(), res;
        if (b == 0) {
            cout << "除数不能为0" << endl;
            throw -1;//抛出异常
        }
        return a / b;
    }
};

class operationFactory {
private:
    map<string, int> operates{{"+" , 1}, {"-" , 2}, {"*" , 3}, {"/" , 4}};
public:
    Operation* createOperation(string operate) {//此处必须返回类指针,不能返回抽象类
        Operation *oper;
        switch (operates[operate]) {//switch的表达式必须为数字或枚举类型
            case 1 : {
                oper = new operationAdd();
                break;
            }
            case 2 : {
                oper = new operationSub();
                break;
            }
            case 3 : {
                oper = new operationMul();
                break;
            }
            case 4 : {
                oper = new operationDiv();
                break;
            }
            default : {
                break;
            }
        }
        return oper;
    }
};

int main()
{
    Operation *oper = operationFactory().createOperation("+");
    oper->setNumberA(4);
    oper->setNumberB(54564);
    cout << oper->getNumberA() << endl;
    double result = oper->getResult();
    cout << result << endl;
    return 0;
}