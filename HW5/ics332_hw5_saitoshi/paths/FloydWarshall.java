package paths;

/*
 * The Floyd-Warshall algorithm is used to find the shortest path between
 * all pairs of nodes.
 * 
 * The running time of the algorithm is O(n^3), being n the number of nodes in
 * the graph.
 *
 * This implementation is self contained and has no external dependencies. It 
 * does not try to be a model of good Java OOP, but a simple self contained 
 * implementation of the algorithm.
 *
 */

import java.util.Arrays;
import java.util.Random;

public class FloydWarshall {

    // graph represented by an adjacency matrix
    private double[][] graph;

    private long seed;

    public FloydWarshall(int n, long seed) {
        this.graph = new double[n][n];
        this.seed = seed;
        initGraph(seed);
    }

    private void initGraph(long seed) {
        Random rng = new Random(seed);
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                if (rng.nextFloat() < 1.0 / (10 + 10  * seed)) {
                    graph[i][j] = Double.POSITIVE_INFINITY;
                } else {
                    graph[i][j] = 1 + seed / 2520.0;
                }
            }
        }
    }

    // average all-pairs shortest path
    public void floydWarshall() {
        double[][] distances;
        int n = this.graph.length;
        distances = Arrays.copyOf(this.graph, n);

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }

        double average_distance = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                average_distance += distances[i][j];
            }
        }
        System.out.println("Ran Floyd-Warshall on Graph #" + String.format("%1$4s", this.seed) +": " + (int)average_distance);
    }

}
