# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation
# ****************************************************
# Targets needed to bring the executable up to date


game: main.o game.o     # should include map.o
		g++  main.o  game.o    -o game -lncurses

main.o: main.cc
		g++ -c main.cc

game.o: game.cc game.h
		g++ -c  game.cc


#map.o: map.cc map.h
#		g++ -c  map.cc

