#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record {
public:
  Record();
  ~Record();
  std::string name;
  std::string number;

//  void setName(const std::string &);
//  std::string getName(void) const;
//  void setNumber(const std::string &);
//  std::string getNumber(void) const;
};

#endif // RECORD_H
