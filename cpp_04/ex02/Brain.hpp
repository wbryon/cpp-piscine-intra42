#pragma once

# include <iostream>

class Brain {
public:
	Brain();
	Brain( std::string const idea );
	Brain( Brain const & other );
	virtual ~Brain();
	Brain & operator=( Brain const & other );

	std::string* getIdea();
	void setIdea( std::string const idea );

private:
	std::string _idea[100];
};