#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weaponType;
public:
    HumanA(std::string nm, Weapon &wt);
    ~HumanA();
    void attack();
};

#endif //CPP_HUMANA_HPP
