    cmake_minimum_required(VERSION 3.29)
    project(cppPhoneDirectory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

find_package(libpqxx CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/path/to/crow)

add_executable(${PROJECT_NAME}
        main.cpp
        colors.hpp
        application/application-user-service.hpp
        domain/user/user.hpp
        domain/user/user-factory.hpp
        domain/user/user-repository.hpp
        domain/user/user-service.hpp
        application/dto-assembler.hpp
        domain/product/product.hpp
        domain/product/product-service.hpp
        domain/product/product-repository.hpp
        domain/product/product-factory.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        libpqxx::pqxx
        Crow::Crow
)
