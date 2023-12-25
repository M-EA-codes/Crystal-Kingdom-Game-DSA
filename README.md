# Crystal Kingdom Game using DSA

## Project Overview
The Quest for the Crystal Kingdom is an interactive game where the player embarks on a journey through an enchanted forest. The objective is to retrieve a legendary crystal while overcoming obstacles, collecting rewards, and strategizing paths to reach the destination.

## Project Structure
- **AVL Tree**: Implemented to manage the player's inventory of item scores.
- **Pathfinding Algorithms**:
  - Floyd's Algorithm: Calculates the shortest path considering obstacles and enemies.
  - Prim's Algorithm: Finds the minimum spanning tree, considering forest entities.
  - Kruskal's Algorithm: Determines the minimum spanning tree considering entity locations.
  - Dijkstra's Algorithm: Finds the shortest path from the player's current location to the crystal, considering obstacles and enemies.

## Game Map Details
The forest map consists of various entities denoted by specific symbols:
- **C**: Clear path
- **J**: Jewel
- **P**: Potion
- **W**: Weapon
- **%**: Death point
- **#**: Obstacle
- **&**: Dragon
- **$**: Goblin
- **@**: Werewolf
- **\***: Crystal (goal point)

Entities include safe paths, obstacles, rewards, enemies, and death points. Interacting with entities impacts the player's score and progress.

## Expected Outcomes
1. Shortest paths between areas in the forest.
2. Shortest path from the player's current location.
3. Minimum spanning tree using Prim's and Kruskal's algorithms.
4. Dynamic scoring system with rewards, enemy encounters, and final score calculation.
5. Menu features include pathfinding options and scoring updates.

## Usage
- **Algorithms**: Implemented from scratch in C++ without pre-built libraries or APIs.
- **Documentation**: The code is well-documented for clarity and ease of understanding.

## How to Run
1. Compile the code using a C++ compiler.
2. Execute the compiled binary to start the game.
3. Follow the in-game prompts for navigation, pathfinding, and interaction.

**Disclaimer**: This was a Project which was implemented with by 3 members including me.
