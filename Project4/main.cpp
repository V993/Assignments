/*
    Leonardo Matone
    Project 4, Maze Solutions
    .cpp file to test Solutions.cpp in conjunction with Maze. and MazeNode. Files.

*/

#include <iostream>
#include "Maze.cpp"
#include "Solutions.cpp"

using namespace std;

int main() {

    Maze mazeTest("maze_1.csv"); // makes a maze based on maze_1.csv

    vector<MazeNode *> DFS = solveDFS(mazeTest);

    for (int i = 0; i < DFS.size(); i++) {
        cout << 
    }
    

}