#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class  ScavTrap : virtual public ClapTrap {
public:
    ScavTrap( void );
    ScavTrap(std::string const &name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap( void );
    ScavTrap& operator=( const ScavTrap &other );

    void attack( std::string const & target );
    void guardGate();
};

#endif