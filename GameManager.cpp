#include "GameManager.h"
#include "Character.h"
#include "Enemy.h"
#include "Boss.h"
#include <fstream>
#include <iostream>

bool GameManager::checkAdminPassword(const string& pass) {
    return pass == ADMIN_PASS;
}

void GameManager::logAction(string action) {
    history.push_back(action);
    ofstream log(LOG_FILE, ios::app);
    if (log.is_open()) {
        log << action << endl;
    }
}

void GameManager::addCharacter(string name, int hp, string rank) {
    entities.push_back(make_shared<Character>(name, hp, rank));
    logAction("Admin added Character: " + name);
}

void GameManager::addEnemy(string name, int dmg, int hp) {
    entities.push_back(make_shared<Enemy>(name, dmg, hp));
    logAction("Admin added Enemy: " + name);
}

void GameManager::saveData() {
    ofstream out(DATA_FILE);
    if (out.is_open()) {
        for (const auto& e : entities) {
            out << e->serialize() << endl;
        }
        logAction("System: Data saved to file.");
    }
}





