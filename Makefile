CPP = g++
NAME = game2


$(NAME) : 2048_Module/Classic/Playclassic.hpp 2048_Module/NegativeTiles/NegativeTiles.hpp 2048_Module/ThreeAndFiveTiles/TwoThreeFiveTiles.hpp Taquin/Taquin.hpp Graphic_mod/InitGraphic.hpp 2048_Module/lib/Module_2048.hpp InitGame.cpp
	$(CPP)  -o  $(NAME)  $^

clean:
	rm *.o
	rm $(NAME)
	make -C Framework clean
	make -C 2048_Module clean
	make -C Taquin clean
	make -C Graphic_mod clean
