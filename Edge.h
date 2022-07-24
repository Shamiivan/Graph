#ifndef EDGE
#define EDGE
#include "Vertex.h"
class Edge {
private:
  int start;  //id of the of the first edge
  int end; //id of the last edge
  double weight;

public:
	Edge();
  Edge(const Vertex&, const Vertex&,double); // constructor makes sure that edge is always instantiated with 2
             // pointers to a starting pointer and end pointer
  Edge(Edge &old_copy); // copy constructor
  ~Edge();

  // getters
  double get_weight();
  int get_start();
  int get_end();

  // setters
  void set_weight(int w);
  void set_vertices(const Vertex&, const Vertex&); // takes two argument to insure that an edge has always 2 vertex`
};

#endif