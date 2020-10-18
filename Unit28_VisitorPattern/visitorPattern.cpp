#include <iostream>
#include <list>
#include <string>
using namespace std;

/* 访问者模式：表示一个作用域某对象结构中的各元素的操作，可以在不改变各元素类的前提定义作用于这些元素的操作
适用于数据结构相对稳定的系统，将处理从数据结构分离出来
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/07 11:14:54
*/
class Man;
class Woman;
class Action {
protected:
    string _type;
public:
    string getType() {
        return _type;
    }
    void setType(string type) {
        _type = type;
    }
    virtual void getManConclusion(Man* concreteElementA) = 0;
    virtual void getWomanConclusion(Woman* concreteElementB) = 0;
};
class Person {
protected:
    string _name;
public:
    string getName() {
        return _name;
    }
    Person() {}
    Person(string name) {
        _name = name;
    }
    virtual void accept(Action* visitor) = 0;
};

class Man : public Person {
public:
    Man(string name) {
        _name = name;
    }
    void accept(Action* visitor) override {
        visitor->getManConclusion(this);
    }
};

class Woman : public Person {
public:
    Woman(string name) {
        _name = name;
    }
    void accept(Action* visitor) override {
        visitor->getWomanConclusion(this);
    }
};

class Success : public Action {
public:
    Success(string type) {
        _type = type;
    }
    void getManConclusion(Man* concreteElementA) override {
        cout << concreteElementA->getName() << this->getType() << "时，背后定有贤妻" << endl;
    }

    void getWomanConclusion(Woman* concreteElementB) override {
        cout << concreteElementB->getName() << this->getType() << "时，背后定有贤夫" << endl;
    }
};

class Fail : public Action {
public:
    Fail(string type) {
        _type = type;
    }
    void getManConclusion(Man* concreteElementA) override {
        cout << concreteElementA->getName() << this->getType() << "时，背后定有坏妻" << endl;
    }

    void getWomanConclusion(Woman* concreteElementB) override {
        cout << concreteElementB->getName() << this->getType() << "时，背后定有坏夫" << endl;
    }
};

class Object {
private:    
    list<Person*> persons;
public:
    void attach(Person* p) {
        persons.push_back(p);
    }
    void detach(Person* p) {
        persons.remove(p);
    }
    void display(Action* visitor) {
        for (Person* p : persons) {
            p->accept(visitor);
        }
    }
};

int main()
{
    Man* m = new Man("小明");
    Woman* w = new Woman("小花");

    Object* ob = new Object();
    ob->attach(w);
    ob->attach(m);
    Success* s = new Success("成功");
    ob->display(s);

    Fail* f = new Fail("失败");
    ob->display(f);
    return 0;
}