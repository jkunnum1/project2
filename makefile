all:	project2

project2: main.o BST.o TST.o 
	g++ BST.o TST.o main.o -o project2

main.o: main.cpp
	g++ -c main.cpp

BST.o: BST.cpp
		g++ -c BST.cpp

TST.o: TST.cpp
		g++ -c TST.cpp

clean:
	rm -f *.o project2
