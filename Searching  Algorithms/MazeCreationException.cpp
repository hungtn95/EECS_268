/**
*	@file : MazeCreationException.cpp
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Implementation of MazeCreationException class
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message) : std::runtime_error(message)
{
}
