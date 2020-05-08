/* Queue Interface */ 

#ifndef QUEUE_HPP
#define QUEUE_HPP

template<class T>
class Queue 
{
    public:
        /** Tests whether this queue is empty.
         * @return True if the queue is empty, or false if not. */
        virtual bool isEmpty() const = 0; 

        /** Adds new entry to the back of the queue.
         * @post If the operation was successful, newEntry is at the back of the queue.
         * @param newEntry is the object to be added as a new item in the queue.
         * @return True if the addition is successful or false if not. */
        virtual bool add(const T& newEntry) = 0; 

        /** Returns the front of the queue
         * @post If the operation was successful, the front of the queue has been removed
         * @return True if the removal is successful or false if not */
        virtual bool remove() = 0; 

        /** Returns the front of the queue.
         * @pre The queue is not empty
         * @post The front of the queue has been returned, and the queue is unchanged.
         * @return The front of the queue. */
        virtual T peek() const = 0;
        
        /** Returns the size of the queue.
         * @return The size of the queue, regardless of population. */
        virtual int size() const; 

        /** Destructor */
        virtual ~Queue() {}
};

#endif