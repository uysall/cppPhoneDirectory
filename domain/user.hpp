    #ifndef USER_HPP
    #define USER_HPP

    #include <string>

    class User {

    public:
    //parametreler alt alta
        int id{};
        std::string name;
        std::string surname;
        std::string email;
        std::string phoneNumber;

        [[nodiscard]] int getId() const { return id; };
        [[nodiscard]] std::string getname() const { return name; }
        [[nodiscard]] std::string getsurname() const { return surname; }
        [[nodiscard]] std::string get_email() const { return email; }
        [[nodiscard]] std::string get_phoneNumber() const { return phoneNumber; };

        User() = default;

        User(std::string name, std::string surname, std::string email, std::string phoneNumber)
            : name(std::move(name)), surname(std::move(surname)), email(std::move(email)),
              phoneNumber(std::move(phoneNumber)) {}

    };


    #endif //USER_HPP
