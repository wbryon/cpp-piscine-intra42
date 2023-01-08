#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << _type << "\033[0;33m default constructor created\033[m" << std::endl;
	this->_brain = new Brain("I'm a cat, i like to drink a milk!");
}

Cat::Cat( Cat const & other) {
	this->_type = other.getType();
	if (other._brain)
		this->_brain = new Brain(*other._brain);
	else
		this->_brain = 0;
    std::cout << _type << "\033[1;36m created with copy constructor\033[m" << std::endl;
}

Cat::~Cat() {
	if (this->_brain)
		delete this->_brain;
    std::cout << "\033[0;34mCat destructor called for \033[m" << this->_type << std::endl;
}

void Cat::makeSound() const {
    std::cout << getType() << " is meows: Meow!" << std::endl;
}

void Cat::setNewIdea( std::string const idea ) {
	this->_brain->setIdea(idea);
}

Brain* Cat::getBrain() const {
	return this->_brain;
}

Cat & Cat::operator=( Cat const & other ) {
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