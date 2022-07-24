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
  double get_weight()const;
  Vertex* get_startPtr()const;
  Vertex* get_endPtr()const;

  // setters
  void set_weight(double w);
  void set_vertices(Vertex*,  Vertex*); // takes two argument to insure that an edge has always 2 vertex`
};

#endif