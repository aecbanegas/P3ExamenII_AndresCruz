Main: Main.o NodoArbol.o Militar.o
	g++ Main.o NodoArbol.o Militar.o -lncurses
Main.o: Main.cpp
	g++ -c Main.cpp
NodoArbol.o: NodoArbol.cpp NodoArbol.h
	g++ -c NodoArbol.cpp
Militar.o: Militar.cpp Militar.h
	g++ -c Militar.cpp
