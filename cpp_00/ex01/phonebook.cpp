#include "phonebook.hpp"

Phonebook::Phonebook(void) : _size(0), _oldest_index(0)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void    Phonebook::printContact(void)
{
	std::cout << "First name: ";
	_contact[_index].printFirstName(0);
	std::cout << std::endl;
	std::cout << "Last name: ";
	_contact[_index].printLastName(0);
	std::cout << std::endl;
	std::cout << "Nickname: ";
	_contact[_index].printNickname(0);
	std::cout << std::endl;
	std::cout << "Phone number: ";
	_contact[_index].printPhoneNumber();
	std::cout << std::endl;
	std::cout << "Darkest secret: ";
	_contact[_index].printDarkestSecret();
	std::cout << std::endl;
	return ;
}

void	Phonebook::printPhonebook(void)
{
	_position = 0;
	std::cout << "|";
	display("Index");
	display("First name");
    display("Last name");
    display("Nickname");
	std::cout << std::endl;
	while (_position < _size)
	{
		std::cout << "|" << std::setw(10);
		std::cout << _position;
		std::cout << "|" << std::setw(10);
		_contact[_position].printFirstName(1);
		std::cout << "|" << std::setw(10);
		_contact[_position].printLastName(1);
		std::cout << "|" << std::setw(10);
		_contact[_position].printNickname(1);
		std::cout << "|" << std::endl;
		_position++;
	}
	return ;
}

void	Phonebook::addContact(void)
{
	if (_size < 8)
	{
		createContact(_size);
		_size++;
	}
	else
	{
		createContact(_oldest_index);
		if (_oldest_index < 7)
			_oldest_index++;
		else
			_oldest_index = 0;
	}
}

void	Phonebook::createContact(int index)
{
	std::cout << "First name: ";
	std::cin >> _input;
	_contact[index].setFirstName(_input);
	std::cout << "Last name: ";
	std::cin >> _input;
	_contact[index].setLastName(_input);
	std::cout << "Nickname: ";
	std::cin >> _input;
	_contact[index].setNickname(_input);
	std::cout << "Phone number: ";
	std::cin >> _input;
	_contact[index].setPhoneNumber(_input);
	std::cout << "Darkest secret: ";
	std::cin >> _input;
	_contact[index].setDarkestSecret(_input);
	return ;
}

void	Phonebook::exitPhonebook(void)
{
	std::exit(EXIT_SUCCESS);
	return ;
}

void	Phonebook::searchContact(void)
{
	printPhonebook();
	std::cout << "Enter index: ";
	std::cin >> _index;
	if (_index >= 0 && _index <= 7)
		printContact();
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wrong input" << std::endl;
	}
}

void	Phonebook::display(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
    std::cout << "|";
}