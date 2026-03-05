#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character {
private:
    string name;
    int health;
    string ranking;

public:

    Character(string n, int h, string r);
    Character(string n = "Traveler");

    ~Character();

    void takeDamage(int damage);
    void showStats();
};

#endif