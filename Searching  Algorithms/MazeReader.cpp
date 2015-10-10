/**
*	@file : MazeReader.cpp
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Implementation of MazeReader class
*/

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
    m_in.open(file);

    if(!m_in.is_open())
    {
        throw (MazeCreationException("The file could not be opened"));
    }
    m_in >> m_rows;
    m_in >> m_cols;
    m_in >> m_startRow;
    m_in >> m_startCol;
    if (m_rows <= 0 || m_cols <= 0)
    {
        throw (MazeCreationException("Invalid numbers of rows and cols"));
    }
    if (m_startRow >= m_rows || m_startCol >= m_cols || m_startRow < 0 || m_startCol < 0)
    {
        throw (MazeCreationException("Invalid starting position"));
    }
    m_maze = new char*[m_rows];
    for (int i = 0; i < m_rows; i++)
    {
        m_maze[i] = new char[m_cols];
    }
    readMaze();
}

MazeReader::~MazeReader()
{
    for (int i = 0; i < m_rows; i++)
    {
        delete[] m_maze[i];
    }
    delete[] m_maze;
}

char** MazeReader::getMaze() const
{
    return m_maze;
}

int MazeReader::getCols() const
{
    return m_cols;
}

int MazeReader::getRows() const
{
    return m_rows;
}

int MazeReader::getStartCol() const
{
    return m_startCol;
}
int MazeReader::getStartRow() const
{
    return m_startRow;
}
void MazeReader::readMaze()	throw (MazeCreationException)
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_in >> m_maze[i][j];
        }
    }
}


