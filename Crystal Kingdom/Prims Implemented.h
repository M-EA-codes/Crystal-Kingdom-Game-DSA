//#pragma once
//#include <iostream>
//#include"graph_operations.h"
////#include <cstring>
//#include<cstring>
//using namespace std;
//
//const int MAX_SIZE = MAP_SIZE * 2;
//
//int prim(int** graph, int numVertices) {
//    int parent[MAX_SIZE]; // to store the parent of each vertex in the MST
//    int key[MAX_SIZE]; // to store the key value of each vertex
//    bool visited[MAX_SIZE]; // to keep track of whether each vertex has been visited
//    memset(visited, false, sizeof visited);
//
//    // initialize key values to a very large number
//    for (int i = 0; i < numVertices; i++) {
//        key[i] = INT_MAX;
//    }
//
//    // the first vertex is always the root, so we set its key to 0
//    key[0] = 0;
//    parent[0] = -1; // no parent for the root
//
//    // repeat for numVertices - 1 times to add all vertices to the MST
//    for (int i = 0; i < numVertices - 1; i++) {
//        // find the vertex with the minimum key value among those that haven't been visited
//        int minKey = INT_MAX;
//        int u = -1;
//        for (int j = 0; j < numVertices; j++) {
//            if (!visited[j] && key[j] < minKey) {
//                minKey = key[j];
//                u = j;
//            }
//        }
//
//        visited[u] = true; // mark the vertex as visited
//
//        // update the key values of all adjacent vertices that haven't been visited
//        for (int v = 0; v < numVertices; v++) {
//            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
//                parent[v] = u;
//                key[v] = graph[u][v];
//            }
//        }
//    }
//
//    // calculate the total weight of the MST and return it
//    int totalWeight = 1;
//    for (int i = 1; i < numVertices; i++) {
//        totalWeight += graph[i][parent[i]];
//    }
//    return totalWeight;
//}
//
//
//
//
//
//
////#include <iostream>
////
////// define the size of the map
////const int MAP_SIZE = 16;
////const int MAP_SIZE_SQRT = 4;
////
////// create an adjacency matrix (initially all zeros)
////int entityMatrix[MAP_SIZE][MAP_SIZE] = { 0 };
////
////// function to add the minimum weighted edge to MST
////void addEdgeToMST(int parent[], int key[], bool mstSet[]) {
////    // initialize the minimum value
////    int min = INT_MAX, min_index;
////
////    for (int i = 0; i < MAP_SIZE; i++) {
////        if (mstSet[i] == false && key[i] < min) {
////            min = key[i];
////            min_index = i;
////        }
////    }
////
////    mstSet[min_index] = true;
////
////    for (int j = 0; j < MAP_SIZE; j++) {
////        if (entityMatrix[min_index][j] != 0 && mstSet[j] == false && entityMatrix[min_index][j] < key[j]) {
////            parent[j] = min_index;
////            key[j] = entityMatrix[min_index][j];
////        }
////    }
////}
////
////// function to print the MST
////void printMST(int parent[]) {
////    std::cout << "Edge \tWeight\n";
////    for (int i = 1; i < MAP_SIZE; i++) {
////        std::cout << parent[i] << " - " << i << "\t" << entityMatrix[i][parent[i]] << std::endl;
////    }
////}
////
////// function to create the MST using Prim's algorithm
////void primMST(int graph[MAP_SIZE][MAP_SIZE], int start) {
////    int parent[MAP_SIZE]; // array to store the MST
////    int key[MAP_SIZE]; // array to store the minimum weights of the edges
////    bool mstSet[MAP_SIZE]; // array to store whether a vertex is in the MST or not
////
////    // initialize all keys as INFINITE and mstSet[] as false
////    for (int i = 0; i < MAP_SIZE; i++) {
////        key[i] = INT_MAX;
////        mstSet[i] = false;
////    }
////
////    // set the first vertex as the starting vertex
////    key[start] = 0;
////    parent[start] = -1;
////
////    for (int count = 0; count < MAP_SIZE - 1; count++) {
////        // add the minimum weighted edge to MST
////        addEdgeToMST(parent, key, mstSet);
////    }
////
////    // print the MST
////    printMST(parent);
////}
////
////// Implementation of Prim's Algorithm to find MST
////void primMST(int graph[MAP_SIZE][MAP_SIZE], int startVertex) {
////    // initialize all variables to default values
////    int key[MAP_SIZE], parent[MAP_SIZE];
////        bool mstSet[MAP_SIZE];
////    for (int i = 0; i < MAP_SIZE; i++) {
////        key[i] = INT_MAX;
////        mstSet[i] = false;
////    }
////
////    // set the key value of the startVertex to 0
////    key[startVertex] = 0;
////    parent[startVertex] = -1;
////
////    // iterate over all vertices in the graph
////    for (int i = 0; i < MAP_SIZE - 1; i++) {
////        // get the vertex with the minimum key value from the set of vertices
////        int u = minKey(key, mstSet);
////
////        // add u to the MST set
////        mstSet[u] = true;
////
////        // update the key value and parent index of all adjacent vertices of u
////        for (int v = 0; v < MAP_SIZE; v++) {
////            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
////                parent[v] = u;
////                key[v] = graph[u][v];
////            }
////        }
////    }
////
////    // print the MST
////    printMST(parent, graph);
////}
////
////// function to find the vertex with minimum key value
////int minKey(int key[], bool mstSet[]) {
////    // initialize min value
////    int min = INT_MAX, min_index;
////
////    for (int v = 0; v < MAP_SIZE; v++)
////        if (mstSet[v] == false && key[v] < min)
////            min = key[v], min_index = v;
////
////    return min_index;
////}
////
////// function to print the MST
////void printMST(int parent[], int graph[MAP_SIZE][MAP_SIZE]) {
////    std::cout << "Edge \tWeight\n";
////    for (int i = 1; i < MAP_SIZE; i++)
////        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
////}
////