#include "phonebook.hpp"

int main()
{
    Phonebook       phonebook;
    std::string     buff;

    while (1)
    {
        std::cout << "Input a command: ";
        std::cin >> buff;
        if (buff == "EXIT" || std::cin.eof())
            phonebook.exitPhonebook();
        else if (buff == "ADD")
            phonebook.addContact();
        else if (buff == "SEARCH")
            phonebook.searchContact();
    }
    return 0;
}