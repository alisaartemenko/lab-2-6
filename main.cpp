#include <iostream>
#include <string>
#include "character.h"
#include "weapon.h"
#include "enemy.h"

using namespace std;

int main() {

    Character hero("Aragorn");
    Character defaultHero;
    Character hero2("Silver", 500, "Beginner");
    cout << "---" << endl;

    cout << "Current heroes: " << Character::getCount() << endl;
    cout << "---" << endl;

    Weapon stick("Stick", 10, 5, false);
    Weapon sword("FireArm", 100);
    cout << "---" << endl;

    Enemy defaultEnemy;
    Enemy dragon("Deathly Claw", 500, 1000);
    cout << "---" << endl;

    Character clone = hero;
    Character newHero = move(hero);

    cout << "--- Testing 'this' pointer ---" << endl;
    hero.updateStats("King Aragorn", 200);
    hero.showStats();
    cout << "---" << endl;

    return 0;
}