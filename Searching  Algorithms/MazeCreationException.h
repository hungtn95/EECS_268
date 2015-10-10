/**
*	@file : MazeCreationException.h
*	@author : Hung Nguyen
*	@date : 2014.11.21
*	Purpose: Header file of MazeCreationException class
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
public:
    /**
    * @post Creates an exception with the message
    */
    MazeCreationException(const char* message);
};

#endif // MAZECREATIONEXCEPTION_H
