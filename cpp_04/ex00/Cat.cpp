#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), _name("Noname") {
    std::cout << _type << "\033[0;36m default constructor created\033[m" << std::endl;
}

Cat::Cat( Cat const & other ) {
    *this = other;
    std::cout << "\033[1;36mCat created with copy constructor\033[m" << std::endl;
}

Cat::~Cat() {
    std::cout << "\033[0;34mCat destructor called for \033[m" << this->_type << std::endl;
}

void Cat::makeSound() const {
    std::cout << getType() << " " << this->_name << " is meows: Meow!" << std::endl;
}

Cat & Cat::operator=( Cat const & other ) {
    if (this != & other)
        this->_type = other.getType();
    return *this;
}