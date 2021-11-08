#pragma once
#include <string>
#include <ctime>

class Track {
  std::string name;
  std::tm date;
  size_t duration;
  bool play;

public:
  Track();
  ~Track();
  void setName(const std::string &);
  std::string getName() const;
  void setDate(const std::tm&);
  std::tm getDate() const;
  void setDuration(const size_t &);
  size_t getDuration() const;
  void setPlay(bool);
  bool getPlay();
};
