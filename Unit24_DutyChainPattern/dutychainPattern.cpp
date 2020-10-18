#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*职责链模式: 使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系
将这个对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/05 15:26:55
*/

// class Handler {
// protected:
//     Handler* _successor;
// public:
//     void setSuccessor(Handler* successor) {
//         _successor = successor;
//     }
//     virtual void handleRequest(int request) = 0;
// };

// class ConcreteHandler1 : public Handler {
// public:
//     void handleRequest(int request) {
//         if (request >= 0 && request < 10) {
//             cout << "处理请求" << request << endl;
//         }else if (_successor != nullptr) {
//             _successor->handleRequest(request);
//         }
//     }
// };

// class ConcreteHandler2 : public Handler {
// public:
//     void handleRequest(int request) {
//         if (request >= 10 && request < 20) {
//             cout << "处理请求" << request << endl;
//         }else if (_successor != nullptr) {
//             _successor->handleRequest(request);
//         }
//     }
// };


// class ConcreteHandler3 : public Handler {
// public:
//     void handleRequest(int request) {
//         if (request >= 20 && request < 30) {
//             cout << "处理请求" << request << endl;
//         }else if (_successor != nullptr) {
//             _successor->handleRequest(request);
//         }
//     }
// };

// int main()
// {
//     Handler* h1 = new ConcreteHandler1();
//     Handler* h2 = new ConcreteHandler2();
//     Handler* h3 = new ConcreteHandler3();

//     h1->setSuccessor(h2);
//     h2->setSuccessor(h3);

//     int arr[5] = {5, 4, 20, 19, 2};

//     for (int i = 0; i < 5; ++i) {
//         h1->handleRequest(arr[i]);
//     }
//     return 0;
// }

//具体例子
class Request {
private:
    string _name;
    string _type;
    int _number;
public:
    void setName(string name) {
        _name = name;
    }
    string getName() {
        return _name;
    }
    void setType(string type) {
        _type = type;
    }
    string getType() {
        return _type;
    }
    void setNumber(int number) {
        _number = number;
    }
    int getNumber() {
        return _number;
    }
};
//管理者
class Request;
class Manager {
protected:
    string _name;
    Manager* _superior;
public:
    Manager() {}
    Manager(string name) {
        _name = name;
    }
    void setSuperior(Manager* superior) {
        _superior = superior;
    }
    virtual void requestApplication(Request* request) = 0;
};

//经理
class CommonManager : public Manager {
public:
    CommonManager(string name) {
        _name = name;
    }
    void requestApplication(Request* request) override {
        if (request->getType() == "请假" && request->getNumber() <= 2) {
            cout << _name << ": " << request->getName() << "请假" << request->getNumber() << "天，批准" << endl;
        }else {
            if (_superior != nullptr) {
                _superior->requestApplication(request);
            }
        }
    }
};

//总监
class Majordomo : public Manager {
public:
    Majordomo(string name) {
        _name = name;
    }
    void requestApplication(Request* request) override {
        if (request->getType() == "请假" && request->getNumber() <= 5) {
            cout << _name << ": " << request->getName() << "请假" << request->getNumber() << "天，批准" << endl;
        }else {
            if (_superior != nullptr) {
                _superior->requestApplication(request);
            }
        }
    }
};

//总经理
class GeneralManager : public Manager {
public:
    GeneralManager(string name) {
        _name = name;
    }
    void requestApplication(Request* request) override {
        if (request->getType() == "请假") {
            cout << _name << ": " << request->getName() << "请假" << request->getNumber() << "天，批准" << endl;
        }else if (request->getType() == "加薪" && request->getNumber() <= 500) {
            cout << _name << ": " <<  request->getName() << "加薪" << request->getNumber() << "，批准" << endl;
        }else if (request->getType() == "加薪" && request->getNumber() > 500) {
            cout << _name << ": " << request->getName() << "加薪" << request->getNumber() << "，以后在说" << endl;
        }
    }
};

int main()
{
    CommonManager* commonManager = new CommonManager("经理");
    Majordomo* majorManager = new Majordomo("总监");
    GeneralManager* generalManager = new GeneralManager("总经理");

    commonManager->setSuperior(majorManager);
    majorManager->setSuperior(generalManager);

    Request *request = new Request();
    request->setName("阿毛");
    request->setNumber(2);
    request->setType("请假");
    commonManager->requestApplication(request);

    request->setNumber(5);
    commonManager->requestApplication(request);

    request->setType("加薪");
    request->setNumber(400);
    commonManager->requestApplication(request);

    request->setNumber(600);
    commonManager->requestApplication(request);

    return 0;
}