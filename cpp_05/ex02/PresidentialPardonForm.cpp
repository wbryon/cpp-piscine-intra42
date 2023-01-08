#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 5, 25), _target("noTarget") {
    std::cout << "\033[0;33mPresidentialPardonForm created with default constructor\033[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 5, 25), _target(target) {
	std::cout << "\033[0;36mPresidentialPardonForm created with target \033[m" << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src) {
	this->_target = src.getTarget();
    std::cout << "\033[1;36mPresidentialPardonForm created with copy constructor\033[m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "\033[0;34mPresidentialPardonForm destructed\033[m" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	setSign(src.getSign());
	this->_target = src.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}
void PresidentialPardonForm::setTarget(std::string const target) {
    this->_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		checkBeforeExecute(executor);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw Bureaucrat::FailException();
		return ;
	}
	std::cout << this->_target << "\033[0;32m was pardoned by Zafod Beeblebrox!\033[m" << std::endl;
}