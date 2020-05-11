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

/**     Tests a given node and returns the number of walls around it.
 * @param a_node pointer to a MazeNode object to be tested
 * @return an integer value designating the number of untraversable nodes around a_node */
int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    // Old implementation: 
    // // check nesw directions to see if they are walls. Count if wall. return count.
    // for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    // {
    //     if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
    //     {
    //         wall_counter++;
    //     }
    // }
    
    // Personal implementation 
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

/**     Tests a given node to see if it is traversible.
 * @param a_node pointer to a MazeNode object to be tested
 * @return true if the node can be traversed, false if not. */
bool canTravel(MazeNode *a_node)
{
    if (a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

/**     Tests a node to see whether it's within a given vector of nodes.
 * @param aVector cannot be empty. Vector contains pointers to MazeNodes.
 * @param aNode must be of pointer type, without null value.
 * @post vector and node go unchanged. access only.
 * @return true if the node is in the vector, false if not. */
bool inVector(vector<MazeNode*> aVector, MazeNode* aNode) 
{
    MazeNode* testNode;
    for (int i = 0; i < aVector.size(); i++) {
        testNode = aVector[i];
        if (testNode == aNode) 
            return true;
    }
    return false;
}

/**     Recursive helper function for solveDFS 
 * @param a_node is a pointer to a node in the maze
 * @param endNode is a pointer to the last node in the maze, for our base case
 * @param visitedVector is the stack which is used to store nodes traversed, and pop back nodes to dead ends.
 * @pre a maze must exist, all params must be of correct types, and there must be a designated start and stop to the maze.
 * @post visitedVector now contains the path to the end in MazeNodes from the caller.
 * @return true if the operation to find the end is found, else false. */
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

/*************************************************************************************/

/*  Applications:
        Detecting cycles in graphs
        Path finding
        Finding strongly connected components in a graph

    Time  : O(V + E)
    Space : O(n) where n is the size of the maze
    Explores each option individually to max distance.
    Memory efficient, not speed efficient. */
/**     Depth-First Search.
 * @param a_maze of class Maze maze to be searched. 
 * @returns ordered vector with the path nodes from start point to end point.*/
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
    Less memory efficient, same time complexity as DFS. */
/**     Breadth-First search
 * @param a_maze of class Maze maze to be searched. 
 * @returns ordered vector with the path nodes from start point to end point.*/
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

/* Applications: 
        Detecting dead-ends
        Path finding
    Time  : long
    Space : a lot
    Explores the maze similarly to BFS, marking each dead end.
    Marks all paths to dead ends as untraversible, leaving the
    only remaining path to the end. */
/**     Dead-End Filling Search.
 * @param a_maze of class Maze maze to be searched. 
 * @returns ordered vector with the path nodes from start point to end point.*/
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

    // setup:

        MazeNode * startNode = a_maze.getFirstNode();
        queue<MazeNode> nodesToVisit;
        nodesToVisit.push(*startNode);
        vector<MazeNode> deadEnds;
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
            deadEnds.push_back(*a_node);
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
        MazeNode deadEndStart = deadEnds[j];
        cout << "Examining dead end at: " << deadEndStart.getStrPos() << " ";
        int numWalls = 3; // as deadEndStart is a dead end
        queue<MazeNode*> toTravel;
        toTravel.push(&deadEndStart);
        while (numWalls >= 2) { //while the node is not in a junction (2 > walls)
            MazeNode* a_node = toTravel.front();
            toTravel.pop();
            a_node->setVisited();
            cout << "Setting " << a_node->getStrPos() << " to visited." << endl;
            for (int k = 0; k < 4; k++) {
                MazeNode * direction = a_node->getDirectionNode((directions::nesw)k);
                if (direction == nullptr) // for cases with mazes not surrounded by walls
                    continue;
                if (canTravel(direction)) {
                    toTravel.push(direction);
                    numWalls = getNumberOfWalls(direction);
                } // end if
            } // end for 
        } // end while 
    } // end for 

    /**     Third Step: Traverse the remaining path to the end.
     * while the end is not found
     *      traverse the maze, adding each travelled node to the vector of traversed nodes
     *      mark each node as visited, using a queue implementation to traverse each available node
     *      As the only nodes marked untraversed are the paths which do not lead to dead ends, 
     *      the only viable path for this algoritm to traverse is the path to the end.
     * 
     * return the vector of nodes to caller.
    */
    //second set up
        bool pathFound = false;
        vector<MazeNode> pathToEnd;
        pathToEnd.push_back(*startNode);
        startNode->setVisited();
        nodesToVisit.push(*startNode); 

    while (!pathFound) {
        MazeNode *a_node = &nodesToVisit.front();
        nodesToVisit.pop();
        cout << "New Iteration. Examining: " << a_node->getStrPos() << endl;
        cout << "node popped from queue. Proceeding to scan directions." << endl;
        for (int l = 0; l < 4; l++) {
            cout << "new direction" << endl;
            MazeNode * directionNode = a_node->getDirectionNode((directions::nesw)l);
            if (directionNode == nullptr)
                continue;
            cout << "Currently examining direction: " << l << " node at: " << directionNode->getStrPos() << endl;
            cout << "Can travel? " << endl;
            if (canTravel(directionNode)) {
                cout << "CAN travel. Setting to visited, pushing back into path to end,\nPushing back into nodes to visit. " << endl;
                directionNode->setVisited();
                pathToEnd.push_back(*directionNode);
                nodesToVisit.push(*directionNode);
                if (directionNode == a_maze.getLastNode()) {
                    cout << "This node is the end! returning current path to caller!" << endl;
                    pathFound = true;
                    return pathToEnd;
                } // end if
            } // end if
            cout << "Can't travel." << endl;
        } // end for
    } // end while

    // If the algorithm reaches this point, it has failed to find the last node.
    cout << "I failed to get to the end! " << endl;
    return deadEnds;
} // end DEF


// Personal algorithm.
// Optimization of past algorithms or an algorithm that already exists.
// Lowest run times recieve 5 points extra credit. Best submission: 10 points extra.
/** Personal Algorithm Search.
 * @param a_maze of class Maze maze to be searched. 
 * @returns ordered vector with the path nodes from start point to end point.*/
std::vector<MazeNode> solveCustom(Maze &a_maze)
{
    vector<MazeNode> result;

    return result;
} // end solveCustom

} // namespace solutions
