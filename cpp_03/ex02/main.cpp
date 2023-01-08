#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap Rusty("Rusty");
    Diamond Gromozeka("Gromozeka");
    Rusty.attack("garbage container");
    Gromozeka.attack("wall");
    Rusty.takeDamage(5);
    Gromozeka.takeDamage(10);
    Rusty.beRepaired(10);
    Gromozeka.beRepaired(30);
    for (int i = 0; i < 10; i++)
        Gromozeka.attack("brick wall");
    Gromozeka.attack("brick wall");
    Gromozeka.beRepaired(10);
    Gromozeka.highFivesGuys();
    return 0;
}