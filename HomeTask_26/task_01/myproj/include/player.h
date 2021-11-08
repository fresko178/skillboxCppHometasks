#pragma once
#include <vector>
#include "track.h"

class Player {
  using PlayList = std::vector<Track>;
  PlayList playList;
  size_t sizePlayList;

public:
  Player(size_t);
  ~Player();
  size_t getSizePlayList() const;
  void addSongToPlayList(const Track &track);
  void showPlayList();
  void createPlayList(const size_t);
  Track findSong(const std::string &);
  void pause(Track &);
  void showSong(Track &);
  Track nextSong();

};
