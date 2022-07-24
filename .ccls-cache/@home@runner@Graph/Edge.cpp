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


bool Edge::has_vertex(const Vertex &vertex){
	if(vertex.get_id() == startPtr->get_id() && vertex.get_value() == startPtr->get_id())
		return true;
	else if(vertex.get_id() == endPtr->get_id() && vertex.get_value() == endPtr->get_value())
		return true;
	
	return false;
}