#include <iostream>
#include <string>
using namespace std;

/*中介者模式一般用于一组对象以定义良好但是复杂的方式进行通信的场合，以及想定制一个分布在多个类中的行为
而又不想生成太多子类的场合
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/06 13:52:41
*/
// class Colleague;
// class Mediator {
// public:
//     virtual void send(string message, Colleague* colleague) = 0;
// };

// class Colleague {
// protected:
//     Mediator* _mediator;
// public:
//     Colleague() {}
//     Colleague(Mediator* mediator) {
//         _mediator = mediator;
//     }
// };

// class ConcreteColleague1 : public Colleague {
// public:
//     ConcreteColleague1(Mediator* mediator) {
//         _mediator = mediator;
//     }
//     void send(string message) {
//         _mediator->send(message, this);
//     }
//     void notify(string message) {
//         cout << "同事1得到信息:" << message << endl;
//     }
// };

// class ConcreteColleague2 : public Colleague {
// public:
//     ConcreteColleague2(Mediator* mediator) {
//         _mediator = mediator;
//     }
//     void send(string message) {
//         _mediator->send(message, this);
//     }
//     void notify(string message) {
//         cout << "同事2得到信息:" << message << endl;
//     }
// };

// class ConcreteMediator : public Mediator {
// private:
//     ConcreteColleague1* _colleague1;
//     ConcreteColleague2* _colleague2;
// public:
//     void setColleague1(ConcreteColleague1* colleague) {
//         _colleague1 = colleague;
//     }
//     void setColleague2(ConcreteColleague2* colleague) {
//         _colleague2 = colleague;
//     }
//     void send(string message, Colleague* colleague) {
//         if (colleague == _colleague1) {
//             _colleague2->notify(message);
//         }else {
//             _colleague1->notify(message);
//         }
//     }
// };

// int main()
// {
//     ConcreteMediator* m = new ConcreteMediator();

//     ConcreteColleague1* c1 = new ConcreteColleague1(m);
//     ConcreteColleague2* c2 = new ConcreteColleague2(m);

//     m->setColleague1(c1);
//     m->setColleague2(c2);

//     c1->send("一起出去玩吗？");
//     c2->send("不去");
//     return 0;
// }

//具体例子
class Country;
class UnitedNations {
public:
    virtual void declare(string message, Country* country) = 0;
};

class Country {
protected:
    UnitedNations* _unitNations;
public:
    Country() {}
    Country(UnitedNations* unitNations) {
        _unitNations = unitNations;
    }
};

class Country1 : public Country {
public:
    Country1(UnitedNations* unitNations) {
        _unitNations = unitNations;
    }
    void declare(string message) {
        _unitNations->declare(message, this);
    }
    void notify(string message) {
        cout << "美国获得消息：" << message << endl;
    }
};
class Country2 : public Country {
public:
    Country2(UnitedNations* unitNations) {
        _unitNations = unitNations;
    }
    void declare(string message) {
        _unitNations->declare(message, this);
    }
    void notify(string message) {
        cout << "中国获得消息：" << message << endl;
    }
};

class UnitNationsSecurityCouncil : public UnitedNations {
private:
    Country1* _c1;
    Country2* _c2;
public:
    void setC1(Country1* c1) {
        _c1 = c1;
    }
    void setC2(Country2* c2) {
        _c2 = c2;
    }
    void declare(string message, Country* country) {
        if (country == _c1) {
            _c2->notify(message);
        }else {
            _c1->notify(message);
        }
    }
};

int main()
{
    UnitNationsSecurityCouncil* UNSC = new UnitNationsSecurityCouncil();
    Country1* c1 = new Country1(UNSC);
    Country2* c2 = new Country2(UNSC);
    
    UNSC->setC1(c1);
    UNSC->setC2(c2);
    c1->notify("中国你好");
    c2->notify("美国你好");
    return 0;
}