#pragma once

# include <iostream>
# include <cmath>
# include <string>
# include <climits>
# include <iomanip>
# include <exception>

class Scalar {
public:
	Scalar();
	~Scalar();
	Scalar( Scalar const & src);
	Scalar & operator=( Scalar const & src);

	void Converter(std::string str);

private:
	std::string	_str;
	double _longNbr;
	int _sign;
	bool _isPoint;
	void convertToInt();
	void convertToChar();
	void convertToFloat();
	void convertToDouble();
	void parseStr();
};