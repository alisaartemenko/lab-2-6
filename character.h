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
    static int count;

public:

    Character(string n, int h, string r);
    Character(string n = "Traveler");

    Character(const Character& other);
    Character(Character&& other) noexcept;

    ~Character();

    void takeDamage(int damage);
    void showStats() const;
    void updateStats(string name, int health);
    static int getCount() {
        return count;
    }
};

#endif