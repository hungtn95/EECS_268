/**
*	@file : Position.h
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Header file of Position class
*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    /**
    *	@post Position created with row and col values set.
    */
    Position(int row, int col);

    /**
    *	@return row value
    */
    int getRow() const;

    /**
    *	@return col value
    */
    int getCol() const;

private:
    int m_row;
    int m_col;

};

#endif // POSITION_H
