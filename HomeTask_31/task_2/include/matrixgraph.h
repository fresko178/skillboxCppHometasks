#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "igraph.h"
#include <map>

class MatrixGraph : public IGraph {
  std::vector<int> tops;
  std::vector<std::vector<int>> array;
  std::map<int, int> coord;

public:
  MatrixGraph();
  MatrixGraph(const IGraph &);
  ~MatrixGraph() override;

  void AddEdge(int, int) override;
  void GetNextVertices(int, std::vector<int> &) const override;
  void GetPrevVertices(int, std::vector<int> &) const override;
  std::vector<int> getTops() const override;
  void print();
};

#endif // MATRIXGRAPH_H
