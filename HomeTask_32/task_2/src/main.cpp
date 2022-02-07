#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using std::cout;
using std::endl;
using std::cin;

void createJSON();

int main()
{
  createJSON();

  nlohmann::json films;
  std::ifstream in("Films.json");
  in >> films;

//std::string nameActor = "Костя";
  std::string nameActor = "Димон";

  for (auto it = films.begin(); it != films.end(); it++) {
    nlohmann::json &cast = it.value()["characters"];
    for (auto jt = cast.begin(); jt != cast.end(); jt++)
    {
      auto str = to_string(jt.value());
// поиска актёра по имени, вывод в консоль названий кинолент, в которых снималься актёр и роль которую он исполнял
      if (str.find(nameActor) != std::string::npos) // актёр найден
      {
        cout << nameActor << " in " << it.key() << " as " << jt.key() << endl;
      }
    }
  }

  in.close();
  std::cout << "program close" << std::endl;
  return 0;
}

void createJSON()
{
  std::ofstream out ("Films.json");
  nlohmann::json films;
  films["Чебуратор"]["country"] = "Эрафия";
  films["Чебуратор"]["date"] = "01.01.1970";
  films["Чебуратор"]["studio"] = "Мёртвый страус";
  films["Чебуратор"]["author"] = "Линус";
  films["Чебуратор"]["director"] = "Царь";
  films["Чебуратор"]["producer"] = "Вайнштейн";
  films["Чебуратор"]["characters"]["Чиполлино"]["info"] = "Чиполлино появился в 1951 году. Образ Чиполлино получил большую популярность в СССР";
  films["Чебуратор"]["characters"]["Чиполлино"]["actor"]["name"] = "Том Крузак";
  films["Чебуратор"]["characters"]["Чиполлино"]["actor"]["info"] = "Полное имя Томас Круз Мапотер IV. Американский актёр, кинорежиссёр, сценарист и кинопродюсер";
  films["Чебуратор"]["characters"]["Колобок"]["info"] = "Персонаж одноимённых восточнославянских народных сказок";
  films["Чебуратор"]["characters"]["Колобок"]["actor"]["name"] = "Димон";
  films["Чебуратор"]["characters"]["Колобок"]["actor"]["info"] = "Он вам не Димон";
  films["Чебуратор"]["characters"]["Чебуратор"]["info"] = "Персонаж исполняющий песню про день варенья гролом";
  films["Чебуратор"]["characters"]["Чебуратор"]["actor"]["name"] = "Петька";
  films["Чебуратор"]["characters"]["Чебуратор"]["actor"]["info"] = "Ходит под Василием Ивановичем, дружит с Анькой, не женат";

  films["Чебуратор новая кровь"]["country"] = "Антлантида";
  films["Чебуратор новая кровь"]["date"] = "01.01.1971";
  films["Чебуратор новая кровь"]["studio"] = "Мёртвый страус";
  films["Чебуратор новая кровь"]["author"] = "Гейтс";
  films["Чебуратор новая кровь"]["director"] = "Царь";
  films["Чебуратор новая кровь"]["producer"] = "Вайнштейн";
  films["Чебуратор новая кровь"]["characters"]["Лютик"]["info"] = "коллега чебуратора по вокально инструментальному ансамблю";
  films["Чебуратор новая кровь"]["characters"]["Лютик"]["actor"]["name"] = "Том Крузак";
  films["Чебуратор новая кровь"]["characters"]["Лютик"]["actor"]["info"] = "Полное имя Томас Круз Мапотер IV. Американский актёр, кинорежиссёр, сценарист и кинопродюсер";
  films["Чебуратор новая кровь"]["characters"]["Колобок"]["info"] = "Персонаж одноимённых восточнославянских народных сказок, по совместительству директор ансамбля";
  films["Чебуратор новая кровь"]["characters"]["Колобок"]["actor"]["name"] = "Димон";
  films["Чебуратор новая кровь"]["characters"]["Колобок"]["actor"]["info"] = "Он вам не Димон";
  films["Чебуратор новая кровь"]["characters"]["Чебуратор"]["info"] = "Персонаж исполняющий песню про день варенья баретоном";
  films["Чебуратор новая кровь"]["characters"]["Чебуратор"]["actor"]["name"] = "Анька";
  films["Чебуратор новая кровь"]["characters"]["Чебуратор"]["actor"]["info"] = "Ходит под Василием Ивановичем, дружит с Петькой, не замужем";

  films["Чебуратор возвращается"]["country"] = "НКР";
  films["Чебуратор возвращается"]["date"] = "01.01.1972";
  films["Чебуратор возвращается"]["studio"] = "Мёртвый страус";
  films["Чебуратор возвращается"]["author"] = "Джобс";
  films["Чебуратор возвращается"]["director"] = "Царь";
  films["Чебуратор возвращается"]["producer"] = "Вайнштейн";
  films["Чебуратор возвращается"]["characters"]["Лютик"]["info"] = "коллега чебуратора по вокально инструментальному ансамблю";
  films["Чебуратор возвращается"]["characters"]["Лютик"]["actor"]["name"] = "Костя";
  films["Чебуратор возвращается"]["characters"]["Лютик"]["actor"]["info"] = "возит шаланды полные кефали";
  films["Чебуратор возвращается"]["characters"]["Колобок"]["info"] = "постоянно пытается выбраться на свободу, даже под страхом не минуемой смерти";
  films["Чебуратор возвращается"]["characters"]["Колобок"]["actor"]["name"] = "Димон";
  films["Чебуратор возвращается"]["characters"]["Колобок"]["actor"]["info"] = "Он вам не Димон";
  films["Чебуратор возвращается"]["characters"]["Чебуратор"]["info"] = "Персонаж исполняющий песню про день варенья фольцетом";
  films["Чебуратор возвращается"]["characters"]["Чебуратор"]["actor"]["name"] = "Тот чьё имя нельзя произносить";
  films["Чебуратор возвращается"]["characters"]["Чебуратор"]["actor"]["info"] = "тёмная личность";

  out << films;
  out.close();
}

//  dict = "{ \"date\": \"01.01.1970\" }"_json;
//  dict = nlohmann::json::parse("{ \"studio\": \"Мёртвый страус\" }");
// можно и так
//  nlohmann::json dict =
//  {
//    {"name", record.name},
//    {"age",  record.age},
//    {"married", record.married}
//  };

