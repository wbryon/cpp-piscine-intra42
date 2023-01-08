#include "Intern.hpp"

Intern::Intern() {
	std::cout << "\033[0;33mIntern created with default constructor\033[m" << std::endl;
}

Intern::Intern(Intern const & src) {
	(void)src;
	std::cout << "\033[1;36mIntern created with src constructor\033[m" << std::endl;
}

Intern::~Intern() {
	std::cout << "\033[0;34mIntern destructed\033[m" << std::endl;
}

Intern & Intern::operator=(Intern const & src) {
	(void)src;
	return *this;
}

Form* Intern::makeForm( std::string const &name, std::string const &target) {
	Form *forms[] = {new PresidentialPardonForm(target), new ShrubberyCreationForm(target), new RobotomyRequestForm(target)};
	for (int i = 0; i < 3; ++i) {
		if (forms[i]->getName() == name) {
			std::cout << "Intern creates <" + forms[i]->getName() + ">" << std::endl;
			return forms[i];
		}
	}
	throw Form::UnknownFormException();
}