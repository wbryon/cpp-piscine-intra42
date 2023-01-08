#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	typename T::iterator res = std::find(container.begin(), container.end(), n);
	if (res == container.end()) {
		throw std::runtime_error("Element not found!");
	}
	return (res);
};