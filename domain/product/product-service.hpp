//
// Created by omer on 10/15/24.
//

#ifndef PRODUCT_SERVICE_HPP
#define PRODUCT_SERVICE_HPP
#include "product-repository.hpp"
#include "product.hpp"
#include <pqxx/pqxx>

#include
#include
#include
#include
#include
#include

namespace ProductService {

    inline void addProduct(const int &id, std::string &name, std::string &productId, pqxx::connection &conn) {
        const Product product{id, name, productId};
        ProductRepository::addProduct(product, conn);
    }
    inline std::vector<Product> listProducts(pqxx::connection& conn) {
        return ProductRepository::listProducts(conn);
    }
    inline void deleteProduct(const Product& id, pqxx::connection& txn) {
        ProductRepository::removeProduct(id, txn);
    }
    inline void updateProduct(const int id, std::string &name, std::string &productId, pqxx::connection& txn) {
        Product product{id, name, productId};
        product.id = id;
        ProductRepository::updateProduct(product, txn);
    }



}
#endif //PRODUCT_SERVICE_HPP
