#ifndef EDGE
#define EDGE
#include "Vertex.h"
class Edge {
private:
  Vertex *start;
  Vertex *end;
  double weight;

public:
	Edge();
  Edge(Vertex *, Vertex *,
       double); // constructor makes sure that edge is always instantiated with 2
             // pointers to a starting pointer and end pointer
  Edge(Edge &old_copy); // copy constructor
  ~Edge();

  // getters
  double get_weight();
  Vertex *get_start_ptr();
  Vertex *get_end_ptr();

  // setters
  void set_weight(int w);
  void set_vertices(Vertex *s, Vertex*e); // takes two argument to insure that an edge has always 2 vertex
};

#endif