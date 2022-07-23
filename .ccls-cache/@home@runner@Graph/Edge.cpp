#include "Edge.h"

Edge::Edge(){
	start = nullptr;
	end =nullptr;
	weight =0;
}
Edge::Edge(Vertex *_start, Vertex *_end, double _weight){
	start = _start;
	end =_end;
	weight = _weight;
}


Edge::Edge(Edge &old_copy){
	///have to make deep copies
}
Edge::~Edge() {
    // delete start;
    // delete end;
  };

  // getters
  double Edge::get_weight(){return weight;}
  Vertex* Edge::get_start_ptr(){return start;}
  Vertex* Edge::get_end_ptr(){return end;}

	//setters
  void Edge::set_weight(int w){weight =w;}
  void Edge::set_vertices(Vertex *s, Vertex *e){start = s; end = e;}
