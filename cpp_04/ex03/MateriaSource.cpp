#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materia_source[i] = NULL;
    std::cout << "\033[0;33mMateriaSource default constructor created\033[m" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia_source[i])
			delete this->_materia_source[i];
		if (other._materia_source[i] == NULL)
			this->_materia_source[i] = NULL;
		else
			this->_materia_source[i] = other._materia_source[i]->clone();
	}
    std::cout << "\033[1;36mMateriaSource copy constructor called\033[m" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia_source[i] != NULL) {
			delete this->_materia_source[i];
			this->_materia_source[i] = NULL;
		}
	}
    std::cout << "\033[0;34mMateriaSource destructor called\033[m" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	std::cout << "\033[0;32mMateriaSource assignment operator called\033[m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materia_source[i] != NULL) {
			delete this->_materia_source[i];
			this->_materia_source[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (other._materia_source[i] == NULL)
			this->_materia_source[i] = NULL;
		else
			this->_materia_source[i] = other._materia_source[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	int index_to_equip = - 1;
	for (int i = 0; i < 4; i++) {
		if (_materia_source[i] == NULL)
			if (index_to_equip == -1)
					index_to_equip = i;
	}
	if (index_to_equip == -1) {
		std::cout << "MateriaSource inventory full, equip impossible" << std::endl;
		return ;
	}
	_materia_source[index_to_equip] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materia_source[i] != NULL && _materia_source[i]->getType() == type) {
			std::cout << "Materia " << type << " created" << std::endl;
			return (_materia_source[i]->clone());
		}
	}
	std::cout << "Required type of materia is not found" << std::endl;
	return NULL;
}
