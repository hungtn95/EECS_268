/**
*	@file : BoxOfAnything.hpp
*	@author : Hung Nguyen
*	@date : 2014.09.25
*	Purpose: Implementation of BoxOfAnything class
*/

template<typename T>
BoxOfAnything<T>::BoxOfAnything(T value)
{
    m_previous = nullptr;
    m_value = value;
}

template <typename T>
T BoxOfAnything<T>::getValue()
{
    return (m_value);
}

template <typename T>
void BoxOfAnything<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
BoxOfAnything<T>* BoxOfAnything<T>::getPrevious()
{
    return (m_previous);
}

template <typename T>
void BoxOfAnything<T>::setPrevious(BoxOfAnything<T>* previous)
{
    m_previous = previous;
}
