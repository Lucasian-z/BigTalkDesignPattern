#include <iostream>
#include <string>
using namespace std;

/* 备忘录模式
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/10/01 15:57:24
*/

class Memento {
private:
    int _attack;
    int _defense;
    int _vitality;
public:
    Memento() {}
    Memento(int a, int b, int c) {
        _attack = a;
        _defense = b;
        _vitality = c;
    }
    void setAttack(int attack) {
        _attack = attack;
    }
    void setDefense(int defense) {
        _defense = defense;
    }
    void setVitality(int vitality) {
        _vitality = vitality;
    }
    int getAttack() {
        return _attack;
    }
    int getDefense() {
        return _defense;
    }
    int getVitality() {
        return _vitality;
    }
    
};

class GameRole {
private:
    int _attack;
    int _defense;
    int _vitality;
public:
    void setAttack(int attack) {
        _attack = attack;
    }
    void setDefense(int defense) {
        _defense = defense;
    }
    void setVitality(int vitality) {
        _vitality = vitality;
    }
    int getAttack() {
        return _attack;
    }
    int getDefense() {
        return _defense;
    }
    int getVitality() {
        return _vitality;
    }
    
    void recoveryState(Memento *memento) {
        this->_attack = memento->getAttack();
        this->_defense = memento->getDefense();
        this->_vitality = memento->getVitality();
    }

    Memento* saveState() {
        return new Memento(_attack, _defense, _vitality);
    }

    void getInitState() {
        _attack = 100;
        _defense = 100;
        _vitality = 100;
    }
    void stateDisplay() {
        printf("生命力：%d\n攻击力：%d\n防御力：%d\n", _vitality, _attack, _defense);
    }
    void fightBoss() {
        _attack = _defense = _vitality = 0;
    }
};

class RoleStateCaretaker {
private:
    Memento* _memento;
public:
    void setMemento(Memento* m) {
        _memento = m;
    }
    Memento* getMemento() {
        return _memento;
    }
};

int main()
{
    GameRole* role = new GameRole();
    role->getInitState();
    role->stateDisplay();
    
    role->setAttack(757);
    RoleStateCaretaker* stateAdmin = new RoleStateCaretaker();
    stateAdmin->setMemento(role->saveState());
    role->fightBoss();
    role->stateDisplay();

    role->recoveryState(stateAdmin->getMemento());
    role->stateDisplay();
    return 0;
}