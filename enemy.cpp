#include "enemy.h"

Enemy::Enemy(string t, int d, int h) : type(t), damage(d), hp(h) {
    cout << "Enemy type: " << type << " is lurking nearby!" << endl;
}

Enemy::~Enemy () {
    cout << "Enemy " << type << " was deleted." << endl;
}

void Enemy::attackEnemy (int damageDone) {
    hp -= damageDone;
}
