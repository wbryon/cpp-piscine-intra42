#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
    _name = "noName";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[0;33mFragTrap default constructor called for \033[m" << _name << std::endl;
}
FragTrap::FragTrap(std::string const & name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "\033[0;31mFragTrap constructor called for \033[m" << this->_name << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "\033[0;34mFragTrap destructor called for \033[m" << this->_name << std::endl;
}
void FragTrap::highFivesGuys(void) {
    std::cout << this->_name << " exclaimed: \"High five, guys!\"" << std::endl;
}