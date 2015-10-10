/**
*	@file : MazeWalker.h
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Header file of MazeWalker class
*/

#include "Position.h"
#include <stack>
#include <queue>
#include <iostream>
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

class MazeWalker
{
public:
    /**
    *	@pre The mazePtr pointer is to a valid maze.
    *	@post A maze walker if created with all needed flags set and the visited array contains all false.
    */
    MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

	/**
	*	@post m_startPos and the visited array are deallocated.
	*/
	~MazeWalker();

    /**
    *	@pre The maze is a valid maze.
    *	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted. The visited array printed during the traversal.
    */
    void walkMaze();

	/**
	*	@post The visited array is printed. 
	*/
	void mazePrint();

protected:
    /**
    *	@pre The current position is valid.
    *	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position.
    */
    void storeValidMoves();

    /**
    *	@pre The position is valid.
    *	@post The current position is set to p and the position is updated as marked.
    */
    void move(Position& p);

    /**
    *	@returns If the current position is the exit, true is returned. False is returned otherwise.
    */
    bool isGoalReached() const;

  //member variables
    bool m_isDFS;
    char** m_maze;
    bool** m_visited;
    int m_rows, m_cols;
	Position* m_curPos;
    Position* m_startPos;

    std::stack<Position> m_moveStack;
    std::queue<Position> m_moveQueue;
};

#endif // MAZEWALKER_H
