#include "Boss.h"

Boss::Boss(string t, int d, int h, string p, bool tr)
    : Enemy(t, d, h),
      phase(p),
      fightTriggered(tr)

{
    cout << "A terrible boss " << t << " appeared!" << endl;
}