#include "Edge.h"

Edge::Edge() {
  start = 0;
  end = 0;
  weight = 0;
}

Edge::Edge(const Vertex &s, const Vertex &e, double _weight) {
  start = s.get_id();
  end = e.get_id();
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
double Edge::get_weight() { return weight; }
int Edge::get_start() { return start; }
int Edge::get_end() { return end; }

// setters
void Edge::set_weight(int w) { weight = w; }
void Edge::set_vertices(const Vertex &s, const Vertex &e) {
  start = s.get_id();
  end = e.get_id();
}
