/**
*	@file : MazeReader.h
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Header file of MazeReader class
*/

#ifndef MAZEREADER_H
#define MAZEREADER_H
#include "MazeCreationException.h"
#include <iostream>
#include <fstream>

class MazeReader
{
public:
    /**
    *	@post A MazeReader is created. A 2D char array is allocated with the maze information.
    *	@throws MazeCreationExecption if any of the following is true:
        *                 -The file could not be opened
        *                 -The rows or cols are zero or less
        *                 -The start position listed is outside the ranges described by the rows and columns
        *                 -You do NOT have to check each character for validity, only the rows, cols, and starting position.
    *
    */
    MazeReader(std::string file) throw (MazeCreationException);

    /**
    *	@post The maze is deallocated.
    */
    ~MazeReader();

    /**
    *	@pre the file was formatting and read in correctly
    *	@return Returns pointer to the maze
    */
    char** getMaze() const;

    /**
    *	@pre the file was formatted and read in correctly
    *	@returns the number of columns listed in the file
    */
    int getCols() const;

    /**
    *	@pre the file was formatted and read in correctly
    *	@returns the number of rows listed in the file
    */
    int getRows() const;

    /**
    *	@pre the file was formatted and read in correctly
    *	@returns the starting column
    */
    int getStartCol() const;

    /**
    *	@pre the file was formatted and read in correctly
    *	@returns the starting row
    */
    int getStartRow() const;

protected:
    /**
    *	@pre the file is properly formatted
    *	@post the characters representing the maze are stores
    */
    void readMaze()	throw (MazeCreationException);

private:
    char** m_maze;
    int m_rows;
    int m_cols;
    int m_startRow;
    int m_startCol;
    std::ifstream m_in;
    std::string m_fileName;
};

#endif // MAZEREADER_H
