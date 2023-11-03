#include "HumanB.hpp"
#include <iostream>

HumanB::~HumanB(){}

HumanB::HumanB(std::string nm) {
    this->name = nm;
    this->weaponType = NULL;
}

void HumanB::setWeapon(Weapon& wt){
    weaponType = &wt;
}

void HumanB::attack(){
    std::cout << name << " attacks with their " << weaponType->getType() << std::endl;
}