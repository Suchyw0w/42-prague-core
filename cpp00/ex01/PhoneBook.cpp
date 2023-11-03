#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->numberOfContacts = 0;
}

PhoneBook::~PhoneBook() {};

void    PhoneBook::addContact() {
    Contact contact;

    contact.addFirstname();
    contact.addLastname();
    contact.addNickname();
    contact.addPhone();
    contact.addSecret();
    if (this->numberOfContacts == 8)
        this->_contacts[7] = contact;
    else
        this->_contacts[this->numberOfContacts] = contact;
    if (this->numberOfContacts < 8)
        this->numberOfContacts++;
}

void PhoneBook::searchContact() const
{
    this->displayAll();

    std::string			prompt;
    std::stringstream	str_stream;
    int num;

    std::cout << "index:\n";
    std::getline(std::cin, prompt);
    str_stream << prompt;

    if (prompt.length() != 1 || prompt[0] < '0' || prompt[0] > '8')
    {
        std::cout << "Invalid Index\n";
        return ;
    }

    str_stream >> num;

    for(int i = 0; i < 8; i++)
    {
        if (i >= this->numberOfContacts)
        {
            std::cout << "Index not found\n";
            break ;
        }
        if (num == i)
        {
            this->displayContact(this->_contacts[i]);
            break ;
        }
    }

}

std::string PhoneBook::formatOutput(std::string output) const
{
    std::string formatted;

    if (output.length() > 10)
    {
        formatted = output.substr(0, 10);
        formatted[9] = '.';
        return (formatted);
    }
    return (output);
}

void PhoneBook::displayAll() const {
    std::cout << std::setfill(' ') << std::setw(10) << "Index";
    std::cout << '|' << std::setfill(' ') << std::setw(10) << "First name";
    std::cout << '|' << std::setfill(' ') << std::setw(10) << "Last name";
    std::cout << '|' << std::setfill(' ') << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < this->numberOfContacts; i++)
    {
        if (i >= this->numberOfContacts)
            break ;
        std::cout << std::right << std::setfill(' ') << std::setw(10) << i;
        std::cout << std::right << '|' << std::setfill(' ') << std::setw(10) << formatOutput(this->_contacts[i].getFirstname());
        std::cout << std::right << '|' << std::setfill(' ') << std::setw(10) << formatOutput(this->_contacts[i].getLastname());
        std::cout << std::right << '|' << std::setfill(' ') << std::setw(10) << formatOutput(this->_contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(Contact contact) const {
    std::cout << "Firstname: " << contact.getFirstname() << std::endl;
    std::cout << "Lastname: " << contact.getLastname() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone: " << contact.getPhone() << std::endl;
    std::cout << "Secret: " << contact.getSecret() << std::endl;
}