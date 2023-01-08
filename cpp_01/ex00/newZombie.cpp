#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* heapZombie;
    heapZombie = new Zombie(name);
    return heapZombie;
}