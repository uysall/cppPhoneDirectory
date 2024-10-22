#ifndef APPLICATION_PRODUCT_SERVICE_HPP
#define APPLICATION_PRODUCT_SERVICE_HPP

#include "../../domain/product/product-service.hpp"
#include "../../domain/product-category/product-category-service.hpp""

namespace ProductApplicationService {
    inline void addProduct(const Product& categoryId, pqxx::connection &conn)
    {
        ProductService::addProduct(categoryId, conn);
    }
    inline void addProductCategory(const ProductCategory& product, pqxx::connection &conn)
    {
        ProductCategoryService::addProductCategory(product, conn);
    }
    inline void removeProduct(const int& id, pqxx::connection &conn)
    {
        ProductService::removeProduct(id,conn );
    }
    inline void deleteProductCategory(const ProductCategory& id, pqxx::connection &conn)
    {
        ProductCategoryService::deleteProductCategory(id,conn );
    }
    inline std::vector<Product> listProduct(const Product& product, pqxx::connection& conn)
    {
        return ProductService::listProduct(product,conn);
    }
    inline ProductCategory listProductCategory(const int &id, pqxx::connection &conn)
    {
        return ProductCategoryService::listProductCategory(id,conn);
    }
    inline void updateProduct(const std::string &name, std::string& categoryId, const std::string &categoryName, pqxx::connection &conn)
    {
        ProductService::updateProduct(name, categoryId, categoryName, conn);
    }
    inline void updateProductCategory(const ProductCategory& productCategory, pqxx::connection &conn)
    {
        ProductCategoryService::updateProductCategory(productCategory, conn);
    }
}

#endif //APPLICATION_PRODUCT_SERVICE_HPP
