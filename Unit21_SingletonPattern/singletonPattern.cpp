#include <iostream>
using namespace std;

/* 单例模式: 分为懒汉式和饿汉式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/03 15:54:00
*/

//懒汉式
class Singleton {
private:
    static Singleton* _instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }
        return _instance;
    }
};
Singleton* Singleton::_instance = nullptr;

//饿汉式
class Singleton2 {
private:
    static Singleton2* _instance;
    Singleton2() {}
public:
    static Singleton2* getInstance() {
        return _instance;
    }
};
Singleton2* Singleton2::_instance = new Singleton2;


int main()
{
    // Singleton* s1 = Singleton::getInstance();
    // Singleton* s2 = Singleton::getInstance();
    // if (s1 == s2) {
    //     cout << "两个对象是相同的实例" << endl;
    // }

    Singleton2* s1 = Singleton2::getInstance();
    Singleton2* s2 = Singleton2::getInstance();
    if (s1 == s2) {
        cout << "两个对象是相同的实例" << endl;
    }

    return 0;
}