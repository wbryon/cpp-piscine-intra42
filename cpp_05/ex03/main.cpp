#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat bureaucrat("VIPerson", 2);
	Intern someRandomIntern;
	Form *form;

	try {
		form = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur Philip Dent");
		form->beSigned(bureaucrat);
		bureaucrat.executeForm(*form);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	try {
		form = someRandomIntern.makeForm("fakeForm", "target");
		form->beSigned(bureaucrat);
		bureaucrat.executeForm(*form);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	delete form;
	return 0;
}