#pragma once

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(std::string const name);
	Character(Character const & other);
	~Character();
	Character & operator=(Character const & other);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

protected:
	AMateria* _materia[4];
	std::string _name;

};