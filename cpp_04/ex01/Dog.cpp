#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << _type << "\033[0;33m default constructor created\033[m" << std::endl;
	this->_brain = new Brain("I'm a dog, i like to gnaw bones");
}

Dog::Dog( Dog const & other) {
	this->_type = other.getType();
	if (other._brain)
		this->_brain = new Brain(*other._brain);
	else
		this->_brain = 0;
    std::cout << _type << "\033[1;36m created with copy constructor\033[m" << std::endl;
}

Dog::~Dog() {
	if (this->_brain)
		delete this->_brain;
    std::cout << "\033[0;34mDog destructor called for \033[m" << this->_type << std::endl;
}

void Dog::setNewIdea( std::string const idea ) {
	this->_brain->setIdea(idea);
}

Brain* Dog::getBrain() const {
	return this->_brain;
}

void Dog::makeSound() const {
    std::cout << getType() << " is barking: Woof!" << std::endl;
}

Dog& Dog::operator=( Dog const & other ) {
	std::cout << "\033[0;32mAssignment operator called\033[m" << std::endl;
	if (this->_brain)
		delete this->_brain;
	if (this != &other)
	{
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = 0;
		this->_type = other.getType();
	}
	return *this;
}