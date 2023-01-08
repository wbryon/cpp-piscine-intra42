#include "Scalar.hpp"

Scalar::Scalar() : _sign(1), _isPoint(false) {}

Scalar::~Scalar() {}

Scalar::Scalar(const Scalar &copy) {
	*this = copy;
}

Scalar &Scalar::operator=( Scalar const &src) {
	if (this != &src) {
		this->_str = src._str;
		this->_longNbr = src._longNbr;
		this->_isPoint = src._isPoint;
	}
	return *this;
}

void Scalar::parseStr() {
	if (_str.empty()) {
		throw std::string("Empty string");
	}
	if (_str.length() > 1) {
		unsigned long i;
		for (i = 0; std::string("\t\v\f\r\n ").find(_str[i], 0) != std::string::npos; ++i) {}
		if (i == _str.length())
			throw std::string("Empty string");
		_str = _str.substr(i);
		if (_str == "nan" || _str == "nanf") {
			_longNbr = NAN;
			return ;
		}
		if (_str[i] == '-' || _str[i] == '+') {
			if (!(std::isdigit(static_cast<int>(_str[i + 1])) || _str == "-inf" || _str == "-inff" || _str == "+inf" || _str == "+inff"))
				throw std::string("\033[0;31mNon valid argument\033[m");
			if (_str[i] == '-')
				_sign = -1;
			++i;
		}
		_str = _str.substr(i);
		if (_str == "inf" || _str == "inff") {
			_longNbr = INFINITY * _sign;
			return ;
		}
		if (_str.length() > 1) {
			for (i = 0; i < _str.length(); ++i) {
				if (_str[i] == '.') {
					if (_isPoint == true || i == _str.length() - 1)
						throw std::string("\033[0;31mnonValid argument\033[m");
					_isPoint = true;
				}
				else if (!(std::isdigit(static_cast<int>(_str[i]))))
					break;
			}
			if (i != _str.length()) {
				if (!(i + 1 == _str.length() && _str[i] == 'f' && _isPoint == true))
					throw std::string("\033[0;31mis not a number\033[m");
			}
			_longNbr = atol(_str.c_str()) * _sign;
		}
	}
	if (_str.length() == 1) {
		if (_str[0] >= '0' && _str[0] <= '9')
			_str[0] -= '0';
		_longNbr = static_cast<double>(_str[0]) * _sign;
	}
}

void Scalar::convertToChar() {
	char c;

	if (_str == "nan" || _str == "nanf") {
		std::cout << "\033[0;31mchar: impossible\033[m" << std::endl;
		return ;
	}
	if (_longNbr == INFINITY || _longNbr == -INFINITY) {
		std::cout << "char: " << "Impossible" << std::endl;
		return ;
	}
	if (_longNbr < CHAR_MAX && _longNbr > CHAR_MIN) {
		c = static_cast<char>(_longNbr);
		if (std::isgraph(static_cast<int>(c))) {
			std::cout << "char: " << c << std::endl;
		}
		else {
			std::cout << "\033[0;31mchar: NonDisplayable\033[m" << std::endl;
		}
	}
	else {
		std::cout << "\033[0;31mchar: nonDisplayable\033[m" << std::endl;
	}
}

void Scalar::convertToFloat() {
	float f;

	f = static_cast<float>(_longNbr);
	int precision = 1;
	if (_str.find(".") != std::string::npos && _str.length() - _str.find(".") - 1 > 0)
		precision = _str.length() - _str.find(".") - 1;
	if (_str[_str.length() - 1] == 'f')
		precision--;
	std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;

}

void Scalar::convertToDouble() {
	int precision = 1;
	if (_str.find(".") != std::string::npos && _str.length() - _str.find(".") - 1 > 0)
		precision = _str.length() - _str.find(".") - 1;
	if (_str[_str.length() - 1] == 'f')
		precision--;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << _longNbr << std::endl;
}

void Scalar::convertToInt() {
	if (_longNbr == INFINITY || _longNbr == -INFINITY || _str == "nan" || _str == "nanf") {
		std::cout << "int: " << "Impossible" << std::endl;
		return ;
	}
	if (_longNbr <= static_cast<double>(2147483647) && _longNbr >= -2147483648) {
		std::cout << "int: " << static_cast<int>(_longNbr) << std::endl;
	}
	else {
		std::cout << "\033[0;31mint: Overflow\033[m" << std::endl;
	}
}

void Scalar::Converter(std::string argv)
{
	_str = argv;
	parseStr();
	convertToChar();
	convertToInt();
	convertToFloat();
	convertToDouble();
}