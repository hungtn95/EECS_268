/**
*	@file : Node.hpp
*	@author : Hung Nguyen
*	@date : 2014.12.05
*	Purpose: Implementation of Node class
*/

template<typename T>
Node<T>::Node()
{
    m_left = nullptr;
    m_right = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other)
{
    if (other.m_left == nullptr)
    {
        m_left = nullptr;
    }
    else
    {
        m_left = new Node<T>(*(other.m_left));
    }

    if (other.m_right == nullptr)
    {
        m_right = nullptr;
    }
    else
    {
        m_right = new Node<T>(*(other.m_right));
    }

    m_value = other.m_value;
}

template<typename T>
T Node<T>::getValue()
{
    return m_value;
}

template<typename T>
Node<T>* Node<T>::getLeft()
{
    return m_left;
}

template<typename T>
Node<T>* Node<T>::getRight()
{
    return m_right;
}

template<typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}

template<typename T>
void Node<T>::setLeft(Node<T>* left)
{
    m_left = left;
}

template<typename T>
void Node<T>::setRight(Node<T>* right)
{
    m_right = right;
}
