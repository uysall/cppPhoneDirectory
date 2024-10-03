#include "crow.h"
#include <nlohmann/json.hpp>
#include "application/application-user-service.hpp"
#include <pqxx/pqxx>
//düz response veriyorum json tipinde response etmem gerek.
// nesnemi crow json tipinde istiyor
int main() {
    crow::SimpleApp app;

    pqxx::connection conn("dbname=direction user=Ömer password=Ou131973 host=127.0.0.1 port=5432");

    CROW_ROUTE(app, "/list_users").methods(crow::HTTPMethod::GET)([&conn]() {
        const auto user = UserApplicationService::userList(conn);
        crow::json::wvalue users_json;
        users_json["User"] = crow::json::wvalue::list();
        return UserApplicationService::userList( conn);
    });

    CROW_ROUTE(app, "/add_users").methods(crow::HTTPMethod::POST)
([&conn](const crow::request& req) {
    try {
        nlohmann::json body = nlohmann::json::parse(req.body);

        UserApplicationService::addUser(
            body["name"].get<std::string>(),
            body["surname"].get<std::string>(),
            body["email"].get<std::string>(),
            body["phoneNumber"].get<std::string>(),
            conn
        );

        return crow::response(201, "User added successfully");
    } catch (...) {
        return crow::response(400, "Invalid user data");
    }
});
    CROW_ROUTE(app, "/remove_user/<int>").methods(crow::HTTPMethod::DELETE)
  ([&conn](const int id) {
      try {
          UserApplicationService::removeUserById(id, conn);
          crow::json::wvalue response;
          response["message"] = "User removed successfully";
          return crow::response(200, response);
      } catch (...) {
          crow::json::wvalue error;
          error["error"] = "User not found";
          return crow::response(404, error);
      }
  });

    CROW_ROUTE(app, "/updated_user/<int>").methods(crow::HTTPMethod::PUT)
   ([&conn](const crow::request& req, const int id) {
       try {
           nlohmann::json body = nlohmann::json::parse(req.body);
           UserApplicationService::updateUser(
               id,
               body["name"].get<std::string>(),
               body["surname"].get<std::string>(),
               body["email"].get<std::string>(),
               body["phoneNumber"].get<std::string>(),
               conn
           );

           crow::json::wvalue response;
           response["message"] = "User updated successfully";
           return crow::response(200, response);
       } catch (...) {
           crow::json::wvalue error;
           error["error"] = "Invalid user data";
           return crow::response(400, error);
       }
   });

    CROW_ROUTE(app, "/get_user/<int>").methods(crow::HTTPMethod::GET)
([&conn](const int id) {
    try {
        const User user = UserApplicationService::getUserById(id, conn);
        crow::json::wvalue response;
        return crow::response(200, response);
    } catch (...) {
        crow::json::wvalue error;
        error["error"] = "User not found";
        return crow::response(404, error);
    }
});


    app.port(18081).multithreaded().run();

    return 0;
}
