#include "Data.hpp"
#include <iomanip>

int main() {
	Data* d = new Data();
	uintptr_t ptr = serialize(d);
	d->value = 42;
	std::cout << std::setw(32) << std::left << "Data value: " << std::right << d->value << std::endl;
	std::cout << std::setw(32) << std::left << "Data address: " << std::right << d << std::endl;
	std::cout << std::setw(32) << std::left << "After serialize ptr address: " << std::right << ptr << std::endl;
	std::cout << std::setw(32) << std::left << "After deserialize Data address: " << std::right << deserialize(ptr) << std::endl;
	std::cout << std::setw(32) << std::left << "Data value: " << std::right << deserialize(ptr)->value << std::endl;
	delete d;
	return 0;
}