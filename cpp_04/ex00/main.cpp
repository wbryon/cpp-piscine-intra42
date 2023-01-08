#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{   
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
    
	std::cout << "type:\t" << j->getType() << " " << std::endl;
    std::cout << "type:\t" << i->getType() << " " << std::endl;
    std::cout << "type:\t" << wrongI->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	wrongI->makeSound();
	wrongMeta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete wrongMeta;
	delete wrongI;
	delete i;
	delete j;

return 0;
}