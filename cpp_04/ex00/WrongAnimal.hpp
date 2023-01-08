#pragma once

# include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal( std::string const & type );
	WrongAnimal( WrongAnimal const & other );
	~WrongAnimal();
	WrongAnimal & operator=( WrongAnimal const & other );

	void setType( std::string const type );
	std::string getType(void) const;
	void makeSound() const;

protected:
	std::string _type;
};