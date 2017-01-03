NAME_EXE=launch

all:
	g++ InitGame.cpp -o $(NAME_EXE) -lsfml-system -lsfml-window -lsfml-graphics
