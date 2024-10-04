#ifndef DTO_ASSEMBLER_HPP
#define DTO_ASSEMBLER_HPP
#include <nlohmann/json.hpp>

namespace DtoAssembler {
    inline crow::json::wvalue generateGetList(const std::vector<User>& userList) {
        nlohmann::json jsonUsers = nlohmann::json::array();

        for (const User& user: userList) {
            nlohmann::json userJson;
            userJson["id"] = user.id;
            userJson["name"] = user.name;
            userJson["surname"] = user.surname;
            userJson["email"] = user.email;
            userJson["phoneNumber"] = user.phoneNumber;

            jsonUsers.push_back(userJson);
        }

        return jsonUsers;
    }

    inline nlohmann::json generateGetUser(const User &user) {
        nlohmann::json jsonUser;
        jsonUser["id"] = user.id;
        jsonUser["name"] = user.name;
        jsonUser["surname"] = user.surname;
        jsonUser["email"] = user.email;
        jsonUser["phoneNumber"] = user.phoneNumber;
        return jsonUser;
    }

    crow::json::wvalue generateGetList(crow::json::wvalue(* user_list)(pqxx::connection &));
}

#endif //DTO_ASSEMBLER_HPP
