#pragma once

#include <stack>
#include <iostream>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T>& src);
	virtual ~MutantStack();
	MutantStack& operator=(const MutantStack<T>& src);

	typedef typename std::deque<T>::iterator myIterator;
	myIterator begin();
	myIterator end();
};