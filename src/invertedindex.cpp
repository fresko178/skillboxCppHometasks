#include "invertedindex.h"
#include <thread>
#include <string>
#include <set>

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
  docs = input_docs;
  std::vector<std::thread> list_th;
  for (std::string str : docs) { //  выделяем слова из строки
    list_th.push_back(std::thread([&, str](){
      std::set<std::string> unique_words; // список уникальных слов
      unique_words.clear();
      std::string buf {""};
      for (char ch : str) {
        if (ch != ' ' && ch != '\0') {
          buf += ch;
        } else {
          unique_words.insert(buf);
          buf.clear();
        }
      }
      unique_words.insert(buf);

      if (!unique_words.empty()) {
        for (auto word : unique_words) {
          freq_dictionary.insert(std::make_pair(word, GetWordCount(word)));
        }
      }
    }));
  }
  for (size_t i {0}; i < list_th.size(); i++) {
    list_th[i].join();
  }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word)
{

  std::vector<Entry> list_entry;
  std::vector<std::string> list_words; // список слов в строке
  std::string buf {""};

  for (size_t index_str {0}; index_str < docs.size(); index_str++) { //  выделяем слова из строки
    list_words.clear();
    for (auto ch : docs[index_str]) {
      if (ch != ' ') {
        buf += ch;
      } else {
        list_words.push_back(buf);
        buf.clear();
      }
    }
    if (!buf.empty()) {
      list_words.push_back(buf);
      buf.clear();
    }

    Entry entry;
    size_t count {0};
    for (auto x : list_words) { // поиск совпадений
      if (x == word) {
        count++; // счётчик совпадений
      }
    }
    if (count > 0) { // совпадения найдены
      entry.doc_id = index_str;
      entry.count = count;
      list_entry.push_back(entry);
    }
  }

  return list_entry;
}
