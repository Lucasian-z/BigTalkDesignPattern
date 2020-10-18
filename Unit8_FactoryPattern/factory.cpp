#include <iostream>
using namespace std;

/* 工厂方法模式，定义一个创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类
克服了简单工厂违背开放-封闭原则的缺点，又保持了封装对象创建过程的优点
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/25 11:04:59
*/

class Operation {
private:
    double _numA = 0;
    double _numB = 0;
public:
    double getnumA() {
        return _numA;
    }
    double getnumB() {
        return _numB;
    }
    void setnumA(double num) {
        _numA = num;
    }
    void setnumB(double num) {
        _numB = num;
    }
    virtual double getResult() = 0;
};

class OperationAdd : public Operation {
public:
    double getResult() override {
        return getnumA() + getnumB();
    }
};
class OperationSub : public Operation {
public:
    double getResult() override {
        return getnumA() - getnumB();
    }
};
class OperationMul : public Operation {
public:
    double getResult() override {
        return getnumA() * getnumB();
    }
};
class OperationDiv : public Operation {
public:
    double getResult() override {
        if (getnumB() == 0) {
            printf("除数不能为0\n");
            throw -1;
        }
        return getnumA() / getnumB();
    }
};

//工厂接口
class IFactory {
public:
    virtual Operation* createOperation() = 0;
};

class AddFactory : public IFactory {
public:
    Operation* createOperation() override {
        return new OperationAdd();
    }
};
class SubFactory : public IFactory {
public:
    Operation* createOperation() override {
        return new OperationSub();
    }
};
class MulFactory : public IFactory {
public:
    Operation* createOperation() override {
        return new OperationMul();
    }
};
class DivFactory : public IFactory {
public:
    Operation* createOperation() override {
        return new OperationDiv();
    }
};

int main()
{
    IFactory* operFactory = new AddFactory();
    Operation* oper = operFactory->createOperation();
    oper->setnumA(5);
    oper->setnumB(5.5);
    printf("result = %.2f\n", oper->getResult());
    return 0;
}