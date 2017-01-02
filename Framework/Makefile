CPP = g++ -Wall -c

all: Board.o

Board.o: ../Exceptions/NotwellformedBoard.hpp Enum_Direction/Direction.hpp Box.hpp Board.hpp Board.cpp
	$(CPP) $^

clean:
	rm *.o
	rm *.gch
