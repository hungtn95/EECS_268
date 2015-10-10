/**
*	@file : SortInfo.h
*	@author : Hung Nguyen
*	@date : 2014.11.13
*	Purpose: Header file of SortInfo class
*/

#include <functional>
#ifndef SORTINFO_H
#define SORTINFO_H
template<typename T>
class SortInfo
{
public:
	/**
	*  @pre None
	*  @post Sets m_sort to sort, m_name to name, m_time to 0.0, m_count to 0
	*  @return None
	*/
    SortInfo(std::function<void(T[], T)> sort, std::string name);

	/**
	*  @pre None
	*  @post None
	*  @return The sort function
	*/
    std::function<void(T[], int)> getSort() const;

	/**
	*  @pre None
	*  @post None
	*  @return The name of the sort
	*/
    std::string getName() const;

	/**
	*  @pre The sort has been timed accurately by another party
	*  @post None
	*  @return The time
	*/
    double getTime() const;

	/**
	*  @pre The sort has been timed accurately by another party, and that time is t
	*  @post The time is set to t
	*  @return None
	*/
    void setTime(double t);

	/**
	*  @pre The sort has been timed accurately by another party
	*  @post None
	*  @return The count of items sorted
	*/
    int getCount() const;

	/**
	*  @pre The sort has been timed accurately by another party, and that time is t
	*  @post The count is set to c, which reflects the number of items the sorted in under the time, m_time
	*  @return None
	*/
    void setCount(int count);

private:
    std::function<void(T[], T)> m_sort;
    std::string m_name;
    double m_time;
    int m_count;
};
#include "SortInfo.hpp"
#endif // SORTINFO_H
