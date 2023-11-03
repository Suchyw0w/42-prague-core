
#ifndef CPP_CONTACT_HPP
#define CPP_CONTACT_HPP

# include <string>
#include <iostream>

class Contact {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone;
    std::string secret;
public:
    Contact();
    Contact(int i);
    ~Contact();
    void    addFirstname();
    void    addLastname();
    void    addNickname();
    void    addPhone();
    void    addSecret();
    int     getIndex();
    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string getPhone() const;
    std::string getSecret() const;
};

#endif //CPP_CONTACT_HPP
