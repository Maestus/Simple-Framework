CPP = g++ -Wall -c

all: Module_2048.o

Module_2048.o: Module_2048.hpp ../../Framework/Board.hpp
	$(CPP) $^

clean:
	rm *.o
	rm *.gch
