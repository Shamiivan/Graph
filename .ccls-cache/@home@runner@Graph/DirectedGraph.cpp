#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() {
  vertices = new Vertex[LIST_SIZE];
  edges = new Edge[LIST_SIZE];
  num_edges = 0;
  num_vertices = 0;
}
DirectedGraph::DirectedGraph(const DirectedGraph &other){
  num_edges = other.num_edges;
  num_vertices = other.num_vertices;

  vertices = new Vertex[LIST_SIZE];
  edges = new Edge[LIST_SIZE];
	
	for(int i{0}; i <num_vertices; i++)
		vertices[i] =  other.vertices[i];

	for(int i{0}; i <num_edges; i++)
		edges[i] =  other.edges[i];
}

DirectedGraph::~DirectedGraph(){
	delete []vertices;
	delete [] edges;
	num_vertices = 0;
	num_edges =0;	
}

int DirectedGraph::get_num_edges() { return num_edges; }
int DirectedGraph::get_num_vertices() { return num_vertices; }

bool DirectedGraph::add_vertex(Vertex &v) {
  if (search_vertex(v) == true) {
    return false;
  } else if (search_vertex(v) == false) {
    vertices[num_vertices] = v;
    num_vertices++;
    return true;
  }
}
// virtual bool add_Vertecices(Vertex *vArray); // add in a set of vertices;

bool DirectedGraph::remove_vertex(Vertex &vertex) {
  int index = search_vertex_index(vertex); //get the index of the vertex
  if (index == -1)
    return false;
	
  // if the there is an edge that is connected to this vertex, remove it
  for (int i{0}; i < num_edges; i++) {
    if (edges[i].has_vertex(vertex)) {
      remove_edge(edges[i]);
    }
  }
	
  
  vertices[index] = vertices[num_vertices - 1];
  vertices[num_vertices - 1].set_id(0);
  vertices[num_vertices - 1].set_value(0);
  num_vertices--;
  return true;
}

// // edges
bool DirectedGraph::add_edge(Edge &e) {
  // add using deep copy, otherwise the edge added will have pointers to
  // external
  Vertex start(*e.get_startPtr()); // make a copy of the starting vertex
  Vertex end(*e.get_endPtr());     // make a copy of the ending vertex
  double weight = e.get_weight();

  Vertex *startPtr; // used to store the pointers of the vertex in graph
  Vertex *endPtr;

  // check if the vertives already exist in the graph
  if (search_vertex(start) == false) {
    add_vertex(start);
    startPtr = (vertices + (num_vertices - 1));
  } else if (search_vertex(start) == true) {
    for (int i{0}; i <= num_vertices; i++) {
      if (vertices[i].get_id() == start.get_id() &&
          vertices[i].get_value() == start.get_value()) {
        startPtr = (vertices + i);
      }
    }
  }
  if (search_vertex(end) == false) {
    add_vertex(end); // if they dont
    endPtr = (vertices + (num_vertices - 1));
  } else if (search_vertex(end) == true) {
    for (int i{0}; i <= num_vertices; i++) {
      if (vertices[i].get_id() == start.get_id() &&
          vertices[i].get_value() == start.get_value()) {
        endPtr = (vertices + i);
      }
    }
  }

  // add the edge to the graph
  Edge new_edge(startPtr, endPtr, weight);
  edges[num_edges] = new_edge;
  num_edges++;
  return true;
}

bool DirectedGraph::remove_edge(Edge &edge) {
  int index = search_edge_index(edge); // index of the edge
  edges[index] = edges[num_edges - 1];
  num_edges--;

  return true;
}

bool DirectedGraph::search_vertex(const Vertex &v) {
  for (int i{0}; i <= num_vertices; i++) {
    if (v.get_id() == vertices[i].get_id() &&
        v.get_value() == vertices[i].get_value()) {
      return true;
    }
  }
  return false;
};
int DirectedGraph::search_vertex_index(const Vertex &v) {
  int index = -1;
  for (int i{0}; i <= num_vertices; i++) {
    if (v.get_id() == vertices[i].get_id() &&
        v.get_value() == vertices[i].get_value()) {
      index = i;
    }
  }
  return index;
};

bool DirectedGraph::search_edge(const Edge &edge) {
  if (edge.get_startPtr() == nullptr && edge.get_endPtr() == nullptr) {
    return false;
  } else {
    // 2 edges with the same start id, end id and weights are considered
    // indetical
    int start_id = edge.get_startPtr()->get_id();
    int end_id = edge.get_endPtr()->get_id();
    double w = edge.get_weight();
    for (int i{0}; i < num_edges; i++) {
      if (edges[i].get_startPtr()->get_id() == start_id &&
          edges[i].get_endPtr()->get_id() == end_id &&
          edges[i].get_weight() == w)
        return true;
    }
    return false;
  }
}

int DirectedGraph::search_edge_index(const Edge &edge) {
  // returns the index of an edge in array of edges
  int index = -1;
  if (edge.get_startPtr() == nullptr && edge.get_endPtr() == nullptr) {
    return index;
  } else {
    // 2 edges with the same start id, end id and weights are considered
    // indetical
    int start_id = edge.get_startPtr()->get_id();
    int end_id = edge.get_endPtr()->get_id();
    double w = edge.get_weight();
    for (int i{0}; i < num_edges; i++) {
      if (edges[i].get_startPtr()->get_id() == start_id &&
          edges[i].get_endPtr()->get_id() == end_id &&
          edges[i].get_weight() == w) {
        index = i;
      }
    }
  }
  return index;
}

void DirectedGraph::display() const {
  std::cout << "Displaying graph:\n";
  std::cout << "Vertices: " << num_vertices << "\n";
  for (int i{0}; i < num_vertices; i++)
    std::cout << "Id: " << vertices[i].get_id() << "\tValue: "

              << vertices[i].get_value() << "\n";

  std::cout << "Number of edges: " << num_edges << "\n";
  // int n=1;
  // std::cout << edges[n].get_startPtr()->get_id()<< "\t"  <<
  // edges[n].get_endPtr()->get_id()<< "\n";

  for (int i{0}; i < num_edges; i++) {
    int start_id = edges[i].get_startPtr()->get_id();
    int start_value = edges[i].get_startPtr()->get_value();
    int end_id = edges[i].get_endPtr()->get_id();
    int end_value = edges[i].get_endPtr()->get_value();

    std::cout << "Edge connects vertex with id : " << start_id
              << " with value: " << start_value
              << " to : vertex with id: " << end_id
              << " and value: " << end_value << "\n";
  };
}
string DirectedGraph::to_string() const {
  for (int i = 0; i < num_vertices; i++) {
  }
}

bool DirectedGraph::clean(){
	delete []vertices;
	delete [] edges;

	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];
	num_vertices = 0;
	num_edges =0;
	return true;
}


bool DirectedGraph::add_vertices(Vertex *vArray, int size){

	for(int i{0}; i < size; i++){
		add_vertex(vArray[i]);
	}
	return true;
}

 bool DirectedGraph::add_edges(Edge *eArray, int size){
for (int i =0 ; i < size; i++){
	std::cout << i << std::endl;
  add_edge(eArray[i]);
}
  return true;
}