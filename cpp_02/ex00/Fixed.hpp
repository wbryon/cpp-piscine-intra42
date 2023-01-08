#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

public:
    Fixed( void );
    ~Fixed( void );
    Fixed( const Fixed& );
    Fixed & operator=( const Fixed& );
    int     getRawBits( void ) const;
    void    setRawBits( int const );

private:
    int                 _fixedPointValue;
    static const int    _bitNumber = 8;
};

#endif