main: main.o HanoiStack.o
	g++ -o main main.o HanoiStack.o -std=c++11

main.o: main.cpp HanoiStack.cpp HanoiStack.h
	g++ -c main.cpp HanoiStack.cpp -std=c++11

HanoiStack.o: HanoiStack.cpp HanoiStack.h
	g++ -c HanoiStack.cpp -std=c++11

clean: 
	rm *.o main