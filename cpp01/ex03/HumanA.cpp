#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(){}

HumanA::HumanA(std::string nm, Weapon &wt) : weaponType(wt) {
    this->name = nm;
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weaponType.getType() << std::endl;
}