#include <iostream>
#include <typeinfo>
#include "Character.h"

class Warrior : public Character {
    public:
        Warrior();
        Warrior(const string &, double, double, string);
        void attack(Character &opponent);
        
    private: 
        string allegience;
    
};