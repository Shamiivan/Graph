#include "Vertex.h";
#ifndef EDGE
#define EDGE
    class Edge
    {
    private:
      Vertex* start;
      Vertex* end;
    public:
        Edge(Vertex s, Vertex e){
          start = &s;
          end = &e;
        };
        ~Edge(){
          delete start;
          delete end;
        };
    };
    
    
#endif