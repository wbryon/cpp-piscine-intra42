#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class    Contact
{
public:

    Contact(void);
    ~Contact(void);
    void            setFirstName(std::string);
    void            printFirstName(int);
    std::string     getFirstName(void) const;

    void            setLastName(std::string);
    void            printLastName(int);
    std::string     getLastName(void) const;

    void            setNickname(std::string);
    void            printNickname(int);
    std::string     getNickname(void) const;

    void            setPhoneNumber(std::string);
    void            printPhoneNumber(void) const;
    std::string     getPhoneNumber(void) const;
    
    void            setDarkestSecret(std::string);
    void            printDarkestSecret(void) const;
    std::string     getDarkestSecret(void) const;

private:

    std::string     _firstName;
    std::string     _lastName;
    std::string     _nickname;
    std::string     _phoneNumber;
    std::string     _darkestSecret;
};

#endif