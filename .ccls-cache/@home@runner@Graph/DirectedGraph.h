#include "Graph.h"

class DirectedGraph:public Graph {
private:
    Edge *edges = nullptr;
    Vertex *vertices = nullptr;
public:
    DirectedGraph(/* args */);
    ~DirectedGraph();
};

DirectedGraph::DirectedGraph(/* args */)
{
}

DirectedGraph::~DirectedGraph()
{
}
