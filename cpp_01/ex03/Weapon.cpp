#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string type)
{
    this->setType(type);
}


void    Weapon::setType( std::string type )
{
    this->_weaponType = type;
}

const std::string& Weapon::getType( void )
{
    return this->_weaponType;
}