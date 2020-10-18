#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 迭代器模式
分离集合对象的遍历行为，抽象出一个迭代器类来负责
这样既不暴露集合的内部结构，又可以让外部代码透明地访问集合内部的数据
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/03 10:52:03
*/
template <typename T>
class ConcreteAggregate;

template <typename T>
class Iterator {
public:
    virtual T& begin() = 0;
    virtual T& end() = 0;
    virtual T& next() = 0;
    virtual bool isDone() = 0;
    virtual T& currentItem() = 0;
};

template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
};

template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    ConcreteAggregate<T>* _aggregate;
    int _cur = 0;
public:
    ConcreteIterator(ConcreteAggregate<T>* aggregate) {
        this->_aggregate = aggregate;
    }
    T& begin() override {
        return (*_aggregate)[0];
    }
    T& end() override {
        return (*_aggregate)[_aggregate->count() - 1];
    }
    T& next() override {
        ++_cur;
        return (*_aggregate)[_cur];
    }
    bool isDone() override {
        return _cur >= _aggregate->count();
    }
    T& currentItem() override {
        return (*_aggregate)[_cur];
    }
};

template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    vector<T> items;
public:
    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(this);
    } 
    int count() {
        return items.size();
    }
    T& operator[](int idx) {
        return items[idx];
    }
    void push(T a) {
        items.push_back(a);
    }
    // void operator=(string str) {
    //     items[idx] = str;
    // }
};

int main()
{
    ConcreteAggregate<string>* persons = new ConcreteAggregate<string>();
    persons->push("小潇");
    persons->push("小明");
    cout << persons->count() << endl;
    Iterator<string> *i = new ConcreteIterator<string>(persons);
    while (!i->isDone()) {
        cout << i->currentItem() << " 请买车票" << endl;
        i->next();
    }
    return 0;
}