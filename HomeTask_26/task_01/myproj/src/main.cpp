#include <iostream>
#include "player.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 1. Реализация имитации аудиоплеера" << endl;
  Player player = Player(9);// заполняем список песен
  player.createPlayList(player.getSizePlayList());
  player.showPlayList();

  Track currentTrack;
  std::string command {""};
  while (command != "exit") {
    cout << "Введите одну из команд (play, pause, next, stop, exit)" << endl;
    cin >> command;
    if (command == "play") {
      cout << "Введите название записи: ";
      std::string song;
      cin >> song;
      Track track = player.findSong(song);
      if (track.getName() == "") { // запись не найдена
        cout << "[Ошибка] Запись не найдена!" << endl;
      } else {
        player.showSong(track);
        currentTrack.setPlay(false); // текущую запись останавливаем
        currentTrack = track; // делаем текущей новую запись
      }
    }
    if (command == "pause") {
      player.pause(currentTrack);
    }
    if (command == "next") {
      currentTrack.setPlay(false); // останавливаем текущую запись
      currentTrack = player.nextSong();
      player.showSong(currentTrack);
    }
    if (command == "stop") {
      if (currentTrack.getPlay() == true) {
        currentTrack.setPlay(false); // текущую запись останавливаем
        std::cout << currentTrack.getName() << " остановлен" << std::endl;
      }
    }
  }
  return 0;
}
