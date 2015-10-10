Lab1: main.o Pokemon.o Dice.o
	g++ -std=c++11 -g main.o Pokemon.o Dice.o -o Lab1

main.o: main.cpp Pokemon.h
	g++ -std=c++11 -g -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp Dice.h Dice.cpp
	g++ -std=c++11 -g -c Pokemon.cpp 

Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -c Dice.cpp 

clean: 
	rm *.o main
	clean done