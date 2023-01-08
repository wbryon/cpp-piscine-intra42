#pragma once

#include <iostream>

class ClapTrap
{
public:
    ClapTrap( void );
    ClapTrap( std::string const & name );
    ClapTrap( const ClapTrap &other );
    ~ClapTrap( void );
    ClapTrap& operator=( const ClapTrap &other );
    
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

protected:
    std::string  _name;
    std::string  _type;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};