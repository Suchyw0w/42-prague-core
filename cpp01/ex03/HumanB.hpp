#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weaponType;
public:
    HumanB(std::string nm);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& wt);
};

#endif //CPP_HUMANB_HPP
