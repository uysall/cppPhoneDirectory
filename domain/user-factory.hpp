#ifndef USER_FACTORY_HPP
#define USER_FACTORY_HPP

#include <pqxx/pqxx>
#include <vector>

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
            row[1].as<std::string>(),
            row[2].as<std::string>(),
            row[3].as<std::string>(),
            row[4].as<std::string>()
        };

        user.id = row[0].as<int>();

        return user;
    }

    inline crow::json::wvalue generateListFromDb(const pqxx::result& res) {
        crow::json::wvalue users;
        for (const auto  &row : res) {
            users[row[0].as<int>()] = {
                {"name", row[1].as<string>()},
                {"surname", row[2].as<string>()},
                {"phone_number", row[3].as<string>()},
                {"email", row[4].as<string>()},
                {"notes", row[5].as<string>()}

            };
        }
        return users;
    }
};

#endif
