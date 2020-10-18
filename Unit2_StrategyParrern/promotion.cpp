#include <iostream>
#include <cmath>
using namespace std;

/* 策略模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/21 14:34:25
*/
class CashSuper {
public:
    virtual double acceptCash(double money) = 0;
};

class CashNormal : public CashSuper {
    double acceptCash(double money) override {
        return money;
    }
};

class CashRebate : public CashSuper {
private:
    double _moneyRebate = 1.0;
public:
    CashRebate(double moneyRebate) {
        _moneyRebate *= moneyRebate;
    }
    double acceptCash(double money) override {
        return money * _moneyRebate;
    }
};

class CashReturn : public CashSuper {
private:
    double _moneyCondition = 0.0;
    double _moneyReturn = 0.0;
public:
    CashReturn(double moneyCondition, double moneyReturn) {
        _moneyCondition = moneyCondition;
        _moneyReturn = moneyReturn;
    }
    double acceptCash(double money) override {
        double res = money;
        if (res >= _moneyCondition) {
            res -= floor(money / _moneyCondition) * _moneyReturn;
        }
        return res;
    }
};

class CashContext {
    CashSuper *cs = nullptr;
public:
    CashContext(int type) {
        switch (type) {
            case 1: {
                cs = new CashNormal();
                break;
            }case 2: {
                cs = new CashReturn(300, 100);
                break;
            }case 3: {
                cs = new CashRebate(0.8);
                break;
            }default: {
                break;
            }
        }
    }
    double getResult(double money) {
        return cs->acceptCash(money);
    }
};

int main()
{
    CashContext *cs1 = new CashContext(3);
    double money = cs1->getResult(500);
    printf("result1 = %.2f\n", money);

    CashContext *cs2 = new CashContext(2);
    money = cs2->getResult(500);
    printf("result = %.2f\n", money);

    CashContext *cs3 = new CashContext(1);
    money = cs3->getResult(500);
    printf("result = %.2f\n", money);
    return 0;
}