#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointVal(0) {
    std::cout << "\033[0;33mDefault constructor called\033[m" << std::endl;
    std::cout << "fixedPointVal: " << _fixedPointVal << std::endl;
}

Fixed::Fixed( const int intNumber ) : _fixedPointVal(intNumber << _bitNumber) {
    std::cout << "\033[0;31mInt constructor called\033[m" << std::endl;
}
Fixed::Fixed( const float floatNumber ) {
    std::cout << "\033[0;36mFloat constructor called\033[m" << std::endl;
    _fixedPointVal = (int)(roundf(floatNumber * (1 << _bitNumber)));
}

Fixed::~Fixed() {
    std::cout << "\033[0;34mDestructor called\033[m" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
    std::cout << "\033[1;36mCopy constructor called\033[m" << std::endl;
    *this=other;
}

Fixed& Fixed::operator=( const Fixed &other ) {
    std::cout << "\033[0;32mAssignation operator called\033[m" << std::endl;
    if (this != &other)
        this->_fixedPointVal = other.getRawBits();
    return *this;
}

bool Fixed::operator>( const Fixed &other ) const {
    std::cout << "\033[0;32moperator > called\033[m" << std::endl;
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<( const Fixed &other ) const {
    std::cout << "\033[0;32moperator < called\033[m" << std::endl;
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=( const Fixed &other ) const {
    std::cout << "\033[0;32moperator >= called\033[m" << std::endl;
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=( const Fixed &other ) const {
    std::cout << "\033[0;32moperator <= called\033[m" << std::endl;
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==( const Fixed &other ) const {
    std::cout << "\033[0;32moperator == called\033[m" << std::endl;
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=( const Fixed &other ) const {
    std::cout << "\033[0;32moperator != called\033[m" << std::endl;
    return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+( const Fixed &other ) const {
    std::cout << "\033[0;32moperator + called\033[m" << std::endl;
    Fixed sum;
    sum.setRawBits(this->getRawBits() + other.getRawBits());
    return sum;
}

Fixed Fixed::operator-( const Fixed &other ) const {
    std::cout << "\033[0;32moperator - called\033[m" << std::endl;
    Fixed subtraction;
    subtraction.setRawBits(this->getRawBits() - other.getRawBits());
    return subtraction;
}

Fixed Fixed::operator*( const Fixed &other ) const {
    std::cout << "\033[0;32moperator * called\033[m" << std::endl;
    Fixed multiply;
    multiply.setRawBits(this->getRawBits() * other.getRawBits() >> _bitNumber);
    return multiply;
}

Fixed Fixed::operator/( const Fixed &other ) const {
    std::cout << "\033[0;32moperator / called\033[m" << std::endl;
    Fixed division;
    division.setRawBits((this->getRawBits() << _bitNumber) / other.getRawBits());
    return division;
}

Fixed & Fixed::operator++() {
    std::cout << "\033[0;32moperator prefix++ called\033[m" << std::endl;
    ++this->_fixedPointVal;
    std::cout << "fixedPointVal: " << _fixedPointVal << std::endl;
    return *this;
}

Fixed Fixed::operator++( int ) {
    std::cout << "\033[0;32moperator postfix++ called\033[m" << std::endl;
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed & Fixed::operator--() {
    std::cout << "\033[0;32moperator prefix-- called\033[m" << std::endl;
    --this->_fixedPointVal;
    return *this;
}

Fixed Fixed::operator--( int ) {
    std::cout << "\033[0;32moperator postfix-- called\033[m" << std::endl;
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed & Fixed::min( Fixed &nbr1, Fixed &nbr2 ) {
    return (nbr1 < nbr2) ? nbr1 : nbr2;
}

const Fixed & Fixed::min( const Fixed &nbr1, const Fixed &nbr2 ) {
    return (nbr1 < nbr2) ? nbr1 : nbr2;
}

Fixed& Fixed::max( Fixed &nbr1, Fixed &nbr2 ) {
    return (nbr1 > nbr2) ? nbr1 : nbr2;
}

const Fixed & Fixed::max( const Fixed &nbr1, const Fixed &nbr2 ) {
    return (nbr1 > nbr2) ? nbr1 : nbr2;
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