output: main.o Ant.o
	g++ main.o Ant.o -o project1

main.o: main.cpp 
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c -std=c++11 Ant.cpp




clean:
	rm *.o lab1
