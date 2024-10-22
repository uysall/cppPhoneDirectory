#ifndef PRODUCT_FACTORY_HPP
#define PRODUCT_FACTORY_HPP

#include "product.hpp"
#include <string>
#include <vector>
#include <pqxx/pqxx>


namespace ProductFactory {
    inline Product create(const int& id, const std::string& name, const std::string& categoryId) {
        return Product{id, name, categoryId };
    }

    inline std::vector<Product> createFromResult(const pqxx::result& rows) {
        std::vector<Product> productList;

        for(const auto& row : rows) {
            Product product;
            product.id = row[0].as<int>();
            product.name = row[1].as<std::string>();
            product.categoryId = row[2].as<std::string>();
            product.categoryName = row[3].as<std::string>();
            productList.push_back(product);
        }
        return  productList;
    }
}

#endif //PRODUCT_FACTORY_HPP
