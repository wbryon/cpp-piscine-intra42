#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with his " << _weaponType.getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weaponType(weapon) {}

HumanA::~HumanA() {}