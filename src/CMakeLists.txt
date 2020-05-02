
add_executable(main.cgi main.cpp)

target_link_libraries(main.cgi PUBLIC jsoncpp cgicc curlpp curl)

add_compile_options(-Wall -Wextra -Wpedantic)
