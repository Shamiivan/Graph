#include "Graph.h"

class DirectedGraph : public Graph {
private:
  Edge *edges;
  Vertex *vertices;
  const size_t LIST_SIZE = 100; // used to initiliaze arrays of vertex and edges

  int num_edges;
  int num_vertices;

public:
  DirectedGraph();
	DirectedGraph(const DirectedGraph &); // copy constructor;
	~DirectedGraph();
	

  // getters and setters
  int get_num_vertices();
  int get_num_edges();

  bool add_vertex(Vertex &);
  bool remove_vertex(Vertex &);

  bool add_edge(Edge &);
  bool remove_edge(Edge &);
  bool search_edge(const Edge &); // returns true if an edge is the graph
  int search_edge_index(const Edge &); // returns the position of an edge in the graph

  bool search_vertex(const Vertex &);
	int search_vertex_index(const Vertex&); //return the index of the vertex;

  string to_string() const;
  void display() const;

	bool clean();
	bool add_vertices(Vertex *vArray, int size);// add in a set of vertices; 
};
