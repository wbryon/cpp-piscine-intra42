#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()  {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    _dName = "noName";
    std::cout << "\033[0;33mDiamondTrap default constructor called\033[m" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const & name ) : FragTrap(name), ScavTrap(name)
                                                             {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    ClapTrap::_name = name + "_clap_name";
    _dName = name;
    std::cout << "\033[0;31mDiamondTrap constructor called for \033[m" << _dName << std::endl;
    std::cout << "HP " << _hitPoints;
    std::cout << " EP: " << _energyPoints;
    std::cout << " AD: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) {
    std::cout << "\033[1;36mDiamondTrap copy constructor called\033[m" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "\033[0;34mDiamondTrap destructor called for \033[m" << _dName << std::endl;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap &other ) {
    if (this != &other)
    {
        this->_dName = other._dName;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void DiamondTrap::whoAmI( void ) {
    std::cout << "DiamondTrap name is " << _dName << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}