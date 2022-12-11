/*
* Team
* Shami Ivan Senga 40228447
* Rezeq Khader 26777538
* */package a3;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.*;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class GraphTest {
    static Graph<Integer> graph;
    static StringBuffer out = new StringBuffer(100);
    @BeforeEach
    void createGraph(){
        try {
            //get the file
            FileInputStream file= new FileInputStream("courses.gph");
//            System.out.println(file.read());
            BufferedReader buffer = new BufferedReader(new InputStreamReader(new FileInputStream("courses.gph")));

            //create a new graph
            graph = new Graph<>(buffer); //create a 2d representation of a graph presented in the file
            //assertEquals(4, graph.numberOfVertices());
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    @Test
    void testIsPrerequesite(){
        assertEquals(true, graph.isPrerequesite("coen243", "coen244"));
        assertEquals(false, graph.isPrerequesite("coen244", "coen243"));
        assertEquals(true, graph.isPrerequesite("coen231", "coen352"));

    }

    @Test
    void testGetPrerequisitePath(){
        String path = "[coen243, coen244, coen352]";
        String pathForCoen490= "[coen243, coen311, coen390, coen490]";
        assertEquals(path.toString(), graph.getPrerequisitesPath("coen352"));
        assertEquals(pathForCoen490, graph.getPrerequisitesPath("coen490"));

        //test for course that do not have prerequesite
        assertEquals(null, graph.getPrerequisitesPath("243"));
    }

    static void printGraph(){
        graph.print(out);
        System.out.println(out.toString());
    }

    @AfterAll
    static void finish(){
        printGraph();
    }

}