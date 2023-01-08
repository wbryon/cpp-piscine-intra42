#include "Scalar.hpp"

int main (int argc, char **argv) {
	if (argc != 2){
		std::cerr << "\033[0;31mWrong arguments number!\033[m" << std::endl;
		return (0);
	}
	try {
		Scalar	obj;
		obj.Converter(argv[1]);
	}
	catch (std::string & e) {
		std::cerr << "\033[0;31mError: \033[m" << e << std::endl;
	}
}