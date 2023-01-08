#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("noName"), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << "\033[0;33mClapTrap default constructor called\033[m" << std::endl;
}
ClapTrap::ClapTrap( std::string const & name ) : _name(name) ,_hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[0;31mClapTrap constructor called for \033[m" << this->_name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) {
    std::cout << "\033[1;36mClapTrap copy constructor called\033[m" << std::endl;
    *this = other;
    return ;
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
    if (this->_energyPoints > 0)
    {
        std::cout << this->_name << " attack " << target << ", "
        << "causing " << this->_attackDamage << " point of damage!" << std::endl;
        --this->_energyPoints;
    }
    else
        std::cout << this->_name << " not enough energy to attack!" << std::endl;
}

void    ClapTrap::takeDamage( unsigned int amount ) {
    if (this->_hitPoints > 0)
    {
        if (amount < this->_hitPoints)
        {
            this->_hitPoints -= amount;
            std::cout << this->_name << " take "
            << amount << " point of damage" << std::endl;
        }
        else
        {
            this->_hitPoints = 0;
            std::cout << this->_name << " is knocked-out" << std::endl;
        }
    }
    else
        std::cout << this->_name << " is already knocked-out" << std::endl;
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    if (this->_energyPoints > 0)
    {
        --this->_energyPoints;
        this->_hitPoints += amount;
        if (this->_hitPoints > 10)
            std::cout << this->_name << " is repaired, it has " << this->_hitPoints << " hitpoints now";
        std::cout << "ClapTrap " << this->_name << " recovered " << amount << " hitpoints" << std::endl;
    }
    else
        std::cout << this->_name << " doesn't have enough energy to be repaired " << std::endl;
}