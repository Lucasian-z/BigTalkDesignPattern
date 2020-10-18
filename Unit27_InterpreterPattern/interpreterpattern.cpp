#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*解释器模式：如果一种特定类型的问题发生的频率足够高，那么可能就值得将该问题的各个实例表述为一个简单语言
中的句子。这样就可以构建一个解释器，该解释器通过解释这些句子来解决该问题。
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/06 15:11:54
*/

//音乐解释器
class PlayContext {
private:
    string _text;
public:
    string getText() {
        return _text;
    }
    void setText(string text) {
        _text = text;
    }
};

class Expression {
public:
    void interpret(PlayContext* context) {
        if (context->getText().length() == 0) {
            return;
        }else {
            string playKey = context->getText().substr(0, 1);
            context->setText(context->getText().substr(2));
            string tmp = context->getText();
            double playValue = stof(tmp.substr(0, tmp.find_first_of(" ")));
            context->setText(tmp.substr(tmp.find_first_of(" ") + 1));
            excute(playKey, playValue);
        }
    }
    virtual void excute(string key, double value) = 0;
};
map<string, int> imap;

class Note : public Expression {
public:
    void excute(string key, double value) override {
        string note = "";
        switch (imap[key]) {
            case 1: 
                note = "1";
                break;
            case 2:
                note = "2";
                break;
            case 3:
                note = "3";
                break;
            case 4:
                note = "4";
                break;
            case 5:
                note = "5";
                break;
            case 6:
                note = "6";
                break;
            case 7:
                note = "7";
                break;
            default:
                break;
        }
        cout << note << " ";
    }    
};

class Scale : public Expression {
public:
    void excute(string key, double value) {
        string scale = "";
        switch (int(value)) {
            case 1:
                scale = "低音";
                break;
            case 2:
                scale = "中音";
                break;
            case 3:
                scale = "高音";
                break;
            default:
                break;
        }
        cout << scale << " ";
    }
};

int main()
{
    imap[string("C")] = 1;
    imap[string("D")] = 2;
    imap[string("E")] = 3;
    imap[string("F")] = 4;
    imap[string("G")] = 5;
    imap[string("A")] = 6;
    imap[string("B")] = 7;

    PlayContext* context = new PlayContext();
    context->setText("O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 ");
    Expression* expression = nullptr;
    while (context->getText().length() > 0) {
        string str = context->getText().substr(0, 1);
        if (str == "O") {
            expression = new Scale();
        }else {
            expression = new Note();
        }
        expression->interpret(context);
    }
    return 0;
}