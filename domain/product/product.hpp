#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <utility>

class Product {
public:
    int id{};
    std::string name;
    std::string productId;

    Product() = default;

    Product(const int& id, std::string& name, std::string& productId)
        : id(id), name(std::move(name)), productId(std::move(productId)) {}
};

#endif // PRODUCT_HPP
