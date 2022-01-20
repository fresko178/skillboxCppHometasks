#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>

class IGraph { // базовый интерфейс
public:
  IGraph(){}
  IGraph(const IGraph *){}
  virtual ~IGraph(){}
  virtual void AddEdge(int, int) = 0; // принимает вершины начала и конца
  virtual void GetNextVertices(int, std::vector<int> &) const = 0; // вектор вершин в которые можно дойти по ребру из данной
  virtual void GetPrevVertices(int, std::vector<int> &) const = 0; // вектор вершин в которые можно дойти по ребру в данную
  virtual std::vector<int> getTops() const = 0;
};

#endif // IGRAPH_H
