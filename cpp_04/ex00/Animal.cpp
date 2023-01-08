#include "Animal.hpp"

Animal::Animal() : _type("EMPTY") {
    std::cout << "\033[0;33mAnimal default constructor created with type \033[m" << _type << std::endl;
}

Animal::Animal( std::string const & type ) : _type(type) {
    std::cout << "\033[0;31mAnimal constructor created with type \033[m" << _type << std::endl;
}

Animal::Animal( Animal const & other ) {
	*this = other;
    std::cout << "\033[1;36mAnimal copy constructor called for \033[m" << _type << std::endl;
}

Animal::~Animal() {
    std::cout << "\033[0;34mAnimal destructor called for \033[m" << _type << std::endl;
}

std::string Animal::getType( void ) const {
	return _type;
}

void Animal::setType( std::string const type ) {
    _type = type;
}

void Animal::makeSound() const {
	std::cout << getType() << " say something weird!" << std::endl;
}

Animal & Animal::operator=( Animal const & other ) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}