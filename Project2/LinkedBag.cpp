//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

//Leonardo Matone

#include "LinkedBag.h"
#include "Node.h"

#include <cstddef>
#include <iostream>

using namespace std;

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount) {
   itemCount = entryCount;
   headPtr = new Node<ItemType>();
   if (entryCount == 0) {
      headPtr = nullptr;
   }
   else
   {
      // Copy first index
      headPtr->setItem(entries[0]);
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      int i = 1;

      while ((i < itemCount) && (newChainPtr != nullptr))
      {
         // Get next item from original chain
         ItemType nextItem = entries[i];
         
         // make a new node with the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         //Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to next node
         newChainPtr = newChainPtr->getNext();
         i++;
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
} // end Array copy

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   //counter ptr
   Node<ItemType>* countNode = headPtr;  
   int counter = 0;
   // count each node:
   while (countNode != nullptr) {
      countNode = countNode->getNext();
      counter++;
   }
   return counter;
}  // end getCurrentSize

template<class ItemType>
int LinkedBag<ItemType>::recursionCount(Node<ItemType>* ptr)
{
   if (ptr == nullptr)
   {
      return 0;
   }
   return 1 + recursionCount(ptr->getNext());
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive() 
{
   return recursionCount(headPtr);
} //end getCurrentSizeRecursive

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
      //new implementation, new node inserted at the end of the linked chain.
// /*

   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);

   //designate where it points (null)
   nextNodePtr->setNext(nullptr); // redundant, because the default is nullptr
   
         //if the headPtr is the only pointer, point it at the new node, done.
   if (headPtr == nullptr) {
      headPtr = nextNodePtr;
   }
   else {
      //establish a pointer to find the last node in the chain
      Node<ItemType>* last = headPtr;
      
      //cycle through each pointer till we hit the nullptr, the last link in the chain.
      while (last->getNext() != nullptr) {
         last = last->getNext();
      }   
      //at this point, cur_ptr must equal nullptr.
      //thus, we change the value of cur_ptr to our new pointer.
      last->setNext(nextNodePtr);
   }
  
   //at this point, cur_ptr must equal nullptr.
   //thus, we change the value of cur_ptr to our new pointer.

   //and increment itemCount
   itemCount++;

   return true;
// */
      //old implementation, new node inserted at the beginning of the linked chain.
/*
   //Add to beginning of chain: new node references rest of chain;
   //(headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain

   //   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
*/
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

template<class ItemType>
bool LinkedBag<ItemType>::deleteSecondNode() {
   
   //counter ptr
   Node<ItemType>* countNode = headPtr;  
   int counter = 0;
   // count each node:
   while (countNode != nullptr) {
      countNode = countNode->getNext();
      counter++;
   }
   //if the chain only has one item, we don't want to remove anything.
   if (counter < 2) {
      return false;
   }

   Node<ItemType>* secondNode = headPtr->getNext();

   // // boring way: 
   // headPtr->setNext(secondNode->getNext());
   // cout << headPtr->getNext()->getItem();
   // secondNode = nullptr;
   // delete secondNode;

   ItemType item = secondNode->getItem();
   //cout << item << endl;
   remove(item);

   return true;
} // end removeSecond

template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom() {
   int deleteThis = rand() % itemCount;
   Node<ItemType>* remover = headPtr;
   cout << deleteThis << endl;

   for (int i = 0; i < deleteThis; i++) {
      remover = remover->getNext();
   }
   ItemType item = remover->getItem();
   remove(item);
   return item;
}