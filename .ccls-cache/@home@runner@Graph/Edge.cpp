#include "Edge.h"

Edge::Edge() {
  startPtr = nullptr;
  endPtr = nullptr;
  weight = 0;
}

Edge::Edge(Vertex *s, Vertex *e, double _weight) {
  startPtr = s;
  endPtr = e;
	weight = _weight;
}
Edge::Edge(Edge &old_copy) {
  /// have to make deep copies
}
Edge::~Edge(){
    // delete start;
    // delete end;
};

// getters
double Edge::get_weight()const { return weight; }
Vertex* Edge::get_startPtr()const { return startPtr; }
Vertex* Edge::get_endPtr()const { return endPtr; }

// setters
void Edge::set_weight(double w) { weight = w; }
void Edge::set_vertices(Vertex *s, Vertex *e) {
  startPtr = s;
  endPtr = e;
}
