NAME_EXE=launch

all:
	g++ -std=c++11 InitGame.cpp -o $(NAME_EXE) -lsfml-system -lsfml-window -lsfml-graphics
