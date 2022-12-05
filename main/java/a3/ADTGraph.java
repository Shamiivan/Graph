package a3;

public interface
ADTGraph<V> {
    public void Init(int n); //Initialize graph with n vertices
    public int numberOfVertices();
    public int numberOfEdges();

    public int firstNeighbor(int vertex); // get the first neighbor of a certain vertex
    public int next(int vertex, int weight); //get the first neighbor of a vertex


    public void setEdge(int i, int j, int weight);
    public void delEdge(int i, int j);

    public boolean isEdge(int i, int j); //returns true if (i,j) is edge

    public int weight(int i, int j); // return the weight of an edge

    //what does a mark do??
    public void setMark(int vertex, int value);

    /*maps the matrix to other values */
    public int getMark(int vertex);

}