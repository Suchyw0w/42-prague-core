#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    void    addContact();
    void    searchContact() const;
    void search(void) const;
    void    displayAll() const;
    void    displayContact(Contact contact) const;
    std::string formatOutput(std::string string) const;
private:
    Contact _contacts[8];
    int numberOfContacts;
};

#endif //CPP_PHONEBOOK_HPP
