#include "map.h"
#include "graph_operations.h"
#include "game_algorithms.h"
#include "Prims Implemented.h"
#include"Simulation.h"
 using namespace std;

// driver code
int main(void){
    // create a map object and generate a random map 
    GameMap map;
    // initializes the map with entities
    map.readGameMap();
    // draw the map on the console
    map.drawGameMap(); 
    // get the size of the map and call the constructor of the Graph class
    Graph entityGraph(map.getMapSize());
    // convert the map to adjacency matrix
    entityGraph.convertToAdjacencyMatrix(&map);
    // get the adjacency matrix
    int** entityMatrix = entityGraph.getMatrix();
    // call the floydWarshall algorithm to find the shortest path between any two areas in the map
    floydWarshall(entityMatrix, map.getMapSize());
    kruskal(entityMatrix, 9, 30);
    game_simulation(map.get_map());
    return 0;
}