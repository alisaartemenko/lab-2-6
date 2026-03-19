#include "enemy.h"
#include "combatant.h"

Enemy::Enemy(string t, int d, int h) : Combatant(t, h), damage(d) {
    cout << "Enemy type: " << type << " is lurking nearby!" << endl;
}

Enemy::~Enemy () {
    cout << "Enemy " << type << " was deleted (from Enemy class)." << endl;
}

void Enemy::attackEnemy (int damageDone) {
    health -= damageDone;
}

bool Enemy::operator>(const Enemy& other) const {
    return this->health > other.health;
}

Enemy Enemy::operator-() const {
    cout << "Curse applied to " << type << "! Damage halved!" << endl;
    return Enemy(this->type, this->damage / 2, this->health);
}

ostream& operator<<(ostream& os, const Enemy& e) {
    os << "ENEMY STATUS [" << e.type << " | HP: " << e.health << " | DMG: " << e.damage << "]";
    return os;
}

istream& operator>>(istream& is, Enemy& e) {
    cout << "Enter enemy type, damage and hp: ";
    is >> e.type >> e.damage >> e.health;
    return is;
}