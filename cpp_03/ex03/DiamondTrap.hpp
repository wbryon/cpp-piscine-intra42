#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap( void );
    DiamondTrap( std::string const & name );
    DiamondTrap( const DiamondTrap &other );
    DiamondTrap & operator=( const DiamondTrap &other );
    ~DiamondTrap( void );

    using ScavTrap::attack;
    void whoAmI( void );
private:
    std::string _dName;
};