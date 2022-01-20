#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "igraph.h"
#include <map>

class ListGraph : public IGraph {
  std::map<int, std::vector<int>> verin;
  std::map<int, std::vector<int>> verout;

public:
  ListGraph();
  ListGraph(const IGraph &);
  ~ListGraph() override;

  void AddEdge(int, int) override;
  void GetNextVertices(int, std::vector<int> &) const override;
  void GetPrevVertices(int, std::vector<int> &) const override;
  std::vector<int> getTops() const override;
  void print();
};

#endif // LISTGRAPH_H
