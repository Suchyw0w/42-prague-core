#include "Zombie.hpp"

int main (void)
{
    Zombie zombie0;
    Zombie zombie1("Mariia");
    Zombie zombie2("");
    Zombie *allocatedZombie = newZombie("Eudald");
    std::string sep;

    std::cout <<"Done with constructors.\n";

    zombie0.announce();
    zombie1.announce();
    zombie2.announce();
    allocatedZombie->announce();

    randomChump("Random");
    std::cout <<"Destructors follow.\n";

    delete allocatedZombie;
}