#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 137, 145), _target("noTarget") {
    std::cout << "\033[0;33mShrubberyCreationForm created with default constructor\033[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 137, 145), _target(target) {
    std::cout << "\033[0;36mShrubberyCreationForm created with target \033[m" << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src) {
	_target = src.getTarget();
    std::cout << "\033[1;36mShrubberyCreationForm created with copy constructor\033[m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "\033[0;34mShrubberyCreationForm destructed\033[m" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	setSign(src.getSign());
	_target = src.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::setTarget(std::string const target) {
    _target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		checkBeforeExecute(executor);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw Bureaucrat::FailException();
		return ;
	}
	
	std::string fileName(_target + "_shrubbery");
	std::fstream output_fstream;
	output_fstream.open(fileName.c_str(), std::ios_base::out);
	if (!output_fstream.is_open()) {
		std::cout << "Failed to open " << fileName << std::endl;
	}
	output_fstream << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n_\\._\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	std::cout << "\033[0;32mShrubberyCreationForm: Execution Completed!\033[m" << std::endl;
}