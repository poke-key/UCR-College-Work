#include <iostream>
#include <typeinfo>
#include "Character.h"

class Elf: public Character {
    public:
        Elf(const string &, double, double, string);
        void attack(Character &elf);
        
    private:
        string familyName;
};