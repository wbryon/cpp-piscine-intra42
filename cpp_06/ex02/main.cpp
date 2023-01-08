#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base *generate(void) {
	int r = rand();
	if (r % 3 == 0) {
		A *obj = new A;
		return obj;
	}
	else if (r % 3 == 1) {
		B *obj = new B;
		return obj;
	}
	else if (r % 3 == 2) {
		C *obj = new C;
		return obj;
	}
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p) != 0) {
		std::cout << "This is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != 0) {
		std::cout << "This is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != 0) {
		std::cout << "This is C" << std::endl;
	}
}

void identify(Base &p) {
	if (dynamic_cast<A*>(&p) != 0) {
		std::cout << "This is A" << std::endl;
	}
	else if (dynamic_cast<B*>(&p) != 0) {
		std::cout << "This is B" << std::endl;
	}
	else if (dynamic_cast<C*>(&p) != 0) {
		std::cout << "This is C" << std::endl;
	}
}

int main() {
	srand(time(NULL));

	Base *obj = generate();
	identify(obj);
	identify(*obj);
	return 0;
}