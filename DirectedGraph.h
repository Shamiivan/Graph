#include "Graph.h"

class DirectedGraph : public Graph {
private:
  Edge *edges;
  Vertex *vertices;
	const size_t LIST_SIZE = 100; //used to initiliaze arrays of vertex and edges

  int num_edges;
  int num_vertices;

public:

	DirectedGraph();
  // // removing the vertex itself is done but it is required to remove the
  // edges that are connected to this vertex. but I don't know how to know which
  // edges to remove given a vertex ??! so can you add the code to remove the
  // edges that are connected to the removed vertex. bool remove_vertex(int
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
  // bool add_edge(Edge &e){
  //   (edges+numedges) = e;
  //   numedges++;
  //   return true;
  // };
  // bool remove_edge(Edge& e);
  // bool search_edge(const Edge &e){
  //   for(int i = 0; i < numedges, i++){
  //     if (*(e).get_start_ptr() == *(edges+i).get_start_ptr()){
  //       if (*(e).get_end_ptr() == *(edges+i).get_end_ptr()){
  //         return true;
  //       }
  //     }
  //   }
  //   return false;
  // };
  // bool search_vertex(const Vertex &v){
  //   for(int i = 0; i < numvertices, i++){
  //     if (*(v).get_id() == *(vertices+i).get_id()){
  //       return true;
  //     }
  //   }
  //   return false;
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
};
