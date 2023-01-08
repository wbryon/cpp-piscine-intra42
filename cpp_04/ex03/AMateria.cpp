#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "EMPTY";
	std::cout << "\033[0;33mAMateria default constructor created with type \033[m" << this->_type << std::endl;
}

AMateria::AMateria(std::string const & type) {
	this->_type = type;
    std::cout << "\033[0;31mAMateria constructor created with type \033[m" << this->_type << std::endl;
}

AMateria::AMateria(AMateria const & other) {
	this->_type = other.getType();
    std::cout << "\033[1;36mAMateria copy constructor called for \033[m" << this->_type << std::endl;
}

AMateria::~AMateria() {
    std::cout << "\033[0;34mAMateria destructor called for \033[m" << this->_type << std::endl;
	//if ()//
}

AMateria & AMateria::operator=(AMateria const & other) {
	std::cout << "\033[0;32mAMateria assignment operator called\033[m" << std::endl;
	this->_type = other.getType();
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses an " << this->_type << " at " << target.getName() << " *" << std::endl;
}
