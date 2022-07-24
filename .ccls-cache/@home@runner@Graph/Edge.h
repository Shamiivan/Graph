#ifndef EDGE
#define EDGE
#include "Vertex.h"
class Edge {
private:
Vertex *startPtr;  //id of the of the first edge
  Vertex *endPtr; //id of the last edge
  double weight;

public:
	Edge();
  Edge(Vertex*, Vertex*,double); // constructor makes sure that edge is always instantiated with 2
             // pointers to a starting pointer and end pointer
  Edge(Edge &old_copy); // copy constructor
  ~Edge();

  // getters
  double get_weight();
  Vertex* get_startPtr();
  Vertex* get_endPtr();

  // setters
  void set_weight(int w);
  void set_vertices(Vertex*,  Vertex*); // takes two argument to insure that an edge has always 2 vertex`
};

#endif