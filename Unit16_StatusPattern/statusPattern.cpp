#include <iostream>
#include <string>
using namespace std;

/* 状态模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/29 15:21:11
*/
class Work;

class State {
public:
    virtual void handle(Work* w) = 0;
};

class Work {
private:
    int _hour;
    bool _finished = false;
    State* _current;
public:
    Work() {
        //_current = new MorningState();
    }
    void setHour(int hour) {
        _hour = hour;
    }
    int getHour() {
        return _hour;
    }
    bool getTaskFinished() {
        return _finished;
    }
    void setTaskFinished(bool finished) {
        _finished = finished;
    }
    void setState(State* s) {
        _current = s;
    }
    void handle() {
        _current->handle(this);
    }
};

class NightState : public State {
public:
    void handle(Work* w) override {
        cout << "晚上休息" << endl;
    }
};

class AfterNoonState : public State {
public:
    void handle(Work* w) override {
        if (w->getHour() < 18) {
            cout << "下午工作，状态不错" << endl;
        }else {
            w->setState(new NightState());
            w->handle();
        }
    }
};

class NoonState : public State {
public:
    void handle(Work* w) override {
        if (w->getHour() < 14) {
            cout << "吃饭，午休" << endl;
        }else {
            w->setState(new AfterNoonState());
            w->handle();
        }
    }
};

class MorningState : public State {
public:
    void handle(Work* w) override {
        if (w->getHour() < 12) {
            cout << "上午精神百倍" << endl;
        }else {
            w->setState(new NoonState());
            w->handle();
        }
    }
};


int main()
{
    Work* Project = new Work();
    Project->setState(new MorningState());
    Project->setHour(10);
    Project->handle();
    Project->setHour(14);
    Project->handle();
    Project->setHour(23);
    Project->handle();
    return 0;
}