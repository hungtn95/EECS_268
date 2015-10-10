/**
*	@file : PreconditionViolationException.cpp
*	@author : Hung Nguyen
*	@date : 2014.10.09
*	Purpose: Implementation of PreconditionViolationException class
*/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char *message) : std::runtime_error(message)
{
}
