#ifndef PRODUCT_REPOSITORY_HPP
#define PRODUCT_REPOSITORY_HPP

#include <pqxx/pqxx>
#include "product.hpp"
#include "product-factory.hpp"

namespace ProductRepository {

    inline void addProduct(const Product &product, pqxx::connection &conn) {
        pqxx::work txn{conn};
        txn.exec_params("INSERT INTO products (id, name, productID) VALUES ($1, $2, $3)",
                        product.id, product.name, product.productId);
        txn.commit();
    }

    inline void removeProduct(const Product &product, pqxx::connection &conn) {
        pqxx::work txn{conn};
        txn.exec_params("DELETE FROM products WHERE id = $1", product.id);
        txn.commit();
    }

    inline std::vector<Product> listProducts(pqxx::connection& db_connection) {
        pqxx::nontransaction nt(db_connection);
        const pqxx::result result = nt.exec("SELECT id, name, price, quantity FROM products");

        return ProductFactory::create(result);
    }

    inline void updateProduct(const Product& product, pqxx::connection& conn) {
        pqxx::work txn{conn};
        txn.exec_params("UPDATE products SET name = $1, price = $2, quantity = $3",
                        product.id, product.name, product.productId);
        txn.commit();
    }

}

#endif
