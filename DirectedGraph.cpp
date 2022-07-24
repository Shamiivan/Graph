#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() {
  vertices = new Vertex[LIST_SIZE];
  edges = new Edge[LIST_SIZE];
  num_edges = 0;
  num_vertices = 0;
}

bool DirectedGraph::add_vertex(Vertex &v) {
	if(search_vertex(v) == true){
		return false;
	}else if(search_vertex(v)==false){
  vertices[num_vertices] = v;
  num_vertices++;
  return true;
	}
}
// virtual bool add_Vertecices(Vertex *vArray); // add in a set of vertices;

// virtual bool remove_vertex(int vertex_id) = 0;

// // edges
bool DirectedGraph::add_edge(Edge &e) {
  // get the id of the vertices connected by the edge;
  // int start_id = e.get_startPtr()->get_id();
  // int start_value = e.get_startPtr()->get_value();

  // int end_id = e.get_endPtr()->get_id();
  // int end_value = e.get_endPtr()->get_value();
	Vertex start(*e.get_startPtr());//make a copy of the starting vertex
	Vertex end(*e.get_endPtr());//make a copy of the ending vertex
	double weight= e.get_weight();
	
	Vertex *startPtr; //be used to 
	Vertex *endPtr;

  // check if the vertives already exist in the graph
	if(search_vertex(start) ==false){
		add_vertex(start); //if they dont
		startPtr = (vertices + (num_vertices-1));
	}else if (search_vertex(start) == true){
		for(int i{0}; i <=num_vertices;i++){
			if(vertices[i].get_id() == start.get_id() && vertices[i].get_value() ==start.get_value()){
				startPtr = (vertices + i);	
			}		
		}
	}
	if(search_vertex(end) ==false){
		add_vertex(end); //if they dont
		endPtr = (vertices + (num_vertices-1));
	}else if (search_vertex(end) == true){
		for(int i{0}; i <=num_vertices;i++){
			if(vertices[i].get_id() == start.get_id() && vertices[i].get_value() ==start.get_value()){
				endPtr = (vertices + i);	
			}		
		}
	}


	//add the edge to the graph
	Edge new_edge(startPtr,endPtr,weight);
  edges[num_edges] = new_edge;
  num_edges++;
  return true;
}

int DirectedGraph::get_num_edges() { return num_edges; }

int DirectedGraph::get_num_vertices() { return num_vertices-1; }

bool DirectedGraph::search_vertex(const Vertex &v) {
  for (int i{0}; i <= num_vertices; i++) {
    if (v.get_id() == vertices[i].get_id() &&
        v.get_value() == vertices[i].get_value()) {
      return true;
    }
  }
  return false;
};
// virtual bool add_edges(Edge &eArray) = 0;

// virtual bool remove_edge(Edge &e) = 0;

// virtual bool
// search_vertex(const Vertex &v) = 0; // return bool if a vertex exist in a
// graph;

// virtual bool
// search_edge(const Edge &e) = 0; // return bool if edges exist in a graph;

// virtual void display(Vertex &v) = 0; // display the path that contains the
// vert

// virtual void display() = 0; // display the path that contains the edge;

// virtual void
void DirectedGraph::display() const{
  std::cout << "Displaying graph:\n";
  std::cout << "Vertices: " << num_vertices << "\n";
  for (int i{0}; i < num_vertices; i++)
    std::cout << "Id: " << vertices[i].get_id() << "\tValue: "
			
              << vertices[i].get_value() << "\n";

  std::cout << "Number of edges: " << num_edges << "\n";
	// int n=1;
	// std::cout << edges[n].get_startPtr()->get_id()<< "\t"  << edges[n].get_endPtr()->get_id()<< "\n";
	
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
// virtual string
// to_String() const = 0; // convert the whole graph to a string such as
// 1-2-4--5;
//                        // 1-3-4; note: each different path is separeted by a
//                        ';'

// virtual bool clean() = 0; // remove all the vertices and edges
// // removing the vertex itself is done but it is required to remove the
// edges that are connected to this vertex. but I don't know how to know which
// edges to remove given a vertex ??! so can you add the code to remove the
// edges that are connected to the removed vertex. i
// bool remove_vertex(int
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
// };

// bool clean(){
// for (int i = 0; i< numvertices; i++){
//   (vertices + i) = nullptr;
// }

//   for (int i = 0; i< numedges; i++){
//   (edges + i) = nullptr;
// }
// }