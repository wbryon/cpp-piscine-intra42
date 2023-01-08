#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	std::cout << "---------------ShrubberyCreationForm------------\n";
	{
		Bureaucrat clerk1("Bob", 1);
		Bureaucrat clerk2("Tom", 140);
		std::cout << "" << std::endl;
		ShrubberyCreationForm form1("Bush");
		ShrubberyCreationForm form2("Bush");

		std::cout << "----------------clerk1---------------------\n";

		clerk1.executeForm(form1);
		try {
			clerk1.signForm(form1);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk1.executeForm(form1);
		
		std::cout << "------------------clerk2--------------------\n";

		clerk2.executeForm(form2);
		try {
			clerk2.signForm(form2);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk2.executeForm(form2);

		std::cout << "---------------------------------------------\n";
	}
	std::cout << "---------------RobotomyRequestForm---------------\n";
	{
		Bureaucrat clerk3("Thrasher", 1);
		Bureaucrat clerk4("Blastus", 50);
		std::cout << "" << std::endl;
		RobotomyRequestForm form1("John");
		RobotomyRequestForm form2("John");

		std::cout << "-----------------clerk3----------------------\n";
		
		clerk3.executeForm(form1);
		try {
			clerk3.signForm(form1);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk3.executeForm(form1);
		
		std::cout << "------------------clerk4----------------------\n";

		clerk4.executeForm(form2);
		try {
			clerk4.signForm(form2);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk4.executeForm(form2);

		std::cout << "----------------------------------------------\n";
	}
	std::cout << "---------------PresidentialPardonForm-------------\n";
	{
		Bureaucrat clerk5("Trisha", 1);
		Bureaucrat clerk6("Ford Prefect", 10);
		std::cout << "" << std::endl;
		PresidentialPardonForm form1("Arthur Philip Dent");
		PresidentialPardonForm form2("Arthur Philip Dent");

		std::cout << "------------------clerk5-----------------------\n";

		clerk5.executeForm(form1);
		try {
			clerk5.signForm(form1);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk5.executeForm(form1);
		
		std::cout << "------------------clerk6-----------------------\n";

		clerk6.executeForm(form2);
		try {
			clerk6.signForm(form2);
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		clerk6.executeForm(form2);

		std::cout << "-----------------Destructors--------------------\n";
	}
}