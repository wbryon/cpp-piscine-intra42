#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << "I'm " << this->_name << std::endl;
}

void    Zombie::setName( std::string name )
{
    this->_name = name;
}

Zombie::Zombie( void )
{
    std::cout << "Instance of Zombie class was created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " was killed" << std::endl;
}