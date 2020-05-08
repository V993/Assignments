/*
    Title: Solutions.cpp
    Author: Leonardo Matone
    Description: source file to navigate and return MazeNode paths through a link-based maze
    Dependencies: Maze.cpp, Maze.hpp, MazeNode.cpp, MazeNode.hpp
*/

#include "Maze.cpp"
#include <iostream>
#include <queue>

using namespace std;

namespace solutions
{


int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    // // check nesw directions to see if they are walls. Count if wall. return count.
    // for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    // {
    //     if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
    //     {
    //         wall_counter++;
    //     }
    // }
    
    MazeNode * direction;
    for (int i = 0; i < 4; i++) 
    {
        direction = a_node->getDirectionNode((directions::nesw)i);
        if (direction == nullptr)
            continue;
        if (direction->isWall()) 
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

bool inVector(vector<MazeNode*> aVector, MazeNode* aNode) {
    MazeNode* testNode;
    for (int i = 0; i < aVector.size(); i++) {
        testNode = aVector[i];
        if (testNode == aNode) 
            return true;
    }
    return false;
}

/*  Applications:
        Detecting cycles in graphs
        Path finding
        Finding strongly connected components in a graph

    Time  : O(V + E)
    Space : O(n) where n is the size of the maze
    Explores each option individually to max distance.
    Memory efficient, not speed efficient.
*/
//recursive helper function for solveDFS
bool recursiveDFS(MazeNode* a_node, MazeNode* endNode, vector<MazeNode> &visitedVector) 
{
    // to test if we are backtracking (as it is a precondition for a_node on the first pass to be unvisited)
    bool alreadyVisited = a_node->isVisited();
    // as we are currently on this node, we mark it visited and push back.
    a_node->setVisited();
    visitedVector.push_back(*a_node);

    //checks all 4 directions. If an option to move is found it calls itself with that directional node.
    for (int i = 0; i < 4; i++) {
        MazeNode *direction = a_node->getDirectionNode((directions::nesw)i);
        // if the direction is null (past the wall) just continue through the loop.
        if (direction == nullptr)
            continue;
        /*  if the node in that direction is not a wall and it has not been visited, 
            make the recursive call with the direction node as the target.  */
        if ((!direction->isWall()) && (!direction->isVisited())) 
        {
            if (direction == endNode)
            { // if the next direction is the endNode, return true and break out of the algorithm. 
                visitedVector.push_back(*direction);
                return true;
            }
            // if it's not the end node:
            return recursiveDFS(direction, endNode, visitedVector);
        }
        //if our node fails this condition, it must either be a wall or visited.
    }
    //if all directions fail our criteria, pop back in our visited vector and make a recursive call with the previous vector.
    visitedVector.pop_back();

    // if the node was already visited, pop back again to accomodate while backtracking.
    if (alreadyVisited)
        visitedVector.pop_back();
    // backtrack to the previous node.
    MazeNode * previousNode = &visitedVector[visitedVector.size()];
    return recursiveDFS(previousNode, endNode, visitedVector);
}

// Depth-First Search.
// @param a class Maze maze to be searched.
// @returns ordered vector with the path nodes from start point to end point.
std::vector<MazeNode> solveDFS(Maze &a_maze)
{
    // establish a node to chase go through each viable path, starting at the firstNode.
    MazeNode * startNode = new MazeNode();
    startNode = a_maze.getFirstNode();

    // establish a target node to be our endpoint, to test if it has been reached.
    MazeNode * endNode = new MazeNode();
    endNode = a_maze.getLastNode();

    // establish a vector of visited nodes
    vector<MazeNode> visited;

    // call the recursive algorithm to modify our visited vector
    recursiveDFS(startNode, endNode, visited);

    return visited;
} // end DFS

/*  Applications:
        Shortest path to the end
        GPS navigation systems (all neighboring locations)
        Similar to Dijkstra's Single Source Shortest Path

    Time  : O(V + E)
    Space : O(V)
    Explores each node around a depth before continuing.
    Less memory efficient, same time complexity as DFS.
*/
//Breadth-First Search
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
std::vector<MazeNode> solveBFS(Maze &a_maze)
{
    /* SETUP */
        // get the first node in the maze
        MazeNode * originNode = a_maze.getFirstNode();

        //set origin as visited
        originNode->setVisited();

        //establish queue of vectors containing paths
        queue<vector<MazeNode>> traversalVectors;

        //construct first path, including first node
        vector<MazeNode> aPath;
        // aPath.push_back(*originNode);

        //push first vector into queue of vectors
        traversalVectors.push(aPath);

        //establish our second queue containing the nodes to be visited
        queue<MazeNode> vertexQueue;
        vertexQueue.push(*originNode);

    // cout << "queues successfully set up, entering while loop: " << endl;

    while (!vertexQueue.empty()) {
        MazeNode a_node = vertexQueue.front();
        // cout << "NEW iteration, examining: " << a_node.getStrPos() << endl;

        // cout << "popping this node from queue" << endl;
        vertexQueue.pop();
        // cout << "copying the peek() of traversalVectors" << endl;
        vector<MazeNode> currentPath = traversalVectors.front();
        currentPath.push_back(a_node);
        // cout << "popping this vector from queue" << endl << endl;
        traversalVectors.pop();

        // cout << "START FOR LOOP:" << endl;
        for (int i = 0; i < 4; i++) {
            // if the direction is null, continue to the next iteration of the loop.
            MazeNode * direction = a_node.getDirectionNode((directions::nesw)i);
            if (direction == nullptr)
                continue;
            // cout << "   testing direction: " << i << endl;
            /** if the node is accessible:
             * mark it as visited,
             * add it to the current path, 
             * and add this node to the queue. */
            // cout << "   let me see if I can travel: " << endl;
            if (canTravel(direction))
            {
                // cout << "   I can travel! Setting this node to visited." << endl;
                // cout << "-------------- DIRECTION " << i << ", " << direction->getStrPos() << " --------------" << endl;
                direction->setVisited();
                // cout << "adding to that vector I copied" << endl;
                // currentPath.push_back(*direction);

                if (direction == a_maze.getLastNode()) {
                    currentPath.push_back(*direction);
                    // cout << "this direction is the end! It's been added to the vector, and I now return said vector to caller." << endl;
                    return currentPath;
                }
                // cout << "adding that vector to the queue of vectors" << endl;
                traversalVectors.push(currentPath);
                // cout << "adding this direction to vertexQueue" << endl;
                vertexQueue.push(*direction);
            }
        }
        // cout << "-------------- NEXT NODE --------------" << endl << endl;
    }

    // cout << "I failed! " << endl;
    /** If the program fails to find the end */
    return aPath;
} // end BFS

// Dead-End Filling Search.
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
std::vector<MazeNode> solveDEF(Maze &a_maze)
{
    /**     First step: Find all dead ends. 
     * establish a startnode from our maze
     * establish a queue of nodes to visit
     * push our startnode into the queue to start it off
     * establish a vector which will contain our dead ends
     * designate a vector of mazeNode pointers to designate what pointers we have traversed
     *      (as to avoid marking them "visited" for when we find the solution)
     * push back our startNode into our visitedNodes
    */
    MazeNode * startNode = a_maze.getFirstNode();
    queue<MazeNode> nodesToVisit;
    nodesToVisit.push(*startNode);
    vector<MazeNode*> deadEnds;
    vector<MazeNode*> visitedNodes;
    visitedNodes.push_back(startNode);

    /** with our setup complete, we now move into the while 
     * loop to iterate through each node, as long as our queue 
     * is empty. Follows almost the same algorithm as the 
     * Breadth-First Search traversal. */
    while(!nodesToVisit.empty()) {
        MazeNode * a_node = &nodesToVisit.front();

        /** Test to see the number of walls. getNumberOfWalls() 
         * has been modified from the original function, to 
         * accomodate for this algorithm. If the number of walls 
         * is 3 (a dead end), we push back into our original 
         * dead-ends vector. */
        if (getNumberOfWalls(a_node) == 3) {
            deadEnds.push_back(a_node);
        }

        nodesToVisit.pop();
        for (int i = 0; i < 4; i++) {
            MazeNode * direction = a_node->getDirectionNode((directions::nesw)i);
            if (direction == nullptr)
                continue;

            if (canTravel(direction) && !inVector(visitedNodes, direction))
            {   
                visitedNodes.push_back(direction); // replaces the need to mark nodes as visited
                nodesToVisit.push(*direction);
                visitedNodes.push_back(direction);
            } // end if 
        } // end for
    } // end while

    visitedNodes.clear(); //destroy the pointers within visitedNodes.

    /**     Second Step: Isolate paths to dead ends.
     * for each dead end:
     *      scan surroundings to see the number of walls
     *      while the number of walls is greater than or equal to 2,
     *          traverse the maze, until the condition is no longer met
     *          mark each traversed node as visited
     *          (we have found a junction)
     * break out of while, repeat for other dead ends.
    */
   
    // iterate through each dead end
    for (int j = 0; j < deadEnds.size(); j++) {
        MazeNode * deadEndStart = deadEnds[j];
        int numWalls = 3; // as deadEndStart is a dead end
        queue<MazeNode*> toTravel;
        toTravel.push(deadEndStart);
        while (numWalls >= 2) { //while the node is not in a junction (2 > walls)
            MazeNode* a_node = toTravel.front();
            toTravel.pop();
            a_node->setVisited();
            for (int k = 0; k < 4; k++) {
                MazeNode * direction = a_node->getDirectionNode((directions::nesw)k);
                if (direction == nullptr) // for cases with mazes not surrounded by walls
                    continue;
                if (canTravel(direction)) {
                    toTravel.push(direction);
                    numWalls = getNumberOfWalls(direction);
                }
            }
        }
    }

    /**     Third Step: Traverse the remaining path to the end.
     * 
    */

    bool pathFound = false;

    vector<MazeNode> pathToEnd;
    pathToEnd.push_back(*startNode);
    startNode->setVisited();
    nodesToVisit.push(*startNode); 

    while (!pathFound) {
        MazeNode a_node = nodesToVisit.front();
        nodesToVisit.pop();

        for (int l = 0; l < 4; l++) {
            MazeNode * direction = a_node.getDirectionNode((directions::nesw)l);
            if (direction == nullptr)
                continue;
            
            if (canTravel(direction)) {
                direction->setVisited();
                pathToEnd.push_back(*direction);
                nodesToVisit.push(*direction);
                if (direction == a_maze.getLastNode())
                    pathFound = true;
            }
        }
    }

    return pathToEnd;
} // end DEF

// Personal algorithm.
// Optimization of past algorithms or an algorithm that already exists.
// Lowest run times recieve 5 points extra credit. Best submission: 10 points extra.
//@param a class Maze maze to be searched.
//@returns ordered vector with the path nodes from start point to end point.
std::vector<MazeNode> solveCustom(Maze &a_maze)
{
    vector<MazeNode> result;

    return result;
} // end solveCustom


} // namespace solutions
