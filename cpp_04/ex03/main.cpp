#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << "===================test 1========================\n";
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("cure"));
	tmp = src->createMateria("random");
	me->equip(tmp);
	std::cout << "===================test 2========================\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->unequip(0);
	me->unequip(2);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	// std::cout << "===================test 3========================\n";
	Character a("A");
	Character b("B");
	a.equip(src->createMateria("ice"));
	b = a;
	b.use(0, *bob);
	a.use(0, *bob);
	Character c(a);
	a.equip(src->createMateria("cure"));
	a.equip(src->createMateria("ice"));
	a.equip(src->createMateria("ice"));
	c.use(0, *bob);
	c.use(0, *bob);
	a.use(1, *bob);
	b.use(1, *bob);
	std::cout << "==================destructors=========================\n";
	delete bob;
	delete src;
	delete me;
	return 0;
}