#include <iostream>
#include <cpr/cpr.h>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
//  cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html")); // результат тотже самый как и строчка ниже
  cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                             cpr::Header({{"accept", "text/html"}}));
  size_t start = r.text.find("<h1>") + 4; // +4 перешагиваем через тег
  size_t end = r.text.find("</h1>");
  cout << r.text.substr(start, end - start) << endl << endl;

  return 0;
}

