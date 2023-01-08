#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat error: maximum possible grade is 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat error: minimum possible grade is 150");
}

const char * Bureaucrat::NameLessExeption::what() const throw() {
    return ("Bureaucrat error: bureaucrat cannot be nameless");
}

Bureaucrat::Bureaucrat() {
    throw NameLessExeption();
    std::cout << "\033[0;33mBureaucrat default created\033[m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
    if (name.empty()) {
        throw NameLessExeption();
    }
    checkGrade(grade);
    setGrade(grade);
    std::cout << "\033[0;31mBureaucrat created with name \033[m"
    << this->_name << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade()) {
    std::cout << "\033[1;36mBureaucrat \033[m" << _name
    << "\033[1;36m created with copy constructor\033[m" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\033[0;34mBureaucrat destructor called for \033[m" << this->_name << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &) {
	std::cout << "\033[0;32mAssignment operator called\033[m" << std::endl;
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

void Bureaucrat::checkGrade(int grade) const {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::setGrade(int grade) {
    this->_grade = grade;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form & form) {
	try {
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << getName() << " cannot sign form because " << e.what() << std::endl;
		return ;
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << getName() << " cannot sign form because " << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src) {
    out << src.getName() << ", bureaucrat grade=" << src.getGrade() << " ";
    return out;
}