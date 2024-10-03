#ifndef USER_FACTORY_HPP
#define USER_FACTORY_HPP

#include <pqxx/pqxx>
#include <vector>


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

    inline std::vector<User> generateListFromDb(const pqxx::result& res)
    {
        std::vector<User> users;
        users.reserve(res.size());
        for (const auto  &row : res) {

            users.emplace_back(generateFromDb(row));
        }

        return users;
    }
};

#endif
