#include "listgraph.h"
#include <iostream>
#include <algorithm>

ListGraph::ListGraph() {
}

ListGraph::ListGraph (const IGraph &gr) {
  verin.clear();
  verout.clear();

  for (auto x : gr.getTops()) {
    std::vector<int> vec;
    gr.GetPrevVertices(x, vec);
    verin.insert(std::pair<int, std::vector<int>>(x, vec));
    vec.clear();
    gr.GetNextVertices(x, vec);
    verout.insert(std::pair<int, std::vector<int>> (x, vec));
  }
}

ListGraph::~ListGraph() {
}

std::vector<int> ListGraph::getTops() const {
  std::vector<int> vec;
  for (auto x : verin) {
    vec.push_back(x.first);
  }
  return vec;
}

void ListGraph::GetNextVertices (int top, std::vector<int> &vec) const {
  vec = verout.find(top)->second;
}

void ListGraph::AddEdge (int from, int to) {
  if (verin.find (from) == verin.end ()) { verin.insert (std::pair<int, std::vector<int>> (from, 0)); }
  if (verout.find (from) == verout.end()) { verout.insert (std::pair<int, std::vector<int>> (from, 0)); }
  if (verin.find (to) == verin.end ()) { verin.insert (std::pair<int, std::vector<int>> (to, 0)); }
  if (verout.find (to) == verout.end()) { verout.insert (std::pair<int, std::vector<int>> (to, 0)); }

  std::map<int, std::vector<int>>::iterator it = verin.find(to);
  bool found {false};
  for (size_t i {0}; !found && (i < it->second.size ()); i++) {
    if (it->second[i] == from) { found = true; }
  }
  if (!found) { it->second.push_back(from); }

  it = verin.find(from);
  found = false;
  for (size_t i {0}; !found && (i < it->second.size ()); i++) {
    if (it->second[i] == from) { found = true; }
  }
  if (!found) { it->second.push_back(to); }
}

void ListGraph::GetPrevVertices (int top, std::vector<int> &vec) const {
  vec = verin.find(top)->second;
}



void ListGraph::print() {
  for (auto x1 : verout) {
    std::sort(x1.second.begin(), x1.second.end());
    std::cout << "  " << x1.first << ": ";
    for (auto x2 : x1.second) {
      std::cout << "  " << x2;
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

