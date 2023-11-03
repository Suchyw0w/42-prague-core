#include "PhoneBook.hpp"
#include <iostream>
#include <cstdio>

int main() {
    std::string input;
    PhoneBook   phoneBook;

    while(1) {
        std::cout << "Enter command:" << std::endl;
        std::getline(std::cin, input);
        if(input.compare("ADD") == 0)
            phoneBook.addContact();
        else if (input.compare("SEARCH") == 0)
            phoneBook.searchContact();
        else if (input.compare("EXIT") == 0)
            break;
        while ((getchar()) != '\n');
    }
    return 0;
};