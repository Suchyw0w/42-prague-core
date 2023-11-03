#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif //CPP_ZOMBIE_HPP
