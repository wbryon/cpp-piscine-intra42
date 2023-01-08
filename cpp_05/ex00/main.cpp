#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *defaultClerk;
    Bureaucrat *clerk1;
    Bureaucrat *clerk2;
    Bureaucrat *clerk3;

    std::cout << "-------------create default-------------" << std::endl;
    try {
        defaultClerk = new Bureaucrat();
        std::cout << *defaultClerk << " started work" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        defaultClerk = 0;
    }
    std::cout << "-------------create John-------------" << std::endl;
    try {
        clerk1 = new Bureaucrat("John", 147);
        std::cout << *clerk1 << " started work" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        clerk1 = 0;
    }
    std::cout << "-------------create Bob-------------" << std::endl;
    try {
        clerk2 = new Bureaucrat("Bob", 4);
        std::cout << *clerk2 << " started work" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        clerk2 = 0;
    }
    std::cout << "-------------create Tom-------------" << std::endl;
    try {
        clerk3 = new Bureaucrat("Tom", 152);
        std::cout << *clerk3 << " started work" << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        clerk3 = 0;
    }
    std::cout << "-------------decrement test-------------" << std::endl;
    try {
        for (int i = 0; i < 5; i++) {
            clerk1->decrementGrade();
            std::cout << *clerk1 << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << *clerk1 << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------increment test-------------" << std::endl;
    try {
        for (int i = 0; i < 5; i++) {
            clerk2->incrementGrade();
            std::cout << *clerk2 << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cerr << *clerk2 << "Exception caught: " << e.what() << std::endl;
    }
    if (clerk1)
        delete clerk1;
    if (clerk2)
        delete clerk2;
    if (clerk3)
        delete clerk3;
    return 0;
}