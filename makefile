# Atsuko Shimizu
# Julie Kunnumpurath
all:	project2

project2: main.o TST.o
	g++ main.o -o project2

main.o: main.cpp
	g++ -c main.cpp -std=c++11

TST.o: TST.cpp
	g++ -c TST.cpp -std=c++11

clean:
	rm -f *.o project2
