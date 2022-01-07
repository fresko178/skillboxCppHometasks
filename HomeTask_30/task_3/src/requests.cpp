#include "requests.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string Requests::enter() {
  cout << "введите аргумент: ";
  string arg {""};
  std::getline(cin, arg);

  if (arg == "get" || arg == "post") { return arg; }

  string val {""};
  cout << "введите значение: ";
  std::getline(cin, val);

  argval.push_back(cpr::Pair(arg, val));

  return "";
}

void Requests::get() {
  string url = "http://httpbin.org/get?";
  for (size_t i {0}; i < argval.size(); i++) {
    url += argval[i].key + "=" + argval[i].value;
    if (i + 1 < argval.size ()) { url += "&"; }
  }

  cpr::Response r = cpr::Get(cpr::Url(url));
  cout << r.text << endl << endl;
}

void Requests::post() {
  string arguments = {""};
  for (size_t i {0}; i < argval.size(); i++) {
    arguments += argval[i].key + " " + argval[i].value;
    if (i + 1 < argval.size ()) (arguments += " ");
  }

  cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(argval.begin(), argval.end()));

  cout << r.text << endl << endl;
}
