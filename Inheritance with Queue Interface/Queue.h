/**
*	@file : Queue.h
*	@author : Hung Nguyen
*	@date : 2014.10.09
*	Purpose: Header file of Queue class
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "QueueInterface.h"
#include "BoxOfAnything.h"
#include <iostream>

template<typename T>
class Queue : public QueueInterface<T>
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a queue of type T
	*  @return Initialzed queue with m_front and m_back set to nullptr and m_size set to 0
	*/
    Queue();

	/**
	*  @pre None
	*  @post Deletes all elements in the queue
	*  @return An empty queue
	*/
    virtual ~Queue();

	/**
	*  @pre None
	*  @post Indicates if the aueue is empty
	*  @return true if the queue is empty, false otherwise
	*/
    virtual bool isEmpty() const;

	/**
	*  @pre None
	*  @post Indicates if the aueue is empty
	*  @return true if the queue is empty, false otherwise
	*/
    virtual void enqueue(const T newEntry);

	/**
	*  @pre The queue is not empty
	*  @post Removes the front of the queue, throws PreconditionViolationException when attempted on an empty stack
	*  @return The value of the entry at the front of the queue
	*/
    virtual T dequeue() throw(PreconditionViolationException);

	/**
	*  @pre The queue is not empty
	*  @post Throws PreconditionViolationException when attempted on an empty stack
	*  @return The value of the entry at the front of the queue
	*/
    virtual T peekFront() const throw(PreconditionViolationException);

	/**
	*  @pre None
	*  @post None
	*  @return the size of the queue
	*/
    virtual int size() const;

	/**
	*  @pre None
	*  @post Prints the contents of the queue or "Queue Empty" if it is empty
	*  @return None
	*/
    virtual void print() const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is less than the rhs's size
	*/
    virtual bool operator< (const QueueInterface<T>& rhs) const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is less than or equal to the rhs's size
	*/
    virtual bool operator<= (const QueueInterface<T>& rhs) const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is greater than the rhs's size
	*/
    virtual bool operator> (const QueueInterface<T>& rhs) const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is greater than or equal to the rhs's size
	*/
    virtual bool operator>= (const QueueInterface<T>& rhs) const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the sizes of both queues are equal
	*/
    virtual bool operator== (const QueueInterface<T>& rhs) const;

	/**
	*  @pre None
	*  @post None
	*  @return True if the sizes of both queues are not equal
	*/
    virtual bool operator!= (const QueueInterface<T>& rhs) const;

private:
    BoxOfAnything<T>* m_front;
    BoxOfAnything<T>* m_back;
    int m_size;
};
#include"Queue.hpp"

#endif // QUEUE_H
