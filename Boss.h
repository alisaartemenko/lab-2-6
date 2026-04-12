#ifndef UNTITLED1_BOSS_H
#define UNTITLED1_BOSS_H
#include <iostream>
#include <string>
#include "enemy.h"

using namespace std;

class Boss : public Enemy {
private:
    string phase;
    bool fightTriggered = false;
public:
    Boss(string t, int d, int h, string p, bool tr);
    ~Boss();
    string serialize() const override;
};

#endif //UNTITLED1_BOSS_H