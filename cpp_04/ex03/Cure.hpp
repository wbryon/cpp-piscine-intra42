#pragma once

# include "Character.hpp"
# include "MateriaSource.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(Cure const & other);
	~Cure();
	Cure & operator=(Cure const & other);

	AMateria* clone() const;
	void use(ICharacter& target);
};