#include <iostream>
#include <string>
using namespace std;

/* 抽象工厂模式:提供一个创建一系列相关或相互依赖对象j接口，而无需指定它具具体的类
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/29 10:27:25
*/
class User {
private:
    int _id;
    string _name;
public:
    int getId() {
        return _id;
    }
    void set(int id) {
        _id = id;
    }
    string getName() {
        return _name;
    }
    void setName(string name) {
        _name = name;
    }
};

class IUser {
public:
    virtual void insert(User *user) = 0;
    virtual User* getUser(int id) = 0;
};

class SqlserverUser : public IUser {
public:
    void insert(User* user) override {
        cout << "在SQL Server中添加一条记录" << endl;
    }
    User* getUser(int id) override {
        cout << "在SQL Server中得到一条记录" << endl;
        return nullptr;
    }
};

class AccessUser : public IUser {
public:
    void insert(User* user) override {
        cout << "在Access中添加一条记录" << endl;
    }
    User* getUser(int id) override {
        cout << "在Access中得到一条记录" << endl;
        return nullptr;
    }
};

class Department {
private:
    int _id;
    string _depName;
public:
    int getId() {
        return _id;
    }
    void setId(int id) {
        _id = id;
    }
    string getName() {
        return _depName;
    }
    void setName(string depName) {
        _depName = depName;
    }
};

class IDepartment {
public:
    virtual void insert(Department* department) = 0;
    virtual Department* getDepartment(int id) = 0;
};

class SqlServerDepartment : public IDepartment {
public:
    void insert(Department* department) override {
        cout << "在SQL Server中给Department表添加一条记录" << endl;
    }
    Department* getDepartment(int id) {
        cout << "在SQL Server中得到Department表的一条记录" << endl;
        return nullptr;
    }
};

class AccessDepartment : public IDepartment {
public:
    void insert(Department* department) override {
        cout << "在Access中给Department表添加一条记录" << endl;
    }
    Department* getDepartment(int id) {
        cout << "在Access中得到Department表的一条记录" << endl;
        return nullptr;
    }
};

//抽象工厂类
class IFactory {
public:
    virtual IUser* createUser() = 0;
    virtual IDepartment* createDepartment() = 0;
};

class SqlServerFactory : public IFactory {
public:
    IUser* createUser() override {
        return new SqlserverUser();
    }
    IDepartment* createDepartment() override {
        return new SqlServerDepartment();
    }
};

class AccessFacroty : public IFactory {
public:
    IUser* createUser() override {
        return new AccessUser();
    }
    IDepartment* createDepartment() override {
        return new AccessDepartment();
    }
};

int main()
{
    User* user = new User();
    Department* department = new Department();
    IFactory *factory = new AccessFacroty();

    IUser* iuser = factory->createUser();
    iuser->insert(user);
    iuser->getUser(1);

    IDepartment* idep = factory->createDepartment();
    idep->insert(department);
    idep->getDepartment(1);

    return 0;
}