#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(){
	vertices = new Vertex[LIST_SIZE];
	num_edges =0;
	num_vertices =0;
}




// virtual bool add_vertex(Vertex &v) = 0;
// virtual bool add_Vertecices(Vertex *vArray); // add in a set of vertices;

// virtual bool remove_vertex(int vertex_id) = 0;

// // edges
// virtual bool add_edge(Edge &e) = 0;
// virtual bool add_edges(Edge &eArray) = 0;

// virtual bool remove_edge(Edge &e) = 0;

// virtual bool
// search_vertex(const Vertex &v) = 0; // return bool if a vertex exist in a graph;

// virtual bool
// search_edge(const Edge &e) = 0; // return bool if edges exist in a graph;

// virtual void display(Vertex &v) = 0; // display the path that contains the vert

// virtual void display() = 0; // display the path that contains the edge;

// virtual void
// display() const = 0; // display the whole graph with your iwn defined format

// virtual string
// to_String() const = 0; // convert the whole graph to a string such as 1-2-4--5;
//                        // 1-3-4; note: each different path is separeted by a ';'

// virtual bool clean() = 0; // remove all the vertices and edges
