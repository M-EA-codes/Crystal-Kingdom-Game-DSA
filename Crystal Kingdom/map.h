#ifndef MAP_H
#define MAP_H

// include required libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>

// constant map size 20 * 20
const int MAP_SIZE = 400;
const int MAP_SIZE_SQRT = 20; // width and height of the map

// number of entities excluding the crystal (which is the goal) 
const int NUM_ENTITIES = 8;

// map symbols/entities
const char CLEAR_PATH = 'C';
const char JEWEL = 'J';
const char POTION = 'P';
const char WEAPON = 'W';
const char DEATH_POINT = '%';
const char OBSTACLE = '#';
const char DRAGON = '&';
const char GOBLIN = '$';
const char WEREWOLF = '@';
const char CRYSTAL = '*'; // goal

// array of entities for random generation
const char entities[NUM_ENTITIES] = { JEWEL, POTION, WEAPON, DEATH_POINT, OBSTACLE, DRAGON, GOBLIN, WEREWOLF };

// map class for all map related functions (for an organized and modular approach)
class GameMap {
private:
    char** map;// [MAP_SIZE_SQRT] [MAP_SIZE_SQRT] ;

public:
    // default constructor initializes the map with clear paths 
    GameMap() {

        map = new char* [MAP_SIZE_SQRT];
        for (int i = 0; i < MAP_SIZE_SQRT; i++) {
            map[i] = new char[MAP_SIZE_SQRT];
        }


        for (int i = 0; i < MAP_SIZE_SQRT; i++) {
            for (int j = 0; j < MAP_SIZE_SQRT; j++) {
                map[i][j] = CLEAR_PATH;
            }
        }
    }

    // generate a random map (won't be used in the final version)
    void generateRandomMap() {
        srand(time(NULL)); // seed the random number generator with the current time

        // set the crystal at a random location on the map
        int crystalX = rand() % MAP_SIZE_SQRT;
        int crystalY = rand() % MAP_SIZE_SQRT;
        map[crystalX][crystalY] = CRYSTAL;

        // generate random entities on the map 
        for (int i = 0; i < MAP_SIZE_SQRT; i++) {
            for (int j = 0; j < MAP_SIZE_SQRT; j++) {
                if (i == crystalX && j == crystalY) {
                    continue; // skip the crystal location
                }

                // generate a random number between 0 and 8 (inclusive)
                int entityIndex = rand() % NUM_ENTITIES;

                // 35 percent change of generating an entity
                if (rand() % 100 < 35) {
                    map[i][j] = entities[entityIndex];
                }
            }
        }
    }

    // would be used as the testcase (uses python script, 'Game_Map_Script.ipynb')
    void readGameMap() {
        // initialize the map with null characters
        for (int i = 0; i < MAP_SIZE_SQRT; i++) {
            for (int j = 0; j < MAP_SIZE_SQRT; j++) {
                map[i][j] = '\0';
            }
        }

        // read the map from csv file
        std::ifstream mapFile("game_map.csv");
        std::string line;

        // read the map line by line
        int row = 0;
        while (std::getline(mapFile, line)) {
            std::stringstream ss(line);
            std::string cell;
            // read the line cell by cell
            int col = 0;
            while (std::getline(ss, cell, ',')) {
                map[row][col] = cell[0];
                col++;
            }
            row++;
        }

        // close the file
        mapFile.close();
    }

    // draw the game map on the console
    void drawGameMap() {
        std::cout << "--------------" << std::endl;//---------------------------" << std::endl;
        for (int i = 0; i < MAP_SIZE_SQRT; i++) {
            std::cout << "| ";
            for (int j = 0; j < MAP_SIZE_SQRT; j++) {
                std::cout << map[i][j] << " ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "--------------" << std::endl;//---------------------------" << std::endl;
    }

    // get the map size
    int getMapSize() {
        // for the adjacency matrix we need the map to be a square matrix
        return MAP_SIZE;
    }

    char** get_map() 
    {
        return map;
    }

    // get individual map cell
    char getMapCell(int row, int col) {
        return map[row][col];
    }
};

#endif /* MAP_H */