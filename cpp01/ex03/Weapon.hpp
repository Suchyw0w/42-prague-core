#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type;
public:
    const std::string& getType();
    void setType(std::string newType);
    Weapon();
    Weapon(std::string newType);
    ~Weapon();
};

#endif //CPP_WEAPON_HPP
