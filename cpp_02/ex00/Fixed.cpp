#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "\033[0;33mDefault constructor called\033[m" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "\033[0;34mDestructor called\033[m" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
    std::cout << "\033[1;36mCopy constructor called\033[m" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=( const Fixed &other )
{
    std::cout << "\033[0;32mAssignation operator called\033[m" << std::endl;
    if (this != &other)
        this->_fixedPointValue = getRawBits();
    return *this;
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}

int  Fixed::getRawBits(void) const
{
    std::cout << "\033[0;35mgetRawBits member function called\033[m" << std::endl;
    return this->_fixedPointValue;
}
