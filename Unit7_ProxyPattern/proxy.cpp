#include <iostream>
#include <string>
using namespace std;

/* 代理模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/24 12:03:50
*/

class IGiveGift {
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};

//被追求者类
class Girl {
private:
    string _name;
public:
    Girl() {};
    Girl(string name) {
        _name = name;
    }
    string getName() {
        return _name;
    }
};

//追求者类
class Pursuit : public IGiveGift {
private:
    Girl *_mm;
public:
    Pursuit(Girl *mm) {
        _mm = mm;
    }
    void giveDolls() override {
        cout << _mm->getName() << "送你洋娃娃" << endl;
    }
    void giveFlowers() override {
        cout << _mm->getName() << "送你鲜花" << endl;
    }
    void giveChocolate() override {
        cout << _mm->getName() << "送你巧克力" << endl;
    }
};

//代理类
class Proxy : public IGiveGift {
private:
    Pursuit *gg;
public:
    Proxy(Girl *mm) {
        gg = new Pursuit(mm);
    }
    void giveDolls() override {
        gg->giveDolls();
    }
    void giveFlowers() override {
        gg->giveFlowers();
    }
    void giveChocolate() override {
        gg->giveChocolate();
    }
};

int main()
{
    Girl *maomao = new Girl("阿毛");
    Proxy *z = new Proxy(maomao);
    z->giveDolls();
    z->giveFlowers();
    z->giveChocolate();
    return 0;
}