#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[0;33mClapTrap default constructor called\033[m" << std::endl;
}
ClapTrap::ClapTrap( std::string const & name ) : _name(name) ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[0;31mClapTrap constructor called for \033[m" << this->_name << std::endl;
    std::cout << "HP " << _hitPoints;
    std::cout << " EP: " << _energyPoints;
    std::cout << " AD: " << _attackDamage << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) {
    std::cout << "\033[1;36mClapTrap copy constructor called\033[m" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "\033[0;34mClapTrap destructor called for \033[m" << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ) {
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void    ClapTrap::attack( std::string const &target ) {
    std::cout << this->_name << " attack " << target << ", "
    << "causing " << this->_attackDamage << " point of damage!" << std::endl;
}

void    ClapTrap::takeDamage( unsigned int amount ) {
    this->_hitPoints -= amount;
    std::cout << this->_name << " take " << amount << " point of damage" << std::endl;
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    this->_hitPoints += amount;
    std::cout << this->_name << " repaired " << amount << " points" << std::endl;
}