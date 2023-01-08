#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->setName(name);
    std::cout << "Zombie class " << this->_name << " was created on the heap" << std::endl;
}

void    Zombie::setName( std::string name )
{
    this->_name = name;    
}

Zombie::Zombie( void )
{
    std::cout << "Zombie class " << _name << " was created on the stack" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie class " << _name << " was killed\n" << std::endl;
}