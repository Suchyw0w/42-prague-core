#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact(){}

void Contact::addFirstname() {
    std::cout << "Enter first name\n";
    std::cin >> this->firstname;
}

void Contact::addLastname() {
    std::cout << "Enter last name\n";
    std::cin >> this->lastname;
}

void Contact::addNickname() {
    std::cout << "Enter nickname\n";
    std::cin >> this->nickname;
}

void Contact::addPhone() {
    std::cout << "Enter phone\n";
    std::cin >> this->phone;
}

void Contact::addSecret() {
    std::cout << "Enter secret\n";
    std::cin >> this->secret;
}

std::string Contact::getFirstname() const { return this->firstname; }
std::string Contact::getLastname() const { return this->lastname; }
std::string Contact::getNickname() const { return this->nickname; }
std::string Contact::getPhone() const { return this->phone; }
std::string Contact::getSecret() const { return this->secret; }