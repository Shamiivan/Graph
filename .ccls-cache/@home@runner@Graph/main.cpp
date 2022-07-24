#include "DirectedGraph.h"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

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
    double weight = 0.4;

    Edge edge(&v1,&v2,weight);

    if (edge.get_startPtr()->get_id() == 1 && edge.get_endPtr()->get_id() == 2)
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
    edge.set_vertices(other_start, other_end); // change the pointer of the starting
                                  // Vertex to anotherVertex
    edge.set_weight(new_weight);

    // check if the starting vertex and the weight has changed n
    if (edge.get_startPtr() == other_start &&
        edge.get_endPtr() == other_end && edge.get_weight() == new_weight)
      cout << "Class: Edge | Test : getters and setters | passed " << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Class: Edge | Test : getters and setters | failed " << endl;
  }
}

void populate_graph(DirectedGraph &graph) {

  static int id = 0; // used to make sure the id are always different when the
                     // function is called
  static int val = 2;
  Vertex v1(++id, val *=2);
  Vertex v2(++id, val *=2);
  Vertex v3(++id, val *=2);
  Vertex v4(++id, val *=2);
  Vertex v5(++id, val *=2);
  Vertex v6(++id, val *=2);
  Vertex v7(++id, val *=2);
  Vertex v8(++id, val *=2);
  Vertex v9(++id, val *=2);
  Vertex v10(++id, val *=2);

  // create edges
  Edge e1(&v1, &v2, 0.2);
  Edge e2(&v3, &v4, 0.2);
  Edge e3(&v3, &v10, 0.2);
  Edge e4(&v10,&v9, 0.2);
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

void test_constructor() {
  //
  try {
    DirectedGraph graph;
    cout << "Class : DirectedGraph \tTest: initialiase constructor \t | PASSED "
            "\n";
  } catch (...) {
    cout << "Class : DirectedGraph \tTest: initialiase constructor \t | FAILED "
            "\n";
  }
}

void test_copy_constructor() {
  DirectedGraph graph;
  Vertex v1(50, 40);
  populate_graph(graph); // add 20 vertices to the graph
	cout << "Num of edges and graphs: " << graph.get_num_edges() << "\t" << graph.get_num_vertices()<< "\n";
	cout <<"##############################################################\n";
	graph.display();
  try {
    DirectedGraph copy(graph);
    if (copy.search_vertex(v1) == true && copy.get_num_vertices() == 21)
      cout << "Class : DirectedGraph \tTest: Initialisation using copy "
              "constructor\t| PASSED \n";
    else
      throw 505;
  } catch (int e) {
    cout << "Class : DirectedGraph \tTest: Initialisatiton using copy "
            "constructor\t| FAILED \n";
  }
}
void test_add_vertex() {
  try {
    DirectedGraph graph;
    Vertex v;
    assert(graph.add_vertex(v) == true);
    cout << "Class : DirectedGraph \tTest:Add a vertex  \t | PASSED \n";
  } catch (...) {
    cout << "Class : DirectedGraph \tTest: add a vertex \t | FAILED \n";
  }
}

void test_add_edge() {
  Vertex v1(1, 50);
  Vertex v2(12, 40);
  Edge edge(&v1, &v2, 0.5);

  DirectedGraph graph;
  try {
    if (graph.add_edge(edge) == true && graph.get_num_edges() == 1 &&
        graph.search_vertex(v1) == true && graph.search_vertex(v2) == true)
      cout << "Class : DirectedGraph \tTest: add an edge\t|PASSED\n";
    else
      throw 505;
  } catch (int e) {
    cout << "Class : DirectedGraph \tTest: add an edge\t|FAILED \n";
  }
}

void test_search_vertex() {
  DirectedGraph graph;

  populate_graph(graph); // add 20 vertices in graph
  Vertex v(50, 60);      // vertex to be added in graph
  Vertex v2(56, 69);     // this vertex will not be added in graph
  graph.add_vertex(v);

  try {
    if (graph.search_vertex(v) == true && graph.search_vertex(v2) == false)
      cout << "Class : DirectedGraph \tTest: search for a vertex \t | PASSED\n";
    else
      throw 505;
  } catch (int e) {
    cout << "Class : DirectedGraph \tTest: search for a vertex \t | FAILED\n";
  }
}
int main(int argc, char const *argv[]) {

  test_vertex_constructor();
  test_vertex_getters_and_setters();

  test_edge_constructor();
  test_edge_getters_and_setters();

  // graph
  test_constructor();
	test_copy_constructor();
  test_add_vertex();
  test_add_edge();

  test_search_vertex();
  return 0;
}
