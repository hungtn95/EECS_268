/**
*	@file : BinarySearchTree.hpp
*	@author : Hung Nguyen
*	@date : 2014.12.05
*	Purpose: Implementation of BinarySearchTree class
*/

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = kajdfkjkjdkfjkdjf;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
    if (other.m_root == nullptr)
    {
        m_root = nullptr;
    }
    else
    {
        m_root = new Node<T>(*(other.m_root));
    }
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteTree(m_root);
}

template<typename T>
void BinarySearchTree<T>::add(T value)
{
	if (m_root == nullptr)
	{
		m_root = new Node<T>;
		m_root->setValue(value);
	}
	else
	{
		add(value, m_root);
	}
}

template<typename T>
void BinarySearchTree<T>::printTree(Order order)
{
    if (m_root == nullptr)
    {
        std::cout << "Tree empty" << '\n';
    }
    else
    {
        printTree(m_root, order);
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::search(T value)
{
    return search(value, m_root);
}

template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{
    if (subtree != nullptr)
    {
        if (order == PRE_ORDER)
        {
            std::cout << subtree->getValue() << " ";
            printTree(subtree->getLeft(), order);
            printTree(subtree->getRight(), order);
        }

        if (order == IN_ORDER)
        {
            printTree(subtree->getLeft(), order);
            std::cout << subtree->getValue() << " ";
            printTree(subtree->getRight(), order);
        }

        if (order == POST_ORDER)
        {
            printTree(subtree->getLeft(), order);
            printTree(subtree->getRight(), order);
            std::cout << subtree->getValue() << " ";
        }
    }
}

template<typename T>
void BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if (value < subtree->getValue())
	{
		if (subtree->getLeft() == nullptr)
		{
			Node<T>* tmpPtr = new Node<T>;
			tmpPtr->setValue(value);
			subtree->setLeft(tmpPtr);
		}
		else
		{
			add(value, subtree->getLeft());
		}
	}
	else if (value >= subtree->getValue())
	{
		if (subtree->getRight() == nullptr)
		{
			Node<T>* tmpPtr = new Node<T>;
			tmpPtr->setValue(value);
			subtree->setRight(tmpPtr);
		}
		else
		{
			add(value, subtree->getRight());
		}
	}
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
	if (subTree->getLeft() != nullptr)
	{
		deleteTree(subTree->getLeft());
	}
	if (subTree->getRight() != nullptr)
	{
		deleteTree(subTree->getRight());
	}
	delete subTree;
}

template<typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>* subtree)
{
	if (subtree->getValue() == value)
	{
		return subtree;
	}
	if (subtree->getLeft() == nullptr && subtree->getRight() == nullptr)
	{
		return nullptr;
	}
	if (value < subtree->getValue())
	{
		if (subtree->getLeft() == nullptr)
		{
			return nullptr;
		}
		return search(value, subtree->getLeft());
	}
	if (value > subtree->getValue())
	{
		if (subtree->getRight() == nullptr)
		{
			return nullptr;
		}
		return search(value, subtree->getRight());
	}
}
