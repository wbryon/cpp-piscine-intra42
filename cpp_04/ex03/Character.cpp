#include "Character.hpp"

Character::Character() {
    std::cout << "\033[0;33mCharacter default constructor created with name \033[m" << getName() << std::endl;
	this->_name = "noName";
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(std::string const name) {
	this->_name = name;
    std::cout << "\033[0;31mCharacter constructor created with name \033[m" << _name << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

Character::Character(Character const & other) {
    std::cout << "\033[1;36mCharacter copy constructor called\033[m" << getName() << std::endl;
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

Character::~Character() {
    std::cout << "\033[0;34mCharacter destructor called for \033[m" << getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Check: " << i << std::endl;
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

Character & Character::operator=(Character const & other) {
	std::cout << "\033[0;32mCharacter assignment operator called\033[m" << std::endl;
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || this->_materia[idx] == NULL) {
		std::cout << "No materia in this index" << std::endl;
		return ;
	}
	this->_materia[idx]->use(target);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (m && this->_materia[i] == NULL) {
			this->_materia[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_materia[idx] == NULL) {
		std::cout << "Invalid index, unequip impossible" << std::endl;
		return ;
	}
	this->_materia[idx] = NULL;
	std::cout << "Character inventory is empty" << std::endl;
}