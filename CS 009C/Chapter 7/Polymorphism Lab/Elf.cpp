#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

//calls the base class constructor
Elf::Elf(const string &elfName, double elfHealth, double elfAttackStrength, string elfFamilyName) : Character(HeroType::ELF, elfName, elfHealth, elfAttackStrength) {
    type = HeroType::ELF;
    name = elfName;
    health = elfHealth;
    attackStrength = elfAttackStrength;
    familyName = elfFamilyName;
}
void Elf::attack(Character &opponent) {
    //instead of using an if statement, I used a switch statement instead so that we can test out each individual case in a more organized way. 
    //the dynamic cast is used to cast the opponent to a specific type of Warrior, Elf, or Wizard. 
       switch (opponent.getType()) {
        case WARRIOR :
            {
                Warrior &opp = dynamic_cast<Warrior &>(opponent);
                cout << "Elf " << name  << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
                opp.damage((health / MAX_HEALTH) * attackStrength);
            }    
            break ;
        case ELF:
            {
                Elf &opp = dynamic_cast<Elf &>(opponent);
                if ( familyName == opp.familyName) {
                    cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
                    cout << "They are both members of the " << familyName << " family." << endl;
                }
                else {
                    cout << "Elf " << name  << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
                    opp.damage((health / MAX_HEALTH) * attackStrength);
                }
            }
            break ;
        
        case WIZARD :
            {
                Wizard &opp = dynamic_cast<Wizard &>(opponent);
                cout << "Elf " << name  << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
                opp.damage((health / MAX_HEALTH) * attackStrength);
            }
            break ;
        default:
            break ;
    }  
}
