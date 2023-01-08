#include "ScavTrap.hpp"

 ScavTrap::ScavTrap() : ClapTrap() {
    _name = "noname";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[0;33mScavTrap default constructor called\033[m" << std::endl;
}
ScavTrap::ScavTrap( std::string const & name ) : ClapTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[0;31mScavTrap constructor called for \033[m" << this->_name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) {
    std::cout << "\033[1;36mScavTrap copy constructor called\033[m" << std::endl;
    *this = other;
}

 ScavTrap::~ ScavTrap() {
    std::cout << "\033[0;34mScavTrap destructor called for \033[m" << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
    if (this != &other)
    {
        this->_name = other._name;
        this->_type = other._type;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << this->_name << " have entered in GateKeeper mode" << std::endl;
}