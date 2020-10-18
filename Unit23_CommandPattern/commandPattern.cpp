#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/04 13:48:20
*/

class Barbecuer {
public:
    void bakeMutton() {
        cout << "烤羊肉串" << endl;
    }
    void bakeChickenWing() {
        cout << "烤鸡翅" << endl;
    }
};

//抽象命令
class Command {
protected:
    Barbecuer* _receiver;
public:
    // Command(Barbecuer* receiver) {
    //     _receiver = receiver;
    // }
    virtual void excuteCommand() = 0;
};

//具体命令
class BakeMuttonCommand : public Command {
public:
    BakeMuttonCommand(Barbecuer* receiver) {
        _receiver = receiver;
    }
    void excuteCommand() override {
        _receiver->bakeMutton();
    }
};

class BakeChickenWingCommand : public Command {
public:
    BakeChickenWingCommand(Barbecuer* receiver) {
        _receiver = receiver;
    }
    void excuteCommand() override {
        _receiver->bakeChickenWing();
    }
};

//服务员
class Waiter {
private:
    list<Command*> orders;
public:
    void setOrder(Command* command) {
        orders.push_back(command);
    }
    void CancelOrder(Command* command) {
        orders.remove(command);
    }
    void notify() {
        for (auto it : orders) {
            it->excuteCommand();
        }
    }
};

int main()
{
    Barbecuer* boy = new Barbecuer();
    Command* cmd1 = new BakeMuttonCommand(boy);
    Command* cmd2 = new BakeChickenWingCommand(boy);
    Waiter* girl = new Waiter();

    girl->setOrder(cmd1);
    girl->setOrder(cmd2);
    girl->notify();
    return 0;
}