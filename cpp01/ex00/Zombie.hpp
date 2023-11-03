#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif //CPP_ZOMBIE_HPP
