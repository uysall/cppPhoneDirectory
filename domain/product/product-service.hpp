#ifndef PRODUCT_SERVICE_HPP
#define PRODUCT_SERVICE_HPP

#include "product-repository.hpp"
#include "product.hpp"
#include <pqxx/pqxx>



namespace  ProductService {

    inline void addProduct(const Product& categoryId, pqxx::connection& conn) {
        ProductRepository::addProduct(categoryId, conn);
    }
    inline std::vector<Product> listProduct(const Product& product,  pqxx::connection& conn) {
        return ProductRepository::listProduct(product, conn);
    }
    inline void removeProduct(const int& id, pqxx::connection& conn) {
        ProductRepository::removeProduct(id, conn);
    }
    inline void updateProduct(const std::string& name, std::string& categoryId, std::string categoryName, pqxx::connection& conn) {
        ProductRepository::updateProduct(name,categoryId,categoryName,conn);
    }
}


#endif