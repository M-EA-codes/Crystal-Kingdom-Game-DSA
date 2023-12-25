/**********************************************************************************************************
 *  game_algorithms.h contains the implementation of the following algorithms:                            *
 *                                                                                                        *
 *  1. Floyd-Warshall algorithm to find the shortest path between any two areas in the forest(map).       *
 *  2. Dijkstra's algorithm to find the shortest path from the player's current position to the crystal.  *
 *  3. Prim's algorithm to find the minimum spanning tree of the forest(map).                             *
 *  4. Kruskal's algorithm to find the minimum spanning tree of the forest(map).                          *
 *                                                                                                        *
***********************************************************************************************************/

#ifndef GAME_ALGORITHMS_H
#define GAME_ALGORITHMS_H

#include "graph_operations.h"
#include <queue>
#include <algorithm>

// implementation of Floyd-Warshall algorithm to find the shortest path between any two areas in the forest(map)
void floydWarshall(int** entityMatrix, int MAP_SIZE) {
    // create a copy of the entity matrix
    int** distance = new int* [MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        distance[i] = new int[MAP_SIZE];
        for (int j = 0; j < MAP_SIZE; j++) {
            distance[i][j] = entityMatrix[i][j];
        }
    }

    // iterate over the matrix and find the shortest path between any two areas in the forest(map)
    for (int k = 0; k < MAP_SIZE; k++) {
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                // if the distance between i and j is greater than the distance between [i and k] + [k and j]
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    // update the distance between i and j
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }

        /* __FOR__DEBUGGING__PURPOSES__ */
        // last iteration shows which matrix gives the shortest path between each pair of nodes
        if (k == MAP_SIZE - 1)
            std::cout << "\nentityMatrix^" << k + 1 << " gives the shortest path between each pair of nodes.\n";
    }

    /* __FOR__DEBUGGING__PURPOSES__ */
    // print the shortest distance matrix
  //  std::cout << "\nShortest distance matrix: \n";
 /*   for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (distance[i][j] == 100 || i == j)
                std::cout << "INF" << " ";
            else
                std::cout << distance[i][j] << " ";
        }*/
        std::cout << std::endl;
//    }
}

// implementation of Dijkstra's algorithm to find the shortest path from the player's current position to the crystal
void dijkstra(int** entityMatrix, int MAP_SIZE, int playerPosition, int crystalPosition) {
    // create a copy of the entity matrix
    int** distance = new int* [MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        distance[i] = new int[MAP_SIZE];
        for (int j = 0; j < MAP_SIZE; j++) {
            distance[i][j] = entityMatrix[i][j];
        }
    }

    // create a boolean array to keep track of the visited nodes
    bool* visited = new bool[MAP_SIZE];
    // initialize the array with false
    for (int i = 0; i < MAP_SIZE; i++) {
        visited[i] = false;
    }

    // create an array to keep track of the distance from the player's current position to each node
    int* distanceFromPlayer = new int[MAP_SIZE];
    // initialize the array with infinity
    for (int i = 0; i < MAP_SIZE; i++) {
        distanceFromPlayer[i] = 100;
    }

    // set the distance from the player's current position to itself to 0
    distanceFromPlayer[playerPosition] = 0;

    // iterate over the matrix and find the shortest path from the player's current position to the crystal
    for (int i = 0; i < MAP_SIZE; i++) {
        // find the node with the minimum distance from the player's current position
        int minDistance = 100;
        int minDistanceNode = 0;
        for (int j = 0; j < MAP_SIZE; j++) {
            if (visited[j] == false && distanceFromPlayer[j] <= minDistance) {
                minDistance = distanceFromPlayer[j];
                minDistanceNode = j;
            }
        }

        // mark the node as visited
        visited[minDistanceNode] = true;

        // update the distanceFromPlayer array
        for (int j = 0; j < MAP_SIZE; j++) {
            // if the node is not visited and the distance between the minDistanceNode and j is not infinity 
            if (visited[j] == false && distance[minDistanceNode][j] != 100 && distanceFromPlayer[minDistanceNode]
                + distance[minDistanceNode][j] < distanceFromPlayer[j]) {

                // update the distanceFromPlayer array
                distanceFromPlayer[j] = distanceFromPlayer[minDistanceNode] + distance[minDistanceNode][j];
            }
        }
    }

    /* __FOR__DEBUGGING__PURPOSES__ */
    // print the distanceFromPlayer array
    std::cout << "\nDistance from player's current position to each node: \n";
    for (int i = 0; i < MAP_SIZE; i++) {
        std::cout << distanceFromPlayer[i] << " ";
    }
    std::cout << std::endl;

    // print the shortest distance from the player's current position to the crystal
    std::cout << "\nShortest distance from player's current position to the crystal: " << distanceFromPlayer[crystalPosition] << std::endl;
}

// implementation of Prim's algorithm to find the minimum spanning tree of the forest(map)
// find the parent of the node
int findParent(int* parent, int node) {
    // if the parent of the node is -1, then return the node
    if (parent[node] == -1) {
        return node;
    }

    // else, find the parent of the parent of the node
    return findParent(parent, parent[node]);
}

// implementation of Kruskal's algorithm to find the minimum spanning tree of the forest(map)
struct Edge {
    int src;  // starting vertex of the edge
    int dst;  // ending vertex of the edge
    int weight;  // weight of the edge
};

void kruskal(int** entityMatrix, int MAP_SIZE, int MAX_EDGES) {
    // create an array of edges
    Edge* edges = new Edge[MAX_EDGES];
    int edgeIndex = 0;

    // iterate over the entity matrix and add the edges to the edges array
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // if the distance between i and j is not infinity and i is less than j
            if (entityMatrix[i][j] != 100 && i < j) {
                // add the edge to the edges array
                edges[edgeIndex].src = i;
                edges[edgeIndex].dst = j;
                edges[edgeIndex].weight = entityMatrix[i][j];
                edgeIndex++;
            }
        }
    }

    // sort the edges array in ascending order of their weights
    for (int i = 0; i < edgeIndex - 1; i++) {
        for (int j = 0; j < edgeIndex - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // create an array to keep track of the parent of each node
    int* parent = new int[MAP_SIZE];
    // initialize the array with -1
    for (int i = 0; i < MAP_SIZE; i++) {
        parent[i] = -1;
    }

    // create an array to keep track of the edges in the minimum spanning tree
    Edge* mst = new Edge[MAP_SIZE - 1];
    int mstIndex = 0;

    // iterate over the edges array and find the minimum spanning tree
    for (int i = 0; i < edgeIndex; i++) {
        // find the parent of the source vertex
        int srcParent = findParent(parent, edges[i].src);
        // find the parent of the destination vertex
        int dstParent = findParent(parent, edges[i].dst);

        // if the parent of the source vertex is not equal to the parent of the destination vertex
        if (srcParent != dstParent) {
            // add the edge to the minimum spanning tree
            mst[mstIndex] = edges[i];
            mstIndex++;
            // update the parent array
            parent[srcParent] = dstParent;
        }
    }

    /* __FOR__DEBUGGING__PURPOSES__ */
    // print the cost of the minimum spanning tree
    int cost = 0;
    for (int i = 0; i < mstIndex; i++) {
        cost += mst[i].weight;
    }

    std::cout << "\nCost of the minimum spanning tree: " << cost << std::endl;
}

# endif /* GAME_ALGORITHMS_H */