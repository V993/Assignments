/* 
    Author: Leonardo Matone
    Project: Doubly-Linked List
    DoublyLinkedList source, defines member functions of DoublyLinkedList
*/
 
#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

//default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0) 
{}

//parameterized constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& aBag) {
    itemCount = aBag.itemCount;
    DoubleNode<T>* origChainPtr = aBag.headPtr;

    if (origChainPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        // copying the first node 
        headPtr = new DoubleNode<T>();
        //
        T firstItem = origChainPtr->getItem();
        headPtr->setItem(firstItem);

        // Copy remaining nodes
        DoubleNode<T>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        // cycling through remaining nodes to copy  
        while (origChainPtr != nullptr) {
            // get next item from original chain
            T nextItem = origChainPtr->getItem();

            // create new doubleNode containing the next item
            DoubleNode<T>* newDoubleNodePtr = new DoubleNode<T>(nextItem);

            // Link new node to the end of the new chain
            newChainPtr->setNext(newDoubleNodePtr);
            newDoubleNodePtr->setPrevious(newChainPtr);

            // advance pointer to the last node
            newChainPtr = newChainPtr->getNext();

            //advance original chain ptr
            origChainPtr = origChainPtr->getNext();
        }//end while

        newChainPtr->setNext(nullptr);
        
    } // end if
}

//destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

//add method, not part of the project, just did for testing
template<class T>
bool DoublyLinkedList<T>::add(const T& anItem) {
//  old method, 
    /* 
        // designate the new DoubleNode
        DoubleNode<T>* nextNodePtr = new DoubleNode<T>();
        // DoubleNode<T>* previousNodePtr = headPtr;

        nextNodePtr->setItem(anItem); //set new item
        nextNodePtr->setNext(headPtr); //new node points next to chain
        nextNodePtr->setPrevious(nullptr); //new node points to null in the previous direction

        // see if the list is empty. If it is, we want the tailPtr to point to this node, as it will be last.
        if ((tailPtr == nullptr) && (headPtr != nullptr)) {
            //std::cout << "in tail mod" << std::endl;
            tailPtr = new DoubleNode<T>();
            headPtr->setPrevious(nextNodePtr);
            tailPtr->setPrevious(headPtr); //designating this the last node in the chain, its previous pointer should point to tail
        }

        if (headPtr != nullptr) {
            headPtr->setPrevious(nextNodePtr);
        }
    
        headPtr = nextNodePtr;
        itemCount++;

        return true;
    */

// new method, orders properly:

    DoubleNode<T>* nextNodePtr = new DoubleNode<T>();
    nextNodePtr->setItem(anItem);
    nextNodePtr->setNext(nullptr);

    if (headPtr == nullptr) { //if the list is empty, make headPtr point to the first node in the chain
        headPtr = nextNodePtr; //headPointer will always point to the first item in the chain
        nextNodePtr->setPrevious(nullptr);
    }
    else {
        DoubleNode<T>* last = new DoubleNode<T>();
        last = tailPtr->getPrevious();
        last->setNext(nextNodePtr);
        nextNodePtr->setPrevious(last);
    }

    tailPtr = new DoubleNode<T>();
    tailPtr->setPrevious(nextNodePtr);

    itemCount++;
    return true;
}

//insert method 
template<class T>
bool DoublyLinkedList<T>::insert(T item, const int &position){

    if ( (position < 1) || (position > itemCount + 1) ){
        return false; 
    }
    
    else {
        // create new node with item
        DoubleNode<T>* newNode = new DoubleNode<T>(item);

        if (position == 1) {// case if the index is 1
            if (headPtr == nullptr) { //check if there's nothign in the list
                headPtr = newNode; //link newnode to list if it's empty
                tailPtr = newNode;
            }
            else { // if there is something in the list: 
                newNode->setNext(headPtr); // set the new item 
                headPtr->setPrevious(newNode);
                headPtr = newNode; //headptr points to new item
            }
        }
        
        else {
            DoubleNode<T>* courrierNode = headPtr; //create current Pointer

            // goes to the node before our insert position
            for(int i = 2; i < position; i++){
                courrierNode = courrierNode->getNext(); 
            }

            if (courrierNode->getNext() != nullptr){//if new node is not at last index
                (courrierNode->getNext())->setPrevious(newNode); 
            }
            else {
                tailPtr = newNode;
                // cout << "tailPTr: " << tailPtr->getItem() << endl;
            }
            // if newNode is at last index
            newNode->setNext(courrierNode->getNext());
            courrierNode->setNext(newNode);
            newNode->setPrevious(courrierNode);   
        }
        itemCount++; // increase size of list beacuse new item added
        return true; //insert successful!
    }
}//end of inster method

//insert method
    // template<class T>
    // bool DoublyLinkedList<T>::insert(T item, const int& position) {

    //     bool canInsert = !(position < 1) || !(position > itemCount + 1);
    //     if (canInsert) 
    //     {
    //         DoubleNode<T>* newNode = new DoubleNode<T>();
    //         DoubleNode<T>* courrierNode = new DoubleNode<T>();
    //         newNode->setItem(item);
    //         courrierNode = headPtr;

    //         int index = 1; //because our indexing is 1 indexed (starting at 1), we start at 1.
    //         //in our while loop, we run through each doubleNode until we hit the node before posiiton index.
    //         if (position == 1) {
    //             if (headPtr == nullptr) {  
    //                 headPtr = newNode;
    //             }
    //             else {
    //                 newNode->setNext(headPtr);
    //                 headPtr->setPrevious(newNode);
    //                 headPtr = newNode;
    //             }
    //         }
    //         else {
    //             while (index < position - 1) { //to get the node before position
    //                 courrierNode = courrierNode->getNext();
    //                 index++; 
    //             } //end while

    //             DoubleNode<T>* previousNode = new DoubleNode<T>();
    //             previousNode = courrierNode; // this is now the node that should be before

    //             courrierNode = courrierNode->getNext(); // this is now the node that should be after
    //             courrierNode->setPrevious(newNode); // set the previous node to our new node
    //             newNode->setNext(courrierNode); // set the next node of our new node to the node that should be after

    //             previousNode->setNext(newNode); // set the next node to our new node
    //             newNode->setPrevious(previousNode); // mset the previous node of our new node to the node that should be before
    //         }
    //         itemCount++;
    //     }

    //     return canInsert;
// }

//remove method
template<class T>
bool DoublyLinkedList<T>::remove(const int& position) {
    DoubleNode<T>* courrierNode = new DoubleNode<T>();
    courrierNode = headPtr;

    bool canRemoveItem = !isEmpty() && (position != 0) && (position <= itemCount);
    if (canRemoveItem) {
        if (position == 1) {
            headPtr = courrierNode->getNext();
            (courrierNode->getNext())->setPrevious(nullptr); //set the second node previous to null
            delete courrierNode; //now delete the node
            courrierNode = nullptr;
        }
        else if (position == itemCount) {
            courrierNode = tailPtr; // courrierNode now points to the last node in the list
            courrierNode = courrierNode->getPrevious(); // making the courrierNode equal to the node to be deleted
            courrierNode->setNext(nullptr);
            tailPtr = courrierNode; //setting the tailptr to the node before the node to be deleted
            delete courrierNode->getNext();
            courrierNode = nullptr;
        }
        else {
            int index = 1; //because our indexing is 1 indexed (starting at 1), we start at 1.
            //in our while loop, we run through each doubleNode until we hit the node before posiiton index.
            while (index < position - 1) {
                courrierNode = courrierNode->getNext();
                index++; 
            } //end while
            //define the node prior to the node to be deleted
            DoubleNode<T>* previousNode = new DoubleNode<T>();
            previousNode = courrierNode;
            //define the node to be deleted
            DoubleNode<T>* nodeToBeDeleted = new DoubleNode<T>();
            nodeToBeDeleted = courrierNode->getNext();
            //define the node after the node to be deleted
            courrierNode = (courrierNode->getNext())->getNext();
            
            //delete the node
            delete nodeToBeDeleted;
            nodeToBeDeleted = nullptr;

            //fill the gap:
            previousNode->setNext(courrierNode);
            courrierNode->setPrevious(previousNode);
        } //end else
    itemCount--;
    } //end if
    return canRemoveItem;
}

//getSize method
template<class T>
int DoublyLinkedList<T>::getSize() const {
    return itemCount;
}

//get headPointer method
template<class T>
DoubleNode<T>* DoublyLinkedList<T>::getHeadPtr() const {
    return headPtr;
}

//get node at position method
template<class T>
DoubleNode<T>* DoublyLinkedList<T>::getAtPos(const int& position) const {

    DoubleNode<T>* courrierNode = new DoubleNode<T>();
    courrierNode = headPtr;
    bool isValid = !isEmpty() && (position != 0) && (position <= itemCount);
    if (isValid) {
        int index = 1; //because our indexing is 1 indexed (starting at 1), we start at 1.
        //in our while loop, we run through each doubleNode until we hit the node before posiiton index.
        while (index < position) {
            courrierNode = courrierNode->getNext();
            index++; 
        } //end while
    }
    return courrierNode;
}

//empty test method
template<class T>
bool DoublyLinkedList<T>::isEmpty() const {
    return itemCount == 0;
}

//clear method
template<class T>
void DoublyLinkedList<T>::clear() {
    DoubleNode<T>* nodeToDeletePtr = headPtr;

    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }
    itemCount = 0;
}

//display method
template<class T>
void DoublyLinkedList<T>::display() const {
    DoubleNode<T>* courrierNode;
    courrierNode = headPtr;
    while (courrierNode->getNext() != nullptr) {
        T item = courrierNode->getItem();
        cout << item <<  " ";
        courrierNode = courrierNode->getNext();
    } // end while
    cout << courrierNode->getItem() << endl;
}

template<class T>
void DoublyLinkedList<T>::displayBackwards() const {
    DoubleNode<T>* courrierNode;
    courrierNode = tailPtr;
    while (courrierNode->getPrevious() != nullptr) {
        T item = courrierNode->getItem();
        cout << item << " ";
        courrierNode = courrierNode->getPrevious();
    }
    cout << courrierNode->getItem() << endl;
}
 
template<class T>
DoublyLinkedList<T> DoublyLinkedList<T>::interleave(const DoublyLinkedList<T>& a_list) {
    
    //establish the first node of the first list
    DoubleNode<T>* doubleNode1;
    doubleNode1 = headPtr;
    int itemCount1 = itemCount;

    //establish the first node of the first list
    DoubleNode<T>* doubleNode2;
    doubleNode2 = a_list.headPtr;
    int itemCount2 = a_list.itemCount;

    //find the largest of the two sizes to be used for the new list
    int interleavedSize = itemCount1 + itemCount2;

    //define the new list
    DoublyLinkedList<T> interleaved;

/*----------------------------------------------------------------------------------------------*/

    int index = 1;
    //cycle through each index of each list and add each consequtively using add()
    while (index <= interleavedSize) {

        // add node/increment index only if the value of the node is not nullptr
        if (doubleNode1 != nullptr)
        {
            //get the item of the doublenode in the first list
            T itemDoubleNode1 = doubleNode1->getItem();            
            interleaved.insert(itemDoubleNode1, index);
            doubleNode1 = doubleNode1->getNext();
            index++;
        }

        // add node/increment index only if the value of the node is not nullptr
        if (doubleNode2 != nullptr) 
        {
            //get the item of the doublenode in the second list
            T itemDoubleNode2 = doubleNode2->getItem();
            interleaved.insert(itemDoubleNode2, index);
            doubleNode2 = doubleNode2->getNext();
            index++;
        }
    } //end while
   
    return interleaved;
}