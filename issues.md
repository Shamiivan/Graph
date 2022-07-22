# Cannot instantied obj of DirectedGraph

Error: message undefined reference to `Graph::Graph()'

Why do we need the constructor of graph? 

**Solved**: DirectedGraph is both a DirectedGraph AND A graph thus it needs both constructors 