#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class UnknownFormException: public std::exception {
		virtual const char* what() const throw();
	};

	Form();
	Form(std::string name, int gradeToExecute, int gradeToSign);
	Form(Form const & src);
	virtual ~Form();
	Form & operator=(Form const & src);

	std::string getName() const;
	void setName(std::string const name);
	bool getSign() const;
	void setSign(bool sign);
	int getGradeToSign() const;
	int getGradeToExecute() const;

	Form & beSigned(Bureaucrat const & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	void checkBeforeExecute(Bureaucrat const & executor) const;

private:
	std::string const _name;
	bool _sign;
	int const _gradeToSign;
	int const _gradeToExecute;

};

std::ostream & operator<<(std::ostream & out, Form const & src);