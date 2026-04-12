
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
public:
    GameManager();
};


#endif //UNTITLED1_GAMEMANAGER_H