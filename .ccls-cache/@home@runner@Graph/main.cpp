#include "Vertex.h"
#include <cassert>
#include <iostream>
#include <string>
#include "Edge.h"

using std::cout, std::endl, std::string;

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
	//then check if the edge has the right pointer to the right vertex
	try{
		Vertex v1(1,20);
		Vertex v2(2,40);

		Vertex *startPtr = &v1;
		Vertex *endPtr = &v2;
		double weight = 0.4;
		
		Edge edge(startPtr, endPtr, weight);

		if(edge.get_start_ptr() == startPtr && edge.get_end_ptr() == endPtr)
      cout << "Test :  Edge contructor initialisation: Passed" << endl;
		else
			throw 505;
	}
		catch(int err){
      cout << "Test : Edge constructor initialisatoin: Failed" << endl;
		}
};

void test_edge_getters_and_setters(){
	///test the setter and getter for an edge
	//it is assumed that if the getters and setters works for the starting starting vertext, it does for the ending one
	
	try{
	Vertex *startPtr = new Vertex();
	Vertex *endPtr = new Vertex();
	double weight = 40;
	
	Vertex *other_start = new Vertex();
	Vertex *other_end = new Vertex();
	double new_weight = 10;
		
	Edge edge(startPtr, endPtr,weight);
	edge.set_start_ptr(other_start); // change the pointer of the starting Vertex to anotherVertex
	edge.set_end_ptr(other_end); // change the pointer of the starting Vertex to anotherVertex
	edge.set_weight(new_weight);

	//check if the starting vertex and the weight has changed n
	if(edge.get_start_ptr() == other_start 
		&& edge.get_end_ptr() == other_end
		&& edge.get_weight() == new_weight)
		cout << " Class: Edge | Test : getters and setters | passed " << endl;
	else 
		throw 505;
	} catch(int err){
		cout << "Class: Edge | Test : getters and setters | failed " << endl;
	}
	
}

int main(int argc, char const *argv[]) {

  test_vertex_constructor();
  test_vertex_getters_and_setters();

	test_edge_constructor();
	test_edge_getters_and_setters();
  return 0;
}
