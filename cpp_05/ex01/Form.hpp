#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception{
	public:
		virtual const char* what() const throw();
	};

	Form();
	Form(std::string name, int gradeToExecute, int gradeToSign);
	Form(Form const & src);
	~Form();
	Form & operator=(Form const & src);

	std::string getName() const;
	void setName(std::string const name);
	bool getSigned() const;
	void setSigned(bool sign);
	int getGradeToSign() const;
	int getGradeToExecute() const;

	Form & beSigned(Bureaucrat const & bureaucrat);

private:
	std::string const _name;
	bool _sign;
	int const _gradeToSign;
	int const _gradeToExecute;

};

std::ostream & operator<<(std::ostream & out, Form const & src);