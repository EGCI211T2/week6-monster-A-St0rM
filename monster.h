#ifndef monster_h
#define monster_h

#include <iostream>
#include <string>
using namespace std;

class monster{
private:
    string name;
    int hp, potion;

public:
    void Attack(monster &); 
    void heal();            

    monster(string = "random", int = 1, int = 1);
    monster(int, int);
    ~monster();

    void display();

    bool operator > (monster &x);
    void operator += (int v);
    void operator += (monster &x);
    void operator --();
};

inline void monster::display(){
    cout << "Name " << name << endl;
    cout << "HP " << hp << endl;
    cout << "Potion " << potion << endl;
}

inline monster::monster(int h, int p){
    name = "SUPER MONSTER";
    hp = (h <= 0) ? 1 : h;          // hp is never 0
    potion = (p <= 0) ? 1 : p;      // same for potion
}

monster::monster(string n, int h, int p){
    name = n;
    hp = (h <= 0) ? 1 : h;          // hp != 0
    potion = (p <= 0) ? 1 : p;
    cout << "Monster " << name << " is here" << endl;
}

bool monster::operator > (monster &x){
    return hp > x.hp;
}

void monster::operator += (int v){
    hp += v;
    if (hp <= 0) hp = 1; 
}

void monster::operator += (monster &x){
    this->hp += x.hp;
    x.hp = 0;
}

void monster::operator --(){
    hp--;
    if (hp < 0) hp = 0;  //decreasing hp
}

monster::~monster(){
    cout << name << " is gone" << endl;
}

#endif