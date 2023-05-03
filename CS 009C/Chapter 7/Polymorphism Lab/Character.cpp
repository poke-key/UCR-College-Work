#include <iostream>
#include "Character.h"
using namespace std;

//this is a constructor for the character class that initializes the local variables.
Character::Character(HeroType type, const string &name, double health, double attackStrength) {
    this->type = type;
    this->name = name;
	this->health = health;
    this->attackStrength = attackStrength;
}

HeroType Character::getType() const {
    return type;
}
const string& Character::getName() const {
    return name;
}
int Character::getHealth() const {
    return health;
}
void Character::damage(double d) {
    cout << name << " takes " << d << " damage." << endl;
    health -= d;
}

bool Character::isAlive() const {
    if(health == 0) {
        return false;
    }
    return true;
}
