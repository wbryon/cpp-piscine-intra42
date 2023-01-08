#include "Zombie.hpp"

void    randomChump( std::string name )
{
    Zombie  stackZombie;
    stackZombie.setName( name );
    stackZombie.announce();
}