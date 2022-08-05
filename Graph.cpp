#include "Graph.h"

Graph::Graph()
{
	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];
	num_edges = 0;
	num_vertices = 0;
}
Graph::Graph(const Graph &other)
{
	// get the number of vertices and edges
	num_edges = other.num_edges;
	num_vertices = other.num_vertices;
	// create new lists of vertices and edges
	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];

	// copy each element
	for (int i{0}; i < num_vertices; i++)
		vertices[i] = other.vertices[i];

	for (int i{0}; i < num_edges; i++)
		edges[i] = other.edges[i];
}

Graph::~Graph()
{
	delete[] vertices;
	delete[] edges;
}

int Graph::get_num_edges() const { return num_edges; }		 // returns the number of edges
int Graph::get_num_vertices() const { return num_vertices; } // returns the number of vertices

bool Graph::add_vertex(Vertex &v)
{
	if (search_vertex(v) == false)
	{
		vertices[num_vertices] = v;
		num_vertices++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Graph::remove_vertex(Vertex &vertex)
{
	int index = search_vertex_index(vertex);
	if (index == -1)
		return false;

	// if the there is an edge that is connected to this vertex, remove it
	for (int i{0}; i < num_edges; i++)
	{
		if (edges[i].has_vertex(vertex))
		{
			remove_edge(edges[i]);
		}
	}

	// swap the last edge to the one at the current position. This can be done because the list of edges is unordered
	vertices[index] = vertices[num_vertices - 1];
	vertices[num_vertices - 1].set_id(0);
	vertices[num_vertices - 1].set_value(0);
	num_vertices--;
	return true;
}

// edges
bool Graph::add_edge(Edge &e)
{
	// add using deep copy, otherwise the edge added will have pointers to
	// external object
	Vertex start(*e.get_startPtr()); // make a copy of the starting vertex
	Vertex end(*e.get_endPtr());	 // make a copy of the ending vertex
	double weight = e.get_weight();

	Vertex *startPtr; // used to store the pointer of the vertex in the edge
	Vertex *endPtr;

	// check if the vertex already exist in the graph, if not add it to the graph
	int index = search_vertex_index(*e.get_startPtr());
	if(index == -1){
		add_vertex(*e.get_startPtr());
		startPtr = (vertices + (num_vertices - 1)); // get the pointer of the vertex 
	}else if(index != -1){
		startPtr = (vertices + index); // get the pointer of the vertex
	}



	int index_end = search_vertex_index(*e.get_endPtr());
	if(index_end == -1){
		add_vertex(*e.get_endPtr());
		endPtr = (vertices + (num_vertices - 1)); // get the pointer of the vertex 
	}else if(index_end != -1){
		endPtr = (vertices + index_end); // get the pointer of the vertex
	}
	

	// add the edge to the graph
	Edge new_edge(startPtr, endPtr, weight);
	edges[num_edges] = new_edge;
	num_edges++;
	return true;
}

bool Graph::remove_edge(Edge &edge)
{
	int index = search_edge_index(edge); // index of the edge
	edges[index] = edges[num_edges - 1];
	num_edges--;

	return true;
}

bool Graph::search_vertex(Vertex &v)
{
	bool found = false;
	for (int i = 0; i < num_vertices; i++)
	{
		if (vertices[i] == v)
			found = true;
	}
	return found;
};
int Graph::search_vertex_index(Vertex &v)
{
	int index = -1;
	for (int i = 0; i < num_vertices; i++)
	{
		if (vertices[i] == v)
			index = i;
	}
	return index;
};

bool Graph::search_edge(const Edge &edge)
{
	bool found = false;

	for (int i = 0; i < num_edges; i++)
	{
		if (edges[i] == edge)
			found = true;
	}
	return found;
}

int Graph::search_edge_index(const Edge &edge)
{
	// returns the index of an edge in array of edges
	int index = -1;

	for (int i = 0; i < num_edges; i++)
	{
		if (edges[i] == edge)
			index = i;
	}
	return index;
}
void Graph::display() const
{
	std::cout << "Displaying graph:\n";
	std::cout << "Vertices: " << num_vertices << "\n";
	for (int i{0}; i < num_vertices; i++)
		std::cout << "Id: " << vertices[i].get_id() << "\tValue: "

				  << vertices[i].get_value() << "\n";

	std::cout << "Number of edges: " << num_edges << "\n";


//display the edges
	for (int i{0}; i < num_edges; i++)
	{
		int start_id = edges[i].get_startPtr()->get_id();
		int start_value = edges[i].get_startPtr()->get_value();
		int end_id = edges[i].get_endPtr()->get_id();
		int end_value = edges[i].get_endPtr()->get_value();

		std::cout << "Edge connects vertex with id : " << start_id
				  << " with value: " << start_value
				  << " to : vertex with id: " << end_id
				  << " and value: " << end_value << "\n";
	};
}
string Graph::to_string() const
{
	for (int i = 0; i < num_vertices; i++)
	{
	}
	return "";
}

bool Graph::clean()
{
	delete[] vertices;
	delete[] edges;

	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];
	num_vertices = 0;
	num_edges = 0;
	return true;
}

bool Graph::add_vertices(Vertex *vArray, int size)
{

	for (int i{0}; i < size; i++)
	{
		add_vertex(vArray[i]);
	}
	return true;
}

bool Graph::add_edges(Edge *eArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		add_edge(eArray[i]);
	}
	return true;
}


// Array subscript overload
const Vertex &Graph::operator[](int i) const
{
	return vertices[i];
}

ostream &operator<<(ostream &os, Graph &g)
{
	// Output all the edges with the format (Vertex id)<-->(Vertex id)

	os << "\n\nDisplaying graph \n";
	os << "Vertices: " << g.num_vertices << "\n";
	os << "Edges " << g.num_edges << "\n";

	for (int i = 0; i < g.get_num_edges(); i++)
	{
		// find the vertices of the edge and get their id
		int start_id = g.edges[i].get_startPtr()->get_id();
		int end_id = g.edges[i].get_endPtr()->get_id();

		// print the edge
		os << start_id << "<-->" << end_id << " ; ";
	}
	os << endl;

	return os;
};


Graph::operator string() const{
	ostringstream os;

	for(int i = 0; i < num_edges; i++){
		int start_id = edges[i].get_startPtr()->get_id();
		int end_id = edges[i].get_endPtr()->get_id();

		os << "(" << start_id << "," << end_id << ")" << " ";
	}
	
	return (os.str());
	

}