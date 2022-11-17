a.out: main.o Distances.o
	g++ -std=c++11 -o a.out main.o Distances.o 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Distances.o: Distances.cpp
	g++ -std=c++11 -c Distances.cpp

clean:
	rm -f *.o a.out
