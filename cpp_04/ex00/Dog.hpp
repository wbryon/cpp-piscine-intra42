#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog( void );
    Dog ( Dog const & other );
    virtual ~Dog();
    Dog & operator=( Dog const & other );

    virtual void makeSound( void ) const;
    
protected:
    std::string _name;
};