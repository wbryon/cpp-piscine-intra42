#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 45, 72), _target("noTarget") {
    std::cout << "\033[0;33mRobotomyRequestForm created with default constructor\033[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 45, 72), _target(target) {
    std::cout << "\033[0;36mRobotomyRequestForm created with target \033[m" << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src) {
	_target = src.getTarget();
    std::cout << "\033[1;36mRobotomyRequestForm created with copy constructor\033[m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\033[0;34mRobotomyRequestForm destructed\033[m" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	setSign(src.getSign());
	_target = src.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}
void RobotomyRequestForm::setTarget(std::string const target) {
    _target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		checkBeforeExecute(executor);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw Bureaucrat::FailException();
		return ;
	}
	
	std::srand(time(NULL));
	int random_value = std::rand();
	if (random_value % 2==0) {
		std::cout << _target << "\033[0;32m has been robotomized successfully!\033[m" << std::endl;
	}
	else
		std::cout << _target << "\033[0;31m failed to robotomize!\033[m" << std::endl;
}