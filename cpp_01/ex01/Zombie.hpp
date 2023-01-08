#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie();
    ~Zombie();
    void        announce( void );
    void        setName( std::string );

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif