#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:

	Intern();
	Intern(Intern const & src);
	~Intern();
	Intern & operator=(Intern const & src);

	Form * makeForm(std::string const & name, std::string const & target);
};