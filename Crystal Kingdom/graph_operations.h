#ifndef GRAPH_OPERATIONS_H
#define GRAPH_OPERATIONS_H

#include "map.h"

// Graph class that stores the adjacency matrix of the map 
class Graph {
private:
    // adjacency matrix
    int** entityMatrix;
    // number of vertices
    int numVertices; // MAP_SIZE

public:
    Graph(int MAP_SIZE) {
        // initialize the matrix with zeroes
        this->numVertices = MAP_SIZE; // set the number of vertices to the size of the map
        entityMatrix = new int* [this->numVertices];

        // populate the matrix with zeroes to represent the edges initially
        for (int i = 0; i < numVertices; i++) {
            entityMatrix[i] = new int[this->numVertices];
            for (int j = 0; j < numVertices; j++) {
                entityMatrix[i][j] = 0;
            }
        }
    }

    // get the matrix
    int** getMatrix() {
        return entityMatrix;
    }

    // function to convert the map to adjacency matrix
    void convertToAdjacencyMatrix(GameMap* map) {
        // int MAP_SIZE = map->getMapSize();
        // create an adjacency matrix (initially all zeros)
        // int entityMatrix[MAP_SIZE][MAP_SIZE] = { 0 };

        // iterate over the map and populate the adjacency matrix
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                // as i and j will go from 0 to MAP_SIZE but the map is indexed from 0 to sqrt(MAP_SIZE)
                // we need to convert the indices to the map indices
                // char entity = '\0'; // initialize the entity to null character 
                // if (i >= 0 && i < MAP_SIZE_SQRT && j >= 0 && j < MAP_SIZE_SQRT) {
                //     entity = map->getMapCell(i, j);
                //     // std::cout << map->getMapCell(i, j) << " ";
                // }

                /*
                    i/MAP_SIZE_SQRT gives the row index and i%MAP_SIZE_SQRT gives the column index
                    how this works:
                    i = 0, 1, 2, 3, 4, 5, 6, 7, 8
                    i/MAP_SIZE_SQRT = 0, 0, 0, 1, 1, 1, 2, 2, 2
                    i%MAP_SIZE_SQRT = 0, 1, 2, 0, 1, 2, 0, 1, 2
                */

                // get the entity at the current index (i, j) (map is 2 by 2)
                char entity = map->getMapCell(i / MAP_SIZE_SQRT, i % MAP_SIZE_SQRT);
                // std::cout << entity << " ";
                int edgeWeight = 0; // initialize the edge weight to 0

                if (i == j) {
                    entityMatrix[i][j] = 100; // set the diagonal elements to 100 to avoid self loops
                }

                // check if the entity is an obstacle ('#')
                if (entity == '#') {
                    // set all corresponding rows and columns to 100
                    for (int k = 0; k < MAP_SIZE; k++) {
                        entityMatrix[i][k] = 100;
                        entityMatrix[k][i] = 100;
                    }
                }

                if (entityMatrix[i][j] != 100) {
                    // is not diagnonal but is a neighbor (adjacent) then check if we have moved to the next row
                    if (i == j + 1 && i % MAP_SIZE_SQRT != 0 || i == j - 1 && j % MAP_SIZE_SQRT != 0
                        || i == j + MAP_SIZE_SQRT || i == j - MAP_SIZE_SQRT) {
                        entityMatrix[i][j] = 1; // set the edge weight to 1
                    }
                    else {
                        entityMatrix[i][j] = 100; // is diagonal and neighbor or rest of the cases
                    }
                }
            }
            // std::cout << std::endl;
        }

        /* __FOR__DEBUGGING__PURPOSES__ */
        //std::cout << "Adjacency Matrix: " << std::endl;
        //std::cout << " ";

        //for (int i = 0; i < MAP_SIZE; i++) {
        //    std::cout << i << "\t";
        //}

        std::cout << std::endl;

        //// print the adjacency matrix
        //for (int i = 0; i < MAP_SIZE; i++) {
        //    std::cout << i << " ";
        //    for (int j = 0; j < MAP_SIZE; j++) {
        //        std::cout << entityMatrix[i][j] << "\t";
        //    }
        //    std::cout << "\t" << std::endl;
        //}
    }
};

#endif /* GRAPH_OPERATIONS_H */

