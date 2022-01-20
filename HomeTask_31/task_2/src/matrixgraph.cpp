#include "matrixgraph.h"
#include <iostream>

MatrixGraph::MatrixGraph() {
}

MatrixGraph::MatrixGraph (const IGraph &gr) {
  tops.clear();
  array.clear();
  coord.clear();
  for (auto x : gr.getTops()) {
    std::vector<int> vec;
    gr.GetNextVertices(x, vec);
    for (auto y : vec) {
      AddEdge(x, y);
    }
  }
}

MatrixGraph::~MatrixGraph() {
}

std::vector<int> MatrixGraph::getTops() const {
  return  tops;
}

void MatrixGraph::GetNextVertices(int top, std::vector<int> &vec) const {
  std::vector<int> vecTops;
  if (coord.find(top) != coord.end ()) {
    size_t i = static_cast<size_t>(coord.find(top)->second);
    for (size_t j {0}; j < array[i].size(); j++) {
      if (array[i][j] == 1) { vecTops.push_back(tops[j]); }
    }
    vec = vecTops;
  }
}

void MatrixGraph::AddEdge (int from, int to) {
  if (coord.find(from) == coord.end()) {
    coord.insert(std::pair<int, int>(from, tops.size()));
    tops.push_back(from);
  }
  if (coord.find(to) == coord.end()) {
    coord.insert(std::pair<int, int>(to, tops.size()));
    tops.push_back(to);
  }
  if (tops.size() != array.size()) {
    array.resize (tops.size());
    for (auto &x : array) {
        x.resize (tops.size());
    }
  }
  array[static_cast<size_t>(coord.find(from)->second)][static_cast<size_t>(coord.find(to)->second)] = 1;
}

void MatrixGraph::GetPrevVertices(int top, std::vector<int> &vec) const {
  std::vector<int> vecTops;
  if (coord.find(top) != coord.end ()) {
    size_t i = static_cast<size_t>(coord.find(top)->second);
    for (size_t j {0}; j < array[i].size(); j++) {
      if (array[j][i] == 1) { vecTops.push_back(tops[j]); }
    }
    vec = vecTops;
  }
}

void MatrixGraph::print() {
  std::cout << " ";
  for (auto x : getTops()) {
      std::cout << "  " << x;
  }
  std::cout << std::endl;

  for (size_t i = 0; i < array.size(); i++) {
    std::cout << "  " << tops[i];
    for (size_t j = 0; j < array[i].size(); j++) {
        std::cout << "  " << array[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

