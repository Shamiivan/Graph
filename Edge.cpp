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
	if(vertex.get_id() == startPtr->get_id() && vertex.get_value() == startPtr->get_value())
		return true;
	else if(vertex.get_id() == endPtr->get_id() && vertex.get_value() == endPtr->get_value())
		return true;
	else
		return false;
}

bool Edge::operator==(Edge &other) {
  //if any of the pointer are nullptr, it means edge is not connected
  if(other.startPtr == nullptr ||  other.endPtr == nullptr)
    return false;
  else if(other.startPtr->get_id() == startPtr->get_id() && other.endPtr->get_id() == endPtr->get_id() && other.weight == weight)
    return true;
  else{
    return false;
  }
}

bool Edge::operator!=(Edge& other) {
  if( *this == other) 
    return false;
  else
    return true;
}


ostream &operator<<(ostream &os, Edge &e) {
  os << "(" << e.get_startPtr()->get_id()<<"," << e.get_endPtr()->get_id() << "," << e.weight<< ")";
  return os;
}