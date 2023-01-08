#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void printIdeas(const Cat & example) {
    int  i = 0;
    while (!example.getBrain()->getIdea()[i].empty())
    {
        std::cout << "Printed idea: " << example.getBrain()->getIdea()[i] << std::endl;
        i++;
    }
}

int main()
{
    Animal *animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    Cat cat1 = Cat();
    std::cout << "------- Before deepcopy cat1 idea -------\n";
    printIdeas(cat1);
    Cat cat2(cat1);
    std::cout << "------- After deepcopy cat2 idea -------\n";
    cat2.setNewIdea("I'm cat");
    cat2.setNewIdea("Meeeeooooow");
    printIdeas(cat2);
    std::cout << "------- After deepcopy cat1 idea -------\n";
    printIdeas(cat1);
    std::cout << "------------- Deepcopy test --------------\n";
    Cat basic;
    {
        Cat tmp = basic;
        printIdeas(tmp);
    }
    printIdeas(basic);
    std::cout << "------------- Destructors --------------\n";
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
}