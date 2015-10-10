/**
*	@file : BinarySearchTree.h
*	@author : Hung Nguyen
*	@date : 2014.12.05
*	Purpose: Header file of BinarySearchTree class
*/

#include <iostream>
#include "Node.h"
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
enum Order
    { PRE_ORDER,
      IN_ORDER,
      POST_ORDER };

template<typename T>
class BinarySearchTree
{
public:
	/**
	*  @pre none
	*  @post creates and initializes a binary search tree of type T
	*  @return initialzed BST with m_root set to nullptr
	*/
    BinarySearchTree();

	/**
	*  @pre none
	*  @post Copy constructor
	*  @return a deep copy of the other BST
	*/
    BinarySearchTree(const BinarySearchTree<T>& other);

	/**
	*  @pre none
	*  @post calls deleteTree and passes in m_root as the starting point
	*  @return An empty BST
	*/
    ~BinarySearchTree();

	/**
	*  @pre none
	*  @post adds the value to the tree
	*  @return none
	*/
    void add(T value);

	/**
	*  @pre if the tree is empty display "Tree empty"
	*  @post print the tree in the specified order
	*  @return none
	*/
    void printTree(Order order);

	/**
	*  @pre none
	*  @post none
	*  @return the result from search(T value, Node<T>* subtree)
	*/
    Node<T>* search(T value);

private:
	/**
	*  @pre none
	*  @post adds the value to the correct branch (left or right) of the subtree
	*  @return none
	*/
    void add(T value, Node<T>* subtree);

	/**
	*  @pre none
	*  @post prints the tree in PRE_ORDER or IN_ORDER or POST_ORDER using the subtree and the "order"
	*  @return none
	*/
    void printTree(Node<T>* subtree, Order order) const;

	/**
	*  @pre none
	*  @post deletes the left subtree, right subtree, and root node of the subtree passed in
	*  @return none
	*/
    void deleteTree(Node<T>* subTree);

	/**
	*  @pre none
	*  @post none
	*  @return a pointer to the node containing the search value or nullptr if the value is not in the tree
	*/
    Node<T>* search(T value, Node<T>* subtree);

    Node<T>* m_root;
};

#endif // BINARYSEARCHTREE_H
#include "BinarySearchTree.hpp"
