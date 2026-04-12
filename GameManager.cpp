#include "GameManager.h"
#include "Character.h"
#include "Enemy.h"
#include "Boss.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

GameManager::GameManager() {
    loadData();
}

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

void GameManager::loadData() {
    try {
        ifstream in(DATA_FILE);
        if (!in.is_open()) throw runtime_error("Data file not found, starting fresh.");

        entities.clear();
        string type, name;
        while (in >> type >> name) {
            if (type == "Character") {
                int hp; string rank; in >> hp >> rank;
                entities.push_back(make_shared<Character>(name, hp, rank));
            } else if (type == "Enemy") {
                int dmg, hp; in >> dmg >> hp;
                entities.push_back(make_shared<Enemy>(name, dmg, hp));
            }
            else if (type == "Boss") {
                int dmg, hp; string phase; bool trig;
                in >> dmg >> hp >> phase >> trig;
                entities.push_back(make_shared<Boss>(name, dmg, hp, phase, trig));
            }
        }
    } catch (const exception& e) {
        cout << "Notice: " << e.what() << endl;
    }
}

void GameManager::showAllEntities() const {
    if (entities.empty()) {
        cout << "The world is currently empty." << endl;
        return;
    }
    for (const auto& e : entities) {
        e->showStats();
    }
}

void GameManager::showHistory() const {
    cout << "\n========== ACTION HISTORY ==========" << endl;
    if (history.empty()) {
        cout << "History is empty." << endl;
    } else {
        for (const auto& log : history) {
            cout << ">> " << log << endl;
        }
    }
    cout << "====================================" << endl;
}

void GameManager::resetAllData() {

    entities.clear();
    history.clear();

    ofstream outEntities(DATA_FILE, ios::trunc);
    ofstream outHistory(LOG_FILE, ios::trunc);

    outEntities.close();
    outHistory.close();

    logAction("System: All data and history have been reset.");
    cout << "All data cleared successfully!" << endl;
}

void GameManager::clearHistory() {
    history.clear();
    ofstream outHistory(LOG_FILE, ios::trunc);
    outHistory.close();
    logAction("System: History cleared.");
}



