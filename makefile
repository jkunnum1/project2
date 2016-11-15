all:	project2

project2: main.o BST.o TST.o
	g++ BST.o main.o -o project2

main.o: main.cpp
	g++ -c main.cpp -std=c++11

BST.o: BST.cpp
	g++ -c BST.cpp -std=c++11

TST.o: TST.cpp
	g++ -c TST.cpp -std=c++11

clean:
	rm -f *.o project2
