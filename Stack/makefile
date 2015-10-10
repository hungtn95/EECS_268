Lab2: main.o StackOfBoxes.o Box.o 
	g++ -std=c++11 -g main.o StackOfBoxes.o Box.o -o Lab2

main.o: main.cpp StackOfBoxes.h
	g++ -std=c++11 -g -c main.cpp

StackOfBoxes.o: StackOfBoxes.h StackOfBoxes.cpp Box.h Box.cpp
	g++ -std=c++11 -g -c StackOfBoxes.cpp 

Box.o: Box.h Box.cpp
	g++ -std=c++11 -g -c Box.cpp 

clean: 
	rm *.o main
	clean done
