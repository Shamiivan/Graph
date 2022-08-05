#ifndef GRAPH
#define GRAPH

#include "Vertex.h"
#include "Edge.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
class Graph{
    protected:
        int num_vertices;
        int num_edges;
        Edge *edges;
        Vertex *vertices;
        const size_t LIST_SIZE = 100; // used to initiliaze arrays of vertex and edges


    public:
       	Graph();
        Graph(const Graph &other);
        virtual ~Graph();

        //number of vertices and number of edges
        int get_num_vertices() const;
        int get_num_edges() const;
 
        //vertices
        virtual bool add_vertex(Vertex &v);
        virtual bool add_vertices(Vertex *vArray, int size);// add in a set of vertices;
        virtual int  search_vertex_index(const Vertex &vertex);
        virtual bool search_vertex(Vertex &v); //return bool if a vertex exist in a graph;
        virtual bool remove_vertex(Vertex &vertex);
        
        // //edges
        virtual bool add_edge(Edge &e);
        virtual bool add_edges(Edge *eArray, int size);
        virtual bool remove_edge(Edge& e);

        virtual int search_edge_index(const Edge &e);
        virtual bool search_edge(const Edge &e);//return bool if edges exist in a graph

        // virtual void display(Vertex &v) =0; //display the path that contains the vert

        // virtual void display() =0; //display the path that contains the edge;
        
        virtual void display() const; //display the whole graph with your iwn defined format
        virtual string to_string() const; //convert the whole graph to a string such as 1-2-4--5; 1-3-4; note: each different path is separeted by a ';'
        virtual bool clean(); //remove all the vertices and edges


        Edge* get_edges() const;
        //operator overloads
        const Vertex& operator[](int) const;        

};

#endif