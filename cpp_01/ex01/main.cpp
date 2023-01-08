#include "Zombie.hpp"

int main(void)
{
    std::string name;
    int N;
    std::cout << "Enter the desired quantity: " << std::endl;
    std::cin >> N;
    Zombie *zombiesArray = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
        zombiesArray[i].announce();
    delete[] zombiesArray;
    return 0;
}