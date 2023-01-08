#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span {
public:
	Span(unsigned int n);
	~Span();
	Span(const Span & src);
	Span & operator = (const Span & src) ;
	void addNumber(int number);
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	int maxElement();
	int minElement();

private:
	unsigned int _n;
	std::vector<int> _vectorArray;
};