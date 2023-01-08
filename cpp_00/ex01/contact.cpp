#include "contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void    Contact::setFirstName(std::string str)
{
    _firstName = str;
    return ;
}

std::string Contact::getFirstName(void) const
{
    return _firstName;
}

void    Contact::printFirstName(int trimmed)
{
    if (trimmed && _firstName.size() > 10)
        std::cout << _firstName.substr(0, 9) + '.';
    else if (_firstName.size())
        std::cout << _firstName;
    return ;
}

void    Contact::setLastName(std::string str)
{
    _lastName = str;
    return ;
}

std::string Contact::getLastName(void) const
{
    return _lastName;
}

void    Contact::printLastName(int name)
{
    if (name && _lastName.size() > 10)
        std::cout << _lastName.substr(0, 9) + '.';
    else if (_lastName.size())
        std::cout << _lastName;
    return ;
}

void    Contact::setNickname(std::string str)
{
    this->_nickname = str;
    return ;
}

std::string Contact::getNickname(void) const
{
    return _nickname;
}

void    Contact::printNickname(int name)
{
    if (name && _nickname.size() > 10)
        std::cout << _nickname.substr(0, 9) + '.';
    else if (_nickname.size())
        std::cout << _nickname;
    return ;
}

void    Contact::setPhoneNumber(std::string str)
{
    _phoneNumber = str;
    return ;
}

std::string Contact::getPhoneNumber(void) const
{
    return _phoneNumber;
}

void    Contact::printPhoneNumber(void) const
{
    if (_phoneNumber.size())
        std::cout << _phoneNumber;
    return ;
}

void    Contact::setDarkestSecret(std::string str)
{
    _darkestSecret = str;
    return ;
}

std::string Contact::getDarkestSecret(void) const
{
    return _darkestSecret;
}

void    Contact::printDarkestSecret(void) const
{
    if (_darkestSecret.size())
        std::cout << _darkestSecret;
    return ;
}