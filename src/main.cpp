#include <iostream>
#include <string>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>

#include <fstream>

#include <cerrno>
#include <cstdlib>
#include <random>

#include <sstream>

#include "client.h"

using namespace std;
using namespace cgicc;


int main() {
  Cgicc formData;
  const CgiEnvironment &env = formData.getEnvironment();

  std::string method = env.getRequestMethod();
  if (method == "GET") {
    cout << "Content-type: text/plain" << endl;
    cout << "X-Content-Type-Options: nosniff" << endl << endl;

    std::cout << method << std::endl;

    form_iterator fi = formData.getElement("challenge");
    if (!fi->isEmpty() && fi != (*formData).end()) {
      cout << **fi;
    }
  } else {
    cout << "Content-type: text/plain" << endl << endl;
    ofstream myfile;
    myfile.open("/tmp/output_cgi.log", std::ofstream::out | std::ofstream::app);
    myfile << "DATA:" << env.getPostData() << std::endl;
    myfile.close();
    std::cout << "You made a post";
    curlpp::Cleanup cleaner;

    bool res = check_file();
    std::cout << res << std::endl;
    if (res) {
      rename_file();
    }
  }
}
