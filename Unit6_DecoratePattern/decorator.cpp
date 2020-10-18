#include <iostream>
#include <string>
using namespace std;

/* 装饰模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/22 17:37:52
*/

class Person {
private:
    string _name;
public:
    Person() {}
    Person(string name) {
        _name = name;
    }
    virtual void show() {
        cout << "装扮的" << _name << endl;
    }
};

class Finery : public Person {
public:
    Person *_component;
public:
    void decorate(Person *component) {
        _component = component;
    }
    void show() override {
        if (_component != nullptr)
            _component->show();
    }
};

class Tshirt : public Finery {
public:
    void show() override {
        cout << "T恤" << endl;
        Finery::show();
    }
};

class Trouser : public Finery {
public:
    void show() override {
        cout << "牛仔裤" << endl;
        Finery::show();
    }
};

int main()
{
    Person *p = new Person("阿毛");
    Tshirt *tshirt = new Tshirt();
    Trouser *trouser = new Trouser();
    tshirt->decorate(p);
    trouser->decorate(tshirt);
    trouser->show();
    return 0;
}