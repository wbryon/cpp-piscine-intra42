#pragma once

#include <iostream>

template<typename T>
void swap(T& val1, T& val2) {
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template<typename T>
T min(const T& val1, const T& val2) {
	if (val1 >= val2) {
		return val2;
	}
	else
		return val1;
}

template<typename T>
T max(const T& val1, const T& val2) {
	if (val1 >= val2) {
		return val1;
	}
	else
		return val2;
}

class Sample {
public:
	int _value;
	Sample(int n) : _value(n) {}
	bool operator==(const Sample& other) const {
		return (this->_value == other._value);
	}
	bool operator!=(const Sample& other) const {
		return (this->_value != other._value);
	}
	bool operator>(const Sample& other) const {
		return (this->_value > other._value);
	}
	bool operator<(const Sample& other) const {
		return (this->_value < other._value);
	}
	bool operator<=(const Sample& other) const {
		return (this->_value <= other._value);
	}
	bool operator>=(const Sample& other) const {
		return (this->_value >= other._value);
	}
};

std::ostream& operator<<(std::ostream& out, const Sample& src) {
	out << src._value;
	return out;
}