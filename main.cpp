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
  Test op_tests;
  op_tests.equality();
  op_tests.assignment();
  op_tests.arr_subscript();
  op_tests.to_string();
  op_tests.print(); // test the << operator overloading function
  cout << "ALL operator overloading functions passed the tests " << endl;
}catch(const char *msg) {
  cout << msg;
};
  

  cout << endl << endl;
  try {
  Test test;
		//tests related to Edge and Vertex class
    
    test.vertex_constructor();
    test.vertex_getters_and_setters();
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
  // display();
  return 0;
};

