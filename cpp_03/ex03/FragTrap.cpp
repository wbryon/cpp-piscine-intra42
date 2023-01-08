#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
    _name = "noName";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[0;33mFragTrap default constructor called for \033[m" << _name << std::endl;
}
FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[0;31mFragTrap constructor called for \033[m" << _name << std::endl;
    std::cout << "HP " << _hitPoints;
    std::cout << " EP: " << _energyPoints;
    std::cout << " AD: " << _attackDamage << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) {
    std::cout << "\033[1;36mFragTrap copy constructor called\033[m" << std::endl;
    *this = other;
}

FragTrap::~FragTrap() {
    std::cout << "\033[0;34mFragTrap destructor called for \033[m" << _name << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap &other ) {
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

void FragTrap::highFivesGuys(void) {
    std::cout << _name << " exclaimed: \"High five!\"" << std::endl;
}