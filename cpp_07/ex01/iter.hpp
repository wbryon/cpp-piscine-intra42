#pragma once
#include <iostream>

template <typename T>
void iter(T* array, size_t size, void func(const T& index)) {
	for (size_t i = 0; i < size; ++i) {
		func(array[i]);
	}
}

template <typename T>
void print(const T& index) {
	std::cout << index << std::endl;
	return ;
}