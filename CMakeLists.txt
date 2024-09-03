cmake_minimum_required(VERSION 3.29)
project(cppPhoneDirection)

set(CMAKE_CXX_STANDARD 20)

find_package(libpqxx CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        user.hpp
        colors.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        libpqxx::pqxx
)
