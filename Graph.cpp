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

	vertices = nullptr;
	edges = nullptr;
}

int Graph::get_num_edges() const { return num_edges; }		 // returns the number of edges
int Graph::get_num_vertices() const { return num_vertices; } // returns the number of vertices

bool Graph::add_vertex(Vertex &v)
{
	if (search_vertex(v) == true)
	{
		return false;
	}
	else if (search_vertex(v) == false)
	{
		vertices[num_vertices] = v;
		num_vertices++;
		return true;
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

	Vertex *startPtr; // used to store the pointers of the vertex in graph
	Vertex *endPtr;

	// check if the vertex already exist in the graph
	if (search_vertex(start) == false)
	{
		add_vertex(start);
		startPtr = (vertices + (num_vertices - 1));
	}
	else if (search_vertex(start) == true)
	{
		for (int i{0}; i <= num_vertices; i++)
		{
			if (vertices[i].get_id() == start.get_id() &&
				vertices[i].get_value() == start.get_value())
			{
				startPtr = (vertices + i);
			}
		}
	}
	if (search_vertex(end) == false)
	{
		add_vertex(end); // if they dont
		endPtr = (vertices + (num_vertices - 1));
	}
	else if (search_vertex(end) == true)
	{
		for (int i{0}; i <= num_vertices; i++)
		{
			if (vertices[i].get_id() == start.get_id() &&
				vertices[i].get_value() == start.get_value())
			{
				endPtr = (vertices + i);
			}
		}
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

bool Graph::search_vertex(const Vertex &v)
{
	for (int i{0}; i <= num_vertices; i++)
	{
		if (v.get_id() == vertices[i].get_id() &&
			v.get_value() == vertices[i].get_value())
		{
			return true;
		}
	}
	return false;
};
int Graph::search_vertex_index(const Vertex &v)
{
	int index = -1;
	for (int i{0}; i <= num_vertices; i++)
	{
		if (v.get_id() == vertices[i].get_id() &&
			v.get_value() == vertices[i].get_value())
		{
			index = i;
		}
	}
	return index;
};

bool Graph::search_edge(const Edge &edge)
{
	if (edge.get_startPtr() == nullptr && edge.get_endPtr() == nullptr)
	{
		return false;
	}
	else
	{
		// 2 edges with the same start id, end id and weights are considered
		// indetical
		int start_id = edge.get_startPtr()->get_id();
		int end_id = edge.get_endPtr()->get_id();
		double w = edge.get_weight();
		for (int i{0}; i < num_edges; i++)
		{
			if (edges[i].get_startPtr()->get_id() == start_id &&
				edges[i].get_endPtr()->get_id() == end_id &&
				edges[i].get_weight() == w)
				return true;
		}
		return false;
	}
}

int Graph::search_edge_index(const Edge &edge)
{
	// returns the index of an edge in array of edges
	int index = -1;
	//if an edge doesnt have a pointer to starting vertex and end vertex it does not exist
	if (edge.get_startPtr() == nullptr && edge.get_endPtr() == nullptr)
	{
		return index;
	}
	else
	{
		// 2 edges with the same start id, end id and weights are considered
		// indetical
		int start_id = edge.get_startPtr()->get_id();
		int end_id = edge.get_endPtr()->get_id();
		double w = edge.get_weight();


		for (int i{0}; i < num_edges; i++)
		{
			if (edges[i].get_startPtr()->get_id() == start_id &&
				edges[i].get_endPtr()->get_id() == end_id &&
				edges[i].get_weight() == w)
			{
				index = i;
			}
		}
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
	// int n=1;
	// std::cout << edges[n].get_startPtr()->get_id()<< "\t"  <<
	// edges[n].get_endPtr()->get_id()<< "\n";

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
}

bool Graph::clean()
{
	delete[] vertices;
	delete[] edges;

	vertices = new Vertex[LIST_SIZE];
	edges = new Edge[LIST_SIZE];
	num_vertices = 0;
	num_edges =0;
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
		std::cout << i << std::endl;
		add_edge(eArray[i]);
	}
	return true;
}


Edge* Graph::get_edges() const{
	return edges;
}

//Array subscript overload

const Vertex & Graph::operator[](int i) const{
	return vertices[i]; 
}

ostream& operator<<(ostream &os, const Graph &g){
	//Output all the edges

	//make a new array of edges
	Edge *edges;
	edges = g.get_edges();
	
	os << "Displaying graph \n";
	os << "Vertices: " << g.get_num_vertices()  << "\n";
	os << "Edges " << g.get_num_edges() << "\n";
	
	for(int i = 0; i < g.get_num_edges(); i++){
		//find the vertices of the edge and get their id
		int start_id = edges[i].get_startPtr() ->get_id();
		int end_id = edges[i].get_endPtr() ->get_id();

		//print the edge
		os << start_id << "<-->" << end_id  <<" ; ";
	}
	os << endl;
	
	return os;	
	//add to os all the vertices
};
