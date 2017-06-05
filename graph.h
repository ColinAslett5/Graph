//Header file for Graph Creator, Colin Aslett, C++ Period 07
#pragma once
#include <vector>
#include <utility>
#include <limits>

using namespace std;

class graph{
 public:
  graph();//initializing the graph
  ~graph();
  //all are bools becuase we have to determine whether the operations can execute.
  bool vertex(const char* name);//adding vertex
  bool edge(const char* name1, const char* name2, int x);//adding an edge
  bool deledge(const char* name1, const char* name2);//deleting edge
  bool delvertex(const char* name);//deleting vertex
  bool dbedge(const char* name1, const char* name2, int x);//adding double edge
  void printpath(const char* name1, const char* name2);//printing shortest path
  void print();
 private:
  pair<vector<char*>, int> Path(const char* name1, const char* name2);
  const int num;
  vector<vector<int>*> matrix;
  vector<char*> label;
};
