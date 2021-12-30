#include <iostream>
#include <cpr/cpr.h>

using std::cout;
using std::cin;
using std::endl;

void get();
void post();
void put();
void del();
void patch();

int main() {

  std::string command {""};
  while (command != "ext") { // так в задании (не exit)
    cout << "Введите команду: ";
    cin >> command;
    if (command == "get") { get(); }
    else  if (command == "post") { post(); }
    else  if (command == "put") { put(); }
    else  if (command == "delete") { del(); }
    else  if (command == "patch") { patch(); }
  }

  return 0;
}

void get() {
  cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
  cout << r.text << endl;
}

void post() {
  cpr::Response r =  cpr::Post(cpr::Url("http://httpbin.org/post"),
    cpr::Payload ( {
                     {"name", "gordon freeman"},
                     {"city", "city_17"}
                   } ));
  cout << r.text << endl;
}

void put() {
  cpr::Response r =  cpr::Put(cpr::Url("http://httpbin.org/put"),
    cpr::Payload ( {
                     {"data", "01.01.1970"},
                   } ));
  cout << r.text << endl;
}

void del() {
  cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
  cout << r.text << endl;
}

void patch() {
  cpr::Response r =  cpr::Patch(cpr::Url("http://httpbin.org/patch"),
    cpr::Payload ( {
                     {"data", "11.11.2000"},
                   } ));
  cout << r.text << endl;
}

