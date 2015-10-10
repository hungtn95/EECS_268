/**
*	@file : StackOfAnything.hpp
*	@author : Hung Nguyen
*	@date : 2014.09.25
*	Purpose: Implementation of StackOfAnything class
*/

template<typename T>
StackOfAnything<T>::StackOfAnything()
{
    m_top = nullptr;
    m_size = 0;
}

template <typename T>
StackOfAnything<T>::~StackOfAnything()
{
    while (this->m_top != nullptr)
    {
        pop();
    }
}

template <typename T>
bool StackOfAnything<T>::isEmpty() const
{
    if (m_size = 0)
    {
        return true;
    }
    return false;
}

template <typename T>
int StackOfAnything<T>::size() const
{
    return (m_size);
}

template <typename T>
void StackOfAnything<T>::push(T value)
{
    BoxOfAnything<T>* temp = m_top;
    m_top = new BoxOfAnything<T>(value);
    m_top->setValue(value);
    m_top->setPrevious(temp);
    m_size ++;
}

template <typename T>
T StackOfAnything<T>::peek() const throw (std::runtime_error)
{
    if (m_top == nullptr)
    {
        throw(std::runtime_error("Peek attempted on empty stack"));
    }
    else
    {
        return (m_top->getValue());
    }
}

template <typename T>
T StackOfAnything<T>::pop() throw (std::runtime_error)
{
    if (m_top == nullptr)
    {
        throw(std::runtime_error("Pop attempted on empty stack"));
    }
    else
    {
        T tempVal = m_top->getValue();
        BoxOfAnything<T>* tempPtr = m_top->getPrevious();
        delete m_top;
        m_top = tempPtr;
        m_size --;
        return (tempVal);
    }
}
