all:	project2

project2: main.o BST.o
	g++ BST.o main.o -o project2

main.o: main.cpp
	g++ -c main.cpp -std=c++11

BST.o: BST.cpp
	g++ -c BST.cpp -std=c++11

clean:
	rm -f *.o project2
