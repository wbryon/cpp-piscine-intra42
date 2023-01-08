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
    Fixed&  operator=( const Fixed & );
    bool    operator>( const Fixed & ) const;
    bool    operator<( const Fixed & ) const;
    bool    operator>=( const Fixed & ) const;
    bool    operator<=( const Fixed & ) const;
    bool    operator==( const Fixed & ) const;
    bool    operator!=( const Fixed & ) const;
    Fixed   operator+( const Fixed & ) const;
    Fixed   operator-( const Fixed & ) const;
    Fixed   operator*( const Fixed & ) const;
    Fixed   operator/( const Fixed & ) const;
    Fixed & operator++();
    Fixed   operator++( int );
    Fixed & operator--();
    Fixed   operator--(int);

    static Fixed &       min( Fixed &, Fixed & );
    static const Fixed & min( const Fixed & , const Fixed & );
    static Fixed&        max( Fixed &, Fixed & );
    static const Fixed & max( const Fixed &, const Fixed & );
    int     getRawBits( void ) const;
    void    setRawBits( int const );
    float   toFloat( void ) const;
    int     toInt( void ) const;

private:
    int                 _fixedPointVal;
    static const int    _bitNumber = 8;   
};

std::ostream & operator << ( std::ostream &, const Fixed & );

#endif