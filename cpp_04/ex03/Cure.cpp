#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "\033[0;33mCure default constructor created with type \033[m" << _type << std::endl;
}

Cure::Cure(Cure const & other) : AMateria(other) {
	*this = other;
    std::cout << "\033[1;36mCure copy constructor called for \033[m" << _type << std::endl;
}

Cure::~Cure() {
    std::cout << "\033[0;34mCure destructor called for \033[m" << _type << std::endl;
}

Cure & Cure::operator=(Cure const & other) {
	std::cout << "\033[0;32mCure assignment operator called\033[m" << std::endl;
	_type = other.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}