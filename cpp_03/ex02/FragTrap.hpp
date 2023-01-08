#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap( void );
    FragTrap( std::string const & name );
    FragTrap(const FragTrap &other);
    ~FragTrap( void );
    FragTrap& operator=( const FragTrap &other );
    
    void highFivesGuys(void);
};