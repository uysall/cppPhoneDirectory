#ifndef USER_FACTORY_HPP
#define USER_FACTORY_HPP

#include <pqxx/pqxx>

using namespace std;
    namespace UserFactory {

    inline User generateForDb(const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber)
    {
        return User{
            name,
            surname,
            email,
            phoneNumber
        };
    }
    inline User generateFromDb(const pqxx::row& row)
    {
        User user = User{
            row[1].as<string>(),
            row[2].as<string>(),
            row[3].as<string>(),
            row[4].as<string>()
        };

        user.id = row[0].as<int>();
        return user;
    }

        inline auto generateListFromDb(const pqxx::result &res) {
        std::vector<User> users;
        for (const auto &row : res) {
            users.emplace_back(
                row[1].as<std::string>(),
                row[2].as<std::string>(),
                row[3].as<std::string>(),
                row[4].as<std::string>()
            );
        }
        return users;
    }
};

#endif
