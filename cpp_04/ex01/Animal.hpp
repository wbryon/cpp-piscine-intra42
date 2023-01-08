#pragma once

# include <iostream>
# include "Brain.hpp"

class Animal {
public:
    Animal( void );
    Animal( std::string const & type );
    Animal( Animal const & other );
    virtual ~Animal();
    Animal & operator=( Animal const & other );

    virtual void makeSound( void ) const;
    void setType( std::string name );
    std::string getType( void ) const;
    
protected:
    std::string _type;
};