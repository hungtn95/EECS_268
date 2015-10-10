Lab05: main.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o -o Lab05

main.o: main.cpp Queue.h Queue.hpp PreconditionViolationException.cpp PreconditionViolationException.h BoxOfAnything.h BoxOfAnything.hpp
	g++ -g -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h 
	g++ -g -std=c++11 -c PreconditionViolationException.cpp