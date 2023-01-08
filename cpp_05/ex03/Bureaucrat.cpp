#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("\033[0;31mBureaucrat error: maximum possible grade is 1\033[m");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("\033[0;31mBureaucrat error: minimum possible grade is 150\033[m");
}

const char * Bureaucrat::NameLessExeption::what() const throw() {
    return ("\033[0;31mBureaucrat error: bureaucrat cannot be nameless!\033[m");
}

const char * Bureaucrat::FailException::what() const throw() {
    return ("\033[0;31mBureaucrat reported: execution failed!\033[m");
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
    std::cout << "\033[0;36mBureaucrat created with name \033[m" << this->_name << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade()) {
    std::cout << "\033[1;36mBureaucrat \033[m" << _name << "\033[1;36m created with copy constructor\033[m" << std::endl;
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
		std::cout << getName() << "\033[0;31m cannot sign form because \033[m" << e.what() << std::endl;
		return ;
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << getName() << "\033[0;31m cannot sign form because \033[m" << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " execute " << form.getName() << std::endl;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src) {
    out << src.getName() << ", grade=" << src.getGrade() << " ";
    return out;
}