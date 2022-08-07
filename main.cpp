#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>

#include "DirectedGraph.h"
#include "tests.h"
using namespace std;

void populate_graph(Graph &graph); // used to populate graphs
ostream& operator<<(ostream &os, const Graph &g); //definition in graph class

int main(int argc, char const *argv[]) {
try{
  //try block for the operator overloading functions
  Test test_op;
  test_op.equality();
  test_op.assignment();
}catch(const char *msg) {
  cout << msg;
};
  try {
  Test test;
		//tests related to Edge and Vertex class
    cout << endl;
    test.vertex_constructor();
    test.vertex_getters_and_setters();
    cout << endl;
    test.edge_constructor();
    test.edge_getters_and_setters();
    test.edge_has_vertex();
    
		cout << endl;

		//test related to graph class
    test.constructor();
    test.copy_constructor();
    test.add_vertex();
    test.remove_edge();
    test.add_edge();
    test.search_vertex();
    test.search_edge();

    test.search_v_index();
    test.remove_vertex();

		test.clean();
		test.add_vertices();//add multiples vertices
		test.add_edges();
    cout << "All test pass\n";
  } catch (const char *msg) {
    cout << msg;
  };


  DirectedGraph g;
  populate_graph(g);
  cout << g;
  
  Vertex vertex = g[3];
  cout << vertex.get_id() << endl;


Graph g2;
populate_graph(g2);
string graph = (string)g2;

cout << graph << endl;



  // display();
  return 0;
};

