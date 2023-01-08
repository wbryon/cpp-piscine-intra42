#pragma once

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
	virtual ~AMateria();
	AMateria & operator=(AMateria const & other);

	std::string const & getType() const;  //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use( ICharacter& target );

protected:
	std::string _type;
};