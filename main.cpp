#include <iostream>
#include <string>
#include "character.h"
#include "weapon.h"
#include "enemy.h"
#include "Boss.h"
#include "Combatant.h"
#include "aSpellcaster.h"
#include "magicTrap.h"
#include "GameManager.h"

using namespace std;

void showFullCombatantInfo(Combatant& unit) {
    cout << ">>> Full information:" << endl;
    unit.showStats();
    unit.shoutBattleCry();
}

void adminMenu(GameManager& gm) {
    int choice;
    do {
        cout << "\n--- ADMIN PANEL ---" << endl;
        cout << "1. Add Character\n2. Add Enemy\n3. Show All Entities\n4. Save to File\n5. View Action History\n6.Reset Data\n0. Logout" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string n, r; int h;
            cout << "Name: "; cin >> n;
            cout << "HP: "; cin >> h;
            cout << "Rank: "; cin >> r;
            gm.addCharacter(n, h, r);
        } else if (choice == 2) {
            string n; int d, h;
            cout << "Name: "; cin >> n;
            cout << "DMG: "; cin >> d;
            cout << "HP: "; cin >> h;
            gm.addEnemy(n, d, h);
        } else if (choice == 3) {
            gm.showAllEntities();
        } else if (choice == 4) {
            gm.saveData();
            cout << "Data successfully saved!" << endl;
        } else if (choice == 5) {
            gm.showHistory();
            cout << "History check: Action logged." << endl;
        } else if (choice == 6) {
            char confirm;
            cout << "ARE YOU SURE? This will delete all characters and logs! (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                gm.resetAllData();
            }
        }
    } while (choice != 0);
}

void userMenu(GameManager& gm) {
    int choice;
    do {
        cout << "\n--- PLAYER MENU ---" << endl;
        cout << "1. View World (Entities)\n2. Perform Action (Cast Spell)\n3.Reset DAta\n 0. Logout" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            gm.showAllEntities();
        } else if (choice == 2) {
            cout << "Choosing a random entity to cast a spell..." << endl;
            // Тут можна додати логіку взаємодії
            gm.logAction("User interacted with the world.");
        } else if (choice == 3) {
            char confirm;
            cout << "ARE YOU SURE? This will delete all characters and logs! (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                gm.resetAllData();
            }
        }
    } while (choice != 0);
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

    cout << "--- End of Testing ---" << endl;

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

    cout << ">>> Pure Virtual Function" << endl;

    Combatant* npc[2];
    npc[0] = new Character("Milly", 3000, "Willager");
    npc[1] = new Enemy("The Helluva", 300, 10000);

    for (int i = 0; i < 2; i++) {
        npc[i]->uniqueTrait();
    }
    for (int i = 0; i < 2; i++) {
        delete npc[i];
    }

    cout << ">>> Interface Demonstration" << endl;
    aSpellcaster* casters[2];
    casters[0] = new Character("Ray", 500, "Young Mage");
    casters[1] = new magicTrap();

    for (int i = 0; i < 2; i++) {
        casters[i]->castSpell();
    }

    for (int i = 0; i < 2; i++) {
        delete casters[i];
    }

    delete hero;
    delete enemy;
    delete newCharacter;
    delete newCharacter;
    delete secondCharacter;
    delete secondEnemy;*/

    GameManager gm;

    int role;
    while (true) {
        cout << "\n=== GAME LOGIN ===\n1. Admin\n2. User\n0. Exit\nChoice: ";
        if (!(cin >> role)) break;

        if (role == 1) {
            string pass;
            cout << "Enter Admin Password: ";
            cin >> pass;
            if (gm.checkAdminPassword(pass)) {
                gm.logAction("Admin logged in.");
                adminMenu(gm);
            } else {
                cout << "Access Denied!" << endl;
            }
        } else if (role == 2) {
            gm.logAction("User logged in.");
            userMenu(gm);
        } else if (role == 0) {
            break;
        }
    }

    return 0;
}