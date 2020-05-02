
set(HEADER_FILES client.h)
set(SOURCE_FILES 
	main.cpp
	client.cpp
	)

add_executable(main.cgi ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(main.cgi PUBLIC jsoncpp cgicc curlpp curl)

add_compile_options(-Wall -Wextra -Wpedantic)
