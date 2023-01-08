#include "Karen.hpp"

int main(int argc, char **argv)
{
    Karen   Karen;

    if (argc != 2)
    {
        std::cout << "There should be two arguments!" << std::endl;
        return 1;
    }
    int value;
    std::string level = argv[1];
    if (level == "DEBUG")
        value = DEBUG;
    if (level == "INFO")
        value = INFO;
    if (level == "WARNING")
        value = WARNING;
    if (level == "ERROR")
        value = ERROR;
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
        value = UB;
    switch (value)
    {
    case 0:
        Karen.complain("DEBUG");
    case 1:
        Karen.complain("INFO");
    case 2:
        Karen.complain("WARNING");
    case 3:
        Karen.complain("ERROR");
        break ;
    default:
        if (value == 4)
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}