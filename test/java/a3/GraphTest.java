package a3;

import org.junit.jupiter.api.Test;

import java.io.*;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class GraphTest {
    static Graph<Integer> graph;
    static StringBuffer out = new StringBuffer(100);
    @Test
    void createGraph(){
        try {
            String PATH = "/Users/shamiivan/IdeaProjects/a3/src/main/resources/elec.gph";
            FileReader file = new FileReader(PATH);
            BufferedReader buffer = new BufferedReader(file);


            graph = new Graph<>(buffer);
            graph.print(out);
            System.out.println(out.toString());
            //assertEquals(4, graph.numberOfVertices());
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

    }


}