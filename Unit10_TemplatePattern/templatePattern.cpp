#include <iostream>
#include <string>
using namespace std;

/* 模板方法模式:通过把不变行为搬移到超类，去除子类中的重复代码
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/26 18:49:52
*/

class TestPaper {
public:
    void question1() {
        cout << "你是谁？" << endl;
        cout << "答案：" << answer1() << endl;
    }
    void question2() {
        cout << "你多大？" << endl;
        cout << "答案：" << answer2() << endl;
    }
    void question3() {
        cout << "你喜欢阅读吗？" << endl;
        cout << "答案：" << answer3() << endl;
    }
protected:
    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

class TestPaperA : public TestPaper {
protected:
    string answer1() override {
        return "阿毛";
    }
    string answer2() override {
        return "18";
    }
    string answer3() override {
        return "喜欢";
    }
};

int main()
{
    TestPaper *stuA = new TestPaperA();
    stuA->question1();
    stuA->question2();
    stuA->question3();
    return 0;
}