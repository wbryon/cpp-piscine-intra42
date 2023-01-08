#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointVal(0) {
    std::cout << "\033[0;33mDefault constructor called\033[m" << std::endl;
    std::cout << "fixedPointVal: " << _fixedPointVal << std::endl;
}

Fixed::Fixed( const int intNumber ) : _fixedPointVal(intNumber << _bitNumber) {
    std::cout << "fixedPointVal: " << _fixedPointVal << std::endl;
    std::cout << "\033[0;31mInt constructor called\033[m" << std::endl;
}
Fixed::Fixed( const float floatNumber ) {
    _fixedPointVal = (int)(roundf(floatNumber * (1 << _bitNumber)));
    std::cout << "\033[0;36mFloat constructor called\033[m" << std::endl;
    std::cout << "fixedPointVal: " << _fixedPointVal << std::endl;
}

Fixed::~Fixed() {
    std::cout << "\033[0;34mDestructor called\033[m" << std::endl;
}

Fixed::Fixed( const Fixed& other ) {
    std::cout << "\033[1;36mCopy constructor called\033[m" << std::endl;
    *this=other;
}

Fixed & Fixed::operator=( const Fixed &other ) {
    std::cout << "\033[0;32mAssignation operator called\033[m" << std::endl;
    if (this != &other)
        this->_fixedPointVal = other.getRawBits();
    return *this;
}

float Fixed::toFloat( void ) const {
    return (((float)_fixedPointVal / (float)(1 << _bitNumber)));
}

int Fixed::toInt( void ) const {
    return _fixedPointVal >> _bitNumber;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointVal = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "\033[0;35mgetRawBits member function called\033[m" << std::endl;
    return this->_fixedPointVal;
}

std::ostream & operator << ( std::ostream &out, const Fixed &other ) {
    out << other.toFloat();
    return out;
}