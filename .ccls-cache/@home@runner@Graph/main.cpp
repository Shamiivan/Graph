#include "DirectedGraph.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
int s = 2; // used to format text

void test_vertex_constructor() {
  try {
    Vertex v(1, 20);
    if (v.get_id() == 1 && v.get_value() == 20)
      cout << "Test : Vertex construcor : Passed " << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Test: vertex constructor : failed " << endl;
  }
};
void test_vertex_getters_and_setters() {
  // instatiate the v

  try {
    Vertex v;
    v.set_id(4);
    v.set_value(40);
    if (v.get_id() == 4 && v.get_value() == 40)
      cout << "Test : Vertex Getters and Setters: Passed " << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Test: Vertex Getters and Setters: failed " << endl;
  }
}

void test_edge_constructor() {
  // make an instance of edge using constructor with arguments
  // then check if the edge has the right pointer to the right vertex
  try {
    Vertex v1(1, 20);
    Vertex v2(2, 40);

    Vertex *startPtr = &v1;
    Vertex *endPtr = &v2;
    double weight = 0.4;

    Edge edge(startPtr, endPtr, weight);

    if (edge.get_start_ptr() == startPtr && edge.get_end_ptr() == endPtr)
      cout << "Test :  Edge contructor initialisation: Passed" << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Test : Edge constructor initialisatoin: Failed" << endl;
  }
};

void test_edge_getters_and_setters() {
  /// test the setter and getter for an edge
  // it is assumed that if the getters and setters works for the starting
  // starting vertext, it does for the ending one

  try {
    Vertex *startPtr = new Vertex();
    Vertex *endPtr = new Vertex();
    double weight = 40;

    Vertex *other_start = new Vertex();
    Vertex *other_end = new Vertex();
    double new_weight = 10;

    Edge edge(startPtr, endPtr, weight);
    edge.set_start_ptr(other_start); // change the pointer of the starting
                                     // Vertex to anotherVertex
    edge.set_end_ptr(other_end); // change the pointer of the starting Vertex to
                                 // anotherVertex
    edge.set_weight(new_weight);

    // check if the starting vertex and the weight has changed n
    if (edge.get_start_ptr() == other_start &&
        edge.get_end_ptr() == other_end && edge.get_weight() == new_weight)
      cout << "Class: Edge | Test : getters and setters | passed " << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Class: Edge | Test : getters and setters | failed " << endl;
  }
}

void make_graph(DirectedGraph &graph) {
  // used
  // create array of Vertex
  for (int i{0}; i < 20; i++) {
    Vertex *v = new Vertex(i, i * 5);
  }
  // Add the vertecies to graph

  // loop through existing vertecises and
  // add each edge created to the graph
}

void test_constructor() {
  //
  try {
    DirectedGraph graph;
    cout << "Class : DirectedGraph \tTest: initialiase constructor \t | PASSED \n";
  } catch (...) {
    cout << "Class : DirectedGraph \tTest: initialiase constructor \t | FAILED \n";
  }
}

void test_add_vertex(){
	try {
	DirectedGraph graph;
	Vertex v;
	assert(graph.add_vertex(v) == true);
	cout << "Class : DirectedGraph \tTest:Add a vertex  \t | PASSED \n";
	} catch(...){
		cout << "Class : DirectedGraph \tTest: add a vertex \t | FAILED \n";
	} 	
}


void test_add_edge(){
	Vertex v1;
	Vertex v2;
	Edge edge(&v1,&v2,0.5);

	DirectedGraph graph;
	try{
	if(graph.add_edge(edge) == true && graph.get_num_edges() == 1)
			cout << "Class : DirectedGraph \tTest: add a edge \t | PASSED\n";
	else 
		throw 505;
	
	} catch(int e){
		cout << "Class : DirectedGraph \tTest: add a edge \t | FAILED \n";
	}
	
}
int main(int argc, char const *argv[]) {

  test_vertex_constructor();
  test_vertex_getters_and_setters();

  test_edge_constructor();
  test_edge_getters_and_setters();

  test_constructor();
	test_add_vertex();
	test_add_edge();
  return 0;
}
