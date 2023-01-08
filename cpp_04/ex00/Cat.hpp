#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat( void );
	Cat( Cat const & other );
    virtual ~Cat();
	Cat & operator=( Cat const & other );

    virtual void makeSound( void ) const;
    
protected:
    std::string _name;
};