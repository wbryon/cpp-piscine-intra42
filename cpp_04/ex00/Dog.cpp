#include "Dog.hpp"

Dog::Dog( void ) : Animal::Animal("Dog"), _name("Noname") {
    std::cout << _type << "\033[0;36m default constructor created\033[m" << std::endl;
}

Dog::Dog( Dog const & other ) {
    *this = other;
    std::cout << "\033[1;36mDog created with copy constructor\033[m" << std::endl;
}

Dog::~Dog() {
    std::cout << "\033[0;34mDog destructor called for \033[m" << this->_type << std::endl;
}

void Dog::makeSound() const {
    std::cout << getType() << " " << this->_name << " is barking: Woof!" << std::endl;
}

Dog & Dog::operator=( Dog const & other ) {
    if (this != &other)
    {
        this->_type = other.getType();
    }
    return *this;
}