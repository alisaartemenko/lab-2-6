#include <iostream>
#include <string>
#include "character.h"
#include "weapon.h"
#include "enemy.h"
#include "Boss.h"
#include "Combatant.h"

using namespace std;

void showFullCombatantInfo(Combatant& unit) {
    cout << ">>> Full information:" << endl;
    unit.showStats();
    unit.shoutBattleCry();
}

int main() {

 /*   Character hero("Aragorn");
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

    cout << "!!! Testing Inheritance Chain !!!" << endl;
    Boss sauron("Sauron", 300, 10000, "Final Phase", true);

    cout << "!!! Testing (Copy/Move/Assignment) !!!" << endl;

    Character a("Warrior_A", 100, "Veteran");
    Character b("Warrior_B", 80, "Rookie");

    cout << "1. Testing Copy Assignment:" << endl;
    a = b;
    a.showStats();

    cout << "2. Testing Move Assignment:" << endl;
    Character c("Warrior_C", 150, "Elite");
    a = std::move(c);
    a.showStats();

    cout << "3. Testing Copy Constructor:" << endl;
    Character d = a;
    d.showStats();

    cout << "--- End of Testing ---" << endl; */

    cout << ">>> Problem (Static Method Binding)" << endl;
    Combatant* newCombatant = new Character();
    newCombatant->takeDamage(100);
    delete newCombatant;

    cout << ">>> Virtual methods" << endl;
    cout << ">>> First: Show Stats"<< endl;
    Combatant* newCharacter = new Character("Victor", 2000, "Warrior");
    newCharacter->showStats();

    cout << ">>> Second: Take Damage"<< endl;
    Combatant* secondCharacter = new Character("Victor", 2000, "Warrior");
    secondCharacter->takeDamage(100);
    secondCharacter->showStats();
    Combatant* enemy = new Enemy("Big Bad Wolf", 200, 2000);
    enemy->takeDamage(500);
    enemy->showStats();

    cout << ">>> Third: Shout Battle Cry" << endl;
    Combatant* hero = new Character("Razor", 3000, "Knight");
    hero->shoutBattleCry();
    Combatant* secondEnemy = new Enemy("The Deathly Claw", 300, 10000);
    secondEnemy->shoutBattleCry();

    cout << ">>> Base class reference" << endl;
    Character mage("Greybeard", 10000, "Mage");
    Enemy dragon("Drawblood", 2000, 100000);

    showFullCombatantInfo(mage);
    showFullCombatantInfo(dragon);

    delete hero;
    delete enemy;
    delete newCharacter;
    delete newCharacter;
    delete secondCharacter;
    delete secondEnemy;


    return 0;
}