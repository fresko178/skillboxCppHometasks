#include <iostream>
#include "player.h"

Player::Player(size_t size) {
  sizePlayList = size;
}

Player::~Player() {
}

size_t Player::getSizePlayList() const {
  return sizePlayList;
}

void Player::addSongToPlayList(const Track &track) {
  playList.push_back(track);
};

void Player::showPlayList() {
  if (playList.size() > 0) {
    std::cout << "Список воспроизведения: " << std::endl;
    for (auto i : playList) {
      std::cout << i.getName() << " "
                << i.getDuration() << "(sec)  "
                << i.getDate().tm_mday << "/" << i.getDate().tm_mon
                << "/" << i.getDate().tm_year << std::endl;
    }
  } else {
    std::cout << "Список воспроизведения пуст" << std::endl;
  }
}

void Player::createPlayList(const size_t size) {
  for (int i {0}; i < size; i++) { // заполняем список песен
    Track track = Track();
    track.setName("track" + std::to_string(i + 1));
    std::tm tm = track.getDate(); // объект уже хранит тек. дату
    tm.tm_mday = 10 + i;
    tm.tm_mon = 1 + i;
    tm.tm_year = 2000 + i;
    track.setDate(tm);
    track.setDuration(60 + static_cast<size_t>(i));
    addSongToPlayList(track);
  }
}

Track Player::findSong(const std::string &song) {
  for (auto i : playList) {
    if (i.getName() == song) {
      return i;
    }
  }
  Track track;
  return track;
}

void Player::pause(Track &track) {
  if (track.getPlay() == true) {
    track.setPlay(false); // ставим запись на паузу
    std::cout << track.getName() << " поставлен на паузу" << std::endl;
  }
}

void Player::showSong(Track &track) {
    std::cout << track.getName() << " "
      << track.getDuration() << "(sec)  "
      << track.getDate().tm_mday << "/" << track.getDate().tm_mon
      << "/" << track.getDate().tm_year << std::endl;
    track.setPlay(true);
}

Track Player::nextSong() {
  bool next {false}; // признак, что получили случайную запись
  Track track;
  while (!next) {
    size_t i = static_cast<size_t>(std::rand()) % getSizePlayList() + 1;
    if (playList[i].getPlay() == false) { // выбрали запись не туже самую
      track = playList[i];
      next = true;
    }
  }
  return track;
}




