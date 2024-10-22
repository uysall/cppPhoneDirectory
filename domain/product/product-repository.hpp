#ifndef PRODUCT_REPOSITORY_HPP
#define PRODUCT_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "product-factory.hpp"
#include "product.hpp"

namespace ProductRepository {

    inline void addProduct(const Product& categoryId, pqxx::connection& conn) {
        pqxx::work txn{conn};
        txn.exec_params("INSERT INTO product (name, categoryId) VALUES ($1, $2)",categoryId);
        txn.commit();
    }

    inline void removeProduct(const int id, pqxx::connection &conn) {
        pqxx::work txn{conn};
        txn.exec_params("DELETE FROM product WHERE id = $1",id);
        txn.commit();
    }

    inline std::vector<Product> listProduct(const Product& product, pqxx::connection& conn) {
        pqxx::work txn(conn);

        const pqxx::result result = txn.exec_params(
            "SELECT p.id, p.categoryId, c.categoryName "
            "FROM product p "
            "LEFT JOIN category c ON p.categoryId = c.id "
            "WHERE p.id = $1",
            product.id);

        return ProductFactory::createFromResult(result);
    }

    inline void updateProduct(const std::string& name, std::string& categoryId,  std::string& categoryName,  pqxx::connection& conn) {
        pqxx::work txn{conn};
        txn.exec_params("UPDATE product SET name = $1, categoryId = $2 WHERE id = $3",
        name, categoryId, categoryName  );
        txn.commit();
    }

}

#endif //PRODUCT_REPOSITORY_HPP
