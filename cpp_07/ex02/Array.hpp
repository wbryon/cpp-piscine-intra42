#include <iostream>

template<typename T>
class Array {
public:
	Array(void) : arrayStart(NULL), arraySize(0) {
		std::cout << "\033[0;33mDefault constructor created\033[m" << std::endl;
	}
	Array(uint32_t count) {
		if (count) {
			arrayStart = new T[count];
		}
		else
			arrayStart = NULL;
		arraySize = count;
	}
	Array(const Array& other) {
		arrayStart = new T [other.arraySize];
		arraySize = other.arraySize;
		for (size_t i = 0; i < other.arraySize; i++) {
			arrayStart[i] = other[i];
		}
	}
	Array& operator=(const Array& other) {
		if (*this == other) {
			return *this;
		}
		if (arrayStart)
			delete [] arrayStart;
		arrayStart = new T [other.arraySize];
		arraySize = other.arraySize;
		for (size_t i = 0; i < other.arraySize; i++) {
			arrayStart[i] = other[i];
		}
	}
	const T& operator[](size_t index) const{
		if (index >= arraySize) {
			throw std::out_of_range("Index out of range of array");
		}
		return arrayStart[index];
	}
	T& operator[](size_t index) {
		if (index >= arraySize) {
			throw std::out_of_range("Index out of range of array");
		}
		return arrayStart[index];
	}
	size_t size() const {
		return arraySize;
	}
	~Array() {
		std::cout << "\033[0;34mDestructor called\033[m" << std::endl;
		if (arrayStart) {
			delete [] arrayStart;
		}
	}
private:
	T* arrayStart;
	size_t arraySize;
};