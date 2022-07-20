#include <iostream>
#include <cassert>
#include <string>
#include "Vertex.h"

using std::cout, std::endl, std::string;

void test_vertex_constructor(){	
	try{
		Vertex v(1, 20);
		if(v.get_id() ==1 && v.get_value() == 20)
			cout << "Test : Vertex construcor : Passed " << endl;
		else
			throw 505;
	}
		catch(int err){
			cout << "Test: vertex constructor : failed " << endl;
		}

};

void test_edge_construcor(){
	//instatiate object wi
}
int main(int argc, char const *argv[])
{


		test_vertex_constructor();
    return 0;
}
