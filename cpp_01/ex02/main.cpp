#include <iostream>
#include <string>

int main(void)
{
    std::string str = "\"HI THIS IS BRAIN\"";
    std::cout << std::endl << "Created string " << str << std::endl;
    std::cout << std::endl;
    std::string *stringPtr;
    stringPtr = &str;
    std::string &stringRef = str;
    std::cout << "address of the string in memory:          " << &str << std::endl;
    std::cout << "address of the string by using stringPtr: " << stringPtr << std::endl;
    std::cout << "address of the string by using stringRef: " << &stringRef << std::endl;
    std::cout << std::endl;
    std::cout << "Print string using the pointer:   " << *stringPtr << std::endl;
    std::cout << "Print string using the reference: " << stringRef << std::endl;

    return 0;
}