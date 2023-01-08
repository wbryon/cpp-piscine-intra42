#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <map>

enum Message
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UB,
};

class Karen {
public:
    Karen();
    ~Karen();
    void    complain( std::string level );
private:
    void    _debug( void );
    void    _info( void );
    void    _warning( void );
    void    _error( void );
};

typedef void (Karen::*funcPtr)(void);

#endif