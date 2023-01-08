#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
public:

    Phonebook(void);
    ~Phonebook(void);

    void    addContact(void);
    void    searchContact(void);
    void    exitPhonebook(void);
    
    void    printPhonebook(void);
    void    printContact(void);
    void    display(std::string);
    void    createContact(int);

private:

    std::string _input;
    int         _index;
    int         _size;
    int         _oldest_index;
    int         _position;
    Contact     _contact[8];

};

#endif