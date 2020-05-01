cmake_minimum_required(VERSION 3.5)

project(main.cgi)

add_executable(main.cgi main.cpp)

set(CMAKE_CXX_STANDARD 11)

target_link_libraries(main.cgi PUBLIC jsoncpp -gicc curlpp curl)

add_compile_options(-Wall -Wextra -Wpedantic)