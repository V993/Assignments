#include "Maze.cpp"

using namespace std;

namespace solutions
{

int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

bool canTravel(MazeNode *a_node)
{
    if (a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

// Depth-First Search.
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
//      Vector of MazeNodes through the entire path of the maze.
std::vector<MazeNode *> solveDFS(Maze &a_maze)
{
    //boolean visited array
    

} // end DFS

// Breadth-First Search
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
//      Vector of MazeNodes through the entire path of the maze.
std::vector<MazeNode *> solveBFS(Maze &a_maze)
{
} // end BFS

// Dead-End Filling Search.
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
//      Vector of MazeNodes through the entire path of the maze.
std::vector<MazeNode *> solveDEF(Maze &a_maze)
{
} // end DEF

// Personal algorithm.
// Optimization of past algorithms or an algorithm that already exists.
// Lowest run times recieve 5 points extra credit. Best submission: 10 points extra.
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
//      Vector of MazeNodes through the entire path of the maze.
std::vector<MazeNode *> solveCustom(Maze &a_maze)
{
} // end solveCustom

} // namespace solutions
