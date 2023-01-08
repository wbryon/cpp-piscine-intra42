#pragma once

#include <iostream>

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
    
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(void);
    Bureaucrat(Bureaucrat const & src);
    ~Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & src);

    std::string getName() const;
    void setGrade(int grade);
    int getGrade() const;
    void checkGrade(int grade) const;
    void decrementGrade();
    void incrementGrade();
    
private:
    std::string const _name;
    int _grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src);