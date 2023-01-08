#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WEIRD") {
    std::cout << "\033[0;33mWrongAnimal default constructor created with type \033[m" << _type << std::endl;
}

WrongAnimal::WrongAnimal( std::string const & type ) : _type(type) {
    std::cout << "\033[0;31mWrongAnimal created with type \033[m" << _type << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) {
	*this = other;
    std::cout << "\033[1;36mWrongAnimal copy constructor called for \033[m" << _type << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "\033[0;34mWrongAnimal destructor called for \033[m" << this->_type << std::endl;
}

std::string WrongAnimal::getType( void ) const {
	return _type;
}

void WrongAnimal::setType( std::string const type ) {
	_type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << getType() << " say something weird!" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & other ) {
	_type = other.getType();
	return *this;
}