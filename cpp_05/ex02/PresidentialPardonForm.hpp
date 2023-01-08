#pragma once

# include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm();
	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	void setTarget(std::string const target);

private:
	std::string _target;
};