all:	project2

project2: main.o BST.o
	g++ BST.o main.o -o project2

main.o: main.cpp
	g++ -c main.cpp

BST.o: BST.cpp
		g++ -c BST.cpp

clean:
	rm -f *.o project2
