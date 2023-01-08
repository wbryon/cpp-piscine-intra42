#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string);
    HumanB();
    ~HumanB();
    void    attack(void);
    void    setName( std::string );
    void    setWeapon(Weapon&);

private:
    std::string _name;
    Weapon      *_weaponType;
};

#endif