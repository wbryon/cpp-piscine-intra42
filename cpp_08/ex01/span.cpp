#include "span.hpp"

Span::Span(unsigned int n) : _n(n) {
	std::cout << "\033[0;31mSpan constructor created with array size = \033[m" << n << std::endl;
}

Span::~Span() {
	std::cout << "\033[0;34mSpan destructor called\033[m" << std::endl;
}

Span::Span(const Span & src) {
	*this = src;
}

Span &Span::operator=(const Span & src) {
	this->_n = src._n;
	this->_vectorArray = src._vectorArray;
	return *this;
}

void Span::addNumber(int number) {
	if (_vectorArray.size() >= _n)
		throw std::out_of_range("array is already full");
	else
		_vectorArray.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while(begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

int Span::maxElement() {
	std::vector<int>::iterator maxElement = std::max_element(_vectorArray.begin(), _vectorArray.end());
	return *maxElement;
}

int Span::minElement() {
	std::vector<int>::iterator minElement = std::min_element(_vectorArray.begin(), _vectorArray.end());
	return *minElement;
}

int Span::shortestSpan() {
	if (_vectorArray.size() < 2)
		throw std::out_of_range("there is no span to find");
	int result = std::abs(_vectorArray[0] - _vectorArray[1]);
	for (std::vector<int>::iterator i = _vectorArray.begin(); i != _vectorArray.end(); ++i) {
		for (std::vector<int>::iterator j = _vectorArray.begin(); j != _vectorArray.end(); ++j) {
			if (i != j && std::abs(*i - *j) < result)
				result = std::abs(*i - *j);
		}
	}
	return result;
}

int Span::longestSpan()
{
	if (_vectorArray.size() < 2)
		throw std::out_of_range("there is no span to find");
	return maxElement() - minElement();
}