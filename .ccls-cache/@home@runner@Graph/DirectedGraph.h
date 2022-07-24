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

  // getters and setters
	int get_num_vertices();
	int get_num_edges();


	bool add_vertex(Vertex&);
	bool add_edge(Edge&);

	bool search_vertex(const Vertex&);

	void display()const;
};
