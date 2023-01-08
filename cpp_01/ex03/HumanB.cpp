#include "HumanB.hpp"

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his " << _weaponType->getType() << std::endl;
}

void    HumanB::setName( std::string name )
{
    this->_name = name;
}

HumanB::HumanB( std::string humanB)
{
    this->setName( humanB );
}

HumanB::HumanB() {}

HumanB::~HumanB() {}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->_weaponType = &weapon;
}