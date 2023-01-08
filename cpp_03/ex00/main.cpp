#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Rusty("Rusty");
    ClapTrap Gromozeka("Gromozeka");
    Rusty.attack("garbage container");
    Rusty.takeDamage(5);
    Gromozeka.takeDamage(10);
    Gromozeka.takeDamage(1);
    Rusty.beRepaired(5);
    for (int i = 0; i < 10; i++)
        Gromozeka.attack("brick wall");
    Gromozeka.attack("brick wall");
    Gromozeka.beRepaired(10);
    
    return 0;
}