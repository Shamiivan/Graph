#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(){
	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];
	num_edges =0;
	num_vertices =0;
}



bool DirectedGraph::add_vertex(Vertex &v){
	vertices[num_vertices] = v;
	num_vertices++;
	return true;
}
// virtual bool add_Vertecices(Vertex *vArray); // add in a set of vertices;

// virtual bool remove_vertex(int vertex_id) = 0;

// // edges
bool DirectedGraph::add_edge(Edge &e){
	edges[num_edges] = e;
	num_edges++;
	return true;
}


int DirectedGraph::get_num_edges(){return num_edges;}

int DirectedGraph::get_num_vertices(){return num_vertices;}


bool DirectedGraph::search_vertex(const Vertex &v){
    for(int i{0}; i <= num_vertices; i++){
      if (v.get_id() == vertices[i].get_id()){
				return true;
      }
    }
    return false;
};
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
  // // removing the vertex itself is done but it is required to remove the
  // edges that are connected to this vertex. but I don't know how to know which
  // edges to remove given a vertex ??! so can you add the code to remove the
  // edges that are connected to the removed vertex. i
//bool remove_vertex(int
  // vertex_id){
  //   int index = 0;
  //   bool found = false;
  //   for(int i = 0; i < numvertices, i++){
  //     if (vertex_id == *(vertices+i).get_id()){
  //     index = i;
  //     found = true;
  //     }
  //   }
  // if (found){
  //    for (int j = index; j<numvertices-1; j++){
  //     *(vertices+j) = *(vertices+j+1);
  //   }
  //   numvertices--;
  //   return true;
  // }else {return false}

  // };
  // bool remove_edge(Edge& e);
  // bool search_vertex(const Vertex &v){
  // };
  // };

  // bool clean(){
  // for (int i = 0; i< numvertices; i++){
  //   (vertices + i) = nullptr;
  // }

  //   for (int i = 0; i< numedges; i++){
  //   (edges + i) = nullptr;
  // }
  // }