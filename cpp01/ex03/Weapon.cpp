#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string t) {
    if (!t.empty())
        this->type = t;
    else
        this->type = "Boxer";
}

Weapon::~Weapon(){}

void Weapon::setType(std::string newType){
    this->type = newType;
}

const std::string& Weapon::getType(){
    std::string &ref = type;
    return ref;
}