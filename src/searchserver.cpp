#include "searchserver.h"
#include <algorithm>
#include <string>
#include <set>

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input)
{
  RelativeIndex relative_index;
  std::vector<RelativeIndex> request_relative;
  std::vector<std::vector<RelativeIndex>> list_relative;

  std::set<std::string> unique_queries; // список уникальных слов
  std::string buf {""};
  for (auto str : queries_input) { //  разбиваем поисковый запрос на отдельные слова
    unique_queries.clear();
    for (auto ch : str) {
      if (ch != ' ') {
        buf += ch;
      } else {
        unique_queries.insert(buf);
        buf.clear();
      }
    }
    if (!buf.empty()) {
      unique_queries.insert(buf);
      buf.clear();
    }

    std::vector<float> list_abs_rank;
    list_abs_rank.resize(_index.docs.size());

    for (auto word : unique_queries) { // высчитываем для документов абсолютную релевантность
      auto it = _index.freq_dictionary.find(word);
      if (it != _index.freq_dictionary.end()) { // совпадение найдено
        for (auto x : it->second) { // идём по списку документов где слово было обнаружено
            list_abs_rank[x.doc_id] += x.count;
        }
      }
    }

    float max = *std::max_element(list_abs_rank.begin(), list_abs_rank.end());
    request_relative.clear();
    for (size_t doc_id {0}; doc_id < list_abs_rank.size(); doc_id++) { // вычисляем относительную релевантность
      relative_index.doc_id = doc_id;
      if (max > 0) {
        relative_index.rank = list_abs_rank[doc_id] / max;
        if (relative_index.rank > 0) {
          request_relative.push_back(relative_index);
        }
      }
    }

    size_t SIZE = {request_relative.size()};
    if (SIZE > 0) {
      for (size_t i {0}; i < SIZE - 1; i++) { // сортируем
        for (size_t j {0}; j < SIZE - 1; j++) {
          if (request_relative[j].rank < request_relative[j + 1].rank) {
            auto tmp = request_relative[j];
            request_relative[j] = request_relative[j + 1];
            request_relative[j + 1] = tmp;
          }
        }
      }
    }
    list_relative.push_back(request_relative);
  }

  return list_relative;
}
