#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "\033[0;33mIce default constructor created with type \033[m" << _type << std::endl;
}

Ice::Ice(Ice const & other) : AMateria(other) {
	*this = other;
    std::cout << "\033[1;36mIce copy constructor called for \033[m" << _type << std::endl;
}

Ice::~Ice() {
    std::cout << "\033[0;34mIce destructor called for \033[m" << _type << std::endl;
}

Ice & Ice::operator=(Ice const & other) {
	std::cout << "\033[0;32mIce assignment operator called\033[m" << std::endl;
	_type = other.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}