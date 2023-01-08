#include "Zombie.hpp"

int main(void)
{
    Zombie *petya;
    petya = newZombie("Petya");
    petya->announce();
    delete petya;
    randomChump("Vasya");
    return 0;
}