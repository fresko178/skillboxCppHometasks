#include "track.h"

Track::Track() {
  name = "";
  time_t t = time(nullptr);
  date = *localtime(&t);
  duration = 0; // sec
  play = false; // признак воспроизведения
}

Track::~Track() {
}

void Track::setName(const std::string &name) {
  this->name = name;
}

std::string Track::getName() const {
  return name;
}

void Track::setDate(const std::tm &date) {
  this->date = date;
}

std::tm Track::getDate() const {
  return date;
}

void Track::setDuration(const size_t &duration) {
  this->duration = duration;
}

size_t Track::getDuration() const {
  return duration;
}

void Track::setPlay(bool play) {
  this->play = play;
}

bool Track::getPlay() {
  return play;
}
