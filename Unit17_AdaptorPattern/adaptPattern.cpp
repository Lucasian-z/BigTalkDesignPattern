#include <iostream>
#include <string>
using namespace std;

/* 适配器模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/30 16:51:45
*/

class Player {
protected:
    string _name;
public:
    Player(){}
    Player(string name) {
        _name = name;
    }
    virtual void attack() = 0;
    virtual void defense() = 0;
};

class Forwards : public Player {
public:
    Forwards(string name) {
        _name = name;
    }
    void attack() override {
        cout << "前锋：" << _name << "进攻" << endl;
    }
    void defense() override {
        cout << "前锋：" << _name << "防守" << endl;
    }
};

class Center : public Player {
public:
    Center(string name) {
        _name = name;
    }
    void attack() override {
        cout << "中锋：" << _name << "进攻" << endl;
    }
    void defense() override {
        cout << "中锋：" << _name << "防守" << endl;
    }
};

class Guards : public Player {
public:
    Guards(string name) {
        _name = name;
    }
    void attack() override {
        cout << "后卫：" << _name << "进攻" << endl;
    }
    void defense() override {
        cout << "后卫：" << _name << "防守" << endl;
    }
};

class ForeignCenter {
private:
    string _name;
public:
    void setName(string name) {
        _name = name;
    }
    string getName() {
        return _name;
    }
    void attack() {
        cout << "外籍中锋：" << _name << "进攻" << endl;
    }
    void defense() {
        cout << "外籍中锋：" << _name << "防守" << endl;
    }
};

class Translator : public Player {
private:
    ForeignCenter *fcenter = new ForeignCenter();
public:
    Translator(string name) {
        fcenter->setName(name);
    }
    void attack() override {
        fcenter->attack();
    }
    void defense() override {
        fcenter->defense();
    }

};

int main()
{
    Player *b = new Forwards("小明");
    b->attack();
    b->defense();
    Player *c = new Center("小花");
    c->attack();
    c->defense();
   
    Player *t = new Translator("姚明");
    t->attack();
    t->defense();

    return 0;
}