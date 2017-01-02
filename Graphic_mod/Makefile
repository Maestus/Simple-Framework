CPP = g++ -Wall -c
CPPFLAGS = `-lsfml-window -lsfml-graphics`

all: InitGraphic.o

InitGraphic.o: InitGraphic.hpp InitGraphic.cpp
	$(CPP) $(CPPFLAGS)  $^

clean:
	rm *.o
