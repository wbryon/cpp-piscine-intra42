#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_idea[i] = "idea";
    std::cout << "\033[0;33mBrain created with default constructor\033[m" << std::endl;
}

Brain::Brain( std::string const idea) {
	_idea[0] = idea;
    std::cout << "\033[0;36mBrain constructor called: \033[m" << _idea[0] << std::endl;
}

Brain::Brain( Brain const & other ) {
	for (int i = 0; i < 100; i++)
		this->_idea[i] = other._idea[i];
    std::cout << "\033[1;36mBrain created with copy constructor\033[m" << std::endl;
}

Brain::~Brain() {
    std::cout << "\033[0;34mDestructor called for Brain\033[m" << std::endl;
}

void Brain::setIdea( std::string const idea ) {
	static int i = 1;
	if (i == 100)
		return ;
	this->_idea[i] = idea;
	i++;
}

std::string* Brain::getIdea() {
	return this->_idea;
}

Brain & Brain::operator=( Brain const & other ) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_idea[i] = other._idea[i];
	}
	return *this;
}