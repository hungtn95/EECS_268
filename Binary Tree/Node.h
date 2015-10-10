/**
*	@file : Node.h
*	@author : Hung Nguyen
*	@date : 2014.12.05
*	Purpose: Header file of Node class
*/

#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a Node instance
	*  @return Initialzed Node with m_left and m_right set to nullptr
	*/
    Node();

	/**
	*  @pre none
	*  @post creates copies of any nodes being pointed to by other
	*  @return a deep copy of the other Node
	*/
    Node(const Node<T>& other);

	/**
	*  @pre none
	*  @post none
	*  @return the value of m_value
	*/
    T getValue();

	/**
	*  @pre none
	*  @post none
	*  @return the value of m_left
	*/
    Node<T>* getLeft();

	/**
	*  @pre none
	*  @post none
	*  @return the value of m_right
	*/
    Node<T>* getRight();

	/**
	*  @pre none
	*  @post creates and initializes a Node instance
	*  @return initialzed Node with m_value set to value
	*/
    void setValue(T value);

	/**
	*  @pre none
	*  @post creates and initializes a Node instance
	*  @return initialzed Node with m_left set to left
	*/
    void setLeft(Node<T>* left);

	/**
	*  @pre none
	*  @post creates and initializes a Node instance
	*  @return initialzed Node with m_right set to right
	*/
    void setRight(Node<T>* right);

private:
    Node<T>* m_left;
    Node<T>* m_right;
    T m_value;
};

#endif // NODE_H
#include "Node.hpp"

