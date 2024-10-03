    #ifndef USER_HPP
    #define USER_HPP

    #include <string>

    class User {

    public:
    //parametreler alt alta

        std::string name;
        std::string surname;
        std::string email;
        std::string phoneNumber;
        int id{};

        User() = default;

        User(std::string name, std::string surname, std::string email, std::string phoneNumber)
            : name(std::move(name)), surname(std::move(surname)), email(std::move(email)),
              phoneNumber(std::move(phoneNumber)) {}

    };


    #endif //USER_HPP
