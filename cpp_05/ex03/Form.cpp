#include "Form.hpp"

const char * Form::GradeTooHighException::what() const throw() {
    return ("\033[0;31mForm error: grade too high!\033[m");
}

const char * Form::GradeTooLowException::what() const throw() {
    return ("\033[0;31mForm error: grade too low!\033[m");
}

const char * Form::FormNotSignedException::what() const throw() {
    return ("\033[0;31mForm error: not signed!\033[m");
}

const char* Form::UnknownFormException::what() const throw() {
	return "Error: No such form exists";
}

Form::Form() : _name("noName"), _sign(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "\033[0;33mForm created with default constructor\033[m" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
    std::cout << "\033[0;36mForm created with parameters: \033[m" << "title -> " << _name << "; grade to sign -> " << _gradeToSign
	<< "; grade to execute -> " << _gradeToExecute << "; is signed -> " << _sign << std::endl;
}

Form::Form(Form const & src) : _name(src.getName()), _sign(src.getSign()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
    std::cout << "\033[1;36mForm created with copy constructor\033[m" << std::endl;
}

Form::~Form() {
    std::cout << "\033[0;34mForm destructed\033[m" << std::endl;
}

Form & Form::operator=(Form const & src) {
	_sign = src.getSign();
	return *this;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSign() const {
    return _sign;
}

void Form::setSign(bool sign) {
    _sign = sign;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}
int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

Form & Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= getGradeToSign()) {
		setSign(true);
	}
	else
		throw Form::GradeTooLowException();
	return *this;
}

void Form::checkBeforeExecute(Bureaucrat const & executor) const {
	if (!getSign()) {
		throw Form::FormNotSignedException();
		return ;
	}
	if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & out, Form const & src) {
	out << "Form: " << src.getName() << " with answer: "
	<< (src.getSign()?"\033[0;32mthis question is in my competence\033[m":"\033[0;31mthis question is beyond my competence\033[m")
	<< ", required grade to sign: " << src.getGradeToSign()
	<< ", required grade to execute: " << src.getGradeToExecute() << std::endl;
	return out;
}