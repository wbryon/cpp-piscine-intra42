#include "mutantstack.hpp"
#include "mutantstack.cpp"

int main() {
	srand(time(NULL));
	MutantStack<int> mstack;
	int tmp;
	for (int i = 0; i < 10; i++) {
		tmp = rand() % 100;
		std::cout << tmp << " ";
 		mstack.push(tmp);
	}
	std::cout << "\nSize of mstack: " << mstack.size() << std::endl;
	MutantStack<int> bStack = mstack;
	std::cout << "Top element in mstack is: " << mstack.top() << std::endl;
	std::cout << "Top element in bStack is: " << bStack.top() << std::endl;
	mstack.pop();
	std::cout << "Print rest of mstack after removing top element: ";
	MutantStack<int>::myIterator it = mstack.begin();
	MutantStack<int>::myIterator ite = mstack.end();
	std::cout << std::endl;
	++it;
	std::cout << "++it = " << *it << std::endl;
	--it;
	std::cout << "--it = " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\nPrint content of bStack using iterator: ";
	MutantStack<int>::myIterator itB = bStack.begin();
	MutantStack<int>::myIterator iteB = bStack.end();
	std::cout << std::endl;
	++itB;
	std::cout << "++itB = " << *itB << std::endl;
	--itB;
	std::cout << "++itB = " << *itB << std::endl;
	while (itB != iteB)
	{
		std::cout << *itB << " ";
		++itB;
	}
	std::cout << "\n";
	std::stack<int> s(mstack);
	while (s.size()) {
		std::cout << s.top() << " ";
		s.pop();
	}                  
	std::cout << std::endl;
	return (0);
}