#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <utility>

struct User {
    std::string name, surname, email, phoneNumber;

    User(std::string name, std::string surname, std::string email, std::string phoneNumber)
        : name(std::move(name)), surname(std::move(surname)), email(std::move(email)), phoneNumber(std::move(phoneNumber)) {
    }
};
#endif