#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

//calls the base class constructor
Wizard::Wizard(const string &wizardName, double wizardHealth, double wizardAttackStrength, int wizardRank) : Character(HeroType::WIZARD, wizardName, wizardHealth, wizardAttackStrength) {
    type = HeroType::WIZARD;
    name = wizardName;
    health = wizardHealth;
    attackStrength = wizardAttackStrength;
    rank = wizardRank;
}

void Wizard::attack(Character &opponent) {
    //instead of using an if statement, I used a switch statement instead so that we can test out each individual case in a more organized way. 
    //the dynamic cast is used to cast the opponent to a specific type of Warrior, Elf, or Wizard. 
    switch (opponent.getType()) {
        case WARRIOR :
            {
                Warrior &opp = dynamic_cast<Warrior &>(opponent);
                cout << "Wizard " << name  << " attacks " << opp.getName() << " --- POOF!!" << endl;
                opp.damage(attackStrength);
            }
            break ;
        case WIZARD:
            {
                Wizard &opp = dynamic_cast<Wizard &>(opponent);
                if (rank == opp.rank) {
                    cout << "Wizard " << name << " does not attack Wizard " << opp.getName() << "." << endl;
                    cout << "They are both members of the " << rank << "." << endl;
                }
                else {
                    cout << "Wizard " << name  << " attacks " << opp.getName() << " --- POOF!!" << endl;
                    opp.damage( attackStrength * (static_cast<double>(rank)/static_cast<double>(opp.rank)));
                }
            }
            break ;
        case ELF :
            {
                Elf &opp = dynamic_cast<Elf &>(opponent);
                cout << "Wizard " << name  << " attacks " << opp.getName() << " --- POOF!!" << endl;
                opp.damage(attackStrength);
            }
                
            break ;
        default:
            break ;
    }
}
