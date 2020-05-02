#include "client.h"

bool check_file() {
  try {

    const char *url = "https://api.dropboxapi.com/2/files/list_folder";
    const std::string token =
        "5m7LXZ_sKCAAAAAAAAACWDemU1NyIcbtrukf73iootUBGBv47L0Qh5PGzVk_Qkpt";

    curlpp::Easy request;

    Json::FastWriter fastWriter;
    Json::Value request_body;
    request_body["path"] = "";
    request_body["limit"] = 1000;

    std::stringstream response;
    std::list<std::string> header;
    header.push_back("Authorization: Bearer " + token);
    header.push_back("Content-Type: application/json");

    const std::string request_body_str = fastWriter.write(request_body);

    request.setOpt(new curlpp::options::Url(url));
    request.setOpt(new curlpp::options::Verbose(true));
    request.setOpt(new curlpp::options::HttpHeader(header));
    request.setOpt(new curlpp::options::PostFields(request_body_str));
    request.setOpt(
        new curlpp::options::PostFieldSize(request_body_str.length()));
    request.setOpt(new curlpp::options::WriteStream(&response));

    request.perform();

    auto response_str = response.str();
    std::list<std::string> files = parse_response(response_str);

    std::string n1 = "miofile.txt";
    auto result1 = std::find(std::begin(files), std::end(files), n1);

    return (result1 != std::end(files));
  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
    throw;
  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
    throw;
  }
}

void rename_file() {
  try {
    const char *url = "https://api.dropboxapi.com/2/files/move_v2";
    const std::string token =
        "5m7LXZ_sKCAAAAAAAAACWDemU1NyIcbtrukf73iootUBGBv47L0Qh5PGzVk_Qkpt";
    std::string new_file = random_string(8);

    curlpp::Easy request;

    Json::Value request_body;
    Json::FastWriter fastWriter;
    request_body["from_path"] = "/miofile.txt";
    request_body["to_path"] = "/" + new_file + ".txt";
    request_body["autorename"] = true;

    std::stringstream response;
    std::list<std::string> header;
    header.push_back("Authorization: Bearer " + token);
    header.push_back("Content-Type: application/json");

    const std::string request_body_str = fastWriter.write(request_body);

    request.setOpt(new curlpp::options::Url(url));
    request.setOpt(new curlpp::options::Verbose(true));
    request.setOpt(new curlpp::options::HttpHeader(header));
    request.setOpt(new curlpp::options::PostFields(request_body_str));
    request.setOpt(
        new curlpp::options::PostFieldSize(request_body_str.length()));

    request.perform();

  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
  }
}

std::list<std::string> parse_response(std::string &response) {

  Json::Value root1;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(response, root1);
  if (!parsingSuccessful) {
    std::cout << "Error parsing the string" << std::endl;
  }
  std::list<std::string> values;
  auto mynames = root1["entries"];
  for (Json::Value::ArrayIndex i = 0; i != mynames.size(); i++) {
    if (mynames[i].isMember("name")) {
      // std::cout << mynames[i]["name"].asString() << std::endl;
      values.push_back(mynames[i]["name"].asString());
    }
  }
  return values;
}



std::string random_string(std::string::size_type length) {
  static auto &chrs = "0123456789"
                      "abcdefghijklmnopqrstuvwxyz"
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  thread_local static std::mt19937 rg{std::random_device{}()};
  thread_local static std::uniform_int_distribution<std::string::size_type>
      pick(0, sizeof(chrs) - 2);

  std::string s;

  s.reserve(length);

  while (length--)
    s += chrs[pick(rg)];

  return s;
}


