#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string, Weapon&);
    ~HumanA();
    void    attack(void);

private:
    std::string _name;
    Weapon      &_weaponType;
};

#endif