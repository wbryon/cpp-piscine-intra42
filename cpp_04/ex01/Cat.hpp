#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat( void );
	Cat( Cat const & other );
	Cat( Cat const *other );
	virtual ~Cat();
	Cat & operator=( Cat const & other );

	virtual void makeSound( void ) const;
	Brain* getBrain( void ) const;
	void setNewIdea( std::string const idea );
	
private:
	Brain* _brain;
};