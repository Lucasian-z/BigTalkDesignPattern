#include <iostream>
#include <string>
#include <list>
using namespace std;

/* 组合模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/02 15:52:09
*/

// class Component {
// protected:
//     string _name;
// public:
//     Component() {}
//     Component(string name) {
//         _name = name;
//     }
//     virtual void add(Component* c) = 0;
//     virtual void remove(Component* c) = 0;
//     virtual void display(int depth) = 0;
// };

// class Leaf : public Component {
// public:
//     Leaf() {}
//     Leaf(string name) {
//         _name = name;
//     }

//     void add(Component* c) override {
//         cout << "Cannot add to a leaf" << endl;
//     }

//     void remove(Component* c) override {
//         cout << "Cannot remove from a leaf" << endl;
//     }

//     void display(int depth) override {
//         cout << string(depth, '-') << _name << endl;
//     }
// };

// class Composite : public Component {
// private:
//     list<Component*> children;
// public:
//     Composite(string name) {
//         _name = name;
//     }
//     void add(Component* c) override {
//         children.push_back(c);
//     }
//     void remove(Component* c) override {
//         children.remove(c);
//     }
//     void display(int depth) override {
//         cout << string(depth, '-') << _name << endl;
//         for (auto component : children) {
//             component->display(depth + 2);
//         }
//     }
// };

// int main()
// {
//     Composite* root = new Composite("root");
//     root->add(new Leaf("Leaf A"));
//     root->add(new Leaf("Leaf B"));

//     Composite* comp = new Composite("Composite X");
//     comp->add(new Leaf("Leaf XA"));
//     comp->add(new Leaf("Leaf XB"));
//     root->add(comp);
//     root->display(1);
//     return 0;
// }

// 实际例子
class Company {
protected:
    string _name;
public:
    Company() {}
    Company(string name) {
        _name = name;
    }
    virtual void add(Company* c) = 0;
    virtual void remove(Company* c) = 0;
    virtual void display(int depth) = 0;
    virtual void lineOfDuty() = 0;
};

class ConcreteCompany : public Company {
private:
    list<Company*> children;
public:
    ConcreteCompany() {}
    ConcreteCompany(string name) {
        _name = name;
    }
    void add(Company* c) override {
        children.push_back(c);
    }
    void remove(Company* c) override {
        children.remove(c);
    }
    void display(int depth) override {
        cout << string(depth, '-') << _name << endl;
        for (auto comp : children) {
            comp->display(depth + 2);
        }
    }
    void lineOfDuty() {
        for (auto comp : children) {
            comp->lineOfDuty();
        }
    }
};

class HRDepartment : public Company {
public:
    HRDepartment() {}
    HRDepartment(string name) {
        _name = name;
    }
    void add(Company* c) override {}
    void remove(Company* c) override {}
    void display(int depth) override {
        cout << string(depth, '-') << _name << endl;
    }
    void lineOfDuty() override {
        cout << "员工招聘培训" << _name;
    }

};

class FinanceDepartment : public Company {
public:
    FinanceDepartment() {}
    FinanceDepartment(string name) {
        _name = name;
    }
    void add(Company* c) override {}
    void remove(Company* c) override {}
    void display(int depth) override {
        cout << string(depth, '-') << _name << endl;
    }
    void lineOfDuty() override {
        cout << "公司财务收支" << endl;
    }
};

int main()
{
    ConcreteCompany* root = new ConcreteCompany("北京总公司");
    root->add(new FinanceDepartment("总公司财务部"));
    root->add(new HRDepartment("总公司人力资源部"));

    ConcreteCompany* comp = new ConcreteCompany("成都分公司");
    comp->add(new HRDepartment("成都分公司人力资源部"));
    comp->add(new FinanceDepartment("成都分公司财务部"));
    root->add(comp);

    ConcreteCompany* comp1 = new ConcreteCompany("杭州分公司");
    comp1->add(new HRDepartment("杭州分公司人力资源部"));
    comp1->add(new FinanceDepartment("杭州分公司财务部"));
    root->add(comp1);

    root->display(1);
    return 0;
}