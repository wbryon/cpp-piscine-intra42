#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WrongCat") {
    std::cout << _type << "\033[0;36m default constructor created\033[m" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ) {
	*this = other;
	std::cout << "WrongCat created with copy constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "\033[0;34mWrongCat destructor called for \033[m" << this->_type << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << getType() << "'s sound: Meow!" << std::endl;
}

WrongCat & WrongCat::operator=( WrongCat const & other ) {
	_type = other.getType();
	return *this;
}