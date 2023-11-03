#include "Zombie.hpp"

Zombie::Zombie()
{
    this->_name = "Constuctor zombie";
    std::cout << this->_name << " was created." << std::endl;
}

Zombie::Zombie(std::string name)
{
    if (!name.empty())
        this->_name = name;
    else
        this->_name = "Constructor zombie";
    std::cout << this->_name << " was created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " was destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}