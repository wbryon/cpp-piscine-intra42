#include "iter.hpp"
#include <string>

class Awesome {
public:
	int _n;
	Awesome(void) : _n(42) {}
	int get(void) const {return this->_n;}
};

std::ostream& operator<<(std::ostream & out, const Awesome & rhs) {
	out << rhs.get();
	return out;
}

int main() {
	{
		int array[] = {1, 2, 3, 4, 5, 6};
		size_t arraySize = sizeof(array) / sizeof(int);
		std::cout << "-------------test1------------" << std::endl;
		iter(array, arraySize, print);
	}
	std::cout << std::endl;
	{
		std::string array[] = {"AAA", "BBB", "CCC", "DDD", "EEE", "XXX"};
		size_t arraySize = sizeof(array) / sizeof(std::string);
		std::cout << "-------------test2------------" << std::endl;
		iter(array, arraySize, print);
	}
	std::cout << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4};
		Awesome tab2[5];
		std::cout << "-------------test3------------" << std::endl;
		iter(tab, 5, print);
		std::cout << "-------------test4------------" << std::endl;
		iter(tab2, 5, print);
	}
}