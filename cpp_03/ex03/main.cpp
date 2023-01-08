#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap CL4PTP("CL4PTP");
    ScavTrap SC4VTP("SC4VTP");
    FragTrap FR4GTP("FR4GTP");
    DiamondTrap Gromozeka("Gromozeka");
    Gromozeka.takeDamage(10);
    Gromozeka.attack("brick wall");
    Gromozeka.beRepaired(10);
    Gromozeka.guardGate();
    Gromozeka.highFivesGuys();
    Gromozeka.whoAmI();
    return 0;
}