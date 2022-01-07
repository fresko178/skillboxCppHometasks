#ifndef REQUESTS_H
#define REQUESTS_H

#include <cpr/cpr.h>

static std::vector<cpr::Pair> argval;

class Requests {
public:
  std::string enter();
  void get();
  void post();
};

#endif // REQUESTS_H
