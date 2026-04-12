
#ifndef UNTITLED1_GAMEMANAGER_H
#define UNTITLED1_GAMEMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Combatant.h"

using namespace std;

class GameManager {
private:
    vector<shared_ptr<Combatant>> entities;
    vector<string> history;
    const string ADMIN_PASS = "admin123";
    const string DATA_FILE = "save_data.txt";
    const string LOG_FILE = "history.txt";
public:
    GameManager();

    bool checkAdminPassword(const string& pass);

    void logAction(string action);
};


#endif //UNTITLED1_GAMEMANAGER_H