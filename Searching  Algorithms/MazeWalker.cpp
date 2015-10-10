/**
*	@file : MazeWalker.cpp
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Implementation of MazeWalker class
*/

#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs)
{
	m_isDFS = dfs;
	m_maze = mazePtr;
	m_visited = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		m_visited[i] = new bool[cols];
		for (int j = 0; j < cols; j++)
		{
			m_visited[i][j] = false;
		}
	}
	m_rows = rows;
	m_cols = cols;
	m_startPos = new Position(startRow, startCol);
}

MazeWalker::~MazeWalker()
{
	delete m_startPos;
	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_visited[i];
	}
	delete[] m_visited;
}

void MazeWalker::mazePrint()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			std::cout << m_visited[i][j];
		}
		std::cout << '\n';
	}
	std::cout << "Visiting position: " << m_curPos->getRow() << ", " << m_curPos->getCol() << '\n';
	std::cout << "--------------------------" << '\n';
}

void MazeWalker::walkMaze()
{
	move(*m_startPos);
	mazePrint();
	while (!isGoalReached())
	{
		storeValidMoves();
		if (m_isDFS)
		{
			if (m_moveStack.empty())
			{
				break;
			}
			move(m_moveStack.top());
			m_moveStack.pop();
		}
		else
		{
			if (m_moveQueue.empty())
			{
				break;
			}
			move(m_moveQueue.front());
			m_moveQueue.pop();
		}
		mazePrint();
	}
	if (isGoalReached())
	{
		std::cout << '\n' << "Exit found!" << '\n';
	}
	else
	{
		std::cout << '\n' << "No way out!" << '\n';
	}
}

void MazeWalker::storeValidMoves()
{
	int row = m_curPos->getRow();
	int col = m_curPos->getCol();

	if (row > 0)
	{
		if (m_maze[row - 1][col] != 'W' && !m_visited[row - 1][col])
		{
			Position up(row - 1, col);
			if (m_isDFS)
			{
				m_moveStack.push(up);
			}
			else
			{
				m_moveQueue.push(up);
			}
		}
	}

	if (row < m_rows - 1)
	{
		if (m_maze[row + 1][col] != 'W' && !m_visited[row + 1][col])
		{
			Position down(row + 1, col);
			if (m_isDFS)
			{
				m_moveStack.push(down);
			}
			else
			{
				m_moveQueue.push(down);
			}
		}
	}

	if (col > 0)
	{
		if (m_maze[row][col - 1] != 'W' && !m_visited[row][col - 1])
		{
			Position left(row, col - 1);
			if (m_isDFS)
			{
				m_moveStack.push(left);
			}
			else
			{
				m_moveQueue.push(left);
			}
		}
	}

	if (col < m_cols - 1)
	{
		if (m_maze[row][col + 1] != 'W' && !m_visited[row][col + 1])
		{
			Position right(row, col + 1);
			if (m_isDFS)
			{
				m_moveStack.push(right);
			}
			else
			{
				m_moveQueue.push(right);
			}
		}
	}

}

void MazeWalker::move(Position& p)
{
	m_curPos = &p;
	m_visited[m_curPos->getRow()][m_curPos->getCol()] = true;
}

bool MazeWalker::isGoalReached() const
{
	if (m_maze[m_curPos->getRow()][m_curPos->getCol()] == 'E')
	{
		return true;
	}
	else
	{
		return false;
	}
}
