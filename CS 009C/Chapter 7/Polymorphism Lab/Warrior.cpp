#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

using namespace std;

//calls the base class constructor
Warrior::Warrior(const string &warriorName, double warriorHealth, double warriorAttackStrength, string warriorAllegience) : Character(HeroType::WARRIOR, warriorName, warriorHealth, warriorAttackStrength) {
    type = HeroType::WARRIOR;
    name = warriorName;
    health = warriorHealth;
    attackStrength = warriorAttackStrength;
    allegience = warriorAllegience;
}
    
void Warrior::attack(Character &opponent) {
    //instead of using an if statement, I used a switch statement instead so that we can test out each individual case in a more organized way. 
    //the dynamic cast is used to cast the opponent to a specific type of Warrior, Elf, or Wizard. 
    switch (opponent.getType()) {
        case WARRIOR:
            {
                Warrior &opp = dynamic_cast<Warrior &>(opponent);
                if (allegience == opp.allegience) {
                    cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
                    cout << "They share an allegiance with " << allegience << "." << endl;
                }
                else {
                    cout << "Warrior " << name  << " attacks " << opp.getName() << " --- SLASH!!" << endl;
                    opp.damage((health / MAX_HEALTH) * attackStrength);
                }
            }
            break ;
        case ELF :
            {
                Elf &opp = dynamic_cast<Elf &>(opponent);
                cout << "Warrior " << name  << " attacks " << opp.getName() << " --- SLASH!!" << endl;
                opp.damage((health / MAX_HEALTH) * attackStrength);
            }
                
            break ;
        case WIZARD :
            {
                Wizard &opp = dynamic_cast<Wizard &>(opponent);
                cout << "Warrior " << name  << " attacks " << opp.getName() << " --- SLASH!!" << endl;
                opp.damage((health / MAX_HEALTH) * attackStrength);
            }
            break ;
        default:
            break ;
    }
}
