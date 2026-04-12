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

