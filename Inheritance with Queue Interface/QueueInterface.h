/**
*	@file : QueueInterface.h
*	@author : Hung Nguyen
*	@date : 2014.10.09
*	Purpose: Definition of Queue Interface
*/

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#endif // QUEUEINTERFACE_H
#include "PreconditionViolationException.h"

template <typename T>
class QueueInterface
{
public:
	/**
	*  @pre None
	*  @post Virtually calls the destructor of the derived class when being deleted
	*  @return None
	*/
    virtual ~QueueInterface(){}

	/**
	*  @pre None
	*  @post Indicates if the aueue is empty
	*  @return true if the queue is empty, false otherwise
	*/
    virtual bool isEmpty() const = 0;

	/**
	*  @pre None
	*  @post Indicates if the aueue is empty
	*  @return true if the queue is empty, false otherwise
	*/
    virtual void enqueue(const T newEntry) = 0;

	/**
	*  @pre The queue is not empty
	*  @post Removes the front of the queue, throws PreconditionViolationException when attempted on an empty stack
	*  @return The value of the entry at the front of the queue
	*/
    virtual T dequeue() throw(PreconditionViolationException) = 0;

	/**
	*  @pre The queue is not empty
	*  @post Throws PreconditionViolationException when attempted on an empty stack
	*  @return The value of the entry at the front of the queue
	*/
    virtual T peekFront() const throw(PreconditionViolationException) = 0;

	/**
	*  @pre None
	*  @post None
	*  @return the size of the queue
	*/
    virtual int size() const = 0;

	/**
	*  @pre None
	*  @post Prints the contents of the queue or "Queue Empty" if it is empty
	*  @return None
	*/
    virtual void print() const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is less than the rhs's size
	*/
    virtual bool operator< (const QueueInterface<T>& rhs) const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is less than or equal to the rhs's size
	*/
    virtual bool operator<= (const QueueInterface<T>& rhs) const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is greater than the rhs's size
	*/
    virtual bool operator> (const QueueInterface<T>& rhs) const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the this queue's size is greater than or equal to the rhs's size
	*/
    virtual bool operator>= (const QueueInterface<T>& rhs) const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the sizes of both queues are equal
	*/
    virtual bool operator== (const QueueInterface<T>& rhs) const = 0;

	/**
	*  @pre None
	*  @post None
	*  @return True if the sizes of both queues are not equal
	*/
    virtual bool operator!= (const QueueInterface<T>& rhs) const = 0;
};
