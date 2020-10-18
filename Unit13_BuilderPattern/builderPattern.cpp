#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 建造者模式:当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时适用的模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/26 19:52:20
*/

class Product {
private:
    vector<string> parts;
public:
    void add(string part) {
        parts.push_back(part);
    }
    void show() {
        cout << "正在创建产品……" << endl;
        for (string &part : parts) {
            cout << part << " ";
        }
        cout << endl;
    }
};

class Builder {
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* getResult() = 0;
};

class Builder1 : public Builder {
private:
    Product *product = new Product();
public:
    void BuildPartA() override {
        product->add("零件A");
    }
    void BuildPartB() override {
        product->add("零件B");
    }
    Product* getResult() override {
        return product;
    }
};

class Builder2 : public Builder {
private:
    Product *product = new Product();
public:
    void BuildPartA() override {
        product->add("零件C");
    }
    void BuildPartB() override {
        product->add("零件D");
    }
    Product* getResult() override {
        return product;
    }
};

class Director {
public:
    void construct(Builder* builder) {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

int main()
{
    Director *director = new Director();
    Builder *b1 = new Builder1();
    Builder *b2 = new Builder2();
    director->construct(b1);
    Product *p1 = b1->getResult();
    p1->show();

    director->construct(b2);
    Product *p2 = b2->getResult();
    p2->show();
    return 0;
}