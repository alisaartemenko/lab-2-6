#include "Boss.h"
#include <iostream>
#include <string>

Boss::Boss(string t, int d, int h, string p, bool tr)
    : Enemy(t, d, h),
      phase(p),
      fightTriggered(tr)

{
    cout << "A terrible boss " << t << " appeared!" << endl;
}

Boss::~Boss() {
    cout << "[2] Destructor Boss (Derived) for: " << name << endl;
}

string Boss::serialize() const {
    return "Boss " + name + " " + to_string(damage) + " " + to_string(health) + " " + phase + " " + (fightTriggered ? "1" : "0");
}
