package a3;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.*;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class GraphTest {
    static Graph<Integer> graph;
    static StringBuffer out = new StringBuffer(100);
    @BeforeEach
    void createGraph(){
        try {
            String PATH = "/Users/shamiivan/IdeaProjects/a3/src/main/resources/elec.gph";
            FileReader file = new FileReader(PATH);
            BufferedReader buffer = new BufferedReader(file);


            graph = new Graph<>(buffer); //create a 2d representation of a graph presented in the file
            graph.print(out);
            System.out.println(out.toString());
            //assertEquals(4, graph.numberOfVertices());
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

    }

    @Test


    void testForEdge(){
        assertEquals(true, graph.isPrerequesite("elec311", "elec273"), "There is edge function is not working");

    }

}