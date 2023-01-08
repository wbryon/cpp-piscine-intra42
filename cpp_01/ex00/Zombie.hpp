#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:

    Zombie(std::string name);
    Zombie();
    ~Zombie();
    void    announce( void );
    void    setName( std::string );

private:

    std::string _name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif