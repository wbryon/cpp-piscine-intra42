#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}

// int main(void)
// {
// 	Fixed x;
// 	// Fixed y(20);
// 	Fixed const y(Fixed(5.05f) * Fixed(2));

// 	std::cout << "x: " << x << std::endl;
// 	std::cout << "++x: " << ++x << std::endl;
// 	std::cout << "x: " << x << std::endl;
// 	std::cout << "x++: " << x++ << std::endl;
// 	std::cout << "x: " << x << std::endl;
// 	std::cout << "--x " << --x << std::endl;
// 	std::cout << "x-- " << x-- << std::endl;
// 	std::cout << "x: " << x << std::endl;
// 	std::cout << "++(++x) " << ++(++x) << std::endl;
// 	std::cout << "y: " << y << std::endl;
// 	std::cout << "x + y: " << x + y << std::endl;
// 	std::cout << "x: " << x << std::endl;
// 	std::cout << "x - y: " << x - y << std::endl;
// 	std::cout << "x * y: " << x * y << std::endl;
// 	std::cout << "---  x = -21, y = 4  ---" << std::endl;
// 	// x = Fixed(-21) ; y = Fixed(4);
// 	std::cout << "x / y: " << x / y << std::endl;

// 	std::cout << "x < y: " << std::boolalpha << (x < y) << std::endl;
// 	std::cout << "x > y: " << std::boolalpha << (x > y) << std::endl;
// 	std::cout << "Max(x, y): " << Fixed::max(x, y) << std::endl;
// 	std::cout << "Min(x, y): " << Fixed::min(x, y) << std::endl;

// 	const Fixed c(241);
// 	const Fixed d(-12);

// 	std::cout << "Max(c, d): " << Fixed::max(c, d) << std::endl;
// 	std::cout << "Min(c, d): " << Fixed::min(c, d) << std::endl;
// 	return (0);
// }