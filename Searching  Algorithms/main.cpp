/**
*	@file : main.cpp
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Implementation of main function
*/

#include "MazeReader.h"
#include <fstream>
#include "MazeWalker.h"

int main(int argc, char** argv)
{
	std::string input;
	std::string type;
	bool dfs = false;
	try
	{
		if (argc != 3)
		{
			throw (std::runtime_error("Input Invalid"));
		}
		else
		{
			input = argv[1];
			type = argv[2];
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << '\n';
		return 0;
	}
	if (type == "-dfs")
	{
		dfs = true;
	}
	MazeReader* maze_reader;
	try
	{
		maze_reader = new MazeReader(input);
	}
	catch (MazeCreationException& e)
	{
		std::cout << e.what() << '\n';
		return 0;
	}
	MazeWalker* maze_walker = new MazeWalker(maze_reader->getMaze(), maze_reader->getStartRow(), maze_reader->getStartCol(), maze_reader->getRows(), maze_reader->getCols(), dfs);
	maze_walker->walkMaze();
	delete maze_reader;
	delete maze_walker;
	return 0;
}
