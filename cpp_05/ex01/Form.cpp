#include "Form.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Form error: grade too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Form error: grade too low");
}

Form::Form() : _name("noName"), _sign(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "\033[0;33mForm created with default constructor\033[m" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name),
_sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
    std::cout << "\033[0;31mForm created with parameters: \033[m" << "name -> " << _name
	<< "; grade to sign -> " << _gradeToSign << "; is signed -> " << _sign << std::endl;
}

Form::Form(Form const & src) : _name(src.getName()), _sign(src.getSigned()),
_gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form created with src constructor" << std::endl;
    std::cout << "\033[1;36mForm created with copy constructor\033[m" << std::endl;
}

Form::~Form() {
    std::cout << "\033[0;34mForm destructor called for \033[m" << _name << std::endl;
}

Form & Form::operator=(Form const & src) {
	_sign = src.getSigned();
	return *this;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _sign;
}

void Form::setSigned(bool sign) {
    _sign = sign;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}
int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

Form & Form::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() <= getGradeToSign()) {
		setSigned(true);
	}
	else
		throw Form::GradeTooLowException();
	return *this;
}

std::ostream & operator<<(std::ostream & out, Form const & src) {
	out << "Form: " << src.getName() << " with answer: " << (src.getSigned()?"this question is in my competence":"this question is beyond my competence")
	<< ", required grade to sign: " << src.getGradeToSign() << ", required grade to execute: " << src.getGradeToExecute() << std::endl;
	return out;
}