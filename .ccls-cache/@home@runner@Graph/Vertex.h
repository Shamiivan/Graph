#ifndef VERTEX
#define VERTEX
class Vertex
{
private:
    int m_id;
    int m_value;
    
public:
    Vertex(int id, int value); //constructor
    Vertex(const Vertex& old_copy); //copy constructor


    //getters/setters
		int get_id(); 
		int get_value();

		void set_id(int id);
		void set_value(int value);
};

#endif