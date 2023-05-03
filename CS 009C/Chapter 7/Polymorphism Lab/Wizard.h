#include <iostream>
#include <typeinfo>
#include "Character.h"

class Wizard: public Character {
    public:
        Wizard(const string &, double, double, int);
        void attack(Character &wizard);
    
    private:
        int rank;
};