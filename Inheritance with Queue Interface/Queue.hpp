/**
*	@file : Queue.hpp
*	@author : Hung Nguyen
*	@date : 2014.10.09
*	Purpose: Implementation of Queue class
*/

template<typename T>
Queue<T>::Queue()
{
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    while (m_front != nullptr)
    {
        dequeue();
    }
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return (m_size == 0);
}

template<typename T>
void Queue<T>::enqueue(const T newEntry)
{
    if (m_size == 0)
    {
        m_back = new BoxOfAnything<T>(newEntry);
        m_back->setValue(newEntry);
        m_back->setNext(nullptr);
        m_front = m_back;
    }
    else
    {
        BoxOfAnything<T>* tempPtr = m_back;
        m_back = new BoxOfAnything<T>(newEntry);
        m_back->setValue(newEntry);
        tempPtr->setNext(m_back);
    }
    m_size ++;
}

template<typename T>
T Queue<T>::dequeue() throw(PreconditionViolationException)
{
    if (m_front == nullptr)
    {
        throw(PreconditionViolationException("Dequeue attempted on an empty stack"));
    }
    else
    {
        BoxOfAnything<T>* tempPtr = m_front->getNext();
        T tempVal = m_front->getValue();
        delete m_front;
        m_front = tempPtr;
        m_size --;
        return (tempVal);
    }
}

template<typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
    if (m_front == nullptr)
    {
        throw(PreconditionViolationException("Peek attempted on an empty stack"));
    }
    else
    {
        return (m_front->getValue());
    }
}

template<typename T>
int Queue<T>::size() const
{
    return (m_size);
}

template<typename T>
void Queue<T>::print() const
{
    if (m_size == 0)
    {
        std::cout << "Queue Empty" << '\n';
    }
    else
    {
        BoxOfAnything<T>* tempPtr = m_front;
        while (tempPtr != nullptr)
        {
            std::cout << tempPtr->getValue();
            if (tempPtr->getNext() != nullptr)
            {
                std::cout << ",";
            }
            tempPtr = tempPtr->getNext();
        }
    }
}

template<typename T>
bool Queue<T>::operator< (const QueueInterface<T>& rhs) const
{
    return(size() < rhs.size());
}

template<typename T>
bool Queue<T>::operator<= (const QueueInterface<T>& rhs) const
{
    return(size() <= rhs.size());
}

template<typename T>
bool Queue<T>::operator> (const QueueInterface<T>& rhs) const
{
    return(size() > rhs.size());
}

template<typename T>
bool Queue<T>::operator>= (const QueueInterface<T>& rhs) const
{
    return(size() >= rhs.size());
}

template<typename T>
bool Queue<T>::operator== (const QueueInterface<T>& rhs) const
{
    return(size() == rhs.size());
}

template<typename T>
bool Queue<T>::operator!= (const QueueInterface<T>& rhs) const
{
    return(size() != rhs.size());
}

