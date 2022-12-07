package a3;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Graph<V> {
    private int numEdges;
    private int numVertices;
    private int[][] matrix;
    private List<Integer> mark;
    private int[] count;
    private DDictionary courses;
    /*Constructors*/
    public void Graph() {
    }

    ;

    public void Graph(int n) {
        init(n);
    }

    /*Initiate graph with n vertices*/
    public void init(int _numVertices) {
        numEdges = 0;
        numVertices = _numVertices;
        mark = new List<>(_numVertices);
        courses = new DDictionary(_numVertices);
        count = new int[_numVertices];
        matrix = new int[_numVertices][_numVertices];

    }


    /*Created Graph from  file
     * BufferedReader : object that can read files
     * */
    Graph(BufferedReader reader) {
        int VISITED = 1;
        int UNVISITED = 0;

        try {

            String line = null;
            StringTokenizer token;
            boolean undirected = false;
            String course,prereq;

            //read the first line
            line = reader.readLine();
            assert (line != null) : "Unable to read number of vertices";

            //check for comment
            while (line.charAt(0) == '#') {
                assert (line = reader.readLine()) != null : "Unable to read number of vertices";
            }


            token = new StringTokenizer(line); //break full string into individual words

            // get the second line, it contains information about the number of vertices
            int numVertices = Integer.parseInt(token.nextToken());

            init(numVertices);

            for (int i = 0; i < numVertices; i++) {
                setMark(i, UNVISITED);
            }


            //check for type of graph(directed or undirected)
            assert (line = reader.readLine()) != null :
                    "Unable to read graph type";

            if (line.charAt(0) == 'U')
                undirected = true;
            else if (line.charAt(0) == 'D')
                undirected = false;
            else assert false : "Bad graph type: " + line;

            //
            while ((line = reader.readLine()) != null) {
                token = new StringTokenizer(line);
                course = token.nextToken();
                prereq = token.nextToken();


                //map vertices to positions
                courses.insert(course);
                courses.insert(prereq);



                //get position of course and prer
                int i= courses.returnKey(course);
                int j= courses.returnKey(prereq);
//                 System.out.println("Course : " + course + " Prereq:  " + prereq + " ");
//                System.out.println(i + " " + j);
                setEdge(i, j, 1);

            }


        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public int numberOfVertices() {
        return numVertices;
    }

    public int numberOfEdges() {
        return numEdges;
    }

    /*Loop through the whole graph and return the first vertex connected to a given vertex */
    public int firstNeighbor(int v1) {
        for (int v2 = 0; v2 < numVertices; v2++) {
            if (isEdge(v1, v2)) return v2;
        }
        return -1;
    }

    public int next(int vertex, int weight) {
        return 0;
    }

    public void setEdge(int i, int j, int weight) {
        assert weight > 0 : "Cannot set weight to 0 or negative number";
        boolean thereIsNoEdge = !isEdge(i,j);
        if (thereIsNoEdge) numEdges++;
        matrix[i][j] = weight;
    }

    public void delEdge(int i, int j) {
        matrix[i][j] = 0;
        numEdges--;
    }


    public int weight(int i, int j) {
        return matrix[i][j];
    }

    /*maps the matrix to other values */
    public void setMark(int vertPos, int value) {
        mark.setValue(vertPos, value);
    }

    public int getMark(int vertPos) {
        return (int) mark.getValueAtPos(vertPos);
    }



    public boolean isPrerequesite(String sourceCourse, String destinationCourse){
        int pos1 = courses.returnKey(sourceCourse);
        int pos2 = courses.returnKey(destinationCourse);
        return isEdge(pos1,pos2);
    }

    boolean isEdge(int i, int j) {
        //check for i and j
        boolean vNothere =  i < 0 || i > numVertices || j < 0 || j > numVertices;
        if(vNothere) return false;
        return matrix[i][j] != 0;
    }




    public void print(StringBuffer out) {
        int i, j;
        for (i =0; i<numVertices; i++){
            out.append(courses.returnValue(i) + " ");
            for(j=0; j<numVertices; j++){
                if(weight(i,j)== 0) out.append("0 ");
                else out.append(weight(i,j) + " ");
            }
            out.append("\n");
        }
        out.append("List of vertices\n");
        for(i=0; i< numVertices; i++){
            out.append(courses.returnValue(i) + " ");
        }
    }
}

