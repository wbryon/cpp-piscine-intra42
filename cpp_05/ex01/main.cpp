#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat clerk2("Bob", 51);
	Bureaucrat clerk1("Tom", 49);
	Form loanApproval("Decision", 50, 50);
	std::cout << "-----------------output1--------------------" << std::endl;
	std::cout << loanApproval;
	std::cout << "-------------------------------------------" << std::endl;
	try {
		clerk2.signForm(loanApproval);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------output2--------------------" << std::endl;
	std::cout << loanApproval;
	std::cout << "-------------------------------------------" << std::endl;
	try {
		clerk1.signForm(loanApproval);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------output3--------------------" << std::endl;
	std::cout << loanApproval;
	std::cout << "---------------destructors-----------------" << std::endl;

	return 0;
}