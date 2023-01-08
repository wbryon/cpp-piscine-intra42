#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "\033[0;31mCreating new MutantStack\033[m" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack<T>& src) : std::stack<T>(src) {
	std::cout << "\033[1;36mMutantStack copied\033[m" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	return ;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& src) {
	std::cout << "\033[0;32mAssignment operator called\033[m" << std::endl;
	if (this == src)
		return (*this);
	std::stack<T>::operator= &src;
	return (*this);
}

template <typename T>
typename MutantStack<T>::myIterator MutantStack<T>::begin(void) {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::myIterator MutantStack<T>::end(void) {
	return this->c.end();
}