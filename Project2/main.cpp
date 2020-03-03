//Leonardo Matone
//testing file for LinkedBag system


#include <iostream>
#include <string>

#include "LinkedBag.h"

using namespace std;

//for part 1, removing the second item in the bag:
/*
int main() {

    //test value linkedbag
    LinkedBag<int> bigBag;
    bigBag.add(20);
    bool test = bigBag.add(30);
    bigBag.add(40);
    bigBag.add(50);
    bigBag.add(60);
    bigBag.add(60);
    bigBag.add(60);
    bigBag.add(60);

    //test sees if it was added (bool returned true)
    cout << "Added: " << test << endl; 

    //test sees if it's actually in the bag.
    cout << "Is in bag: " << bigBag.contains(20) << endl;

    //establish vector to test all results
    vector<int> vectorTest = bigBag.toVector();

    //output the size of LinkedBag. Should be 5.
    cout << "New size: " << bigBag.getCurrentSize() << endl;

    //output contents of linkedbag from vector
    cout << "| ";
    for (int i = 0; i < bigBag.getCurrentSize(); i++) {
        cout << vectorTest[i] << " | ";
    }
    cout << endl << endl; 

    bool testRemoved = bigBag.removeSecond();
    cout << "removed: " << testRemoved << endl;
    cout << "New size: " << bigBag.getCurrentSize() << endl;

    cout << "| ";
    for (int i = 0; i < bigBag.getCurrentSize(); i++) {
        cout << vectorTest[i] << " | ";
    }
    cout << endl; 
}
*/

    //for part 2, revising add() so that entries are added at the end of the chain:
/*
int main() {

    //test value linkedbag
    LinkedBag<int> bigBag;
    bigBag.add(20);
    bool test = bigBag.add(30);
    bigBag.add(40);
    bigBag.add(50);
    bigBag.add(60);

    //test sees if it was added (bool returned true)
    cout << test << endl; 

    //test sees if it's actually in the bag.
    cout << bigBag.contains(20) << endl;

    //establish vector to test all results
    vector<int> vectorTest = bigBag.toVector();

    //output the size of LinkedBag. Should be 5.
    cout << "New size: " << bigBag.getCurrentSize() << endl;

    //output contents of linkedbag from vector
    cout << "| ";
    for (int i = 0; i < bigBag.getCurrentSize(); i++) {
        cout << vectorTest[i] << " | ";
    }
    cout << endl; 
}
*/

    //for part 3, revising getCurrentSize so that it counts the number of nodes in the linked chain
    //manually, ITERATIVELY and RECURSIVELY.
/*
int main() {
    LinkedBag
}
*/

    //for part 4, making a new constructor which creates a linkedbag from an array.
/*
int main() {
    int array[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    //cout array to test
    cout << "| ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " | ";
    }
    cout << endl << endl;
    
    //convert array to linkedBag
    LinkedBag<int> bagFromArray(array, 10);

    //convert linkedBag to vector
    vector<int> vectorTest = bagFromArray.toVector();

    //cout vector for testing
    cout << "| ";
    for (int i = 0; i < bagFromArray.getCurrentSize(); i++) {
        cout << vectorTest[i] << " | ";
    }
    cout << endl; 
}
*/

    //for part 5, creating a method which removes a random entry from the bag.

int main() {
    
}