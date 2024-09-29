#Compiler setup
CC = g++
CFLAGS = -Wall -Wextra

all:
	$(CC) $(CFLAGS) -c tetromino_game.cpp pieces.cpp
	$(CC) $(CFLAGS) -o tetromino_game tetromino_game.o pieces.o -lraylib
	$(RM) *.o