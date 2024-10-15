#ifndef DOMAIN_SERVICE_HPP
#define DOMAIN_SERVICE_HPP

#include "product-repository.hpp"
#include "product.hpp"

namespace ProductFactory {
    inline Product create(const int& id, std::string& name, std::string& productId) {
        return Product{id, name, productId};
    }
    inline std::vector<Product> createFromResult(const pqxx::result& result) {
        std::vector<Product> productList;

        for(const auto& row : result) {
            Product product;
            product.id = row[0].as<int>();
            product.name = row[1].as<std::string>();
            product.productId = row[2].as<std::string>();
            productList.push_back(product);
        }
        return  productList;
    }
}




#endif