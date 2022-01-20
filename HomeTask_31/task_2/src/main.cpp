#include <iostream>
#include "matrixgraph.h"
#include "listgraph.h"

using std::cout;
using std::endl;

int main() {
  MatrixGraph mg;
  mg.AddEdge (5, 4);
  mg.AddEdge (2, 5);
  mg.AddEdge (1, 2);
  mg.AddEdge (3, 4);
  mg.AddEdge (4, 5);
  mg.AddEdge (1, 2);
  mg.AddEdge (3, 1);
  mg.print();
  ListGraph lg = mg;
  lg.print();
  MatrixGraph mgg = lg;
  mgg.print();

  cout << "program close" << endl;
  return 0;
}

