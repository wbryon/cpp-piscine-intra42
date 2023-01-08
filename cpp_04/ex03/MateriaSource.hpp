#pragma once

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource( MateriaSource const & other );
	virtual ~MateriaSource();
	MateriaSource & operator=( MateriaSource const & other );

	void learnMateria(AMateria* m);
	AMateria* createMateria( std::string const & type );

protected:
	AMateria* _materia_source[4];
};