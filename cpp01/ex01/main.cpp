#include "Zombie.hpp"

int main(void)
{
    int zombieCount;

    zombieCount = 5;
    Zombie *zombies = zombieHorde(zombieCount, "");
    for (int i = 0; i < zombieCount; i++)
        zombies[i].announce();

    delete[] zombies;

    Zombie *newZombies = zombieHorde(zombieCount, "David");
    for (int i = 0; i < zombieCount; i++)
        newZombies[i].announce();

    delete[] newZombies;
}