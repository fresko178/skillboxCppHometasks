#pragma once

#include <vector>
#include <map>
#include <string>

struct Entry
{
  size_t doc_id; // номер элемента в векторе docs, по которому хранится текст
  size_t count;  // сколько раз ключевое слово встретилось в документе doc_id.

  bool operator ==(const Entry& other) const // Данный оператор необходим для проведения
  {                                          // тестовых сценариев
    return (doc_id == other.doc_id &&
    count == other.count);
  }
};

class InvertedIndex
{
public:
  InvertedIndex() = default;

  std::vector<std::string> docs; // список содержимого документов
  std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь

  /**
  * Обновить или заполнить базу документов, по которой будем совершать поиск
  * @param input_docs содержимое документов
  */
  void UpdateDocumentBase(std::vector<std::string> input_docs);

  /**
  * Метод определяет количество вхождений слова word в загруженной базе документов
  * @param word слово, частоту вхождений которого необходимо определить
  * @return возвращает подготовленный список с частотой слов
  */
  std::vector<Entry> GetWordCount(const std::string& word);
};
