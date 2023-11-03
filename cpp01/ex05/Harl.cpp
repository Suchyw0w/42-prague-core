#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	printMsg(std::string msg)
{
    std::cout << std::endl  << "+" << std::string(20, '=') << "+";
    std::cout<< "..." << msg << "...";
    std::cout << "+" << std::string(20, '=') << "+" << std::endl;
}

void Harl::debug(void)
{
    printMsg("DEBUG");
    std::cout << "I love having extra bacon for my 7XL-double-cheese-" << std::endl;
    std::cout << "triple-pickle-special- ketchup burger. I really do!";
}

void Harl::info(void)
{
    printMsg("INFO");
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did," << std::endl;
    std::cout << "I wouldn't be asking for more!";
}

void Harl::warning(void)
{
    printMsg("WARNING");
    std::cout << "This is unacceptable! I want to speak to the" << std::endl;
    std::cout << "manager now.";
}

void Harl::error(void)
{
    printMsg("ERROR");
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started" << std::endl;
    std::cout << "working here since last month." << std::endl;
}

void    Harl::complain( std::string level )
{
    void		(Harl::*complainLevels[])(void) =
            {
                    &Harl::debug,
                    &Harl::info,
                    &Harl::warning,
                    &Harl::error
            };

    std::string	complains[4] =
            {
                    "DEBUG",
                    "INFO",
                    "WARNING",
                    "ERROR"
            };

    for (size_t i = 0; i < 4; i++)
    {
        if (level.compare(complains[i]) == 0)
        {
            (this->*complainLevels[i])();
            return ;
        }
    }
    printMsg("WRONG LEVEL");
}