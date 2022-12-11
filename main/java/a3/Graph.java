package a3;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Graph<V> {
    private int numEdges;
    private int numVertices;
    private int[][] matrix;
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
        courses = new DDictionary(_numVertices);
        count = new int[_numVertices];
        matrix = new int[_numVertices][_numVertices];

    }


    /*Created Graph from  file
     * BufferedReader : object that can read files
     * */
    Graph(BufferedReader reader) {

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


            //the first line without a comment contains information about the number of vertices
            token = new StringTokenizer(line); //break full string into individual words
            int numVertices = Integer.parseInt(token.nextToken());

            //create graph with
            init(numVertices);

            //check for type of graph(directed or undirected)
            assert (line = reader.readLine()) != null :
                    "Unable to read graph type";

            if (line.charAt(0) == 'U')
                undirected = true;
            else if (line.charAt(0) == 'D')
                undirected = false;
            else assert false : "Bad graph type: " + line;

            //reade every line add the course into the matrix and create a new edge
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
                setEdge(i, j, 1);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public String getPrerequisitesPath(String courseCode){
        ArrayList<String>  path= new ArrayList<>();
        String prereqPath = "";
        String course = courseCode;
        path.add(course);
        while(hasPrerequesite(course)){
            addToPath(path,course);
            course = path.get(0);
        }
        //test is
        if(path.size() == 1){
            return null;
        }
        return path.toString();
    }

    //compare 2 course and determine if the first is the prereq of the second
    public boolean isPrerequesite(String sourceCourse, String destinationCourse){
        int pos1 = courses.returnKey(destinationCourse);
        int pos2 = courses.returnKey(sourceCourse);
        return isEdge(pos1,pos2);
    }

    //add the first prerequisite found
    public ArrayList<String> addToPath(ArrayList<String> path, String courseCode){
        int course = courses.returnKey(courseCode);
        //loop through prereq and check if there is an edge
        for(int prereq=0; prereq <numVertices; prereq++){
            if(isEdge(course,prereq)){
                String value = courses.returnValue(prereq);
                path.add(0,value);
                break;
            }
        }
        return path;
    }


    //return true if a course has at least one prereq
    public boolean hasPrerequesite(String courseCode){
        int pos = courses.returnKey(courseCode);
        for(int j=0; j <numVertices; j++){
            if(isEdge(pos,j)) return true;
        }
        return false;
    }
    public void setEdge(int i, int j, int weight) {
        assert weight > 0 : "Cannot set weight to 0 or negative number";
        boolean thereIsNoEdge = !isEdge(i,j);
        if (thereIsNoEdge) numEdges++;
        matrix[i][j] = weight;
    }



    public int weight(int i, int j) {
        return matrix[i][j];
    }


    boolean isEdge(int i, int j) {
        //check for i and j
        boolean vNotThere =  i < 0 || i > numVertices || j < 0 || j > numVertices;
        if(vNotThere) return false;
        return matrix[i][j] != 0;
    }




    public int numberOfVertices() {
        return numVertices;
    }

    public int numberOfEdges() {
        return numEdges;
    }

    public void delEdge(int i, int j) {
        matrix[i][j] = 0;
        numEdges--;
    }
    public void print(StringBuffer out) {
        out.append("Showing Adjecency matrix of graph\n");
        int i, j;
        for (i =0; i<numVertices; i++){
            out.append(courses.returnValue(i) + " ");
            for(j=0; j<numVertices; j++){
                if(weight(i,j)== 0) out.append("0 ");
                else out.append(weight(i,j) + " ");
            }
            out.append("\n");
        }
    }
}

