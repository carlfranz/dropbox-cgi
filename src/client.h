

#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

#include <jsoncpp/json/json.h>

#include <sstream>

#include <random>
#include <algorithm>

bool check_file();

void rename_file();

std::list<std::string> parse_response(std::string &response);


std::string random_string(size_t length);
