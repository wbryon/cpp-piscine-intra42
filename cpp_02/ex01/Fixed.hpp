#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

public:
    Fixed( const int );
    Fixed( const float );
    Fixed( void );
    ~Fixed( void );
    Fixed( const Fixed & );
    Fixed & operator=( const Fixed & );
    int     getRawBits( void ) const;
    void    setRawBits( int const);
    float   toFloat( void ) const;
    int     toInt( void ) const;

private:
    int                 _fixedPointVal;
    static const int    _bitNumber = 8;   
};

std::ostream & operator << ( std::ostream & , const Fixed & );

#endif