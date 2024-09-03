#include "user.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <pqxx/pqxx>
#include <iomanip>

//detalar kısmı eklenecek

void addUser(pqxx::connection &conn) {
    std::vector<User> users;
    int numberOfUsers;

    while (true) {
        std::cout << "How many users do you want to add? ";
        std::cin >> numberOfUsers;

        if (std::cin.fail() || numberOfUsers <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << RED << "Invalid number of users. Please enter a positive integer." << RESET << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    for (int i = 0; i < numberOfUsers; i++) {
        std::string name, surname, email, phoneNumber;

        std::cout << "User " << i + 1 << " - Enter the information:" << std::endl;

        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Surname: ";
        std::getline(std::cin, surname);

        std::cout << "Email: ";
        std::getline(std::cin, email);

        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber);

        users.emplace_back(name, surname, email, phoneNumber);
    }

    pqxx::nontransaction exec(conn);

    for (const auto &user : users) {
        std::string query = "INSERT INTO direction.direction_table(name, surname, email, phonenumber) VALUES ($1, $2, $3, $4);";
        exec.exec_params(query, user.name, user.surname, user.email, user.phoneNumber);
    }

    std::cout << GREEN << "Users have been successfully added to the database!" << RESET << std::endl;
}

void removeUser(pqxx::connection &conn) {
    pqxx::nontransaction exec(conn);
    std::string query = "SELECT name, surname, email, phonenumber FROM direction.direction_table;";
    pqxx::result res = exec.exec(query);

    std::cout << "\nSelect the user to remove:\n";
    int index = 1;
    for (const auto &row : res) {
        std::cout << index++ << ") "
                  << BLUE << std::setw(15) << std::left << row["name"].c_str()
                  << YELLOW << std::setw(12) << std::left << row["surname"].c_str()
                  << GREEN << std::setw(30) << std::left << row["email"].c_str()
                  << RED << std::setw(15) << std::left << row["phonenumber"].c_str() << RESET << std::endl;
    }

    int userChoice;
    while (true) {
        std::cout << "Enter the number of the user to remove: ";
        std::cin >> userChoice;

        if (std::cin.fail() || userChoice <= 0 || userChoice > res.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << RED << "Invalid choice. Please select a valid user number." << RESET << std::endl;
        } else {
            break;
        }
    }

    std::string phoneNumber = res[userChoice - 1]["phonenumber"].c_str();

    const std::string deleteQuery = "DELETE FROM direction.direction_table WHERE phonenumber = $1;";
    const pqxx::result deleteRes = exec.exec_params(deleteQuery, phoneNumber);

    if (deleteRes.affected_rows() > 0) {
        std::cout << GREEN << "User has been successfully removed from the database!" << RESET << std::endl;
    } else {
        std::cerr << RED << "No user found with the given phone number." << RESET << std::endl;
    }
}

void listUsers(pqxx::connection &conn) {
    pqxx::nontransaction exec(conn);
    std::string query = "SELECT name, surname, email, phonenumber FROM direction.direction_table;";
    pqxx::result res = exec.exec(query);

    std::cout << "\nResults:\n";
    std::cout << std::left
              << BLUE << std::setw(5) << "No."
              << BLUE << std::setw(15) << "Name"
              << YELLOW << std::setw(12) << "Surname"
              << GREEN << std::setw(30) << "Email"
              << RED << std::setw(15) << "Phone Number" << RESET << std::endl;

    int index = 1;
    for (const auto &row : res) {
        std::cout << BLUE << std::setw(1) << std::left << index++ << ")   "
                  << BLUE << std::setw(15) << std::left << row["name"].c_str()
                  << YELLOW << std::setw(12) << std::left << row["surname"].c_str()
                  << GREEN << std::setw(30) << std::left << row["email"].c_str()
                  << RED << std::setw(15) << std::left << row["phonenumber"].c_str() << RESET << std::endl;
    }
}

int main() {
    try {
        pqxx::connection conn("dbname=direction user=Ömer password=Ou131973 host=127.0.0.1 port=5432");

        if (!conn.is_open()) {
            std::cerr << RED << "Can't open database" << RESET << std::endl;
            return 1;
        }

        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add User\n";
            std::cout << "2. Remove User\n";
            std::cout << "3. List Users\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    addUser(conn);
                    break;
                case 2:
                    removeUser(conn);
                    break;
                case 3:
                    listUsers(conn);
                    break;
                case 4:
                    std::cout << "Exit" << std::endl;
                    break;
                default:
                    std::cerr << RED << "Invalid choice. Please try again." << RESET << std::endl;
            }
        } while (choice != 4);

    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
