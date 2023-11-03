#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << this->_name << " was destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
    if (!name.empty())
        this->_name = name;
    else
        this->_name = "Constuctor zombie";
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}