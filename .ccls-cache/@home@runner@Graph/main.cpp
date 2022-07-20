#include "Vertex.h"
#include <cassert>
#include <iostream>
#include <string>

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
  // instatiate
  Vertex v;
  v.set_id(4);
	v.set_value(40);

  try {
    if (v.get_id() == 4 && v.get_value() == 40)
      cout << "Test : Getters and Setters: Passed " << endl;
    else
      throw 505;
  } catch (int err) {
    cout << "Test: Getters and Setters: failed " << endl;
  }
}

void test_edge_construcor() {
  // instatiate object with values
}
int main(int argc, char const *argv[]) {

  test_vertex_constructor();
	test_vertex_getters_and_setters();
  return 0;
}
