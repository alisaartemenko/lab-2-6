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
    Enemy dragonEnemy("Deathly Claw", 500, 1000);
    cout << "---" << endl;

    Character clone = hero;
    Character newHero = move(hero);

    cout << "--- Testing 'this' pointer ---" << endl;
    hero.updateStats("King Aragorn", 200);
    hero.showStats();
    cout << "---" << endl;

    Character heroAgain("Willson", 100, "Warrior");
    heroAgain.updateStats("King Willson", 150);
    heroAgain.showStats();
    cout << "---" << endl;

    const Character npc("Old Man", 50, "Villager");
    cout << "--- Testing const object ---" << endl;

    npc.showStats();
    //npc.updateStats("Villain", 10);

    Enemy dragon("Dragon", 100, 500);
    Enemy goblin("Goblin", 20, 80);

    cout << "--- Testing Operators ---" << endl;

    cout << "Original dragon: " << dragon << endl;
    cout << "Original goblin: " << goblin << endl;
    cout << "---" << endl;
    if (dragon > goblin) {
        cout << "Result: Dragon is tougher!" << endl;
    }
    cout << "---" << endl;
    Enemy weakDragon = -dragon;
    cout << "Weakened: " << weakDragon << endl;
    cout << "---" << endl;
    Enemy customEnemy;
    cin >> customEnemy;
    cout << "You created: " << customEnemy << endl;

    return 0;
}