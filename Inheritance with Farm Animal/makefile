Lab04: main.o AnimalPen.o Chicken.o Cow.o CyberChicken.o FarmAnimal.o
	g++ -g -std=c++11 main.o AnimalPen.o Chicken.o Cow.o CyberChicken.o FarmAnimal.o -o Lab04

main.o: main.cpp FarmAnimal.h Chicken.h Cow.h CyberChicken.h
	g++ -g -std=c++11 -c main.cpp

AnimalPen.o: AnimalPen.cpp AnimalPen.h 
	g++ -g -std=c++11 -c AnimalPen.cpp

Chicken.o: Chicken.cpp Chicken.h
	g++ -g -std=c++11 -c Chicken.cpp

Cow.o: Cow.cpp Cow.h
	g++ -g -std=c++11 -c Cow.cpp

CyberChicken.o: CyberChicken.cpp CyberChicken.h
	g++ -g -std=c++11 -c CyberChicken.cpp

FarmAnimal.o: FarmAnimal.cpp FarmAnimal.h
	g++ -g -std=c++11 -c FarmAnimal.cpp