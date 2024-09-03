#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <pqxx/pqxx>
#include <iomanip>

#include "colors.hpp"




struct User {
    std::string name, surname, email, phoneNumber;

    User(std::string name, std::string surname, std::string email, std::string phoneNumber)
        : name(std::move(name)), surname(std::move(surname)), email(std::move(email)), phoneNumber(std::move(phoneNumber)) {}

    void print() const {
        std::cout << BLUE << std::setw(15) << std::left << name
                  << YELLOW << std::setw(12) << std::left << surname
                  << GREEN << std::setw(20) << std::left << email
                  << RED << std::setw(15) << std::left << phoneNumber << RESET << std::endl;
    }
};

#endif // USER_HPP
