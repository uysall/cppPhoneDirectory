#ifndef USER_SERVICE_HPP
#define USER_SERVICE_HPP

#include "user.hpp"
#include "user-repository.hpp"
#include "user-factory.hpp"
#include <pqxx/pqxx>

namespace UserService {
    inline void addUser(const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, pqxx::connection& conn)
    {
        const User user = UserFactory::generateForDb(name, surname, email, phoneNumber);
        UserRepository::addUser(user, conn);
    }

    inline User getUserById(const int id, pqxx::connection &conn)
    {
        return UserRepository::getUserById(conn);
    }

    inline void removeUserById(const int id, pqxx::connection &conn)
    {
        UserRepository::removeUserById(id, conn);
    }

    inline std::vector<User> userList(pqxx::connection &conn)
    {
        return UserRepository::userList(conn);
    }

    inline void updateUser(const int& id, const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, pqxx::connection &conn)
    {
        User user = UserRepository::getUserById(conn);
        user.name = name;
        user.surname = surname;
        user.email = email;
        user.phoneNumber = phoneNumber;

        UserRepository::updateUser(user, conn);
    }
}

#endif