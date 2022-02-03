#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main()
{
  std::ofstream out ("Колобок_VS_Чиполлино.json");
  nlohmann::json dict;
  dict["1) name"] = "Колобок VS Чиполлино";
  dict["2) country"] = "Эрафия";
  dict["3) date"] = "01.01.1970";
  dict["4) studio"] = "Мёртвый страус";
  dict["5) author"] = "Линус";
  dict["6) director"] = "Царь";
  dict["7) producer"] = "Вайнштейн";

  dict["8) characters"]["1"]["name"] = "Чиполлино";
  dict["8) characters"]["1"]["info"] = "Чиполлино появился в 1951 году. Образ Чиполлино получил большую популярность в СССР";
  dict["8) characters"]["1"]["actor"]["name"] = "Том Круз";
  dict["8) characters"]["1"]["actor"]["info"] = "Полное имя Томас Круз Мапотер IV. Американский актёр, кинорежиссёр, сценарист и кинопродюсер";

  dict["8) characters"]["2"]["name"] = "Колобок";
  dict["8) characters"]["2"]["info"] = "Персонаж одноимённых восточнославянских народных сказок";
  dict["8) characters"]["2"]["actor"]["name"] = "Дмитрий Нагиев";
  dict["8) characters"]["2"]["actor"]["info"] = "Родился 4 апреля 1967 года в Ленинграде. в 1980-е годы завоевал звание чемпиона СССР среди юниоров по спортивной гимнастике";

  out << dict;
  out.close();

  std::cout << "program close" << std::endl;
  return 0;
}


