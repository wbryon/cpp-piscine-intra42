#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog( void );
	Dog( Dog const & other );
	virtual ~Dog();
	Dog & operator=( Dog const & other );

	virtual void makeSound() const;
	Brain* getBrain( void ) const;
	void setNewIdea( std::string const idea );
	
private:
	Brain* _brain;
};