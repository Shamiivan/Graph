#ifndef VERTEX
#define VERTEX
#include <iostream>
#include <sstream>

using std::ostream;
using std::ostringstream;
using std::endl;
class Vertex
{
private:
    int m_id;
    int m_value;
    
public:
		Vertex (); // default constructor
    Vertex(int id, int value); //constructor with value
    Vertex(const Vertex& old_copy); //copy constructor


    //getters/setters
		int get_id()const;
		int get_value()const;

		void set_id(int id);
		void set_value(int value);

    //operator overloads
    Vertex operator=(Vertex& other);
    bool operator==(Vertex& other) const;

    friend ostream &operator<<(ostream &os, Vertex);
};

#endif