#include "DirectedGraph.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
void test_vertex_constructor();
void test_vertex_getters_and_setters();
void test_edge_constructor();
void test_edge_getters_and_setters();
void test_edge_has_vertex();
void test_constructor();
void test_copy_constructor();
void test_remove_edge();
void test_add_vertex();
void test_remove_vertex();
void display();
void populate_graph(DirectedGraph &graph);
void test_add_edge();
void test_search_vertex();
void test_search_edge();
void test_search_v_index();
void test_string();
void test_clean();

//bonuses
void test_add_vertices();
void test_add_edges();
int main(int argc, char const *argv[]) {
  try {
		//tests related to Edge and Vertex class
    test_vertex_constructor();
    test_vertex_getters_and_setters();
    test_edge_constructor();
    test_edge_getters_and_setters();
    test_edge_has_vertex();
    
		cout << endl;

		//test related to graph class
    test_constructor();
    test_copy_constructor();
    test_add_vertex();
    test_remove_edge();
    test_add_edge();
    test_search_vertex();
    test_search_edge();

    test_search_v_index();
    test_remove_vertex();

		test_clean();
		test_add_vertices();//add multiples vertices
		test_add_edges();
    cout << "All test pass\n";
  } catch (const char *msg) {
    cout << msg;
  };


  // display();
  return 0;
}

void test_vertex_constructor() {
  Vertex v(1, 20);
  if (v.get_id() == 1 && v.get_value() == 20)
    cout << "Class : Vertex \tTest: initialiaze object with constructor with "
            "arguments\t|PASSED\n";
  else
    throw "Class : Vertex \tTest: initialiaze object with constructor with "
          "arguments\t|FAILED\n";
};

void test_vertex_getters_and_setters() {
  // instatiate the v

  Vertex v;
  v.set_id(4);
  v.set_value(40);
  if (v.get_id() == 4 && v.get_value() == 40)
    cout << "Class: Vertex\tTest: getters and setters\t|PASSED\n";
  else
    throw "Class: Vertex\tTest: getters and setters\t|FAILED\n";
}

void test_edge_constructor() {
  // make an instance of edge using constructor with arguments
  // then check if the edge has the right pointer to the right vertex
  Vertex v1(1, 20);
  Vertex v2(2, 40);
  double weight = 0.4;

  Edge edge(&v1, &v2, weight);

  if (edge.get_startPtr()->get_id() == 1 && edge.get_endPtr()->get_id() == 2)
    cout << "Class: Edge\tTest: initialiase constructor\t|PASSED" << endl;
  else
    throw "Class: Edge\tTest: initialiase constructor\t|FAILED";
}

void test_edge_getters_and_setters() {
  /// test the setter and getter for an edge
  // it is assumed that if the getters and setters works for the starting
  // starting vertext, it does for the ending one

  Vertex *startPtr = new Vertex();
  Vertex *endPtr = new Vertex();
  double weight = 40;

  Vertex *other_start = new Vertex();
  Vertex *other_end = new Vertex();
  double new_weight = 10;

  Edge edge(startPtr, endPtr, weight);
  edge.set_vertices(other_start,
                    other_end); // change the pointer of the starting
                                // Vertex to anotherVertex
  edge.set_weight(new_weight);
  // check if the starting vertex and the weight has changed n
  if (edge.get_startPtr() == other_start && edge.get_endPtr() == other_end &&
      edge.get_weight() == new_weight)
    cout << "Class: Edge\tTest : getters and setterst\t|PASSED\n";
  else
    throw "Class: Edge\tTest : getters and setterst\t|FAILED\n";
}

void test_edge_has_vertex() {
  Vertex v1(1, 50);
  Vertex v2(2, 60);
  Vertex v3(3, 70);

  Edge edge(&v1, &v2, 0.4);
  if (edge.has_vertex(v1) == true && edge.has_vertex(v2) == true &&
      edge.has_vertex(v3) == false)
    cout << "Class: Edge\tTest : has vertex\t|PASSED\n";
  else
    throw "Class: Edge\tTest : has vertex \t|FAILED\n";
}
void test_constructor() {
  DirectedGraph graph;
  cout << "Class : DirectedGraph\tTest: initialiase constructor\t|PASSED "
          "\n";
}
void test_copy_constructor() {
  DirectedGraph graph;
  Vertex v1(50, 40);
  populate_graph(graph); // add ten vertices and 11 edges
  graph.add_vertex(v1);

  DirectedGraph copy(graph);
  if (copy.search_vertex(v1) == true && copy.get_num_vertices() == 11 &&
      copy.get_num_edges() == 11)
    cout << "Class : DirectedGraph \tTest: Initialisation using copy "
            "constructor\t|PASSED \n";
  else
    throw "Class : DirectedGraph \tTest: Initialisatiton using copy "
          "construcotr\t|FAILED\n";
}
void test_remove_edge() {
  DirectedGraph graph;

  populate_graph(graph); // add 10 vertices and 11 edges
  Vertex v(50, 60);      // vertex to be added in graph
  Vertex v2(56, 69);
  Edge e1(&v, &v2, 0.5);
  graph.add_edge(e1);
  populate_graph(graph); // add 10 more vertices and 11edges
  graph.remove_edge(e1);

  if (graph.search_edge(e1) == false && graph.get_num_edges() == 22)
    cout << "Class : DirectedGraph \tTest: remove an edge\t|PASSED\n";
  else
    throw "Class : DirectedGraph \tTest: remove an edge\t|FAILED\n";
}
void test_add_vertex() {
  DirectedGraph graph;
  Vertex v(4, 10);
  graph.add_vertex(v);
  if (graph.search_vertex(v) == true)
    cout << "Class : DirectedGraph \tTest:Add a vertex  \t | PASSED \n";
  else
    throw "Class : DirectedGraph \tTest: add a vertex \t | FAILED \n";
}
void display() {
  DirectedGraph graph;
  populate_graph(graph);
  graph.display();
}
void test_remove_vertex() {
  DirectedGraph graph;

  populate_graph(graph); // add 10 vertices and 11 edges
  Vertex v1(50, 60);     // vertex to be added in graph
  Vertex v2(56, 69);
  Edge e1(&v1, &v2, 0.5);
  graph.add_edge(e1);    // adding the edge means adding the vertices
  populate_graph(graph); // add 10 more vertices and 11edges
  graph.remove_vertex(v2);

  if (graph.search_vertex(v2) == false && graph.search_vertex(v1) == true &&
      graph.search_edge(e1) == false && graph.get_num_edges() == 22 &&
      graph.get_num_vertices() == 21)
    cout << "Class : DirectedGraph \tTest: remove a vertex\t|PASSED\n";
  else
    throw "Class : DirectedGraph \tTest: remove a vertex\t|FAILED\n";
}
void test_add_edge() {
  Vertex v1(1, 50);
  Vertex v2(12, 40);
  Edge edge(&v1, &v2, 0.5);

  DirectedGraph graph;
  if (graph.add_edge(edge) == true && graph.get_num_edges() == 1 &&
      graph.search_vertex(v1) == true && graph.search_vertex(v2) == true)
    cout << "Class : DirectedGraph \tTest: add an edge\t|PASSED\n";
  else
    throw "Class : DirectedGraph \tTest: add an edge\t|FAILED \n";
}
void test_search_vertex() {
  DirectedGraph graph;

  populate_graph(graph); // add 10 vertices and 11 edges
  Vertex v(50, 60);      // vertex to be added in graph
  Vertex v2(56, 69);     // this vertex will not be added in graph
  graph.add_vertex(v);

  if (graph.search_vertex(v) == true && graph.search_vertex(v2) == false)
    cout << "Class : DirectedGraph \tTest: search for a vertex \t | PASSED\n";
  else
    throw "Class : DirectedGraph \tTest: search for a vertex \t | FAILED\n";
}
void test_search_edge() {
  DirectedGraph graph;

  populate_graph(graph); // add 10 vertices and 11 edges
  Vertex v(50, 60);      // vertex to be added in graph
  Vertex v2(56, 69);
  Edge e;
  Edge e1(&v, &v2, 0.5);
  graph.add_edge(e1);

  if (graph.search_edge(e1) == true && graph.search_edge(e) == false)
    cout << "Class: DirectedGraph\tTest: search for an edge\t|PASSED\n";
  else
    throw "Class : DirectedGraph \tTest: search for an edge\t|FAILED\n";
}

void test_search_v_index() {
  DirectedGraph graph;
  populate_graph(graph); // add 10 vertices
  Vertex v1(2, 30);
  graph.add_vertex(v1);

  if (graph.search_vertex_index(v1) == 10)
    cout << "Class: DirectedGraph\tTest: search for a vertex and return it's "
            "index\t|PASSED\n";
  else
    throw "Class: DirectedGraph\tTest: search for a vertex and return it's "
          "index\t|FAILED\n";
}

void test_clean(){
 	DirectedGraph graph;
	populate_graph(graph);
	Vertex v1(1,40);
	Vertex v2(2,80);
	Edge e(&v1,&v2,0.5);
	graph.add_edge(e);
	graph.clean();

	if(graph.get_num_edges() ==0 && graph.get_num_vertices() == 0 
		&& graph.search_vertex(v1) == false  
		&& graph.search_edge(e) ==false)
			cout << "Class: DirectedGraph\tTest: clean method\t|PASSED\n";
	else
		throw "Class: DirectedGraph\tTest: clean method\t|FAILED\n";
}

void test_add_vertices(){
	DirectedGraph graph;
	int size = 4;
	Vertex *vArray = new Vertex[size];
	for(int i{0}; i< size;i++){
		Vertex v(i,i*2);
		vArray[i] = v;
	}
	graph.add_vertices(vArray, size);

	if(graph.search_vertex(vArray[0]) == true && graph.search_vertex(vArray[3])==true  &&graph.search_vertex(vArray[4])== true) 
		cout << "Class: DirectedGraph\tTest: add multiple vertices\t|PASSED\n";
	else 
		throw "Class: DirectedGraph\tTest: add multiple vertices\t|FAILED\n";
	 
}

void test_add_edges(){
	DirectedGraph graph;

	Vertex v1(1,10);
	Vertex v2(2,20);
	Vertex v3(4,30);
	Vertex v4(4,50);

	Edge e1(&v1,&v2,0.5);
	Edge e2(&v2,&v3,0.5);
	Edge e3(&v3,&v4,0.5);

	int size = 3;
	Edge *eArray = new Edge[size];
	eArray[0] =e1;
	eArray[1] = e2;
	eArray[2] = e3;
	graph.add_edges(eArray,size);	

	cout << "Baby this what we're looking for: " << graph.search_edge_index(eArray[2]);
	if(graph.search_edge(eArray[0]) == true && graph.search_edge(eArray[1])==true  &&graph.search_edge(eArray[2])== true) 
		cout << "Class: DirectedGraph\tTest: add multiple edges\t|PASSED\n";
	else 
		throw "Class: DirectedGraph\tTest: add multiple edges\t|FAILED\n";
	
}
void test_string(){
	// DirectedGraph graph;
	// Vertex v1(1,10);
	// Vertex v2(2,20);
	// Vertex v3(3,30);
	// Vertex v4(4,40);
	// Vertex v5(5,50);
	// Vertex v6(6,60);
	// Vertex v7(7,70);

	// Edge e1(&v1,&v2,0.5);
	// Edge e2(&v2,&v3,0.5);
	// Edge e3(&v1,&v2,0.5);
	// Edge e1(&v1,&v2,0.5);
	// Edge e1(&v1,&v2,0.5);
	// Edge e1(&v1,&v2,0.5);
	// Edge e1(&v1,&v2,0.5);
	// Edge e1(&v1,&v2,0.5);
}
void populate_graph(DirectedGraph &graph) {

  static int id = 0; // used to make sure the id are always different when the
                     // function is called
  int val = 4;
  Vertex v1(id += 1, 40);
  Vertex v2(id += 2, val *= 2);
  Vertex v3(id += 3, val *= 2);
  Vertex v4(id += 4, val *= 2);
  Vertex v5(id += 5, val *= 2);
  Vertex v6(id += 6, val *= 2);
  Vertex v7(id += 7, val *= 2);
  Vertex v8(id += 8, val *= 2);
  Vertex v9(id += 9, val *= 2);
  Vertex v10(id += 10, val *= 2);

  // create edges
  Edge e1(&v1, &v2, 0.2);
  Edge e2(&v3, &v4, 0.2);
  Edge e3(&v3, &v10, 0.2);
  Edge e4(&v10, &v9, 0.2);
  Edge e5(&v7, &v3, 0.2);
  Edge e6(&v2, &v9, 0.2);
  Edge e7(&v5, &v7, 0.2);
  Edge e8(&v5, &v1, 0.2);
  Edge e9(&v5, &v2, 0.2);
  Edge e10(&v7, &v9, 0.2);
  Edge e11(&v9, &v6, 0.2);

  // add edges, adding edges add also the vertices they connect
  graph.add_edge(e1);
  graph.add_edge(e2);
  graph.add_edge(e3);
  graph.add_edge(e4);
  graph.add_edge(e5);
  graph.add_edge(e6);
  graph.add_edge(e7);
  graph.add_edge(e8);
  graph.add_edge(e9);
  graph.add_edge(e10);
  graph.add_edge(e11);

  // add vertecis that are not connected by edges
  graph.add_vertex(v4);
  graph.add_vertex(v8);
}
