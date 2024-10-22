#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <nlohmann/json.hpp>

class Product {
public:
    int id{};
    std::string name;
    std::string categoryId;
    std::string categoryName;

    Product() = default;

    Product(const int& id, std::string name, std::string categoryId)
        : id(id), name(std::move(name)), categoryId(std::move(categoryId)),categoryName(std::move(categoryName)) {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Product, id, name, categoryId, categoryName)
};



#endif //PRODUCT_HPP
