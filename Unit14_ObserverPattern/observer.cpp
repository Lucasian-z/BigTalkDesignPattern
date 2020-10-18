#include <iostream>
#include <string>
#include <list>
using namespace std;

/* 观察者模式:定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象，这个主题对象在状态
发生变化时，会通知所有观察者对象，使它们能够自动更新自己
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/28 12:45:54
*/
class Subject;
class Observer {
protected:
    string _name;
    Subject* _sub;
public:
    Observer() {}
    Observer(string name, Subject* sub) {
        _name = name;
        _sub = sub;
    }
    virtual void Update() = 0;
};
class Subject {//抽象通知者
public:
    virtual void Attach(Observer* observer) = 0;//增加观察者
    virtual void Detach(Observer* observer) = 0;//移除观察者
    virtual void Notify() = 0;//通知
    virtual string get() = 0;
    virtual void set(string action) = 0;
};

class Boss : public Subject {
private:
    list<Observer*> observers;
    string _action;
public:
    void Attach(Observer* observer) override {
        observers.push_back(observer);
    }
    void Detach(Observer* observer) override {
        observers.remove(observer);
    }
    void Notify() override {
        for (auto it : observers) {
            it->Update();
        }
    }
    string get() override {
        return _action;
    }
    void set(string action) override {
        _action = action;
    }
};



class StockObserver : public Observer {
public:
    StockObserver() {}
    StockObserver(string name, Subject* sub) {
        _name = name;
        _sub = sub;
    }
    void Update() override {
        cout << _sub->get() << " " << _name << " 关闭股票行情,继续工作" << endl;
    }
};

class NBAObserver : public Observer {
public:
    NBAObserver() {}
    NBAObserver(string name, Subject* sub) {
        _name = name;
        _sub = sub;
    }
    void Update() override {
        cout << _sub->get() << " " << _name << " 关闭直播,继续工作" << endl;
    }
};

int main()
{
    Boss* boss = new Boss();
    StockObserver *employee1 = new StockObserver("阿毛", boss);
    NBAObserver *employee2 = new NBAObserver("小李", boss);
    boss->Attach(employee1);
    boss->Attach(employee2);
    boss->set("老板回来了");
    boss->Detach(employee2);
    boss->Notify();
    return 0;
}