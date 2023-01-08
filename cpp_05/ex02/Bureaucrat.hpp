#pragma once

#include <iostream>
# include <fstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char * what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char * what() const throw();
    };

    class NameLessExeption : public std::exception {
    public:
        virtual const char * what() const throw();
    };

	class FailException: public std::exception{
		public:
			virtual const char* what() const throw();
	};

    Bureaucrat(void);
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & src);

    std::string getName() const;
	void setName(std::string const name);
    void setGrade(int grade);
    int getGrade() const;
    void checkGrade(int grade) const;
    void decrementGrade();
    void incrementGrade();
    void signForm(Form & form);
	void executeForm(Form const & form);
private:
    std::string const _name;
    int _grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src);