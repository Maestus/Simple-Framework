CPP = g++ -Wall -c

all: TwoThreeFiveTiles.o

ThreeAndFiveTiles.o: TwoThreeFiveTiles.hpp TwoThreeFiveTiles.cpp
	$(CPP) $^

clean:
	rm *.o
