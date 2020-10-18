#include <iostream>
#include <map>
#include <string>
using namespace std;

/*享元模式：运用共享技术有效地支持大量细粒度的对象
若应用程序使用了大量的对象，而大量的这些对象造成了很大的存储开销时，或者对象的大多数状态可以
外部状态，如果删除对象的外部状态就可以用相对较少的共享对象取代很多组对象，此时可以考虑使用享元模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/06 14:43:54
*/

class User {
private:
    string _name;
public:
    User(string name) {
        _name = name;
    }
    string getName() {
        return _name;
    }
};

class Website {
public:
    virtual void use(User* user) = 0;
};

class ConcreteWebsite : public Website {
private:
    string _name;
public:
    ConcreteWebsite(string name) {
        _name = name;
    }
    void use(User* user) override {
        cout << "网站类别：" << _name << "  用户：" << user->getName() << endl;
    }
};

class WebsiteFactory {
private:
    map<string, ConcreteWebsite*> imap;
public:
    Website* getWebsite(string website) {
        if (imap.find(website) == imap.end()) {
            imap.insert({website, new ConcreteWebsite(website)});
        }
        return imap[website];
    }
    int getWebsiteCount() {
        return imap.size();
    }
};

int main()
{
    WebsiteFactory* f = new WebsiteFactory();
    Website* w1 = f->getWebsite("博客");
    Website* w2 = f->getWebsite("产品展示");
    Website* w3 = f->getWebsite("百科");
    Website* w4 = f->getWebsite("博客");

    w1->use(new User("阿毛"));
    w2->use(new User("小明"));
    w3->use(new User("小花"));
    w4->use(new User("张无忌"));

    cout << "网站总数：" << f->getWebsiteCount() << endl;
    return 0;
}