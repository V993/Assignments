

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> testQueue;

    testQueue.push(20);
    testQueue.push(30);
    testQueue.push(40);
    testQueue.push(50);

    int sizeQueue = testQueue.size();
    cout << "Size of Queue: " << sizeQueue << endl << "| ";

    while(!testQueue.empty()) {
        cout << testQueue.front() << " | ";
        testQueue.pop();
    }
    cout << endl <<  "Data output, queue empty? " << testQueue.empty() << endl;
}