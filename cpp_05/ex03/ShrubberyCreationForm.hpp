#pragma once

# include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

	void execute(Bureaucrat const & executor) const;
	void doExecute() const;
	std::string getTarget() const;
	void setTarget(std::string const target);

private:
	std::string _target;
};